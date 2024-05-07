#include "Zombie.hpp"

Zombie::Zombie( void )
{
    this->_name = "Bino";
}

Zombie::Zombie( std::string name )
{
    this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " <aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
}

void    Zombie::announce( void )
{
    std::cout << this->_name << ":" << ">: BraiiiiiiinnnzzzZ..." << std::endl;
}