//Here's an application program in C++ that uses the Vector class to store and display book titles from a data file, following the Model-View-Controller (MVC) pattern:

#include <iostream>
#include <fstream>
#include <string>
//#include "Vector.h"
#include "13.cpp"

class Model
{
private:
    Vector<std::string> m_titles ;
    //int* a;
public:
    void ReadTitlesFromFile(const std::string& filename);
    Vector<std::string>& GetTitles();
};

void Model::ReadTitlesFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (file.is_open()) 
    {
        std::string title;
        while (std::getline(file, title)) 
        {
            m_titles.push_back(title);
        }
        file.close();
    }
    else 
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
}

Vector<std::string>& Model::GetTitles()
{
    return m_titles;
}

class View
{
public:
    void DisplayTitles(const Vector<std::string>& titles);
};

void View::DisplayTitles(const Vector<std::string>& titles)
{
    std::cout << "List of titles:" << std::endl;
    for (size_t i = 0; i < titles.size(); ++i) 
    {
        std::cout << titles[i] << std::endl;
    }
}

class Controller
{
private:
    Model m_model;
    View m_view;
public:
    void ReadAndDisplayTitles(const std::string& filename);
};


void Controller::ReadAndDisplayTitles(const std::string& filename)
{
    m_model.ReadTitlesFromFile(filename);
    m_view.DisplayTitles(m_model.GetTitles());
}

int main()
{
    Controller controller;
    controller.ReadAndDisplayTitles("titles.txt");
    return 0;
}
//Explanation of how it fits the MVC pattern :
//-Model : The `Model` class represents the data and business logic.In this case, it reads book titles from a file and stores them in the `titles` vector.The `ReadTitlesFromFile` method reads the titles from the file and populates the vector.The `GetTitles` method provides access to the titles vector.
//- View: The `View` class is responsible for presenting the data to the user.In this case, the `DisplayTitles` method displays the titles on the screen in the same order as stored in the vector.
//- Controller: The `Controller` class handles the interaction between the model and the view.It orchestrates the process of reading the titles from the file and displaying them.The `ReadAndDisplayTitles` method calls the appropriate methods in the model and view to achieve the desired functionality.
//The `Vector` class acts as a data structure in the Model component, storing and managing the book titles.The `Model` class encapsulates the functionality required to read the titles from a file, making it independent of the specific data structure used.
//The `View` class is responsible for presenting the titles to the user, following the principle of separation of concerns.It only focuses on the presentation aspect and does not modify the data.
//The `Controller` class acts as a mediator between the model and the view.It coordinates the flow of data and controls the interaction between the two.It obtains the titles from the model and passes them to the view for display.
//This design adheres to the MVC pattern by separating the concerns of data, presentation, and control.It allows for flexibility, maintainability, and reusability of the components.For example, if we want to modify the way titles are displayed, we can change the `View` class without affecting the model or controller.Similarly, if we want to read titles from a different source, we can update the `Model` class without impacting the view or controller.