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
int deleteCountry(CountryRepo* repo,int index);

int updateCountry(Country* c,CountryRepo* repo,int index);
int migrationCountry(CountryRepo* repo,int index1,int index2,long long nr);

void getContain(CountryRepo* repo, char* substring);
void getByContinent(CountryRepo* repo,char* continent);

#endif