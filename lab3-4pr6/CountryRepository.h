#ifndef REPOSITORY
#define REPOSITORY
#include "Country.h"


/* Trebuie sa scapi de printf din repository,adauga teste,fa redo

/*
-----------------------------------------------------
A typedef  of type CountryRepo is defined  by two properties:
<Country> which is a vector of type Country
<length> the length of CountryRepo
-------------------------------------------------------------
 */
typedef struct
{
	Country* country[100];
	int length;
}CountryRepo;


/*
---------------------------------------------------------------
This function creates a CountryRepo
INPUT:---
OUTPUT:A variable of type CountryRepo
--------------------------------------------------------------
*/
CountryRepo* createRepo();
/*
--------------------------------------------------------------
This function frees the memory allocated for a variable of type CountryRepo
INPUT:A variable of type CountryRepo
OUTPUT:----
--------------------------------------------------------------
*/
void destroyRepo(CountryRepo* repo);

/*
--------------------------------------------------------------
This function adds a country to the repository
INPUT:A variable of type Country and a variable of type CountryRepo
OUTPUT:1 if the country was succesfull added,0 -otherwise
---------------------------------------------------------------
*/
int addCountry(Country* c,CountryRepo* repo);
/*
----------------------------------------------------------------
This function deletes a country from the repository
INPUT:A variable of type CoiuntryRepo,a variable of type char
OUTPUT:-----
---------------------------------------------------------------
*/
void deleteCountry(CountryRepo* repo,char* name);

/*
--------------------------------------------------------------------------------
This function searches for a country in the repository by name
INPUT:a variable of type CountryREPo,a variable of type char
OUTPUT:the index of the country if the country is in the repository, -1 otherwise
---------------------------------------------------------------------------------
*/
int findCountry(CountryRepo* repo,char* name);
/*
------------------------------------------------------------------------------
This function updates the informations about a country
INPUT:a variable of type Country and a variable of type COuntryREpo
OUTPUT:1 if the update was succesfull , 0 - otherwise
------------------------------------------------------------------------------
*/
int updateCountry(Country* c,CountryRepo* repo);
/*
---------------------------------------------------------------------------------
THis function calculates the population of two countries after migration
INPUT:a variable of type COuntryREPO,two variables of type integer,a long long variable
OUTPUT:1 if the migration was succesfull,0 - otherwise
-----------------------------------------------------------------------------------
*/
int migrationCountry(CountryRepo* repo,int index1,int index2,long long nr);
/*
-----------------------------------------------------------------------------------
This function gets all the countries who have in their name a given substring
INPUT:a variable of type CountryREpo,a variable of type char
OUTPUT:----
-----------------------------------------------------------------------------------
*/
CountryRepo getContain(CountryRepo* repo, char* substring);
/*
-----------------------------------------------------------------------------------
This function gets all countries from a certain continent and sorts them by name
INPUT:a variable of CountryRepo,a variable of type char
OUTPUT:-----
-----------------------------------------------------------------------------------
*/
CountryRepo getByContinent(CountryRepo* repo,char* continent);

/*
-------------------------------------------------------------------------------------------------------------------------------------
This function gets all the countries from a continent which have a population greater than a given value and sorts them by population
INPUT:a variable of type CountryRepo,a variable of type char,a variable of type long long
OUTPUT:-----
--------------------------------------------------------------------------------------------------------------------------------------
*/
CountryRepo getByContinentPopulation(CountryRepo* repo,char* continent,long long nr);

void testCountryRepo();

#endif
