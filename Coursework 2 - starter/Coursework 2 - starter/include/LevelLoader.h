/*! \file LevelLoader.h
Loads in points in world through file

This class loads in a set of points in the world through file

This class uses the Singleton design pattern.

*/

#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class LevelLoader
{


private:



	LevelLoader();
	~LevelLoader();

	vector<float> m_groundPoints;

	int m_groundPointsNum;

	static LevelLoader * p_Instance;


public:

	static LevelLoader * GetInstance();

	void LoadModel(string modelName);


	vector<float>& GetGroundPoints();

	int getNum();

	void levelCreator(); //!< attempt to write a file
};