#include "UI.h"
#include <Windows.h>
#include "Song.h"

using namespace std;

int main()
{
	system("color f4");

	// _CrtDumpMemoryLeaks is frequently called at the end of program execution to verify that all memory allocated by the application has been freed. 
	// The function can be called automatically at program termination by turning on the _CRTDBG_LEAK_CHECK_DF bit field of the _crtDbgFlag flag using the _CrtSetDbgFlag function.
	// (https://msdn.microsoft.com/en-us/library/d41t22sb.aspx)
	int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	flag |= _CRTDBG_LEAK_CHECK_DF;
	_CrtSetDbgFlag(flag);

	FileRepository repo("songs.txt");
	SongValidator validator{};
	Controller ctrl(repo, validator);
	//ctrl.addSongToRepo("Ed Sheeran", "I see fire", 4, 54, "https://www.youtube.com/watch?v=2fngvQS_PmQ");
	//ctrl.addSongToRepo("The Proclaimers", "I would walk 500 miles", 3, 37, "https://www.youtube.com/watch?v=otXGqU4LBEI");
	//ctrl.addSongToRepo("Doctor Who", "I am the Doctor", 3, 55, "https://www.youtube.com/watch?v=otXGqU4LBEI");

	//cout << ctrl.getRepo().getSongs()[0]->getArtist();

	UI ui(ctrl);
	ui.run();

	return 0;
}