
#include "SaveLoad.h"



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

void SaveLoad::Load(std::string filename, int* buffer, int size)
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
			
			cout << line << ' \n';
			while (true)
			{
				CutStart = commaIndex + 1; // cuts after the comma
				commaIndex = line.find(',', commaIndex + 1); //finds index num


				if (commaIndex < 0)
					break;

				string numStr = line.substr(CutStart, commaIndex - CutStart); //which index to cut from and how many characters to cut   //substr has 2 parameters the position and how many (pos,len)
				buffer [i] = std::stoi(numStr);
				i++;
		
			}

			std::cout << std::endl;
		}
		myfile.close();

	}
	else
		cout << "Unable to Open file";
}

