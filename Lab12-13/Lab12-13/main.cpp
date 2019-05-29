#include "Lab1213.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{};
	TutorialValidator v;
	Controller ctrl{ repo,v };
	Lab1213 w{ ctrl };
	w.show();
	return a.exec();
}
