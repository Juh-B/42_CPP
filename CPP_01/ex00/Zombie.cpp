#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : _name(name)
{
	std::cout << "Look! The Zombie "
			  << GREEN << _name << RESET
			  << " has risen from the dead!"
			  << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Oh no... The Zombie "
			  << GREEN << this->_name << RESET
			  << " died again..."
			  << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
