#include "../includes/A.hpp"

A::A()
{
}

A::~A()
{
}

A::A(const A &other)
{
	(void)other;
}

A &A::operator=(const A &other)
{
	(void)other;
	return *this;
}
