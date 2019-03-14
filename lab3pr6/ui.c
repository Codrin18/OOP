#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "controller.h"

void uiInitSetUp(ui **worldUI)
{
	*worldUI = malloc(sizeof(ui));
	controllerInitSetUp(&((*worldUI) -> newUI));
}

void uiGetAllCountries(ui *worldUI)
{
	controllerGetAllCountries(worldUI -> newUI);
}

void uiAddCountry(ui *worldUI, char name[],char continent,long long population)
{
	controllerAddCountry(worldUI -> newUI,name,continent,population);
}

void uiDeleteCountry(ui *worldUI,int index)
{
	controllerDeleteCountry(worldUI -> newUI,index);
}

void uiUpdateCountry(ui *worldUI,int index,char name[],char continent[],long long population)
{
	controllerUpdateCountry(worldUI -> newUI,index,name,continent,population);
}

void uiMigration(ui *worldUI,int index1,int index2,long long nr)
{
	controllerMigration(worldUI -> newUI,index1,index2,nr);
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
}

int validCommand(int command)
{
    if (command < 0 || command > 5) return 0;
    return 1;
}

void runApplication()
{

	ui *worldUI;
	uiInitSetUp(&worldUI);

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
            	printf("We are getting all the countries from the repo...\n")
            	uiGetAllCountries(worldUI);
            	break;
            }
            case 2:
            {
            	printf("We are adding a country to the repo...\n");
            	char name[50];
            	char continent[15];
            	long long population;
            	printf("Give a name for the country...\n");
            	scnaf("%d",name);
            	printf("Give the continent for the country...\n");
            	scanf("%d",continent);
            	printf("Give the population of the country...\n");
            	scanf("%d",&population);
            	uiAddCountry(worldUI,name,continent,population);
            	break;
            }
            case 3:
            {
            	int index;
            	printf("Give an index for the country you want to delete...\n");
            	scanf("%d",&index);
            	uiDeleteCountry(worldUI,index);
            	break;
            }
            case 4:
            {
            	int index;
            	printf("Give an index for the country you want to update...\n");
            	scanf("%d",index);
            	char name[50];
            	char continent[15];
            	long long population;
            	printf("Give a name for the country...\n");
            	scnaf("%d",name);
            	printf("Give the continent for the country...\n");
            	scanf("%d",continent);
            	printf("Give the population of the country...\n");
            	scanf("%d",&population);
            	uiUpdateCountry(worldUI,index,name,continent,population);
            	break;
            }
            case 5:
            {
            	int index1,index2;
            	printf("Give the index from for the migration from a country to another country.Please give different number, do no be equal...\n");
            	scanf("%d%d",&index1,&index2);
            	long long nr;
            	printf("Please tell how many migrate froma country to another...\n");
            	scanf("%d",&nr);
            	uiMigration(worldUI,index1,index2,nr);
            	break;
            }
        }
    }
}