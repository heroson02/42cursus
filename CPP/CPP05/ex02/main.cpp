# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

static void testForm(Bureaucrat* bur, Form* form)
{
    std::cout << std::endl << "Sign & Execute <" << form->getName() << ">" << std::endl;
    bur->signForm(*form);
    bur->executeForm(*form);
}

int main()
{
    ShrubberyCreationForm* shrub = new ShrubberyCreationForm("Shrub");
    RobotomyRequestForm* robot = new RobotomyRequestForm("Robotomy");
    PresidentialPardonForm* pardon = new PresidentialPardonForm("Pardon");

    Bureaucrat* bob = new Bureaucrat("Bob", 120);
    Bureaucrat* james = new Bureaucrat("James", 33);
    Bureaucrat* son = new Bureaucrat("Son", 1);

    std::cout << "====== NORMAL TEST ======" << std::endl;

    testForm(bob, shrub);
    testForm(james, robot);
    testForm(son, pardon);

    std::cout << std::endl << "===== SIGNED FORM TEST ======" << std::endl;

    testForm(bob, pardon);

    delete shrub;
    delete robot;
    delete pardon;

    delete bob;
    delete james;
    delete son;

    return (0);
}