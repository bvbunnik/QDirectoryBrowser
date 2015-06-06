#include "directorybrowser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    DirectoryBrowser w(0, "I will browse!");
    w.show();
	return a.exec();
}
