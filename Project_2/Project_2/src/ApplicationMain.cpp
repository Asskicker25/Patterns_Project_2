#include "GameWindow.h"

int main(int argc, char* argv[])
{
	GameWindow application;

	Debugger::print = true;

	application.InitializeWindow(1366, 728);

	application.Render();

	return 0;
}