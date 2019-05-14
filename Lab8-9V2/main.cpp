#include <iostream>
#include "UI.h"
#include <string>
using namespace std;

int main()
{
	Repository repo{};
	Controller ctrl{ repo };

	UI ui{ ctrl };

	ui.run();

	return 0;
}