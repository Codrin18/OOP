
#include <stdio.h>
#include <string.h>


typedef struct 
{
	char name[50];
	char continent[50];
	long long population;
}Country;

Country create_country(char name[],char continent[],long long population)
{
	Country c;
	strcpy(c.name,name);
	strcpy(c.continent,continent);
	c.population = population;

	return c;
}

char* get_name(Country* c)
{
	return c -> name;
}

char* get_continent(Country* c)
{
	return c -> continent;
}

long long get_population(Country* c)
{
	return c -> population;
}