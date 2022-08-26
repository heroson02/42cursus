#include "Form.hpp"

int main()
{
    Form* constitution = new Form("Constitution", 10, 30);
    Form* toHigh;
    Form* toLow;
    
    std::cout << *constitution << std::endl;
    try
    {
       toHigh = new Form("toHigh", 0, 20);
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
       toLow = new Form("ToLow", 10, 199);
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    Bureaucrat* bob = new Bureaucrat("Bob", 5);
    
    std::cout << *bob;

    bob->signForm(*constitution);

    std::cout << *constitution;

    bob->signForm(*constitution);
    std::cout << std::endl;
    Form* nop = new Form("Constitution", 1, 1);
    Bureaucrat* john = new Bureaucrat("John", 12);

    john->signForm(*nop);
    
    delete constitution;
    delete bob;
    delete nop;
    delete john;
}