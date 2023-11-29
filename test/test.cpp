#include <iostream>
/*
class A
{
	private :
		int i;

	public :
		A() {};
		void f(int x) const
		{
			const_cast<A*>(this)->i = x;
			std::cout << i << std::endl;
		}
};
*/
typedef struct s_s {
	int a;
	int b;
	float c;
	bool d;
} t_s;

int main()
{

//	A a; If expression is a pointer to a polymorphic type, and target-type is a pointer to void, the result is a pointer to the most derived object pointed or referenced by expression.
//	a.f(5);

	t_s s;
	s.a = 10;
	s.b = 20;
	s.c = 67;
	s.d = true;

	int *ps = reinterpret_cast<int*>(&s);
	std::cout << sizeof(ps) <<  " " << sizeof(s) << std::endl; 
	std::cout << *ps << std::endl;
	ps++;
	std::cout << *ps << std::endl;
	ps++;
	std::cout << *ps << std::endl;
	return (0);
}
