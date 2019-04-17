#include <iostream>
#include "UI.h"

using namespace std;

int main()
{
	Repository repo{};

	Tutorial t1{ "Minecraft in one week with C/C++","ProgrammingKnowledge",Duration{12,45},100000,"https://www.youtube.com/watch?v=F5mRW0jo-U4" };

	repo.add(t1);

	Controller ctrl{ repo };

	UI ui{ ctrl };

	ui.run();

	return 0;
}