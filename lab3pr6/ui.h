#ifndef UI
#define UI

#include "controller.h"

typedef struct 
{
	controller newUi;
}ui;


void uiInitSetUp(ui **worldUi);
void uiGetAllCountries(ui *worldUi);
void uiAddCountry(ui *worldUi, char name[],char continent,long long population);
void uiDeleteCountry(ui *worldUi,int index);
void uiUpdateCountry(ui *worldUi,int index,char name[],char continent[], long long population);
void uiMigration(ui *worldUi,int index1,int index2,long long nr);
void printMenu();
int validCommand();
void runApplication();


#endif