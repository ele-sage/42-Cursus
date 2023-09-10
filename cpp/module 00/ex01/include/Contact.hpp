#ifndef CONTACT_H
#define CONTACT_H

#include "Headers.hpp"

class Contact
{
public:
	Contact();
	Contact(std::string first, std::string last, std::string nick, std::string secret, std::string num, int index);
	~Contact();

	std::string	getAllInfo();
	int 		getIndex();
	void 		setIndex(int index);

private:
	std::string m_First_name;
	std::string m_Last_name;
	std::string m_Nickname;
	std::string m_Secret;
	std::string m_Phone_num;
	int			m_Index;
};

#endif