
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domain.h"


typedef struct 
{
		Country con[100];
		int lenght;

}world;

void repositoryInitSetUp(world **currentWorld)
{
	*currentWorld = malloc(sizeof(world));
	(*currentWorld) -> lenght = 0;
}

void repositoryGetAllCountries(world *currentWorld)
{
	for (int i = 0; i < currentWorld -> lenght; ++i)
	{
		printf("\tname - %s\n",currentWorld -> con[i].name);
		printf("\tcontinent - %s\n",currentWorld -> con[i].continent);
		printf("\tpopulation - %lli\n",currentWorld -> con[i].population);
	}
}

void repositoryAddCountry(world *currentWorld,char name[],char continent[],long long population)
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
		printf("We are adding a new country to the repository...\n");
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
		printf("Index out of rande...");
	}
	else
	{
		strcpy(currentWorld -> con[index].name,name);
		strcpy(currentWorld -> con[index].continent,continent);
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
		printf("A part of the population of the country from index1 migrates towards the country from index2...");
		currentWorld -> con[index1].population -= nr;
		currentWorld -> con[index2].population += nr;
	}
}

int containsString(char *st1,char *st2)
{
	char *res;
	void *ret;
	ret = NULL;
	res = strstr(st1,st2);
	if (res == ret) return 0;
	return 1;
}

void repositoryGetAllWhoContain(world *currentWorld,char substring[])
{
	if (substring == "")
	{
		repositoryGetAllCountries(currentWorld);
	}
	else
	{
		Country countries[100];
		int index = 0;
		for (int i = 0; i < currentWorld -> lenght; ++i)
		{
			if (containsString(currentWorld -> con[i].name, substring) == 1)
			{
				countries[index++] = currentWorld -> con[i];
			}
		}

		for (int i = 0; i < index; ++i)
		{
			printf("\tname - %s\n",countries[i].name);
			printf("\tcontinent - %s\n",countries[i].continent);
			printf("\tpopulation - %lli\n",countries[i].population);
		}
	}
}