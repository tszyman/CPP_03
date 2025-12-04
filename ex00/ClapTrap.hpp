#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
public:
	// Orthodox Canonical Form
	ClapTrap();									// default ctor
	ClapTrap(const std::string &name);			// parametrized ctor
	ClapTrap(const ClapTrap &other);			// copy ctor
	ClapTrap &operator=(const ClapTrap &other);	// copy assignment operator
	~ClapTrap();								// destructor

	// Member functions
	void			attack(const std::string &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoint;
	unsigned int	_attackDamage;

};
#endif
