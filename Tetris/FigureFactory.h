#ifndef FIGURE_FACTORY_H
#define FIGURE_FACTORY_H

#include "Figure.h"

enum FIGURE {
	O = 0,
	I = 1,
	S = 2,
	Z = 3,
	L = 4,
	J = 5,
	T = 6
};

class FigureFactory : public Figure
{
private:
	static std::shared_ptr<Figure> createFigure(const FIGURE& figure);
public:
	FigureFactory() = delete;
	static std::shared_ptr<Figure> getRandomFigure();
};
#endif // !FIGURE_FACTORY_H

