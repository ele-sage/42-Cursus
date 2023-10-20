#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "headers.hpp"

class PhoneBook
{
private:
	Contact		m_contacts[8];
    static int	last_index;

	void		searchContact(void);
    void		printContact(Contact contact);
	void		printContact(void);
    void		addContact();
public:
    PhoneBook();
    ~PhoneBook();
	bool	prompt(void);
};

#endif