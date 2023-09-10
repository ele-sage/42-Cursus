#include "Contact.hpp"

Contact::Contact()
{
	m_First_name = "";
	m_Last_name = "";
	m_Nickname = "";
	m_Secret = "";
	m_Phone_num = "";
	m_Index = -1;
}

Contact::Contact(std::string first, std::string last, std::string nick, std::string secret, std::string num)
{
	m_First_name = first;
	m_Last_name = last;
	m_Nickname = nick;
	m_Secret = secret;
	m_Phone_num = num;
	m_Index = index;
}

std::string Contact::getAllInfo()
{
	std::string info = "";
	info += "First name: " + m_First_name + "\n";
	info += "Last name: " + m_Last_name + "\n";
	info += "Nickname: " + m_Nickname + "\n";
	info += "Secret: " + m_Secret + "\n";
	info += "Phone number: " + m_Phone_num + "\n";
	return info;
}

int Contact::getIndex()
{
	return m_Index;
}

void Contact::setIndex(int index)
{
	m_Index = index;
}

Contact::~Contact()
{
}