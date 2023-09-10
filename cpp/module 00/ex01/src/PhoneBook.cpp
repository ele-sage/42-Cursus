#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	for(int i = 0; i < MAX_CONTACTS; i++)
	{
		this->contacts[i] = Contact();
	}
	this->last_index = 0;
}

void PhoneBook::addContact(Contact contact)
{
	if (this->last_index == MAX_CONTACTS)
	{
		this->contacts[0] = contact;
		this->contacts[0].setIndex(0);
		this->last_index = 1;	
	}
	else
	{
		this->contacts[this->last_index] = contact;
		this->contacts[this->last_index].setIndex(this->last_index);
		this->last_index++;
	}
}

PhoneBook::~PhoneBook()
{
}
