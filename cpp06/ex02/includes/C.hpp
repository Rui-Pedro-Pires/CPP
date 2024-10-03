#pragma once
#ifndef C_HPP
# define C_HPP

# include <iostream>

class C
{
private:

public:
    C();
    ~C();
    C(const C& other);
    C& operator=(const C& other);
};

#endif
