#include "ClapTrap.hpp"

int main()
{
	std::cout << "=== Test 1: Default Construction ===" << std::endl;
	ClapTrap clap1;

	std::cout << "\n=== Test 2: Basic Construction (parametrized) ===" << std::endl;
	ClapTrap clap2("CT-002");

	std::cout << "\n=== Test 3: Basic Actions ===" << std::endl;
	clap2.attack("Dummy ClapTrap");
	clap2.takeDamage(2);
	clap2.beRepaired(2);

	std::cout << "\n=== Test 4: Running out of energy ===" << std::endl;
	ClapTrap clap3("CT-003");
	for (int i = 0; i < 11; i++)
	{
		clap3.attack("some_imagiary_enemy");
	}

	std::cout << "\n=== Test 5: Running out of hit points ===" << std::endl;
	ClapTrap clap4("CT-004");
	clap4.takeDamage(15);
	clap4.attack("some_imaginary_enemy");
	clap4.beRepaired(5);

	std::cout << "\n=== Test 6: Copy constructor test ===" << std::endl;
	ClapTrap clap5("CT-005");
	ClapTrap clap6(clap5);

	std::cout << "\n=== Test 7: Assignment operator test ===" << std::endl;
	ClapTrap clap7("CT-007");
	clap7 = clap5;

	std::cout << "\n=== Destructors called ===" << std::endl;
	return (0);
}
