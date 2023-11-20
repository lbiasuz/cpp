#include "PhoneBook.hpp"
#include "Contact.hpp"

void	print_help(void)
{
	std::cout << "COMMANDS: \n 1 - ADD \n 2 - SEARCH \n 3 - EXIT" << std::endl;
}

void	add(PhoneBook *book)
{
	std::string	first;
	std::string	last;
	std::string	nick;
	std::string	phone;
	std::string	secret;

	std::cout << "Name: ";
	std::cin >> first;
	std::cout << "Last name: ";
	std::cin >> last;
	std::cout << "Nickname: ";
	std::cin >> nick;
	std::cout << "Phone number: ";
	std::cin >> phone;
	std::cout << "Secret: ";
	std::cin >> secret;
	book->add(first, last, nick, phone, secret);
}

void search(PhoneBook *book) {

	Contact contact;
	int		index;

	book->list();
	index = -1;
	std::cout << "Escolha 1 contato: ";
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cin.clear();
		return ;
	}
	if (index < 0 || index >= 8)
		return ;
	contact = book->get(index);
	std::cout << "Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickName() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Secret: " << contact.getDarkestSecret() << std::endl;
}

int	main(void)
{
	std::string	cmd;
	PhoneBook	book;

	while (1)
	{
		std::cout << "PHONE BOOK: ";
		std::cin >> cmd;
		if (std::cin.eof())
			break ;
		if (cmd == "ADD")
			add(&book);
		else if (cmd == "SEARCH")
			search(&book);
		else if (cmd == "EXIT")
			break;
		else
			print_help();
	}
}