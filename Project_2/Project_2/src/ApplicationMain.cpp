#include "GameWindow.h"

int main(int argc, char* argv[])
{
	GameWindow application;

	application.InitializeWindow(1366, 728);

	application.Render();

	return 0;
}