#include "formulashow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FormulaShow w;
	w.show();
	return a.exec();
}
