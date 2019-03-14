
#include "controller.h"
#include "repository.h"
#include <stdio.h>
#include <stdlib.h>



void controllerInitSetUp(controller **worldController)
{
	*worldController = malloc(sizeof(controller));
	repositoryInitSetUp(&((*worldController) -> NewController));
}

void controllerGetAllCountries(controller *worldController)
{
	repositoryGetAllCountries(worldController -> NewController);
}

void controllerAddCountry(controller *worldController, char name[],char continent[],long long population)
{
	repositoryAddCountry(worldController -> NewController,name,continent,population);
}

void controllerDeleteCountry(controller *worldController,int index)
{
	repositoryDeleteCountry(worldController -> NewController,index);
}

void controllerUpdateCountry(controller *worldController,int index,char name[],char continent[],long long population)
{
	repositoryUpdateCountry(worldController -> NewController,index,name,continent,population);
}

void controllerMigration(controller *worldController,int index1,int index2,long long nr)
{
	repositoryMigration(worldController -> NewController,index1,index2,nr);
}

void controllerGetAllWhoContain(controller *worldController,char sub[])
{
	repositoryGetAllWhoContain(worldController -> NewController,sub);
}

