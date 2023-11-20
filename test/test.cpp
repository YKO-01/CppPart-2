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

//	A a;
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
