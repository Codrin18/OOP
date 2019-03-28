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
int deleteCountryController(Controller* ctrl,int index);

int updateCountryController(Controller* ctrl,int index,char* name,char* continent,long long population);
int migrationCountryController(Controller* ctrl,int index1,int index2,long long nr);

void getContainController(Controller* ctrl,char* substring);
void getByContinentController(Controller* ctrl,char* continent);
void getByContinentPopulationController(Controller* ctrl,char* continent,long long nr);

CountryRepo* findAll(Controller* ctrl);
void printAll(Controller* ctrl);

int undo(Controller* ctrl);

#endif
