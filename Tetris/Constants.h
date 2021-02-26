#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Windows.h>
#include <stdint.h>
inline const uint8_t getFieldHigth()
{
	return 35;
}
inline const uint8_t getFieldwidth()
{
	return 25;
}
inline const uint8_t getCountPointsInFigure()
{
	return 4;
}
inline const uint8_t getCountFigureShapes()
{
	return 7;
}
inline const POINT getNextFigurePosition()
{
	POINT position;
	position.x = 20;
	position.y = 1;
	return position;
}
inline const POINT getStartFigurePosition()
{
	POINT position;
	position.x = 6;
	position.y = 1;
	return position;
}
inline const POINT getSchorePosition()
{
	POINT position;
	position.x = 10;
	position.y = 33;
	return position;
}
inline const char getEmptyChar()
{
	return L'-';
}
inline const char getDarkChar()
{
	return L' ';
}
inline const char getPointChar()
{
	return L'0';
}
inline const char getWallChar()
{
	return L'#';
}
inline const int32_t getSpaceKeyCode()
{
	return 32;
}
inline const int32_t getRightKeyCode()
{
	return 77;
}
inline const int32_t getDownKeyCode()
{
	return 80;
}
inline const int32_t getLeftKeyCode()
{
	return 75;
}
inline const uint16_t getBorderSize()
{
	return 1;
}
inline const uint16_t getTopBorder()
{
	return getBorderSize();
}
inline const uint16_t getBottomBorder()
{
	return 30 + getTopBorder() - 1;
}
inline const uint16_t getLeftBorder()
{
	return getBorderSize();
}
inline const uint16_t getRightBorder()
{
	return 15 + getLeftBorder() - 1;
}
inline const uint16_t getSchoreIncrement()
{
	return 100;
}
inline const uint16_t getTikCount()
{
	return 20;
}
#endif // !CONSTANTS_H

