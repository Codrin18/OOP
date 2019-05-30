#include <iostream>
#include "UI.h"
#include <string>
using namespace std;

int main()
{
	Repository repo{};
	TutorialValidator v;
	Controller ctrl{ repo,v };

	UI ui{ ctrl };

	ui.run();

	return 0;
}