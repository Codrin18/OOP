#ifndef REPOSITORY
#define REPOSITORY
#include "Country.h"


typedef struct
{
	Country* country[100];
	int length;
}CountryRepo;

CountryRepo* createRepo();
void destroyRepo(CountryRepo* repo);

int addCountry(Country* c,CountryRepo* repo);
void deleteCountry(CountryRepo* repo,char* name);

int findCountry(CountryRepo* repo,char* name);
int updateCountry(Country* c,CountryRepo* repo);
int migrationCountry(CountryRepo* repo,int index1,int index2,long long nr);

void getContain(CountryRepo* repo, char* substring);
void getByContinent(CountryRepo* repo,char* continent);
void getByContinentPopulation(CountryRepo* repo,char* continent,long long nr);



#endif
