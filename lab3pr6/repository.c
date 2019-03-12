

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "repository.h"
#include "domain.h"


void repositoryIniSetUp(world **currentWorld)
{
	*currentWorld = malloc(sizeof(world));
	(*currentWorld) -> lenght = 0;
}

void repositoryGetAllCountries(world *currentWorld)
{
	for (int i = 0; i < currentWorld -> lenght; ++i)
	{
		printf("\tname - %d\n",currentWorld -> name);
		printf("\tcontinent - %d\n",currentWorld -> continent);
		printf("\tpopulation - %d\n",currentWorld -> population);
	}
}

void repositoryAddCountry(world *currentWorld,char name[50],char continent[50],long long population)
{
	int index = -1;
	for (int i = 0; i < currentWorld -> lenght; ++i)
	{
		if (currentWorld ->con[i].name == name)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		prinf("We are adding a new country to the repository");
		Country newCountry;
		newCountry = create_country(name,continent,population);
		currentWorld -> con[currentWorld -> lenght++] = newCountry;
	}
	else
	{
		printf("The country already exists");
	}
}

void repositoryDeleteCountry(world *currentWorld, int index)
{
	if (index < 0 || index > currentWorld -> lenght)
	{
		printf("Index out of range");
	}
	else
	{
		while (index < currentWorld -> lenght)
		{
			currentWorld -> con[index] = currentWorld -> con[index + 1];
			++index;
		}
		currentWorld -> lenght--;
	}
}

void repositoryUpdateCountry(world *currentWorld,int index,char name[],char continent[],long long population)
{
	if (index < 0 || index > currentWorld -> lenght)
	{
		printf("Index out of rande...")
	}
	else
	{
		currentWorld -> con[index].name = name;
		currentWorld -> con[index].continent = continent;
		currentWorld -> con[index].population = population;
	}
}

void repositoryMigration(world *currentWorld,int index1,int index2,long long nr)
{
	if (index1 < 0 || index1 > currentWorld -> lenght || index2 < 0 || index2 > currentWorld -> lenght)
	{
		printf("One of the indexes is out of range...");
	}
	else
	{
		printf("A part of the population of the country from index1 migrates towards the country from index2...")
		long long a = currentWorld -> con[index1].population - nr;
		currentWorld -> con[index1].population = a;
		long long a = currentWorld -> con[index2].population + nr;
		currentWorld -> con[index2].population = a;
	}
}

