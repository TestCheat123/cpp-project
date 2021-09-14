#include "fileloader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void file::fileread(int **date, int val) {
	std::string line;
	std::fstream in("date.txt");
	if (in.is_open()) {
		while (std::getline(in, line))
		{
			fileloading.val++;
		}
	}

	fileloading.date = new int* [6];
	for (int i = 0; i < val; i++) {
		fileloading.date[i] = new int[val];
	}

	std::string d;
	if (in.is_open()) {
		int i = 0;
		int j = 0;
		while (std::getline(in, d)) {
			std::istringstream ss(d);
			int num;
			while (ss >> num) {
				fileloading.date[i][j] = num;
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

void file::deletedata(int** date, int val) {
	for (int i = 0; i < val; i++) {
		delete[] fileloading.date[i];
	}
	delete[] fileloading.date;
}