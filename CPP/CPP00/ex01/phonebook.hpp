#include <iostream>
#include <cstring>

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
	~Contact();
};

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

Contact::Contact()
{
	Contact("", "", "", "", "");
}
Contact::~Contact() {}

class PhoneBook
{
	Contact		arr[8];
	int			count;

	public :
	PhoneBook()
	{
		(void)arr;
		count = 0;
	};
	void	add();
};

void PhoneBook::add()
{
	std::string	input[5];

	if (count > 7)
	
	for (int i = 0; i < 5; i++)
		std::cin >> input[i];
	arr[count] = Contact(input[0], input[1], input[2], input[3], input[4]);
	count++;
}
