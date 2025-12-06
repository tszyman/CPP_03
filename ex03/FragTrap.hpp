#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	// Orthodox Canonical Form
	FragTrap();									// default ctor
	FragTrap(const std::string &name);			// parametrized ctor
	FragTrap(const FragTrap &other);			// copy ctor
	FragTrap &operator=(const FragTrap &other);	// copy assignment operator
	~FragTrap();								// destructor

	// Member functions (modified from ClapTrap)
	void			attack(const std::string &target);
	// Additional function for FragTrap
	void			highFivesGuys();

protected:
	// Static constants for FragTrap's specific values
	static const unsigned int FRAG_HP = 100;
	static const unsigned int FRAG_ENERGY = 100;
	static const unsigned int FRAG_DAMAGE = 30;
};
#endif
