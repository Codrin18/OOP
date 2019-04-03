#ifndef CONTROLLER
#define CONTROLLER

#include "CountryRepository.h"
#include "OperationsStack.h"

typedef struct
{
	CountryRepo* repo;
	OperationsStack* undoStack;
} Controller;

Controller* createController(CountryRepo* repo,OperationsStack* undoStack);
void destroyController(Controller* ctrl);

int addCountryController(Controller* ctrl,char* name,char* continent,long long population);
void deleteCountryController(Controller* ctrl,char* name);

int updateCountryController(Controller* ctrl,char* name,char* continent,long long population);
int migrationCountryController(Controller* ctrl,int index1,int index2,long long nr);

CountryRepo getContainController(Controller* ctrl,char* substring);
CountryRepo getByContinentController(Controller* ctrl,char* continent);
CountryRepo getByContinentPopulationController(Controller* ctrl,char* continent,long long nr);

CountryRepo* findAll(Controller* ctrl);
void printAll(Controller* ctrl);

int undo(Controller* ctrl);

#endif
