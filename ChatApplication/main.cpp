#include "ChatApplication.h"
#include <QtWidgets/QApplication>
#include <QDesktopWidget>
#include "ChatSession.h"
#include "chatwindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	ChatSession session;

	ChatWindow user1{ User{ "jon.snow", "Jon Snow" }, session };
	// create user2 "tyrion.lannister", "Tyrion Lannister"
	ChatWindow user2{ User{"tyrion.lannister","Tyrion Lannister"},session };
	// create user3 "arya.stark", "Arya Stark"

	// create user4 "daenerys.targaryen", "Daenerys Targaryen"
	
	user1.show();
	user2.show();
	

	// move the windows across the screen
	// get the screen's coordinates
	QRect screenRect = QApplication::desktop()->screen()->rect();
	int x = screenRect.x();
	int y = screenRect.y();
	int width = screenRect.width();
	int height = screenRect.height();

	// move the first window in the top left corner
	user1.move(x, y);
	// move the second lower

	// move the third in the top right corner

	// move the fourth lower


	return a.exec();
}
