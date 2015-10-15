#include "usbreaderdemo.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UsbReaderDemo w;
	w.show();
	return a.exec();
}
