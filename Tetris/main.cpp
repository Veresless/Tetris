#include <cstdlib>
#include "TetrisApp.h"

int main ()
{
	srand(static_cast<unsigned int>(time(0)));
	TetrisApp app;
	app.Run();
	return 0;
}
