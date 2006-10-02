#include "mainwindow.h"
#include <QApplication>

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	VPiano *vp = new VPiano;
	vp->show();
	return app.exec();
}
