

#include "..\include\Line.h"
#include "..\include\LevelLoader.h"
#include <fstream>

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

Line::Line(b2World * m_world, const float v)
{

	srand(time(NULL));


	LevelLoader::GetInstance()->LoadModel("Level1.txt"); //!< gets singleton instance of leveloader


	vector<float> vop = LevelLoader::GetInstance()->GetGroundPoints(); //!< gets ground points of vector


	int l = LevelLoader::GetInstance()->getNum(); 


	
	b2ChainShape chain; //!< chain shape
	b2Vec2 vertices[1000];  //!< dont know why i cant pass this variable

	for (int i = 0; i < v; i++) //!< loops through the vertices
	{
		vertices[i].Set(vop[i * 2], vop[(i * 2) + 1]); //!< sets the vertices

	}
	chain.CreateChain(vertices, v); //!< creates a chain of the  vertices

	
	float fOffset = 5.25f; //!< the offset between the body and the line that were not fitting correctly
	m_groundLine.resize(v);
	m_groundLine.setPrimitiveType(sf::LinesStrip);


	for (int i = 0; i < v; i++) //!< loops through the vertices
	{
		
		int r = rand() % 255; //!< sets random color each time it loops thorugh
		int g = rand() % 255;
		int b = rand() % 255;
		m_groundLine[i] = sf::Vertex(sf::Vector2f(vop[i * 2], vop[(i * 2) + 1] + fOffset), (sf::Color(r, g, b)));  //!< sets position and color
	}


	/// Box2d Line Body
	/** defining the body, the circle shape and the fixture,
	sets the density, friction and restitution of the body*/
	b2BodyDef l_bodyDef;
	b2FixtureDef l_fixtureDef;

	l_fixtureDef.density = 0.1;
	l_fixtureDef.friction = 2.0;
	l_fixtureDef.restitution = 0.5;

	l_bodyDef.type = b2_staticBody;
	l_bodyDef.position.Set(0.f, 5.f);

	m_lineBody = m_world->CreateBody(&l_bodyDef);
	l_fixtureDef.shape = &chain;

	m_lineBody->CreateFixture(&l_fixtureDef);

}

Line::~Line()
{
}

void Line::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_groundLine); //!< draws the line
}
