# include "Bureaucrat.hpp"

int main()
{
    Bureaucrat* bureaucrat = new Bureaucrat("Bob", 2);
    Bureaucrat* stagiaire = new Bureaucrat("Cafe", 149);
    
    // Test --
    try
    {
        std::cout << *bureaucrat;
        bureaucrat->increaseGrade();
        std::cout << bureaucrat->getName() << " Grade increased! Felicitations! " << std::endl;
        std::cout << *bureaucrat;
        bureaucrat->increaseGrade();
        std::cerr << "[+][1] Exception does'nt work nicely. " << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "[1] Exception : " << e.what() << std::endl;
    }

    // Test ++
    try
    {
        std::cout << *stagiaire;
        stagiaire->decreaseGrade();
        std::cout << stagiaire->getName() << " Grade decreased! That's suck! " << std::endl;
        std::cout << *stagiaire;
        stagiaire->decreaseGrade();
        std::cerr << "[+][2] Exception does'nt work nicely. " << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "[2] Exception : " << e.what() << std::endl;
    }

    Bureaucrat* toHigh;
    Bureaucrat* toLow;

    // Test ToHigh
    try
    {
        toHigh = new Bureaucrat("ToHigh", 0);
        std::cerr << "[+][3] Exception does'nt work nicely. " << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "[3] Exception : " << e.what() << std::endl;
    }
    
    try
    {
        toLow = new Bureaucrat("ToLow", 420);
        std::cerr << "[+][4] Exception does'nt work nicely. " << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "[4] Exception : " << e.what() << std::endl;
    }
    
    delete bureaucrat;
    delete stagiaire;
}