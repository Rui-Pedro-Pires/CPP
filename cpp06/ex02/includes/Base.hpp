#pragma once
#ifndef Base_HPP
# define Base_HPP

# include <iostream>

class Base
{
private:

public:
    Base();
    virtual ~Base();
    Base(const Base& other);
    Base& operator=(const Base& other);
};

#endif
