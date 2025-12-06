#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = SCAV_HP;
	_energyPoints = SCAV_ENERGY;
	_attackDamage = SCAV_DAMAGE;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

// Parametrized ctor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = SCAV_HP;
	_energyPoints = SCAV_ENERGY;
	_attackDamage = SCAV_DAMAGE;
	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

// Copy ctor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap " << _name << " copy constructor called" << std::endl;
}

// Copy assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return(*this);
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

// Attack function
void	ScavTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is destroyed and cannot attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack because it has no energypoints left!" << std::endl;
		return;
	}
	_energyPoints--;	// attack costs 1 point energy
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << "(EP: "<<_energyPoints <<")" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
