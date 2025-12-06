#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "========== Construction Test ==========" << std::endl;
	std::cout << "\n--- Creating ClapTrap ---" << std::endl;
	ClapTrap clap("CT-001");

	std::cout << "\n--- Creating FragTrap ---" << std::endl;
	FragTrap Frag("FT-001");

	std::cout << "\n========== Attack Comparison ==========" << std::endl;
	std::cout << "\n--- ClapTrap Attack ---" << std::endl;
	clap.attack("enemy");

	std::cout << "\n--- FragTrap Attack ---" << std::endl;
	Frag.attack("enemy");

	std::cout << "\n========== FragTrap Special Ability ==========" << std::endl;
	Frag.highFivesGuys();

	std::cout << "\n========== Energy and HP Tests ==========" << std::endl;
	FragTrap Frag2("FT-002");

	// Test with more damage (FragTrap has 100 HP)
	Frag2.takeDamage(30);
	Frag2.beRepaired(20);
	Frag2.attack("target");

	std::cout << "\n========== Energy Depletion Test ==========" << std::endl;
	FragTrap Frag3("FT-003");
	std::cout << "Attacking 51 times (FragTrap has 50 energy):" << std::endl;
	for (int i = 0; i < 101; i++)
	{
			Frag3.attack("dummy");
	}

	std::cout << "\n========== Destruction Test ==========" << std::endl;
	FragTrap Frag4("FT-004");
	Frag4.takeDamage(100); // Destroy it
	Frag4.attack("enemy"); // Try to attack when destroyed
	Frag4.highFivesGuys();	   // Can still use special ability?

	std::cout << "\n========== Copy Constructor Test ==========" << std::endl;
	FragTrap Frag5("FT-005");
	FragTrap Frag6(Frag5);
	Frag6.attack("enemy");
	Frag6.highFivesGuys();

	std::cout << "\n========== Assignment Operator Test ==========" << std::endl;
	FragTrap Frag7("FT-007");
	Frag7 = Frag5;
	Frag7.attack("enemy");
	Frag7.highFivesGuys();

	std::cout << "\n=== Destructors called ===" << std::endl;
	return (0);
}
