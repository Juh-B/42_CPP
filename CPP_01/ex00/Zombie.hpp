#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define GREEN   "\033[32m"
# define RESET   "\033[0m"

class Zombie
{
	public:
		Zombie(const std::string& name);
		~Zombie(void);

		void announce(void) const;

	private:
		std::string		_name;
};

Zombie* newZombie(const std::string& name);
void randomChump(const std::string& name);

#endif
