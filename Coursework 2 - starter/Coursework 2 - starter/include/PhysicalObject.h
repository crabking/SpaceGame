

/*! \file PhysicalObject.h
Class that defines degrees and radians

degrees to radians,radians to degrees

*/

#pragma once

#include <Box2D/Box2D.h>

/*!
\def degrees to radians
\def radians to degrees


*/
#define DEG2RAD 0.017453f;
#define RAD2DEG 57.29577f;

class PhysicalObject {

protected:
	b2Body * m_body = nullptr;
};