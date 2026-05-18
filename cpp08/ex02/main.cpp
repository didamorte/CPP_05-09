#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "=== Subject Test (MutantStack) ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\n=== Same Test (std::list) ===" << std::endl;
	{
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << "Top: " << lst.back() << std::endl;
		lst.pop_back();
		std::cout << "Size: " << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\n=== Reverse Iterator Test ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		std::cout << "Forward: ";
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "Reverse: ";
		for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
			std::cout << *rit << " ";
		std::cout << std::endl;
	}

	std::cout << "\n=== Copy Constructor Test ===" << std::endl;
	{
		MutantStack<int> mstack1;
		mstack1.push(10);
		mstack1.push(20);
		mstack1.push(30);

		MutantStack<int> mstack2(mstack1);
		std::cout << "mstack2: ";
		for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	std::cout << "\n=== Assignment Operator Test ===" << std::endl;
	{
		MutantStack<int> mstack1;
		mstack1.push(100);
		mstack1.push(200);

		MutantStack<int> mstack2;
		mstack2.push(999);
		mstack2 = mstack1;

		std::cout << "mstack2 after assignment: ";
		for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	std::cout << "\n=== String Stack Test ===" << std::endl;
	{
		MutantStack<std::string> mstack;
		mstack.push("Hello");
		mstack.push("World");
		mstack.push("!");

		for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	std::cout << "\n=== Empty/Size Test ===" << std::endl;
	{
		MutantStack<int> mstack;
		std::cout << "Empty: " << (mstack.empty() ? "true" : "false") << std::endl;
		mstack.push(42);
		std::cout << "Empty after push: " << (mstack.empty() ? "true" : "false") << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
	}

	return (0);
}
