#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	Contact		arr[8];
	int			count;
	int			amount;
	int			old;
	void		remove_add();
	void		input_contact(int idx);

	public :
	PhoneBook();
	void	add();
	void	search();
	void	print_line(std::string text);
	void	guideline_print();
	void	print_arr_line(int index);
	void	print_contact(int input);
};
#endif