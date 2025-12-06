#include "DiamondTrap.hpp"

int main()
{
	// Test 1: Construction Chain
	std::cout << "\n========== TEST 1: Construction Chain ==========" << std::endl;
	std::cout << "Creating DiamondTrap 'Warrior'..." << std::endl;
	std::cout << "Expected: ClapTrap → ScavTrap → FragTrap → DiamondTrap" << std::endl;
	std::cout << "---" << std::endl;
	DiamondTrap warrior("Warrior");

	// Test 2: Identity (whoAmI)
	std::cout << "\n========== TEST 2: Identity Test (whoAmI) ==========" << std::endl;
	std::cout << "Testing whoAmI() method..." << std::endl;
	warrior.whoAmI();
	std::cout << "Expected: DiamondTrap name = 'Warrior', ClapTrap name = 'Warrior_clap_name'" << std::endl;

	// Test 3: Attack (ScavTrap version)
	std::cout << "\n========== TEST 3: Attack Test ==========" << std::endl;
	std::cout << "DiamondTrap should use ScavTrap's attack message..." << std::endl;
	warrior.attack("training dummy");
	std::cout << "Expected: ScavTrap Warrior_clap_name attacks training dummy, causing 30 points of damage!" << std::endl;

	// Test 4: Inherited Special Abilities
	std::cout << "\n========== TEST 4: Inherited Special Abilities ==========" << std::endl;
	std::cout << "Testing guardGate() from ScavTrap:" << std::endl;
	warrior.guardGate();
	std::cout << "\nTesting highFivesGuys() from FragTrap:" << std::endl;
	warrior.highFivesGuys();

	// Test 5: Attribute Verification
	std::cout << "\n========== TEST 5: Attribute Mix Verification ==========" << std::endl;
	std::cout << "DiamondTrap should have:" << std::endl;
	std::cout << "  - HP: 100 (from FragTrap)" << std::endl;
	std::cout << "  - Energy: 50 (from ScavTrap)" << std::endl;
	std::cout << "  - Damage: 30 (from FragTrap)" << std::endl;
	std::cout << "---" << std::endl;

	DiamondTrap tester("Tester");
	std::cout << "\nTaking 50 damage (should survive with 100 HP):" << std::endl;
	tester.takeDamage(50);

	std::cout << "\nTaking another 30 damage:" << std::endl;
	tester.takeDamage(30);

	std::cout << "\nRepairing 20 HP:" << std::endl;
	tester.beRepaired(20);

	std::cout << "\nAttacking (costs 1 energy from remaining):" << std::endl;
	tester.attack("target");

	// Test 6: Energy Depletion
	std::cout << "\n========== TEST 6: Energy Depletion Test ==========" << std::endl;
	std::cout << "DiamondTrap has 50 energy from ScavTrap" << std::endl;
	std::cout << "Attempting 52 actions (should fail after 50)..." << std::endl;
	DiamondTrap energyTest("EnergyBot");

	for (int i = 1; i <= 52; i++)
	{
		energyTest.attack("enemy");
	}

	// Test 7: Hit Points Depletion
	std::cout << "\n========== TEST 7: Hit Points Depletion Test ==========" << std::endl;
	DiamondTrap hpTest("HPBot");
	std::cout << "Taking 100 damage (should be destroyed):" << std::endl;
	hpTest.takeDamage(100);

	std::cout << "\nTrying to attack when destroyed:" << std::endl;
	hpTest.attack("enemy");

	std::cout << "\nTrying to repair when destroyed:" << std::endl;
	hpTest.beRepaired(50);

	std::cout << "\nCan still call whoAmI() when destroyed:" << std::endl;
	hpTest.whoAmI();

	// Test 8: Copy Constructor
	std::cout << "\n========== TEST 8: Copy Constructor Test ==========" << std::endl;
	std::cout << "Creating original DiamondTrap:" << std::endl;
	DiamondTrap original("Original");
	original.whoAmI();

	std::cout << "\nCreating copy via copy constructor:" << std::endl;
	DiamondTrap copy(original);
	copy.whoAmI();

	// Test 9: Assignment Operator
	std::cout << "\n========== TEST 9: Assignment Operator Test ==========" << std::endl;
	std::cout << "Creating DiamondTrap 'Alpha':" << std::endl;
	DiamondTrap alpha("Alpha");
	alpha.whoAmI();

	std::cout << "\nCreating DiamondTrap 'Beta':" << std::endl;
	DiamondTrap beta("Beta");
	beta.whoAmI();

	std::cout << "\nAssigning Alpha to Beta:" << std::endl;
	beta = alpha;
	beta.whoAmI();
	std::cout << "Beta should now have Alpha's data" << std::endl;

	// Test 10: Multiple DiamondTraps
	std::cout << "\n========== TEST 10: Multiple DiamondTraps ==========" << std::endl;
	std::cout << "Creating multiple DiamondTraps:" << std::endl;
	DiamondTrap d1("Romeo");
	DiamondTrap d2("Juliet");
	DiamondTrap d3("Mercutio");

	std::cout << "\nIdentity check for all:" << std::endl;
	d1.whoAmI();
	d2.whoAmI();
	d3.whoAmI();

	std::cout << "\nAll attack different targets:" << std::endl;
	d1.attack("Tybalt");
	d2.attack("Paris");
	d3.attack("Capulet");

	// Test 11: Default Constructor
	std::cout << "\n========== TEST 11: Default Constructor Test ==========" << std::endl;
	std::cout << "Creating DiamondTrap with default constructor:" << std::endl;
	DiamondTrap defaultDT;
	defaultDT.whoAmI();
	defaultDT.attack("target");

	// Test 12: All Actions Combined
	std::cout << "\n========== TEST 12: Combined Actions Test ==========" << std::endl;
	DiamondTrap combo("ComboBot");
	combo.whoAmI();
	combo.attack("enemy1");
	combo.takeDamage(25);
	combo.beRepaired(10);
	combo.attack("enemy2");
	combo.guardGate();
	combo.highFivesGuys();
	combo.whoAmI();

	// Test 13: Edge Case - Exact Lethal Damage
	std::cout << "\n========== TEST 13: Edge Case - Exact Lethal Damage ==========" << std::endl;
	DiamondTrap edgeCase("EdgeBot");
	std::cout << "Taking exactly 100 damage (exact HP amount):" << std::endl;
	edgeCase.takeDamage(100);
	edgeCase.attack("target");

	// Test 14: Destruction Chain
	std::cout << "\n========== TEST 14: Destruction Chain ==========" << std::endl;
	std::cout << "Creating a DiamondTrap in a scope block..." << std::endl;
	std::cout << "Expected destruction order: DiamondTrap → FragTrap → ScavTrap → ClapTrap" << std::endl;
	std::cout << "---" << std::endl;
	{
		DiamondTrap scoped("ScopedBot");
		scoped.whoAmI();
		std::cout << "\nLeaving scope now..." << std::endl;
	}
	std::cout << "Scope exited - destructor chain complete" << std::endl;

	std::cout << "\n=== Destructors called ===" << std::endl;

	return (0);
}
