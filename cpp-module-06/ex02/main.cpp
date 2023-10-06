#include "Base.hpp"
#include <ctime>
#include <cstdlib>

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base * generate(void)
{
	srand(clock());

	int i = rand() % 3;

	if (i == 1)
		return new A();
	else if (i == 2)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	 if (dynamic_cast<A *>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "C" << std::endl;
}


void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
}

int	main()
{
	Base *base1 = generate();
	Base *base2 = generate();
	Base *base3 = generate();

	std::cout << "Base1 by pointer:	";
	identify(*base1);
	std::cout << std::endl << "Base1 by reference:	";
	identify(base1);
	std::cout << std::endl << "Base2 by pointer:	";
	identify(*base2);
	std::cout << std::endl << "Base2 by reference:	";
	identify(base2);
	std::cout << std::endl << "Base3 by pointer:	";
	identify(*base3);
	std::cout << std::endl << "Base3 by reference:	";
	identify(base3);
	std::cout << std::endl;

	delete base1;
	delete base2;
	delete base3;

	std::cout << "______________Test every class______________" << std::endl;
	A *a_ptr = new A;
    A &a_ref = *a_ptr;

    identify(dynamic_cast<Base *>(a_ptr));
    identify(dynamic_cast<Base &>(a_ref));
    
	delete a_ptr;

	B *b_ptr = new B;
    B &b_ref = *b_ptr;

    identify(dynamic_cast<Base *>(b_ptr));
    identify(dynamic_cast<Base &>(b_ref));
    
	delete b_ptr;

	C *c_ptr = new C;
    C &c_ref = *c_ptr;

    identify(dynamic_cast<Base *>(c_ptr));
    identify(dynamic_cast<Base &>(c_ref));
    
	delete c_ptr;

}
