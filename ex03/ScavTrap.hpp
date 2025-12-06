#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	// Orthodox Canonical Form
	ScavTrap();									// default ctor
	ScavTrap(const std::string &name);			// parametrized ctor
	ScavTrap(const ScavTrap &other);			// copy ctor
	ScavTrap &operator=(const ScavTrap &other);	// copy assignment operator
	~ScavTrap();								// destructor

	// Member functions (modified from ClapTrap)
	void			attack(const std::string &target);
	// Additional function for ScavTrap
	void			guardGate();

protected:
	// Static constants for ScavTrap's specific values
	static const unsigned int SCAV_HP = 100;
	static const unsigned int SCAV_ENERGY = 50;
	static const unsigned int SCAV_DAMAGE = 20;
};
#endif
