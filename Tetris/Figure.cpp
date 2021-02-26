#include "Figure.h"
#include "Constants.h"

Figure::Figure(const std::vector<std::vector<POINT>>& shapeVector, const uint8_t flipCount)
	: m_shape(shapeVector)
	, m_flipCount(flipCount)
	, m_currentFlip(0)
{

}
Figure::Figure(const Figure& figure)
	: m_shape(figure.m_shape)
	, m_flipCount(figure.m_flipCount)
	, m_currentFlip(figure.m_currentFlip)
{

}
void Figure::Flip()
{
	m_currentFlip = ((m_currentFlip + 1) % m_flipCount);
}
const std::vector<POINT> Figure::getFlipedShape() const
{
	return m_shape[((m_currentFlip + 1) % m_flipCount)];
}
const std::vector<POINT> Figure::getGlobalPositionShape(const POINT& position, const std::vector<POINT>& shape)
{
	std::vector<POINT> returnShape(getCountPointsInFigure());
	for (uint8_t i = 0; i < getCountPointsInFigure(); i++)
	{
		returnShape[i].x = shape[i].x + position.x;
		returnShape[i].y = shape[i].y + position.y;
	}
	return returnShape;
}