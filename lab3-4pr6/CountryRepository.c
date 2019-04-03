#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CountryRepository.h"
#include <assert.h>

CountryRepo* createRepo()
{
	CountryRepo* repo = (CountryRepo*)malloc(sizeof(CountryRepo));
	repo -> length = 0;

	return repo;
}

void destroyRepo(CountryRepo* repo)
{
	for (int i = 0; i < repo -> length; ++i)
		destroyCountry(repo -> country[i]);
	free(repo);
}


int findCountry(CountryRepo* repo,char* name)
{
    for (int i = 0 ; i < repo -> length; ++i)
    {
        if (strcmp(repo -> country[i] -> name,name) == 0)
        {
            return i;
        }
    }
    return -1;
}

int addCountry(Country* c,CountryRepo* repo)
{
	int index = -1;
	for (int i = 0; i < repo -> length; ++i)
	{
		if (strcmp(repo -> country[i] -> name, getName(c)) == 0)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		repo -> country[repo->length++] = copyCountry(c);
		return 1;
	}
	else return 0;
}

void deleteCountry(CountryRepo* repo,char* name)
{
    int index = -1;
    for (int i = 0; i < repo -> length; ++i)
    {
        if (strcmp(repo -> country[i] -> name,name) == 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
        return;

    destroyCountry(repo -> country[index]);

    while(index < repo -> length - 1)
    {
        repo -> country[index] = repo -> country[index+1];
        ++index;
    }
    repo -> length--;

}

int updateCountry(Country* c,CountryRepo* repo)
{

    for (int i = 0; i < repo -> length; ++i)
    {
        if (strcmp(repo -> country[i] -> name, getName(c)) == 0)
        {
            repo -> country[i] = copyCountry(c);
            return 1;
        }
    }
    return 0;

}

int migrationCountry(CountryRepo* repo,int index1,int index2,long long nr)
{
	if (index1 < 0 || index1 >= repo -> length || index2 < 0 || index2 >= repo -> length)
	{
		return 0;
	}
	else
	{
		repo -> country[index1] -> population -= nr;
		repo -> country[index2] -> population += nr;
		return 1;
	}
}

int containsString(char* st1,char* st2)
{
	char *res;
	void *ret;
	ret = NULL;
	res = strstr(st1,st2);
	if (res == ret) return 0;
	return 1;
}

CountryRepo getContain(CountryRepo* repo,char* substring)
{
	Country* countries[100];
	int index = 0;
	for (int i = 0; i < repo -> length; ++i)
	{
		if (containsString(repo -> country[i] -> name, substring) == 1)
		{
			countries[index++] = repo -> country[i];
		}
	}

    CountryRepo result;

    for (int i = 0; i < index; ++i)
    {
        result.country[i] = countries[i];
    }

    result.length = index;

    return result;
}

CountryRepo getByContinent(CountryRepo* repo,char* continent)
{
	Country* countries[100];
    int index = 0;
    for (int i = 0; i < repo -> length; ++i)
    {
        if (strcmp(repo -> country[i] -> continent,continent) == 0)
        {
            countries[index++] = repo -> country[i];
        }
    }

    for (int i = 0; i < index - 1; ++i)
    {
        for (int j = j + 1; j < index; ++j)
        {
            if (strcmp(countries[i] -> name,countries[j] -> name) > 0)
            {
                Country* aux = countries[i];
                countries[i] = countries[j];
                countries[j] = aux;
            }
        }
    }

    CountryRepo result;

    for (int i = 0; i < index; ++i)
    {
        result.country[i] = countries[i];
    }

    result.length = index;

    return result;

}

CountryRepo getByContinentPopulation(CountryRepo* repo,char* continent,long long nr)
{
    Country* countries[100];
    int index = 0;
    for (int i = 0; i < repo -> length; ++i)
    {
        if (strcmp(repo -> country[i] -> continent,continent) == 0 && repo -> country[i] -> population > nr)
        {
            countries[index++] = repo -> country[i];
        }
    }

    for (int i = 0; i < index - 1; ++i)
    {
        for (int j = j + 1; j < index; ++j)
        {
            if (repo -> country[i] -> population > repo -> country[j] -> population)
            {
                Country* aux = countries[i];
                countries[i] = countries[j];
                countries[j] = aux;
            }
        }
    }

    CountryRepo result;

    for (int i = 0; i < index; ++i)
    {
        result.country[i] = countries[i];
    }

    result.length = index;

    return result;
}

//------------------------------Test functions ------------------------------------


void test_Unique_CountryOK()
{
    CountryRepo* repo = createRepo();
    Country* c = createCountry("Romania","Europe",100);

    int res = addCountry(c,repo);

    assert( res == 1);
    assert(repo -> length == 1);
}

void testAdd_DuplicateCountry()
{
    CountryRepo* repo = createRepo();
    Country* c1 = createCountry("Romania","Europe",100);
    Country* c2 = createCountry("Romania","Europe",100000);

    int a = addCountry(c1,repo);

    int res = addCountry(c2,repo);

    assert(res == 0);
}
void testUpdate_CountryOK()
{
    CountryRepo* repo = createRepo();
    Country* c = createCountry("Romania","Europe",100);
    Country* c2 = createCountry("Romania","Europe",100000);
    int a = addCountry(c,repo);
    int res = updateCountry(c2,repo);

    assert(res == 1);
}

void testCountryRepo()
{
    testUpdate_CountryOK();
    test_Unique_CountryOK();
    testAdd_DuplicateCountry();
}
