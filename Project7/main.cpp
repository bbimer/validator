//#include <iostream>
//
//namespace my {
//	template<class T>
//	class auto_ptr {
//		T* m_ptr;
//	public:
//		auto_ptr(T* ptr) : m_ptr(ptr) { std::cout << m_ptr << " - smart pointer created" << std::endl; }
//		auto_ptr() : auto_ptr(nullptr) {}
//		auto_ptr(auto_ptr& other) {
//			m_ptr = other.m_ptr;
//			other.m_ptr = nullptr;
//		}
//		~auto_ptr() {
//			std::cout << m_ptr << " - smart pointer deleted" << std::endl;
//			if (m_ptr) {
//				delete m_ptr;
//			}
//		}
//
//		T& operator*() {
//			return *m_ptr;
//		}
//	};
//
//}
//
//template<class T>
//void MyFunc(my::auto_ptr<T>& ptr) { 
//
//}
//
//int main() {
//	my::auto_ptr<int> int_ptr(new int(3));
//	my::auto_ptr<int> sp_ptr(new int(5));
//	MyFunc(sp_ptr); 
//
//	return 0;
//}

// 1
#include <iostream>
#include <string>
#include "stack.h"

bool type_br(char open, char close) {
	return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}


void check_br(const std::string& input) {
	Stack<char> stack;
	for (size_t i = 0; i < input.length(); ++i) {
		char bracket = input[i];

		if (bracket == ';')
		{
			break;
		}

		if (bracket == '(' || bracket == '{' || bracket == '[') {
			stack.push(bracket);
		}
		else if (bracket == ')' || bracket == '}' || bracket == ']') {
			if (stack.isEmpty()) {
				stack.print();

				if (stack.top() == '\0') {
					std::cout << "empty" << std::endl;
					return;
				}
			}

			char top = stack.top();
			stack.pop();

			if (!type_br(top, bracket)) {
				std::cout << "error" << std::endl;
				return;
			}
		}
	}
	if (!stack.isEmpty()) {
		std::cout << "error" << std::endl;
		return;
	}

	std::cout << "brackets is correct!" << std::endl;
}

int main() {
	std::string input = "({x-y-z} * [x + 2y] - (z + 4x))";

	check_br(input);

	return 0;
}
