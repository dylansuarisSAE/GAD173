#pragma once
#include <string>
#include <iostream>
#include <fstream>
class Load
{
public:

	Load(); 
	~Load();



	static void Loadlevel(std::string filename, int* buffer, int size);
};

