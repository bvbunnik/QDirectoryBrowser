#include "directorybrowser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    DirectoryBrowser w;
    w.show();
	return a.exec();
}
