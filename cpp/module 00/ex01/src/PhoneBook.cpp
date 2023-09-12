#include "../include/headers.hpp"

int PhoneBook::last_index = 0;

PhoneBook::PhoneBook()
{
	for(int i = 0; i < MAX_CONTACTS; i++)
	{
		this->m_contacts[i] = Contact();
	}
	this->last_index = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact()
{
	Contact contact = Contact();
	contact.createContact();
	if (this->last_index == MAX_CONTACTS)
	{
		m_contacts[0] = m_contacts[1];
		this->m_contacts[0] = contact;
		this->m_contacts[0].setIndex(0);
		this->last_index = 1;	
	}
	else
	{
		this->m_contacts[this->last_index] = contact;
		this->m_contacts[this->last_index].setIndex(this->last_index);
		this->last_index++;
	}
}

void PhoneBook::searchContact()
{
	int index;
	std::string input;
	std::cout << "Please enter the index of the contact you wish to view: " << std::flush;
	std::getline(std::cin, input);
	if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
	{
		index = input[0] - '0';
		if (this->m_contacts[index].getIndex() != -1)
		{
			this->printContact(this->m_contacts[index]);
		}
		else
		{
			std::cout << "No contact at that index." << std::endl;
		}
	}
	else
	{
		std::cout << "Invalid input." << std::endl;
	}
}

void PhoneBook::printContact(Contact contact)
{
	std::cout << contact.getFullInfo() << std::endl;
}

void PhoneBook::printContact()
{
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (this->m_contacts[i].getIndex() != -1)
		{
			this->m_contacts[i].printFormattedInfo();
		}
	}
}

bool PhoneBook::prompt()
{
	std::string input;
	std::cout << "Command: " << std::flush;
	std::getline(std::cin, input);
	if (input == "EXIT")
	{
		return false;
	}
	else if (input == "ADD")
	{
		this->addContact();
	}
	else if (input == "SEARCH")
	{
		this->printContact();
		this->searchContact();
	}
	else
	{
		std::cout << "Invalid command." << std::endl;
	}
	return true;
}
