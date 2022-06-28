#include "Contact.hpp"

Contact::Contact()
{
	Contact("", "", "", "", "");
}

std::string Contact::get_first_name()
{
	return (this->first_name);
}

std::string Contact::get_last_name()
{
	return (this->last_name);
}

std::string Contact::get_nickname()
{
	return (this->nickname);
}

std::string Contact::get_secret()
{
	return (this->darkest_secret);
}

std::string Contact::get_phone_number()
{
	return (this->phone_number);
}

Contact::Contact(std::string first_name_, std::string last_name_,
	std::string nickname_, std::string phone_number_, 
	std::string darkest_secret_)
{
	first_name = first_name_;
	last_name = last_name_;
	nickname = nickname_;
	phone_number = phone_number_;
	darkest_secret = darkest_secret_;
}
