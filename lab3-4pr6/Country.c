#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Country.h"

Country* createCountry(char* name,char* continent,long long population)
{
	Country* c = (Country*)malloc(sizeof(Country));

	c -> name = (char*)malloc(sizeof(char) * strlen(name) + 1);

	strcpy(c -> name, name);

	c -> continent = (char*)malloc(sizeof(char) * strlen(continent) + 1);

	strcpy(c -> continent, continent);

	c -> population = population;

	return c;
}

void destroyCountry(Country* c)
{
	free(c -> name);
	free(c -> continent);

	free(c);
}

Country* copyCountry(Country* c)
{
	if (c == NULL)
		return NULL;
	Country * newCountry = createCountry(getName(c),getContinent(c),getPopulation(c));

	return newCountry;
}

char* getName(Country* c)
{
	return c -> name;
}

char* getContinent(Country* c)
{
	return c -> continent;
}

long long getPopulation(Country* c)
{
	return c -> population;
}