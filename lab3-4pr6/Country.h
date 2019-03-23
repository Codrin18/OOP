#ifndef COUNTRY
#define COUNTRY

typedef struct 
{
	char* name;
	char* continent;
	long long population;

}Country;

Country* createCountry(char* name,char* continent,long long population);
void destroyCountry(Country* c);
Country* copyCountry(Country* c);

char* getName(Country* c);
char* getContinent(Country* c);
long long getPopulation(Country* c);

#endif