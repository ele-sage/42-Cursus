#ifndef CONTACT_H
#define CONTACT_H

#include "headers.hpp"

class Contact
{
private:
	std::string 		m_First_name;
	std::string 		m_Last_name;
	std::string 		m_Nickname;
	std::string 		m_Secret;
	std::string 		m_Phone_num;
	int					m_Index;
	
	const std::string	validInput(std::string prompt);
public:
	Contact();
	~Contact();

	const std::string	getFullInfo();
	void				printFormattedInfo();
	int 				getIndex();
	void 				setIndex(int index);
	void 				createContact();
};

#endif