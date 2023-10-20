#include "../include/headers.hpp"

Contact::Contact()
{
	m_First_name = "";
	m_Last_name = "";
	m_Nickname = "";
	m_Secret = "";
	m_Phone_num = "";
	m_Index = -1;
}

Contact::~Contact()
{
}

const std::string Contact::getFullInfo()
{
	std::string info = "";
	std::stringstream ss;
    ss << m_Index;

	info += "Contact #" + ss.str() + "\n";
	info += "First name:\t" + m_First_name + "\n";
	info += "Last name:\t" + m_Last_name + "\n";
	info += "Nickname:\t" + m_Nickname + "\n";
	info += "Phone number:\t" + m_Phone_num + "\n";
	info += "Darkest secret:\t" + m_Secret + "\n";
	return info;
}

void Contact::printFormattedInfo()
{
	std::cout << std::setw(10) << m_Index << "|";
	if (m_First_name.length() > 10)
		std::cout << m_First_name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << m_First_name << "|";
	if (m_Last_name.length() > 10)
		std::cout << m_Last_name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << m_Last_name << "|";
	if (m_Nickname.length() > 10)
		std::cout << m_Nickname.substr(0, 9) << "." << std::endl;
	else
		std::cout << std::setw(10) << m_Nickname << std::endl;
	std::cout << std::endl;
}

int Contact::getIndex()
{
	return m_Index;
}

void	Contact::setIndex(int index)
{
	m_Index = index;
}

const std::string Contact::validInput(std::string prompt)
{
	std::string input = "";

	while (input == "")
	{
		std::cout << prompt << std::flush;
		std::getline(std::cin, input);
		if (!std::cin.good() || input.empty())
		{
			std::cin.clear();
			std::cout << "Invalid input. Please try again." << std::endl;
			input = "";
		}
	}
	return input;
}

void	Contact::createContact()
{
	std::string promt = "Please enter your ";
	m_First_name = validInput(promt + "first name: ");
	m_Last_name = validInput(promt + "last name: ");
	m_Nickname = validInput(promt + "nickname: ");
	m_Phone_num = validInput(promt + "phone number: ");
	m_Secret = validInput(promt + "darkest secret: ");
	std::cout << "\nContact created!" << std::endl;
}