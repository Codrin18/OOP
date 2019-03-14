#ifndef UI
#define UI

#include "controller.h"

typedef struct 
{
	controller *newUI;
}ui;


void uiInitSetUp(ui **worldUi);
void uiGetAllCountries(ui *worldUi);
void uiAddCountry(ui *worldUi, char name[],char continent[],long long population);
void uiDeleteCountry(ui *worldUi,int index);
void uiUpdateCountry(ui *worldUi,int index,char name[],char continent[], long long population);
void uiMigration(ui *worldUi,int index1,int index2,long long nr);
void uiGetAllWhoContain(ui *worldUI,char sub[]);
void printMenu();
int validCommand(int command);
void runApplication();


#endif
