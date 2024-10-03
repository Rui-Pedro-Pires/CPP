#pragma once
#ifndef A_HPP
# define A_HPP

# include <iostream>

class A
{
private:

public:
    A();
    ~A();
    A(const A& other);
    A& operator=(const A& other);
};

#endif
