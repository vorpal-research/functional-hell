#include <iostream>
#include <utility>
#include <memory>

// provide the -I.. flag
#include "matchers_aux.hpp"

using namespace functional_hell::matchers;

class Type {
public:
    virtual ~Type() {};
    virtual std::string toString() const = 0;

    using Ptr = std::shared_ptr<Type>;
};

class Integer: public virtual Type {
    virtual std::string toString() const override {
        return "integer";
    }
};
class Pointer: public virtual Type {
    Type::Ptr pointee;
public:
    Pointer(Type::Ptr pointee): pointee{pointee} {};
    Type::Ptr getPointee() const { return pointee; }

    virtual std::string toString() const override {
        return getPointee()->toString() + "*";
    }
};

struct IntegerExtractor {
    match_bool unapply(Type::Ptr ptr) const {
        match_bool ret {dynamic_cast<Integer*>(ptr.get())};
        return ret;
    }
};

struct PointerExtractor {
    storage_t<Type::Ptr> unapply(Type::Ptr type) const {
        storage_t<Type::Ptr> ret;
        auto ptr = dynamic_cast<Pointer*>(type.get());
        if(!ptr) return ret;

        ret.construct();
        ret->set_1(ptr->getPointee());
        
        return ret;
    }
};

auto $integer = make_pattern(IntegerExtractor{});
auto $pointer = make_pattern(PointerExtractor{});

int main () {
    Type::Ptr tp = std::make_shared<Pointer>(std::make_shared<Pointer>(std::make_shared<Integer>()));

    Type::Ptr i = std::make_shared<Integer>();
    if($pointer($pointer($integer())) >> tp) {
        std::cerr << "Hit!" << std::endl;
    }

    if(auto m = $pointer(_1) >> tp) {
        std::cerr << m->_1->toString() << std::endl; // integer*
    }
}