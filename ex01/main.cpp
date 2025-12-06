#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "========== Construction Test ==========" << std::endl;
	std::cout << "\n--- Creating ClapTrap ---" << std::endl;
	ClapTrap clap("CT-001");

	std::cout << "\n--- Creating ScavTrap ---" << std::endl;
	ScavTrap scav("ST-001");

	std::cout << "\n========== Attack Comparison ==========" << std::endl;
	std::cout << "\n--- ClapTrap Attack ---" << std::endl;
	clap.attack("enemy");

	std::cout << "\n--- ScavTrap Attack ---" << std::endl;
	scav.attack("enemy");

	std::cout << "\n========== ScavTrap Special Ability ==========" << std::endl;
	scav.guardGate();

	std::cout << "\n========== Energy and HP Tests ==========" << std::endl;
	ScavTrap scav2("ST-002");

	// Test with more damage (ScavTrap has 100 HP)
	scav2.takeDamage(30);
	scav2.beRepaired(20);
	scav2.attack("target");

	std::cout << "\n========== Energy Depletion Test ==========" << std::endl;
	ScavTrap scav3("ST-003");
	std::cout << "Attacking 51 times (ScavTrap has 50 energy):" << std::endl;
	for (int i = 0; i < 51; i++)
	{
			scav3.attack("dummy");
	}

	std::cout << "\n========== Destruction Test ==========" << std::endl;
	ScavTrap scav4("ST-004");
	scav4.takeDamage(100); // Destroy it
	scav4.attack("enemy"); // Try to attack when destroyed
	scav4.guardGate();	   // Can still use special ability?

	std::cout << "\n========== Copy Constructor Test ==========" << std::endl;
	ScavTrap scav5("ST-005");
	ScavTrap scav6(scav5);
	scav6.attack("enemy");
	scav6.guardGate();

	std::cout << "\n========== Assignment Operator Test ==========" << std::endl;
	ScavTrap scav7("ST-007");
	scav7 = scav5;
	scav7.attack("enemy");
	scav7.guardGate();

	std::cout << "\n=== Destructors called ===" << std::endl;
	return (0);
}
