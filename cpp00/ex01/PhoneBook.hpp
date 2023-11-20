#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook {
	private:
		Contact	_contacts[8];
		int		_index;
		int		_size;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void add(
			std::string first,
			std::string last,
			std::string nick,
			std::string phone,
			std::string secret
		);
		Contact	get(int index);
		void	list(void);
		int		getSize(void);
};

#endif