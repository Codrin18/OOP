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

int deleteCountryUI(UI* ui,int index)
{
	return deleteCountryController(ui -> ctrl,index);
}

int updateCountryUI(UI* ui,int index,char* name,char* continent,long long population)
{
	return updateCountryController(ui -> ctrl,index,name,continent,population);
}

int migrationCountryUI(UI* ui,int index1,int index2,long long nr)
{
	return migrationCountryController(ui -> ctrl,index1,index2,nr);
}

void getContainUI(UI* ui,char* substring)
{
	getContainController(ui -> ctrl,substring);
}

void getByContinentUI(UI* ui,char* continent)
{
	getByContinentController(ui -> ctrl,continent);
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
}

int validCommand(int command)
{
    if (command < 0 || command > 7) return 0;
    return 1;
}

void startUI(UI* worldUI)
{
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
            	int index;
            	printf("Give an index for the country you want to delete...\n");
            	scanf("%d",&index);
            	int res = deleteCountryUI(worldUI,index);
            	if (res == 1)
            	{
            		printf("The country was deleted...");
            	}
            	else
            	{
            		printf("Index out of range...");
            	}
            	break;
            }
            case 4:
            {
            	int index;
            	printf("Give an index for the country you want to update...\n");
            	scanf("%d",&index);
            	char name[50];
            	char continent[15];
            	long long population;
            	printf("Give a name for the country...\n");
            	scanf("%s",name);
            	printf("Give the continent for the country...\n");
            	scanf("%s",continent);
            	printf("Give the population of the country...\n");
            	scanf("%lli",&population);
            	int res = updateCountryUI(worldUI,index,name,continent,population);
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
        }
    }
}



