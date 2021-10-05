#include "App.h"

void App::start() {
	File mass = File();
	Datetime d = Datetime();
	UI ui;
	mass.fileread();
	ui.ShowLocalDateTime();
	for (int i = 1; i <= mass.val; i++) {
		d.getData(mass.date, i);
		d.nDataS();
		d.pDataS();
		ui.ShowAllDateInfo(d);
	}
	std::cout << std::endl << "Next date next month" << std::endl;
	for (int i = 1; i <= mass.val; i++) {
		d.getData(mass.date, i);
		d.nDataS();
		d.pDataS();
		ui.ShowDateFromNextMonth(d);
	}

}