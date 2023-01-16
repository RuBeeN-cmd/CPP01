#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie1 = newZombie("Bill");
	randomChump("Will");

	zombie1->announce();
	delete zombie1;
	return 0;
}
