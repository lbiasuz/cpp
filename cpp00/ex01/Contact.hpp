#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:
		Contact(void);
		Contact(
			std::string firstName,
			std::string lastName,
			std::string nickName,
			std::string phoneNumber,
			std::string darkestSecret
		);
		~Contact(void);
		Contact &operator=(const Contact &contact);

		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkestSecret(void);
};

#endif
