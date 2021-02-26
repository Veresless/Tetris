#ifndef TETRIS_APP_H
#define TETRIS_APP_H

#include "BaseApp.h"
#include "Figure.h"
#include "FigureFactory.h"

class TetrisApp : public BaseApp
{
typedef BaseApp Parent;

private:
	std::shared_ptr<Figure> m_nextFigure;
	std::shared_ptr<Figure> m_currentFigure;
	POINT m_currentFigurePosition;
	uint32_t m_schore;
	uint16_t m_counter;
	bool m_boost;
	
	void Init();
	void PrintSchore();
	void NextFigure();
	void PrintNextFigure();
	void PrintCurrentFigure();
	void EraseFigure(const POINT& position, const Figure& figure, const char symbol);
	bool IsClear(const std::vector<POINT>& shape);
	void FlipCurrentFigure();
	void ClearRows();
	void DeleteRow(const uint32_t row);

public:
	TetrisApp();
	virtual void KeyPressed(int btnCode);
	virtual void UpdateF(float deltaTime);
};

#endif // ! TETRIS_APP_H