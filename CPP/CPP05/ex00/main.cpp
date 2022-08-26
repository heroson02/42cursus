# include "Bureaucrat.hpp"

int main()
{
    Bureaucrat* bureaucrat = new Bureaucrat("Bob", 2);
    Bureaucrat* stagiaire = new Bureaucrat("Cafe", 149);
    
    try
    {
        std::cout << *bureaucrat;
        bureaucrat->increaseGrade();
        std::cout << *bureaucrat;
        bureaucrat->increaseGrade();
    }
    catch (std::exception & e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    std::cout << std::endl << std::endl;
    try
    {
        std::cout << *stagiaire;
        stagiaire->decreaseGrade();
        std::cout << *stagiaire;
        stagiaire->decreaseGrade();
    }
    catch (std::exception & e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    std::cout << std::endl << std::endl;

    Bureaucrat* toHigh;
    Bureaucrat* toLow;
    try
    {
        toHigh = new Bureaucrat("ToHigh", 0);
    }
    catch (std::exception & e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    
    try
    {
        toLow = new Bureaucrat("ToLow", 420);
    }
    catch (std::exception & e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    
    delete bureaucrat;
    delete stagiaire;
}
