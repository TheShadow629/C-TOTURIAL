#include <iostream>
#include<map>
#include <string>

void mapTest()
{
	std::map<std::string, int> Popularity;
	Popularity.insert(std::pair<std::string, int>("Age", 19));
	Popularity.insert(std::map<std::string, int>::value_type("Age", 19));
	Popularity["ID"] = 123;
	Popularity["ID"] = 0;

	std::cout << Popularity["ID"];

	std::map<int, int>::iterator it1;
	std::map<std::string, int>::iterator it=Popularity.find("ID");
	std::cout << it->first;
	std::cout << it->second;
	Popularity.erase("ID");
	std::map<std::string, int>::iterator it2 = Popularity.find("ID"); //Popularity.end()

	if (Popularity.find("ID")!=Popularity.end())
	{
		std::cout << "found it";
	}
	//Popularity.begin();

	for(std::map<std::string, int>::iterator i= Popularity.begin();i!= Popularity.end();i++)
	{
		std::cout << i->first;
		std::cout << i->second;
	}

	Popularity.clear();




}
