#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UI.h"


UI* createUI(Controller* c)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = c;
	return ui;
}

void destroyUI(UI* ui)
{
	destroyController(ui->ctrl);
	free(ui);
}


int addCountryUI(UI* ui,char* name,char* continent,long long population)
{
	return addCountryController(ui -> ctrl,name,continent,population);
}

int deleteCountryUI(UI* ui,char* name)
{
	return deleteCountryController(ui -> ctrl,name);
}

int updateCountryUI(UI* ui,char* name,char* continent,long long population)
{
	return updateCountryController(ui -> ctrl,name,continent,population);
}

int migrationCountryUI(UI* ui,int index1,int index2,long long nr)
{
	return migrationCountryController(ui -> ctrl,index1,index2,nr);
}

void getContainUI(UI* ui,char* substring)
{
	CountryRepo result = getContainController(ui -> ctrl,substring);

    for (int i = 0; i < result.length; ++i)
    {
        printf("\tname - %s\n",result.country[i] -> name);
        printf("\tcontinent - %s\n",result.country[i] -> continent);
        printf("\tpopulation - %lli\n",result.country[i] -> population);
    }
}

void getByContinentUI(UI* ui,char* continent)
{
	CountryRepo result = getByContinentController(ui -> ctrl,continent);

    for (int i = 0; i < result.length; ++i)
    {
        printf("\tname - %s\n",result.country[i] -> name);
        printf("\tcontinent - %s\n",result.country[i] -> continent);
        printf("\tpopulation - %lli\n",result.country[i] -> population);
    }
}

void getByContinentPopulationUI(UI* ui,char* continent,long long nr)
{

    CountryRepo result = getByContinentPopulationController(ui -> ctrl,continent,nr);

    for (int i = 0; i < result.length; ++i)
    {
        printf("\tname - %s\n",result.country[i] -> name);
        printf("\tcontinent - %s\n",result.country[i] -> continent);
        printf("\tpopulation - %lli\n",result.country[i] -> population);
    }

}

void listAll(UI* ui)
{
	printAll(ui -> ctrl);
}

void printMenu()
{
	printf("Available options\n");
	printf("0. close the application\n");
	printf("1. get all countries\n");
	printf("2. add new country\n");
	printf("3. delete an existing country\n");
	printf("4. update an existing country\n");
	printf("5. migration towards a country\n");
    printf("6. get all countries whose name contain a given substring\n");
    printf("7. get all countries from a continent and sort them\n");
    printf("8.get all counties from a given continent whose population is greater than a given value and sort them\n");
    printf("9.undo the last operation\n");
    printf("10. redo the last operation\n");
}

int validCommand(int command)
{
    if (command < 0 || command > 10) return 0;
    return 1;
}

void populate(UI* worldUI)
{
    int res;

    res = addCountryController(worldUI -> ctrl,"Romania","Europe",1000000);
    res = addCountryController(worldUI -> ctrl,"Germania","Europe",2000000);
    res = addCountryController(worldUI -> ctrl,"Polonia","Europe",3000000);
    res = addCountryController(worldUI -> ctrl,"Ungaria","Europe",1000000);
    res = addCountryController(worldUI -> ctrl,"Bulgaria","Europe",1000000);
    res = addCountryController(worldUI -> ctrl,"Japonia","Asia",5000000);
    res = addCountryController(worldUI -> ctrl,"Rusia","Asia",2000000);
    res = addCountryController(worldUI -> ctrl,"SUA","NorthAmerica",1000000);
    res = addCountryController(worldUI -> ctrl,"Franta","Europe",1000000);
    res = addCountryController(worldUI -> ctrl,"Spania","Europe",1000000);
}

void undoUI(UI* ui)
{
    int res = undo(ui -> ctrl);
    if (res == 1)
        printf("Undo was successful.\n");
    else
        printf("No more undos to be made.\n");
}

void redoUI(UI* ui,Country* c)
{
    int res = redo(ui -> ctrl,c);

    if (res == 1)
        printf("Redo was successful...\n");
    else
        printf("No more redos to be made...\n");
}

void startUI(UI* worldUI)
{
    populate(worldUI);
	while(1)
    {
        printMenu();
        int command;
        scanf("%d",&command);
        while(validCommand(command)!=1)
        {
            printf("Invalid command.Give another one.\n");
            scanf("%d",&command);
        }

        if (command == 0 ) break;

        switch(command)
        {
            case 1:
            {
            	printf("We are getting all the countries from the repo...\n");
            	listAll(worldUI);
            	break;
            }
            case 2:
            {
            	printf("We are adding a country to the repo...\n");
            	char name[50];
            	char continent[15];
            	long long population;
            	printf("Give a name for the country...\n");
            	scanf("%s",name);
            	printf("Give the continent for the country...\n");
            	scanf("%s",continent);
            	printf("Give the population of the country...\n");
            	scanf("%lli",&population);
            	int res = addCountryUI(worldUI,name,continent,population);
            	if (res == 1)
            	{
            		printf("The country was added...");
            	}
            	else
            	{
            		printf("The country already exists...");
            	}
            	break;
            }
            case 3:
            {
            	char name[50];
            	printf("Give a name for the country you want to delete...\n");
            	scanf("%s",name);
            	int res = deleteCountryUI(worldUI,name);
            	break;
            }
            case 4:
            {
            	char name[50];
            	char continent[15];
            	long long population;
            	printf("Give a name for the country...\n");
            	scanf("%s",name);
            	printf("Give the continent for the country...\n");
            	scanf("%s",continent);
            	printf("Give the population of the country...\n");
            	scanf("%lli",&population);
            	int res = updateCountryUI(worldUI,name,continent,population);
            	if (res == 1)
            	{
            		printf("The country was updated...");
            	}
            	else
            	{
            		printf("Index out of range...");
            	}
            	break;
            }
            case 5:
            {
            	int index1,index2;
            	printf("Give the index from for the migration from a country to another country.Please give different number, do no be equal...\n");
            	scanf("%d%d",&index1,&index2);
            	long long nr;
            	printf("Please tell how many migrate from a country to another...\n");
            	scanf("%lli",&nr);
            	int res = migrationCountryUI(worldUI,index1,index2,nr);
            	if (res == 1)
            	{
            		printf("Migration was succesfull...");
            	}
            	else
            	{
            		printf("Index1 or index2 out of range...");
            	}
            	break;
            }
            case 6:
            {
                char sub[50];
                printf("Give a substring..\n");
                scanf("%s",sub);
                getContainUI(worldUI,sub);
                break;
            }
            case 7:
            {
                char continent[50];
                printf("Give us a continent...\n");
                scanf("%s",continent);
                getByContinentUI(worldUI,continent);
                break;
            }
            case 8:
            {
                char continent[50];
                printf("Give us a continent...\n");
                scanf("%s",continent);
                long long nr;
                printf("Give us a value...\n");
                scanf("%lli",&nr);
                getByContinentPopulationUI(worldUI,continent,nr);
                break;
            }
            case 9:
            {
                undoUI(worldUI);
                break;
            }
            case 10:
            {
                char name[50];
                printf("Give us name of the country...\n");
                scanf("%s",name);
                char continent[50];
                printf("Give us a continent\n");
                scanf("%s",continent);
                long long nr;
                printf("Give us population\n");
                scanf("%lli",&nr);
                Country* c = createCountry(name,continent,nr);
                redoUI(worldUI,c);
                break;
            }
        }
    }
}



