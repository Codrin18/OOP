#include <stdio.h>
#include <stdlib.h>
#include "UI.h"

int main()
{
    testCountryRepo();
	CountryRepo* repo = createRepo();
	OperationsStack* s = createStack();
	Controller* ctrl = createController(repo, s);
	UI* ui = createUI(ctrl);

	startUI(ui);

}
