#include "Zombie.hpp"

int main()
{
	std::cout << std::endl
			  << "====================== HEAP ======================"
			  << std::endl << std::endl;

	Zombie *heapZombie = newZombie("Heapster");
	heapZombie->announce();
	delete heapZombie;


	std::cout << std::endl << std::endl
			  << "===================== STACK ======================"
			  << std::endl << std::endl;

	randomChump("Stacky");

	return 0;
}
