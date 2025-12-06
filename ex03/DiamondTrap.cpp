#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	_name = "Default";
	_hitPoints = FragTrap::FRAG_HP;
	_energyPoints = ScavTrap::SCAV_ENERGY;
	_attackDamage = FragTrap::FRAG_DAMAGE;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

// Parametrized ctor
DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap() {
	_name = name;
	_hitPoints = FragTrap::FRAG_HP;
	_energyPoints = ScavTrap::SCAV_ENERGY;
	_attackDamage = FragTrap::FRAG_DAMAGE;
	std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
}

// Copy ctor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap " << _name << " copy constructor called" << std::endl;
}

// Assignment Operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is: " << _name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}
