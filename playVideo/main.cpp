#include "playvideo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	playVideo w;
	w.show();
	return a.exec();
}
