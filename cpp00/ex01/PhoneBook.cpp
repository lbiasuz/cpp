#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() {
	this->_index = 0;
	this->_size = 0;
}
PhoneBook::~PhoneBook() { 
	std::cout << "PhoneBook Destroyed" << std::endl;
}

Contact PhoneBook::get(int index) { return (this->_contacts[index]); }
int PhoneBook::getSize() { return (this->_size); }

void PhoneBook::add(
	std::string first,
	std::string last,
	std::string nick,
	std::string phone,
	std::string secret
) {
	Contact contact = Contact(first, last, nick, phone, secret);
	this->_contacts[this->_index] = contact;
	if (this->_index >= 7)
		this->_index = 0;
	else
		this->_index++;
	if (this->_size <= 7)
		this->_size++;
	std::cout << first << " contact successfully added!" << std::endl;
}

void truncate_format(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	std::cout << std::right << std::setw(10) << std::setfill(' ') << str << "|";
}

void PhoneBook::list(void)
{
	std::cout << "|";
	truncate_format("Index");
	truncate_format("First Name");
	truncate_format("Last name");
	truncate_format("Nickname");
	std::cout << std::endl;
	for (int index = 0; index < this->getSize(); index++)
	{
		std::cout << "|";
		std::cout << std::right << std::setw(10) << std::setfill(' ') << index << "|";
		truncate_format(this->_contacts[index].getFirstName());
		truncate_format(this->_contacts[index].getLastName());
		truncate_format(this->_contacts[index].getNickName());
		std::cout << std::endl;
	}
}