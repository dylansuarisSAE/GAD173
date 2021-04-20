
#include "SaveLoad.h"
#include <iostream>
#include <fstream>

using namespace std;
SaveLoad::SaveLoad() {

}


SaveLoad::~SaveLoad() {

}



void SaveLoad::Save(string filename, int*buffer, int X_Count, int Y_Count)
{
	ofstream myfile;
	myfile.open(filename);

		for (size_t y = 0; y < Y_Count; y++)
		{
			for (size_t x = 0; x < X_Count; x++)
			{
				int i = x + y * X_Count;
				myfile << buffer[i] << ", ";
			}

			myfile << std::endl;
		}

	myfile.close();
}

