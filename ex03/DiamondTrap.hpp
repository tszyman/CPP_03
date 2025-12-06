#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	// Orthodox Canonical Form
	DiamondTrap();									// default ctor
	DiamondTrap(const std::string &name);			// parametrized ctor
	DiamondTrap(const DiamondTrap &other);			// copy ctor
	DiamondTrap &operator=(const DiamondTrap &other);	// copy assignment operator
	~DiamondTrap();								// destructor

	// Member functions (modified from ClapTrap)

	// Using ScavTrap's attack function
	using			ScavTrap::attack;
	// Additional function for ScavTrap
	void			whoAmI();

private:
	std::string		_name;						// Diamond Trap's name, shadows ClapTrap's name

};
#endif
