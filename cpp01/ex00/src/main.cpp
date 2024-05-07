#include "Zombie.hpp"

int main(void)
{
    Zombie  zombie1;
    Zombie  *zombie2;
    zombie1 = Zombie("ZEE");
    zombie1.announce();
    zombie2 = newZombie( "fds");
    zombie2->announce();
}
