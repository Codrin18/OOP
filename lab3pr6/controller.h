#ifndef CONTROLLER
#define CONTROLLER

#include "repository.h"


typedef struct 
{
	
	world *NewController;

}controller;

void controllerInitSetUp(controller **worldController);
void controllerGetAllCountries(controller *worldController);
void controllerAddCountry(controller *worldController, char name[],char continent[],long long population);
void controllerDeleteCountry(controller *worldController,int index);
void controllerUpdateCountry(controller *worldController,int index,char name[],char continent[],long long population);
void controllerMigration(controller *worldController,int index1,int index2,long long nr);
void controllerGetAllWhoContain(controller *worldController,char sub[]);
void controllerGetAllByContinent(controller *worldController,char continent[]);



#endif
