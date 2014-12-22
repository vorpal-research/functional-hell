#include <iostream>
#include <memory>
#include <string>

// provide the -I.. flag
#include "matchers_aux.hpp"
#include "matchers_fancy_syntax.h"

using namespace functional_hell::matchers;
using namespace functional_hell::matchers::placeholders;

class Expr: public std::enable_shared_from_this<Expr> {
protected:
    Expr() {}
public:
    virtual ~Expr() {}

    using Ptr = std::shared_ptr<const Expr>;
};

class VarExpr: public Expr {
    std::string name;

    VarExpr(const std::string& name) : name(name) {}
public:
    static Expr::Ptr create(const std::string& name) {
        return Expr::Ptr{ new VarExpr(name) };
    }

    const std::string& getName() const { return name; }
};

struct VarExtractor {
    storage_t<const std::string&> unapply(Expr::Ptr v) const {
        if(auto var = dynamic_cast<const VarExpr*>(v.get())) {
            return make_storage(var->getName());
        }
        return {};
    }
};

auto Var_ = make_pattern(VarExtractor{});

class AppExpr: public Expr {
    Expr::Ptr lhv;
    Expr::Ptr rhv;

    AppExpr(Expr::Ptr lhv, Expr::Ptr rhv): lhv(lhv), rhv(rhv) {}
public:
    static Expr::Ptr create(Expr::Ptr lhv, Expr::Ptr rhv) {
        return Expr::Ptr{ new AppExpr(lhv, rhv) };
    }

    Expr::Ptr getLhv() const { return lhv; }
    Expr::Ptr getRhv() const { return rhv; }
};

struct AppExtractor {
    storage_t<Expr::Ptr, Expr::Ptr> unapply(Expr::Ptr v) const {
        if(auto app = dynamic_cast<const AppExpr*>(v.get())) {
            return make_storage(app->getLhv(), app->getRhv());
        }
        return {};
    }
};

auto App_ = make_pattern(AppExtractor{});

class AbsExpr: public Expr {
    std::string var;
    Expr::Ptr expr;

    AbsExpr(const std::string& var, Expr::Ptr expr): var(var), expr(expr) {}

public:
    static Expr::Ptr create(const std::string& var, Expr::Ptr expr) {
        return Expr::Ptr{ new AbsExpr(var, expr) };
    }

    const std::string& getVar() const { return var; }
    Expr::Ptr getExpr() const { return expr; }
};

struct AbsExtractor {
    storage_t<const std::string&, Expr::Ptr> unapply(Expr::Ptr v) const {
        if(auto abs = dynamic_cast<const AbsExpr*>(v.get())) {
            return make_storage(abs->getVar(), abs->getExpr());
        }
        return {};
    }
};

auto Abs_ = make_pattern(AbsExtractor{});

Expr::Ptr Var(const std::string& name) {
    return VarExpr::create(name);
}

Expr::Ptr App(Expr::Ptr lhv, Expr::Ptr rhv) {
    return AppExpr::create(lhv, rhv);
}

Expr::Ptr Abs(const std::string& var, Expr::Ptr expr) {
    return AbsExpr::create(var, expr);
}

class Type: public std::enable_shared_from_this<Type> {
protected:
    Type() {}
public:
    virtual ~Type() {}

    using Ptr = std::shared_ptr<const Type>;
};

class ConstType : public Type {
    ConstType() = default;
public:
    static Type::Ptr create() {
        return Type::Ptr{ new ConstType() };
    }
};

struct ConstTypeExtractor {
    storage_t<> unapply(Type::Ptr t) const {
        return !!dynamic_cast<const ConstType*>(t.get());
    }
};

auto Const_ = make_pattern(ConstTypeExtractor{});

class TyVarType : public Type {
    std::string name;

    TyVarType(const std::string& name): name(name) {}
public:
    static Type::Ptr create(const std::string& name) {
        return Type::Ptr{ new TyVarType(name) };
    }

    const std::string& getName() const {
        return name;
    }
};

struct TyVarTypeExtractor {
    storage_t<const std::string&> unapply(Type::Ptr t) const {
        if(auto tv = dynamic_cast<const TyVarType*>(t.get())) {
            return make_storage(tv->getName());
        }
        return {};
    }
};

auto TyVar_ = make_pattern(TyVarTypeExtractor{});

class ArrowType : public Type {
    Type::Ptr lhv;
    Type::Ptr rhv;

    ArrowType(Type::Ptr lhv, Type::Ptr rhv): lhv(lhv), rhv(rhv) {}
public:
    static Type::Ptr create(Type::Ptr lhv, Type::Ptr rhv) {
        return Type::Ptr{ new ArrowType(lhv, rhv) };
    }

    Type::Ptr getLhv() const { return lhv; }
    Type::Ptr getRhv() const { return rhv; }
};

struct ArrowTypeExtractor {
    storage_t<Type::Ptr, Type::Ptr> unapply(Type::Ptr t) const {
        if(auto tv = dynamic_cast<const ArrowType*>(t.get())) {
            return make_storage(tv->getLhv(), tv->getRhv());
        }
        return {};
    }
};

auto Arrow_ = make_pattern(ArrowTypeExtractor{});

Type::Ptr Const() {
    return ConstType::create();
}

Type::Ptr TyVar(const std::string& name) {
    return TyVarType::create(name);
}

Type::Ptr Arrow(Type::Ptr lhv, Type::Ptr rhv) {
    return ArrowType::create(lhv, rhv);
}

std::ostream& operator<<(std::ostream& ost, Expr::Ptr e) {
    SWITCH(e) {
        NAMED_CASE(m, Var_(_1)) ost << m->_1;
        NAMED_CASE(m, App_(_1 & Abs_(_, _), _2)) ost << "(" << m->_1 << ")" << m->_2;
        NAMED_CASE(m, App_(_1, Var_(_2))) ost << m->_1 << " " << m->_2;
        NAMED_CASE(m, App_(_1, _2)) ost << m->_1 << "(" << m->_2 << ")";
        NAMED_CASE(m, Abs_(_1, _2)) ost << "\\" << m->_1 << "." << m->_2;
    }
    return ost;
}

std::ostream& operator<<(std::ostream& ost, Type::Ptr t) {
    SWITCH(t) {
        CASE(Const_()) ost << "*";
        NAMED_CASE(m, TyVar_(_1)) ost << m->_1;
        NAMED_CASE(m, Arrow_(Const_(), _1)) ost << "* -> " << m->_1;
        NAMED_CASE(m, Arrow_(TyVar_(_1), _2)) ost << m->_1 << " -> " << m->_2;
        NAMED_CASE(m, Arrow_(_1, _2)) ost << "(" << m->_1 << ") -> " << m->_2;
    }
    return ost;
}

bool operator==(Expr::Ptr lhv, Expr::Ptr rhv) {
    SWITCH(lhv, rhv) {
        CASE(Var_(_1), Var_(_1)) return true;
        CASE(App_(_1, _2), App_(_1, _2)) return true;
        CASE(Abs_(_1, _2), Abs_(_1, _2)) return true;
    }
    return false;
}

Expr::Ptr substituteVar(Expr::Ptr where, const std::string& from, Expr::Ptr to) {
    SWITCH(where) {
        CASE(Var_(from)) return to;
        CASE(Var_(_)) return where;
        NAMED_CASE(m, App_(_1, _2)) return App(substituteVar(m->_1, from, to), substituteVar(m->_2, from, to));
        NAMED_CASE(m, Abs_(from, _1)) return where; // inner `from` overrides the outer one
        NAMED_CASE(m, Abs_(_1, _2)) return Abs(m->_1, substituteVar(m->_2, from, to));
    }
    return nullptr;
}

Expr::Ptr outerEval(Expr::Ptr what) {
    SWITCH(what)
        NAMED_CASE(m, App_(Abs_(_1, _2), _3))
            return outerEval(substituteVar(m->_2, m->_1, m->_3));

    return what;
}

Expr::Ptr innerEval(Expr::Ptr what) {
    SWITCH(what) {
        NAMED_CASE(m, App_(_1, _2)){
            SWITCH(innerEval(m->_1), innerEval(m->_2)) {
                NAMED_CASE(m, Abs_(_1, _2), _3) return substituteVar(m->_2, m->_1, m->_3);
                NAMED_CASE(m, _1, _2) return App(m->_1, m->_2);
            }
        }

        NAMED_CASE(m, Abs_(_1, _2)) return Abs(m->_1, innerEval(m->_2));
    }
    return what;
}

int main() {
    auto exExpr = App(Abs("x", App(Var("f"), Var("x"))), Var("2"));
    std::cout << exExpr << std::endl;
    std::cout << substituteVar(exExpr, "2", Var("y")) << std::endl;
    std::cout << outerEval(exExpr) << std::endl;
    std::cout << innerEval(exExpr) << std::endl;
    std::cout <<
        Arrow(
            Arrow(Const(), Arrow(Const(), Const())),
            Arrow(Arrow(Const(), Const()), Arrow(Const(), Const()))
        ) << std::endl;
}
