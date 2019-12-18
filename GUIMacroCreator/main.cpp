#include <QtWidgets/QApplication>

#include "ListWidget.h"
#include "MacroWindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MacroWindow window;

	window.resize(240, 230);
	window.setWindowTitle("Macro Recorder");
	window.show();

	return app.exec();
}
