#ifndef FIGURE_H
#define FIGURE_H

#include <Windows.h>
#include <vector>
#include <stdint.h>
#include <cstdlib>
#include <ctime>
#include <memory>

class Figure {
private:
	std::vector<std::vector<POINT>> m_shape;
	const uint8_t m_flipCount;
	uint8_t m_currentFlip;
public:
	Figure(const std::vector<std::vector<POINT>>& shapeVector, const uint8_t flipCount);
	Figure(const Figure& figure);
	Figure() = delete;
	Figure(Figure&& figure) = delete;
	const Figure& operator= (const Figure& figure) = delete;
	void Flip();
	inline const std::vector<POINT> getShape() const;
	const std::vector<POINT> getFlipedShape() const;
	static const std::vector<POINT> getGlobalPositionShape(const POINT& position, const std::vector<POINT>& shape);
	~Figure() = default;
};

inline const std::vector<POINT> Figure::getShape() const
{
	return m_shape[m_currentFlip];
}
#endif // !FIGURE_H
