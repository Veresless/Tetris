#include "FigureFactory.h"
#include "Constants.h"

std::shared_ptr<Figure> FigureFactory::createFigure(const FIGURE& figure)
{
	std::vector<std::vector<POINT>> shapeVector;
	std::vector<POINT> shape1(getCountPointsInFigure());
	std::vector<POINT> shape2(getCountPointsInFigure());
	std::vector<POINT> shape3(getCountPointsInFigure());
	std::vector<POINT> shape4(getCountPointsInFigure());
	switch (figure)
	{
	case FIGURE::O:
		shape1[0].x = 1;
		shape1[0].y = 1;
		shape1[1].x = 1;
		shape1[1].y = 2;
		shape1[2].x = 2;
		shape1[2].y = 1;
		shape1[3].x = 2;
		shape1[3].y = 2;
		shapeVector.push_back(shape1);
		return std::make_shared<Figure>(shapeVector, 1);
	case FIGURE::I:
		shape1[0].x = 1;
		shape1[0].y = 0;
		shape1[1].x = 1;
		shape1[1].y = 1;
		shape1[2].x = 1;
		shape1[2].y = 2;
		shape1[3].x = 1;
		shape1[3].y = 3;
		shapeVector.push_back(shape1);
		shape2[0].x = 0;
		shape2[0].y = 1;
		shape2[1].x = 1;
		shape2[1].y = 1;
		shape2[2].x = 2;
		shape2[2].y = 1;
		shape2[3].x = 3;
		shape2[3].y = 1;
		shapeVector.push_back(shape2);
		return std::make_shared<Figure>(shapeVector, 2);
	case FIGURE::J:
		shape1[0].x = 1;
		shape1[0].y = 0;
		shape1[1].x = 1;
		shape1[1].y = 1;
		shape1[2].x = 1;
		shape1[2].y = 2;
		shape1[3].x = 0;
		shape1[3].y = 2;
		shapeVector.push_back(shape1);
		shape2[0].x = 0;
		shape2[0].y = 1;
		shape2[1].x = 1;
		shape2[1].y = 1;
		shape2[2].x = 2;
		shape2[2].y = 1;
		shape2[3].x = 2;
		shape2[3].y = 2;
		shapeVector.push_back(shape2);
		shape3[0].x = 1;
		shape3[0].y = 0;
		shape3[1].x = 1;
		shape3[1].y = 1;
		shape3[2].x = 1;
		shape3[2].y = 2;
		shape3[3].x = 2;
		shape3[3].y = 0;
		shapeVector.push_back(shape3);
		shape4[0].x = 0;
		shape4[0].y = 1;
		shape4[1].x = 1;
		shape4[1].y = 1;
		shape4[2].x = 2;
		shape4[2].y = 1;
		shape4[3].x = 0;
		shape4[3].y = 0;
		shapeVector.push_back(shape4);
		return std::make_shared<Figure>(shapeVector, 4);
	case FIGURE::L:
		shape1[0].x = 1;
		shape1[0].y = 0;
		shape1[1].x = 1;
		shape1[1].y = 1;
		shape1[2].x = 1;
		shape1[2].y = 2;
		shape1[3].x = 2;
		shape1[3].y = 2;
		shapeVector.push_back(shape1);
		shape2[0].x = 0;
		shape2[0].y = 1;
		shape2[1].x = 1;
		shape2[1].y = 1;
		shape2[2].x = 2;
		shape2[2].y = 1;
		shape2[3].x = 2;
		shape2[3].y = 0;
		shapeVector.push_back(shape2);
		shape3[0].x = 1;
		shape3[0].y = 0;
		shape3[1].x = 1;
		shape3[1].y = 1;
		shape3[2].x = 1;
		shape3[2].y = 2;
		shape3[3].x = 0;
		shape3[3].y = 0;
		shapeVector.push_back(shape3);
		shape4[0].x = 0;
		shape4[0].y = 1;
		shape4[1].x = 1;
		shape4[1].y = 1;
		shape4[2].x = 2;
		shape4[2].y = 1;
		shape4[3].x = 0;
		shape4[3].y = 2;
		shapeVector.push_back(shape4);
		return std::make_shared<Figure>(shapeVector, 4);
	case FIGURE::S:
		shape1[0].x = 0;
		shape1[0].y = 2;
		shape1[1].x = 1;
		shape1[1].y = 2;
		shape1[2].x = 1;
		shape1[2].y = 1;
		shape1[3].x = 2;
		shape1[3].y = 1;
		shapeVector.push_back(shape1);
		shape2[0].x = 1;
		shape2[0].y = 0;
		shape2[1].x = 1;
		shape2[1].y = 1;
		shape2[2].x = 2;
		shape2[2].y = 1;
		shape2[3].x = 2;
		shape2[3].y = 2;
		shapeVector.push_back(shape2);
		return std::make_shared<Figure>(shapeVector, 2);
	case FIGURE::Z:
		shape1[0].x = 0;
		shape1[0].y = 1;
		shape1[1].x = 1;
		shape1[1].y = 1;
		shape1[2].x = 1;
		shape1[2].y = 2;
		shape1[3].x = 2;
		shape1[3].y = 2;
		shapeVector.push_back(shape1);
		shape2[0].x = 2;
		shape2[0].y = 0;
		shape2[1].x = 2;
		shape2[1].y = 1;
		shape2[2].x = 1;
		shape2[2].y = 1;
		shape2[3].x = 1;
		shape2[3].y = 2;
		shapeVector.push_back(shape2);
		return std::make_shared<Figure>(shapeVector, 2);
	case FIGURE::T:
	default:
		shape1[0].x = 0;
		shape1[0].y = 1;
		shape1[1].x = 1;
		shape1[1].y = 1;
		shape1[2].x = 1;
		shape1[2].y = 0;
		shape1[3].x = 2;
		shape1[3].y = 1;
		shapeVector.push_back(shape1);
		shape2[0].x = 1;
		shape2[0].y = 0;
		shape2[1].x = 1;
		shape2[1].y = 1;
		shape2[2].x = 1;
		shape2[2].y = 2;
		shape2[3].x = 0;
		shape2[3].y = 1;
		shapeVector.push_back(shape2);
		shape3[0].x = 0;
		shape3[0].y = 1;
		shape3[1].x = 1;
		shape3[1].y = 1;
		shape3[2].x = 1;
		shape3[2].y = 2;
		shape3[3].x = 2;
		shape3[3].y = 1;
		shapeVector.push_back(shape3);
		shape4[0].x = 1;
		shape4[0].y = 0;
		shape4[1].x = 1;
		shape4[1].y = 1;
		shape4[2].x = 1;
		shape4[2].y = 2;
		shape4[3].x = 2;
		shape4[3].y = 1;
		shapeVector.push_back(shape4);
		return std::make_shared<Figure>(shapeVector, 4);
	}
}

std::shared_ptr<Figure> FigureFactory::getRandomFigure()
{
	return createFigure(static_cast<FIGURE>(rand() % getCountFigureShapes()));
}