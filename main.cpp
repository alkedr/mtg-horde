#ifndef USE_PRECOMPILED
# include "precompiled.hpp"
#endif

#include "MainWindow.hpp"


int main(int argc, char ** argv) {
	QApplication app(argc, argv);

	MainWindow window;
	window.setWindowTitle("Zombies");
	window.show();

	return app.exec();
}
