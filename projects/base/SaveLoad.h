#pragma once
#include <iostream>
#include <fstream>
#include <string>

class SaveLoad
{
public:

	SaveLoad();


	~SaveLoad();

	static void Save(std::string filename, int* buffer, int X_Count, int Y_Count);
	static void Load(std::string filename, int* buffer, int size);


};

