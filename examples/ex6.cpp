#include <iostream>
#include <utility>
#include <memory>
#include <string>
#include <vector>
#include <cassert>


// provide the -I.. flag
#include "matchers_aux.hpp"

using namespace functional_hell::matchers;
using namespace functional_hell::matchers::placeholders;

struct Person {
    std::string name;
    unsigned long long age;
    std::vector<int> phone;
};

struct PersonExtractor
{
    storage_t<std::string&, unsigned long long&, std::vector<int>&> unapply(Person& v) const {
        return make_storage(v.name, v.age, v.phone);
    }

    storage_t<const std::string&, unsigned long long, const std::vector<int>&> unapply(const Person& v) const {
        return make_storage(v.name, v.age, v.phone);
    }
};

template<class Lam>
struct LambdaExtractor {
    Lam lam;

    template<class ...Args>
    auto unapply(Args&&... args) const -> decltype(lam(std::forward<Args>(args)...)) {
        return lam(std::forward<Args>(args)...);
    }
};

template<class Lam>
pattern<LambdaExtractor<Lam>> make_pattern_of_lambda(Lam lam) {
    return make_pattern(LambdaExtractor<Lam>{ lam });
}

static auto Person_ = make_pattern(PersonExtractor{});

template<class T> std::string sig(const T& val) { return __PRETTY_FUNCTION__; }

static auto PersonAlt_ = make_pattern_of_lambda([](Person& p){ return make_storage(p.name, p.age, p.phone); });

int main () {
    auto pers = Person{ "Mike", 43, {} };
    assert(Person_("Mike", 43, Nil) >> pers);
    assert(Person_("Mike", 43, _1) >> pers);
    assert(Person_("Mike", 43, _) >> pers);
    assert(Person_(_, _, _1) >> pers);

    {
        auto m = Person_(_2, 43, _) >> pers;
        assert(m);
        assert(m->_2 == "Mike");
        assert(!m->_1); // m->_1 has type 'none', which is convertible to false
    }

    {
        auto m = Person_(_2, _1, Cons(_3, _)) >> pers;
        assert(!m);
    }

    {
        Person other{ "Jim", 22, std::vector<int>{ 5, 6, 9, 5, 7, 9, 3 } };
        auto m = PersonAlt_(_2, _1, Cons(_, Cons(_3, _))) >> other;
        assert(m);
        assert(m->_2 == "Jim");
        assert(m->_1 == 22);
        assert(m->_3 == 6);
    }

    {
        Person other{ "Jim", 22, std::vector<int>{ 5, 6, 9, 5, 7, 9, 3 } };
        auto m = Person_(_2, _1, Cons(_, Cons(_3, _))) >> other;
        assert(m);
        assert(m->_2 == "Jim");
        assert(m->_1 == 22);
        assert(m->_3 == 6);
        m->_1 = 30;
        unsigned long long x = m->_1;
        assert(x == 30);
        assert(other.age == 30);
        m->_2 = "Barry";
        assert(other.name == "Barry");
    }

    {
        std::vector<int> nums{1,2,3,4};
        auto m = Seq(_2, 2, _, 4) >> nums;
        assert(m);
        assert(m->_2 == 1);
    }

    {
        std::vector<int> nums{1,2,3,4};
        auto m = (Seq(_1, _2, _3, 3) | Seq(_3, _2, _1, 4)) >> nums;
        assert(m);
        assert(m->_1 == 3);
        m->_1 = 4;
        assert(nums[2] == 4);
    }

    {
        std::vector<int> nums{1,2,3,4,5};
        auto m = (Seq(_, _2, _3, 3) | Seq(_3, _2, _, 4)) >> nums;
        assert(!m);
    }

    {
        Person other{ "Jim", 22, std::vector<int>{ 5, 6, 9, 5, 7, 9, 3 } };
        auto m = PersonAlt_(_2, _1, Seq(_, _3, _, _, _, _, _)) >> other;
        assert(m);
        assert(m->_2 == "Jim");
        assert(m->_1 == 22);
        assert(m->_3 == 6);
    }

    {
        Person other{ "Jim", 22, std::vector<int>{ 5, 6, 9, 5, 7, 9, 3 } };
        auto m = (Person_("Jim", _, _) & PersonAlt_(_1, _2, _)) >> other;
        assert(m);
        assert(m->_1 == "Jim");
        assert(m->_2 == 22);
    }

    {
        auto numbers = std::vector<int>{ 5, 6, 9, 5, 7, 9, 3 };
        assert(BSeq(5,6,9,5,7,9,3) >> numbers);
        assert(BSeq(*_,5,7,9,3) >> numbers);
        assert(BSeq(5,6,9,*_) >> numbers);
        assert(BSeq(5,6,*_,9,3) >> numbers);
        assert(BSeq(*_) >> numbers);

        auto m = BSeq(5, *BSeq(*_1)) >> numbers;
        assert(m);

        std::vector<int> sub(std::begin(m->_1), std::end(m->_1));
        std::vector<int> test{6,9,5,7,9,3};
        assert(sub == test);
    }

}
