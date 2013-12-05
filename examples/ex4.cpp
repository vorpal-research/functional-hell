#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

#include "matchers_fancy_syntax.h"

template<class Con>
void print_container(std::ostream& ost, const Con& con) {
	using namespace functional_hell::matchers;
	
	SWITCH(con) {
		NAMED_CASE(m, Cons(_1, _2) ) {
		    ost << m->_1;
		    for(const auto& el : m->_2) {
		        ost << ", " << el;
		    }
		}
		
		CASE( Nil ) ost << "<empty =(>";
	}
}

int main() {
	using namespace std;
	vector<int> foo{1,2,3,4,5};
	std::string fii = ("Hello");
	std::string fuu = "";

	print_container(std::cout, foo);
	std::cout << std::endl;
	print_container(std::cout, fii);
	std::cout << std::endl;
	print_container(std::cout, fuu);
	std::cout << std::endl;
}