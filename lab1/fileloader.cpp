#include "fileloader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void file::fileread() {
	std::string line;
	std::fstream in("date.txt");
	std::getline(in, line);
	if (in.is_open()) {
		while (std::getline(in, line))
		{
			val++;
		}
	}

	date = new int* [6];
	for (int i = 0; i < val; i++) {
		date[i] = new int[val];
	}

	std::string d;
	if (in.is_open()) {
		int i = 0;
		int j = 0;
		while (std::getline(in, d)) {
			std::istringstream ss(d);
			int num;
			while (ss >> num) {
				date[i][j] = num;
				i++;
				if (i > 5) {
					j++;
					i = 0;
				};
			}

		}
	}
	else
	{
		std::cout << "File read error" << std::endl;
	}
	in.close();
}

void file::deletedata() {
	for (int i = 0; i < val; i++) {
		delete[] date[i];
	}
	delete[] date;
}

void file::datasort() {
	int temp1[6];	
	for (int i = 0; i < val; i++)
	{
		
	}
}