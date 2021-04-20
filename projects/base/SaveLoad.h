#pragma once
#include <iostream>

class SaveLoad
{
public:

	SaveLoad();


	~SaveLoad();

	static void Save(std::string filename, int* buffer, int X_Count, int Y_Count);



};

