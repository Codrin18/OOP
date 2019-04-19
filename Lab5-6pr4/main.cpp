#include <iostream>
#include "UI.h"

using namespace std;

int main()
{
	Repository repo{};

	Tutorial t1{ "Minecraft in one week with C/C++","ProgrammingKnowledge",Duration{12,45},100000,"https://www.youtube.com/watch?v=F5mRW0jo-U4" };
	Tutorial t2{ "Learn Javascript:Full course for beginners","FreeCodeCamp",Duration{180,27},500000,"https://www.youtube.com/watch?v=PkZNo7MFNFg&t=2s" };
	Tutorial t3{ "Web development tutorial:HTML,CSS,Javascript","FreeCodeCamp",Duration{60,27},200000,"https://www.youtube.com/watch?v=jaVNP3nIAv0" };
	Tutorial t4{ "Data structures and algorithms with Javascript","FreeCodeCamp",Duration{120,27},300000,"https://www.youtube.com/watch?v=t2CEgPsws3U" };
	Tutorial t5{ "Learn Python:Full course for beginners","FreeCodeCamp",Duration{180,52},800000,"https://www.youtube.com/watch?v=rfscVS0vtbw" };
	Tutorial t6{ "Python Django Web Framework:Full course for beginners","FreeCodeCamp",Duration{300,43},1000000,"https://www.youtube.com/watch?v=F5mRW0jo-U4&t=1s" };
	Tutorial t7{ "Python algorithms for interview","FreeCodeCamp",Duration{60,27},300000,"https://www.youtube.com/watch?v=p65AHm9MX80" };
	Tutorial t8{ "Neural newtowrks with Javascript","FreeCodeCamp",Duration{300,16},10000,"https://www.youtube.com/watch?v=6E6XecoTRVo" };


	repo.add(t1);
	repo.add(t2);
	repo.add(t3);
	repo.add(t4);
	repo.add(t5);
	repo.add(t6);
	repo.add(t7);
	repo.add(t8);
	Controller ctrl{ repo };

	UI ui{ ctrl };

	ui.run();

	return 0;
}