#include "../includes/Base.hpp"

Base::Base()
{
}

Base::~Base()
{
}

Base::Base(const Base &other)
{
	(void)other;
}

Base &Base::operator=(const Base &other)
{
	(void)other;
	return *this;
}
