#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
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

};
#endif
