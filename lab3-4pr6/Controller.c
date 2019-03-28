#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"


Controller* createController(CountryRepo* repo,OperationsStack* undoStack)
{
	Controller* ctrl = (Controller*)malloc(sizeof(Controller));
	ctrl->repo = repo;
	ctrl->undoStack = undoStack;
	return ctrl;
}

void destroyController(Controller* ctrl)
{
	destroyRepo(ctrl->repo);
	destroyStack(ctrl->undoStack);

	free(ctrl);
}

int addCountryController(Controller* ctrl,char* name,char* continent,long long population)
{
	Country* c = createCountry(name,continent,population);
	int res = addCountry(c,ctrl -> repo);

	if (res == 1)
	{
		Operation* o = createOperation(c, "add");
		push(ctrl->undoStack, o);
		// once added, the operation can be destroyed (a copy of the operation was added)
		destroyOperation(o);
	}

	destroyCountry(c);

	return res;

}

int deleteCountryController(Controller* ctrl,int index)
{
	int res = deleteCountry(ctrl -> repo,index);
	return res;
}

int updateCountryController(Controller* ctrl,int index,char* name,char* continent,long long population)
{
	Country* c = createCountry(name,continent,population);
	int res = updateCountry(c,ctrl -> repo,index);
	return res;
}

int migrationCountryController(Controller* ctrl,int index1,int index2,long long nr)
{
	int res = migrationCountry(ctrl -> repo,index1,index2,nr);
	return res;
}

void getContainController(Controller* ctrl,char* substring)
{
	getContain(ctrl -> repo,substring);
}

void getByContinentController(Controller* ctrl,char* continent)
{
	getByContinent(ctrl -> repo,continent);
}

void getByContinentPopulationController(Controller* ctrl,char* continent,long long nr)
{
    getByContinentPopulation(ctrl -> repo,continent,nr);
}

CountryRepo* findAll(Controller* ctrl)
{
	return ctrl -> repo;
}

void printAll(Controller* ctrl)
{
	CountryRepo* result = findAll(ctrl);
	for (int i = 0; i < result -> length; ++i)
    {
        printf("\tname - %s\n",result -> country[i] -> name);
        printf("\tcontinent - %s\n",result -> country[i] -> continent);
        printf("\tpopulation - %lli\n",result -> country[i] -> population);
    }
}

int undo(Controller* ctrl)
{
    if (isEmpty(ctrl -> undoStack))
    {
        return 0;
    }

    Operation* operation = pop(ctrl->undoStack);

    if (strcmp(getOperationType(operation),"add") == 0)
    {
        Country* c = getCountry(operation);
        deleteCountry(ctrl -> repo,ctrl -> repo -> length - 1);
        ctrl -> repo -> length--;
    }

    destroyOperation(operation);

    return 1;
}
