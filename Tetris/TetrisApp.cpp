#include <conio.h>
#include <string.h>

#include "TetrisApp.h"
#include "Constants.h"

TetrisApp::TetrisApp()
	: Parent(getFieldwidth(), getFieldHigth())
	, m_nextFigure(FigureFactory::getRandomFigure())
	, m_currentFigure(FigureFactory::getRandomFigure())
	, m_currentFigurePosition(getStartFigurePosition())
	, m_schore(0)
	, m_counter(0)
	, m_boost(false)
{
	Init();
}
void TetrisApp::Init()
{
	for (uint16_t i = getLeftBorder() - getBorderSize(); i <= getRightBorder() + getBorderSize(); i++)
	{
		for (uint16_t j = getTopBorder() - getBorderSize(); j <= getBottomBorder() + getBorderSize(); j++)
		{
			if ((i < getLeftBorder() || i > getRightBorder())
				||
				(j < getTopBorder() || j > getBottomBorder()))
			{
				SetChar(i, j, getWallChar());
			}
			else
			{
				SetChar(i, j, getEmptyChar());
			}
		}
	}
	PrintNextFigure();
	string schoreName = "Scrore: ";
	uint16_t itteration = 0;
	for (char symbol : schoreName)
	{
		SetChar(getSchorePosition().x - schoreName.length() + itteration++, getSchorePosition().y, symbol);
	}
	PrintSchore();
}
void TetrisApp::PrintSchore()
{
	string schore(std::to_string(m_schore));
	uint16_t itteration = 0;
	for (char symbol : schore)
	{
		SetChar(getSchorePosition().x + itteration++, getSchorePosition().y, symbol);
	}
}
void TetrisApp::NextFigure()
{
	EraseFigure(getNextFigurePosition(), *m_nextFigure, getDarkChar());
	m_currentFigurePosition.x = getStartFigurePosition().x;
	m_currentFigurePosition.y = getStartFigurePosition().y;
	m_currentFigure = m_nextFigure;
	if (IsClear(Figure::getGlobalPositionShape(m_currentFigurePosition, m_currentFigure->getShape())))
	{
		m_nextFigure = FigureFactory::getRandomFigure();
		PrintNextFigure();
	}
	else
	{
		exit(0);
	}
}
void TetrisApp::PrintNextFigure()
{
	for (POINT point : m_nextFigure->getShape())
	{
		SetChar(point.x + getNextFigurePosition().x, point.y + getNextFigurePosition().y, getPointChar());
	}
}
void TetrisApp::PrintCurrentFigure()
{
	for (POINT point : m_currentFigure->getShape())
	{
		SetChar(point.x + m_currentFigurePosition.x, point.y + m_currentFigurePosition.y, getPointChar());
	}
}
void TetrisApp::EraseFigure(const POINT& position, const Figure& figure, const char symbol)
{
	std::vector<POINT> globalPosition = Figure::getGlobalPositionShape(position, figure.getShape());
	for (POINT point : globalPosition)
	{
		SetChar(point.x, point.y, symbol);
	}
}
bool TetrisApp::IsClear(const std::vector<POINT>& shape)
{
	bool returnValue = true;
	for (uint8_t i = 0; i < getCountPointsInFigure() && returnValue; i++)
	{
		if (GetChar(shape[i].x, shape[i].y) != getEmptyChar())
		{
			returnValue = false;
		}
	}
	return returnValue;
}
void TetrisApp::FlipCurrentFigure()
{		
	if (nullptr != m_currentFigure)
	{
		if (IsClear(Figure::getGlobalPositionShape(m_currentFigurePosition, m_currentFigure->getFlipedShape())))
		{
			m_currentFigure->Flip();
		}
	}
}
void TetrisApp::DeleteRow(const uint32_t row)
{
	for (int16_t i = row; i >= getTopBorder(); i--)
	{
		if (i != getTopBorder())
		{
			for (uint16_t j = getLeftBorder(); j <= getRightBorder(); j++)
			{
				SetChar(j, i, GetChar(j, i-1));
			}
		}
		else
		{
			for (uint16_t j = getLeftBorder(); j <= getRightBorder(); j++)
			{
				SetChar(j, i, getEmptyChar());
			}
		}
	}
}
void TetrisApp::ClearRows()
{
	std::vector<uint32_t> rows;
	for (POINT point : Figure::getGlobalPositionShape(m_currentFigurePosition, m_currentFigure->getShape()))
	{
		bool exists = false;
		for (uint8_t i = 0; i < rows.size() && !exists; i++)
		{
			if (point.y == rows[i])
			{
				exists = true;
			}
		}
		if (!exists)
		{
			rows.push_back(point.y);
		}
	}
	for (uint16_t row : rows)
	{
		bool rowIsFull = true;
		for (uint16_t i = getLeftBorder(); i <= getRightBorder() && rowIsFull; i++)
		{
			if (getPointChar() != GetChar(i, row))
			{
				rowIsFull = false;
			}
		}
		if (rowIsFull) {
			DeleteRow(row);
			m_schore += getSchoreIncrement();
			PrintSchore();
		}
	}
	
}
void TetrisApp::KeyPressed(int btnCode)
{
	if (!m_boost)
	{
		if (getSpaceKeyCode() == btnCode)
		{
			EraseFigure(m_currentFigurePosition, *m_currentFigure, getEmptyChar());
			FlipCurrentFigure();
			PrintCurrentFigure();
		}

		if (btnCode == getRightKeyCode())
		{
			POINT position(m_currentFigurePosition);
			position.x++;
			EraseFigure(m_currentFigurePosition, *m_currentFigure, getEmptyChar());
			if (IsClear(Figure::getGlobalPositionShape(position, m_currentFigure->getShape())))
			{
				m_currentFigurePosition.x++;
			}
			PrintCurrentFigure();
		}
		else if (btnCode == getLeftKeyCode())
		{
			POINT position(m_currentFigurePosition);
			position.x--;
			EraseFigure(m_currentFigurePosition, *m_currentFigure, getEmptyChar());
			if (IsClear(Figure::getGlobalPositionShape(position, m_currentFigure->getShape())))
			{
				m_currentFigurePosition.x--;
			}
			PrintCurrentFigure();
		}
		else if (btnCode == getDownKeyCode())
		{
			m_boost = true;
		}
	}
}
void TetrisApp::UpdateF(float deltaTime)
{
	m_counter++;
	if (getTikCount() == m_counter || m_boost) {
		EraseFigure(m_currentFigurePosition, *m_currentFigure, getEmptyChar());
		POINT posiblePosition(m_currentFigurePosition);
		posiblePosition.y++;
		if (IsClear(Figure::getGlobalPositionShape(posiblePosition, m_currentFigure->getShape())))
		{
			m_currentFigurePosition.y++;
		}
		else
		{
			PrintCurrentFigure();
			ClearRows();
			NextFigure();
			m_boost = false;
		}
		PrintCurrentFigure();
		m_counter = 0;
	}
}
