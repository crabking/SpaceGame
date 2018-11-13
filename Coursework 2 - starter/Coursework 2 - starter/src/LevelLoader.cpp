

#include <string.h>
#include "LevelLoader.h"


// Include all STL sequence containers
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <stdlib.h>     /* srand, rand */

// Include String and file processing tools
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>

LevelLoader * LevelLoader::p_Instance = nullptr; 

LevelLoader * LevelLoader::GetInstance()
{

	if (!p_Instance)
	{
		p_Instance = new LevelLoader;
	}
	return p_Instance;
}

LevelLoader::LevelLoader()
{
	levelCreator();
}


LevelLoader::~LevelLoader()
{
}

void LevelLoader::LoadModel(string LevelName) 
{

	

	std::fstream textfile(LevelName, std::ios_base::in); 


	string l_line = "";

	if (textfile.is_open())
	{



		while (getline(textfile, l_line))
		{
			string s;
			istringstream iss(l_line);

			iss >> s; //!< read to first whitespace

			if (s == "g")
			{

				float l_positionIndex;

				while (iss >> l_positionIndex)
				{
					m_groundPoints.push_back(l_positionIndex); //!< pushes on the onto the index
				}

			}




		}
		//!< closes the modelfile
		textfile.close();

	}

	
}




vector<float>& LevelLoader::GetGroundPoints()
{
	return m_groundPoints; //!< returns groundpoints
}

int LevelLoader::getNum() {
	return m_groundPointsNum; //!< gets umber of grounpoints
}

void LevelLoader::levelCreator() {

	float firstVertex = 1; //!< sets first vertex slightly where car spawns

	srand(time(NULL));


	ofstream outputFile;
	outputFile.open("Level1.txt");

	/// Write to file loop
	/** for loop that writes 30 lines of an identifier char and 2 floats, one that increases and another that is random between 0 and 50 */
	for (int i = 0; i < 1000; i++) 
	{
		outputFile << "g" << " " <<  firstVertex << "." << 0 << " "; 
		outputFile << rand() % 50 << "." << 0 << " " << endl;
		firstVertex = firstVertex + 100;
	}
	
	
	


}