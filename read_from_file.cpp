#include "read_from_file.h"
#include <fstream>
#include <string>
#include <iostream>

void read_from_file(std :: string path)
{
	std::ifstream rfile;

	rfile.open(path);

	std :: cout << std :: endl;
	
	if (!rfile.is_open())
	{
		std::cout << "File opening error while reading from" << std::endl;
	}
	else
	{
		std :: string i;
		while(!rfile.eof())
		{
			i = "";
			getline(rfile, i);
			std::cout << i << std::endl;
		}
	}

	rfile.close();
}