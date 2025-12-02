#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Look! The Zombie "
			  << BLUE << "xxx" << RESET
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

void Zombie::setName(const std::string& name)
{
	this->_name = name;
}
