

#include "BlockShape.h"



BlockShape::BlockShape(b2World * m_world, const sf::View& view, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation)
{
	/// Draws the sfml of the blockshape
	/** sets the size, origin, rotation, órientation, fillcolor, and outline thickness*/
	m_blockShape.setSize(size);
	m_blockShape.setOrigin(size * 0.5f);
	m_blockShape.setRotation(-orientation);

	

	/// Box2d Definitions
	/** defining the body.
	the circle shape and the fixture.
	sets the density.
	friction and restitution of the body.*/
	b2PolygonShape l_polygonShape;
	b2BodyDef l_bodyDef;
	b2FixtureDef l_fixtureDef;

	/// Box2d creation of the block body
	/** defining the body.
	sets the body to dynamic.
	sets the bodys position in the world.
	sets the angle.
	creates the body in the world and creates the fixtur.
	sets the size of hte box.
	creates the world and then the body. */
	l_bodyDef.type = b2_dynamicBody;
	l_bodyDef.angle = orientation * DEG2RAD;
	l_bodyDef.position.Set(position.x, position.y);

	l_fixtureDef.density = 0.5f;
	l_fixtureDef.friction = 2.0f;
	l_fixtureDef.restitution = 0.05f;

	l_polygonShape.SetAsBox(size.x, size.y);
	l_fixtureDef.shape = &l_polygonShape;

	m_blockBody = m_world->CreateBody(&l_bodyDef);
	m_blockBody->CreateFixture(&l_fixtureDef);



}


BlockShape::~BlockShape()
{
}




void BlockShape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_blockShape); //! draw ball 1
}

void BlockShape::update(sf::View& gameView)
{

	/// SFML to Body positioning
	/** gets position, and sets the position of the SFML to the box2d body.*/
	b2Vec2 blockpos = m_blockBody->GetPosition();
	m_blockShape.setPosition(blockpos.x, blockpos.y); //! set position to the ballbody.
}



