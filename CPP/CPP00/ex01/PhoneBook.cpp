#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	count = 0;
	old = 0;
	amount = 0;
}

void	PhoneBook::input_contact(int idx)
{
	std::string	input[5];

	std::cout << "first name? : ";
	std::cin >> input[0];
	std::cout << "last name? : ";
	std::cin >> input[1];
	std::cout << "nickname? : ";
	std::cin >> input[2];
	std::cout << "phone number? : ";
	std::cin >> input[3];
	std::cout << "darkest secret? : ";
	std::cin >> input[4];
	arr[idx] = Contact(input[0], input[1], input[2], input[3], input[4]);
}

void	PhoneBook::remove_add()
{
	input_contact(old);
	count++;
	old++;
	if (old > 8)
		old = 0;
}

void	PhoneBook::add()
{
	if (count > 7)
		remove_add();
	else
	{
		input_contact(count);
		count++;
		amount++;
	}
}

void	PhoneBook::print_line(std::string text)
{
	if (text.length() <= 10)
		std::cout << std::setw(10) << text;
	else
	{
		text = text.substr(0, 9) + ".";
		std::cout << std::setw(10) << text;
	}
	std::cout << "|";
}

void	PhoneBook::guideline_print()
{
	print_line("Index");
	print_line("First name");
	print_line("Last name");
	print_line("Nickname");
	std::cout << std::endl;
}

void	PhoneBook::print_arr_line(int index)
{
	print_line(std::to_string(index));
	print_line(arr[index].get_first_name());
	print_line(arr[index].get_last_name());
	print_line(arr[index].get_nickname());
	std::cout << std::endl;
}

void	PhoneBook::print_contact(int index)
{
	std::cout << "First Name : " << arr[index].get_first_name() << std::endl;
	std::cout << "Last Name : " << arr[index].get_last_name() << std::endl;
	std::cout << "Nickname : " << arr[index].get_nickname() << std::endl;
	std::cout << "Phone Number : " << arr[index].get_phone_number() << std::endl;
	std::cout << "Darkest Secret : " << arr[index].get_secret() << std::endl;
}

int		input_valid_check(const char *input, int amount)
{
	for (int i = 0; input[i]; i++)
	{
		if (!isnumber(input[i]))
			return (0);
	}
	int	num = atoi(input);
	if (num > amount || num < 0 || num > 7)
		return (0);
	return (1);
};

void	PhoneBook::search()
{
	std::string	input;

	guideline_print();
	if (count == 0)
		return ;
	for (int i = 0; i < amount; i++)
		print_arr_line(i);
	std::cout << "Search Index : ";
	std::cin >> input;
	if (!input_valid_check(input.c_str(), amount))
	{
		std::cout << "Error : wrong input" << std::endl;
		return ;
	}
	int num = atoi(input.c_str());
	print_contact(num);
}
