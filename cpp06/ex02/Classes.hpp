#ifndef BASE_HPP
# define BASE_HPP

class Base {
	public:
		virtual ~Base(void);
};

class A: public Base {
	public:
		A(void);
		~A(void);
};
class B: public Base {
	public:
		B(void);
		~B(void);
};
class C: public Base {
	public:
		C(void);
		~C(void);
};

void	identify(Base *p);
void	identify(Base &p);
Base*	generate(void);

#endif