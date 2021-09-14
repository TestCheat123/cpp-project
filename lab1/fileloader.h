#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
class file
{
	public :
		int **date;
		int val = 0;
		void fileread(int **date, int val);
		void deletedata(int **date, int val);
};

file fileloading;