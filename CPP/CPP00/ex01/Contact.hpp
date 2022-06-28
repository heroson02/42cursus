#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	public :
	Contact();
	Contact(std::string first_name_,
		std::string last_name_, std::string nickname_,
		std::string phone_number_, std::string darkest_secret_);
	std::string	get_first_name();
	std::string	get_last_name();
	std::string	get_nickname();
	std::string	get_phone_number();
	std::string	get_secret();
};
#endif