#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Headers.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	std::string	getInfo(Contact contact);
	void		printContacts(void);
	void		addContact(Contact contact);

private:
	static int	last_index;
	Contact		contacts[8];
};

#endif