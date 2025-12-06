#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = FRAG_HP;
	_energyPoints = FRAG_ENERGY;
	_attackDamage = FRAG_DAMAGE;
	std::cout << "FragTrap default constructor called" << std::endl;
}

// Parametrized ctor
FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = FRAG_HP;
	_energyPoints = FRAG_ENERGY;
	_attackDamage = FRAG_DAMAGE;
	std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

// Copy ctor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap " << _name << " copy constructor called" << std::endl;
}

// Copy assignment operator
FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return(*this);
}

// Destructor
FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

// Attack function
void	FragTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " is destroyed and cannot attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " can't attack because it has no energypoints left!" << std::endl;
		return;
	}
	_energyPoints--;	// attack costs 1 point energy
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " is giving everyone a High Five!" << std::endl;
}
