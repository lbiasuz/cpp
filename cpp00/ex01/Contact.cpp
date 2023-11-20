#include "Contact.hpp"

Contact::Contact(
	std::string firstName,
	std::string lastName,
	std::string nickName,
	std::string phoneNumber,
	std::string darkestSecret
	) {
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickName = nickName;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

Contact::Contact(void) {}
Contact::~Contact(void) {}

Contact &Contact::operator=(const Contact &contact)
{
	this->_firstName = contact._firstName;
	this->_lastName = contact._lastName;
	this->_nickName = contact._nickName;
	this->_phoneNumber = contact._phoneNumber;
	this->_darkestSecret = contact._darkestSecret;
	return (*this);
}

std::string	Contact::getFirstName(void) {
	return (this->_firstName);
}

std::string	Contact::getLastName(void) {
	return (this->_lastName);
}

std::string	Contact::getNickName(void) {
	return (this->_nickName);
}

std::string	Contact::getPhoneNumber(void) {
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) {
	return (this->_darkestSecret);
}


