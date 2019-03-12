#ifndef DOMAIN
#define DOMAIN

typedef struct 
{
	char name[50];
	char continent[15];
	long long population;
}Country;

Country create_country(char name[],char continent[],long long population);
char* get_name(Country* c);
char* get_continent(Country* c);
long long get_population(Country* c);

#endif