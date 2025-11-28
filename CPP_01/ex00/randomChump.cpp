#include "Zombie.hpp"

void randomChump(const std::string& name)
{
	Zombie	tmpZombie(name);

	tmpZombie.announce();
}
