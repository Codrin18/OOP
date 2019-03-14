#ifndef REPOSITORY
#define REPOSITORY

#include "domain.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
		Country con[100];
		int lenght;

}world;

void repositoryInitSetUp(world **currentworld);
void repositoryGetAllCountries(world *currentworld);
void repositoryAddCountry(world *currentworld, char name[],char continent,long long population);
void repositoryDeleteCountry(world *currentworld,int index);
void repositoryUpdateCountry(world *currentworld,int index,char name[],char continent[],long long population);
void repositoryMigration(world *currentworld,int index1,int index2,long long nr);
void repositoryGetAllWhoContain(world *currentWorld,char substring[]);

#endif
