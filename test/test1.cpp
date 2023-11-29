#include <iostream>

class Base
{
	private :
		int a;
	public :
		Base(int a) : a(a) {}
		~Base() {}
		void getint()
		{
			return (a);
			}
};

class A : public Base
{
	private :
		int x;
	public :
		A(int x) : x(a) {}
		~A() {}
		void getint()
		{
			return (x);
			}
};

class B : public Base
{
	private :
		int b;
	public :
		B(int b) : b(a) {}
		~B() {}
		void getint()
		{
			return (b);
			}
};

class C : public Base
{
	private :
		int c;
	public :
		C(int c) : c(c) {}
		~C() {}
		void getint()
		{
			return (c);
			}
};

int main()
{
	Base *ptr = new Base(5);
	void *p = dynamic_cast<void *>(ptr);
	return (0);
}
