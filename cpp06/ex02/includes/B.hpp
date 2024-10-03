#pragma once
#ifndef B_HPP
# define B_HPP

# include <iostream>

class B
{
private:

public:
    B();
    ~B();
    B(const B& other);
    B& operator=(const B& other);
};

#endif
