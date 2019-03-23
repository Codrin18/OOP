#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CountryRepository.h"

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

int deleteCountry(CountryRepo* repo,int index)
{
	if (index < 0 || index >= repo -> length)
	{
		return 0;
	}
	else
	{
		while(index < repo -> length)
		{
			repo -> country[index] = repo -> country[index+1];
			++index;
		}
		return 1;
	}
}

int updateCountry(Country* c,CountryRepo* repo,int index)
{
	if (index < 0 || index >= repo -> length)
	{
		return 0;
	}
	else
	{
		repo -> country[index] = copyCountry(c);
		return 1;
	}
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

void getContain(CountryRepo* repo,char* substring)
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

	for (int i = 0; i < index; ++i)
	{
		printf("\tname - %s\n",countries[i] -> name);
		printf("\tcontinent - %s\n",countries[i] -> continent);
		printf("\tpopulation - %lli\n",countries[i] -> population);
	}
}

void getByContinent(CountryRepo* repo,char* continent)
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


    for (int i = 0; i < index; ++i)
    {
        printf("\tname - %s\n",countries[i] -> name);
        printf("\tcontinent - %s\n",countries[i] -> continent);
        printf("\tpopulation - %lli\n",countries[i] -> population);
    }
}