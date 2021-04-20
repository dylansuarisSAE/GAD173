
#include "SaveLoad.h"
#include <iostream>
#include <fstream>
#include <string>

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

void SaveLoad::Load(std::string filename)
{
	string line;
	ifstream myfile(filename);
	int CutStart = 0;
	int commaIndex = -1;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << ' \n';
			while (true)
			{
				CutStart = commaIndex + 1;
				commaIndex = line.find(',', commaIndex + 1);

				string numStr = line.substr(CutStart, commaIndex - CutStart);
				int num = std::stoi(numStr);
				std::cout << num << std::endl;

				if (commaIndex < 0)
					break;

			}
		}
		myfile.close();

	}
	else
		cout << "Unable to Open file";
}

