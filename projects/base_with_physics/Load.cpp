#include "Load.h"
using namespace std;

Load::Load()
{

}
Load::~Load()
{

}

void Load::Loadlevel(std::string filename, int* buffer, int size)
{
	string line;
	ifstream myfile(filename);
	int i = 0;

	if (myfile.is_open())
	{
		int CutStart = 0;
		int commaIndex = -1;
		while (getline(myfile, line))
		{

			cout << line << "\n"; 
			while (true)
			{
				CutStart = commaIndex + 1; // cuts after the comma
				commaIndex = line.find(',', commaIndex + 1); //finds index num


				if (commaIndex < 0)
					break;

				string numStr = line.substr(CutStart, commaIndex - CutStart); //which index to cut from and how many characters to cut   //substr has 2 parameters the position and how many (pos,len)
				buffer[i] = std::stoi(numStr);
				i++;

			}

			std::cout << std::endl;
		}
		myfile.close();

	}
	else
		cout << "Unable to Open file";
}
