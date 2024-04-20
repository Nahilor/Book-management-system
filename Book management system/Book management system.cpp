#include <iostream>
#include <string>

// structure definitions
struct book
{
    std::string title;
    std::string ID;
    std::string genre;
    std::string auther;
};

struct library
{
    book bk;
};

// Function declarations
library* addbook(library[], int&);
int searchbook(library[], int);

int main()
{
    int choice;
    int n = 1;
    library* lib = new library[n];

    // main sys loop
    while (true)
    {
        // Displaying options for the user
        std::cout << "1 - For adding a book to the library." << std::endl;
        std::cout << "2 - To show the books." << std::endl;
        std::cout << "3 - To search for a specific book." << std::endl;
        std::cout << "3 - To exit the program." << std::endl;
        std::cin >> choice;
        if (choice == 1)
        {
            lib = addbook(lib, n);
        }
        else if (choice == 2)
        {
            std::cout << "The number of books currently in the library is " << n-1 << ".\n";
            for (int i = 0; i < n; i++)
            {
                std::cout << lib[i].bk.ID << "\t";
                std::cout << lib[i].bk.title << "\t";
                std::cout << lib[i].bk.auther << "\t";
                std::cout << lib[i].bk.genre << std::endl;
            }
        }
        else if (choice == 3)
        {
            std::cin.ignore();
            int index = searchbook(lib, n);
            if (index != -1)
            {
                std::cout << lib[index].bk.ID << "\t";
                std::cout << lib[index].bk.title << "\t";
                std::cout << lib[index].bk.auther << "\t";
                std::cout << lib[index].bk.genre << std::endl;
            }
            else if (index == -404){ std::cout << "An error has occured please try again." << std::endl; }
            else { std::cout << "Book is not in the library." << std::endl; }

        }
        else if (choice == 4)
        {
            delete[] lib;
            return 0;
        }
        else
        {
            std::cout << "invalid input";
        }
    }
}

// Adds a book and also increases the array size.
library* addbook(library lib[], int &n)
{
    // adding a book
    std::cout << "Enter the book title: " << std::endl;
    std::cin >> lib[n - 1].bk.title;
    std::cin.ignore();
    std::cout << "Enter the book auther: " << std::endl;
    std::cin >> lib[n - 1].bk.auther;
    std::cin.ignore();
    std::cout << "Enter the book ID: " << std::endl;
    std::string bkid;
    std::getline(std::cin, bkid);
    for (int i = 0; i < n; i++)
    {
        if (lib[i].bk.ID == bkid)
        {
            std::cout << "book already exists." << std::endl;
        }
        else
        {
            lib[n-1].bk.ID = bkid;
        }
    }
    std::cin.ignore();
    std::cout << "Enter the book genre: " << std::endl;
    std::cin >> lib[n - 1].bk.genre;
    std::cin.ignore();

    // Increasing array size
    library* newlib = new library[n+1];
    for (int i = 0; i < n; i++)
    {
        newlib[i].bk.title = lib[i].bk.title;
        newlib[i].bk.ID = lib[i].bk.ID;
        newlib[i].bk.genre = lib[i].bk.genre;
        newlib[i].bk.auther = lib[i].bk.auther;
    }
    delete[] lib;
    n++;
    return newlib;
}

// Searches a book by its title and returns the index of the book in the array
int searchbook(library lib[], int n)
{
    std::string bktitle;
    std::cout << "Enter the title of the book" << std::endl;
    std::getline(std::cin, bktitle);
    for (int i = 0; i < n; i++)
    {
        if (lib[i].bk.title == bktitle) { return i; }
        else { return -1; }
    }
    return -404;
}