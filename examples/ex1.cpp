#include <iostream>
#include <utility>
#include <memory>

// provide the -I.. flag
#include "matchers_fancy_syntax.h"

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
        return !!dynamic_cast<Integer*>(ptr.get());
    }
};

struct PointerExtractor {
    storage_t<Type::Ptr> unapply(Type::Ptr type) const {
        auto ptr = dynamic_cast<Pointer*>(type.get());

        if(!ptr) return {};

        return make_storage(ptr->getPointee());
    }
};

auto Integer_ = make_pattern(IntegerExtractor{});
auto Pointer_ = make_pattern(PointerExtractor{});

int main () {
    Type::Ptr tp = std::make_shared<Pointer>(
                       std::make_shared<Pointer>(
                           std::make_shared<Integer>()
                       )
                   );
    Type::Ptr i = std::make_shared<Integer>();

    SWITCH(tp) {
        CASE(Pointer_(Pointer_(Integer_()))) {
            std::cerr << "Hit!" << std::endl;
        }
        NAMED_CASE(M, Pointer_(_1)) {
            SWITCH(M->_1) {
                CASE(Integer_()) {
                    std::cerr << "eieio" << std::endl;
                }
            }
            std::cerr << M->_1->toString() << std::endl;
        }
        DEFAULT_CASE;
    }

    if(Pointer_(Pointer_(Integer_())) >> tp) {
        std::cerr << "Hit!" << std::endl;
    }

    if(auto m = Pointer_(_1) >> tp) {
        std::cerr << m->_1->toString() << std::endl; // integer*
    }
}
