#include "Character.hpp"

AMateria **Character::_unequipped = NULL;
int Character::_count = 0;

static bool _inRange(int idx)
{
	if (idx < 0 || idx > 3)
		return (false);
	return (true);
}

static void _fillNull(AMateria **inventory)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

static void _deleteInventory(AMateria **inventory)
{
	for (int i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i];
}

Character::Character() : _name("default")
{
	_fillNull(_inventory);
}

Character::Character(string const & name) : _name(name)
{
	_fillNull(_inventory);
}

Character::Character(const Character &copy)
{
	*this = copy;
}

Character& Character::operator=(const Character &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_deleteInventory(_inventory);
		for (int i = 0; i < 4; i++)
		{
			if (copy._inventory[i])
				_inventory[i] = copy._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	_deleteInventory(_inventory);
	if (_count > 0)
		deleteUnequipped();
}

void Character::deleteUnequipped()
{
	for (int i = 0; i < _count; i++)
	{	
		if (_unequipped[i])
		{
			//cout << "unequipped : " << _unequipped[i]->getType() << endl;
			delete _unequipped[i];
		}
	}
	_count = 0;
}

string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{	
	if (_inRange(idx) && _inventory[idx])
	{
		AMateria **tmp = new AMateria*[_count + 1];
		for (int i = 0; i < _count; i++)
			tmp[i] = _unequipped[i];
		tmp[_count] = _inventory[idx];
		_count++;
		if (_unequipped)
			delete[] _unequipped;
		_unequipped = tmp;
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (_inRange(idx) && _inventory[idx])
		_inventory[idx]->use(target);
}
