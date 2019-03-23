#include "OperationsStack.h"
#include <stdlib.h>
#include <string.h>

Operation* createOperation(Country* c, char* operationType)
{
	Operation* o = (Operation*)malloc(sizeof(Operation));
	o->country = copyCountry(c);

	if (operationType != NULL)
	{
		o->operationType = (char*)malloc(sizeof(char)*(strlen(operationType) + 1));
		strcpy(o->operationType, operationType);
	}
	else
		o->operationType = NULL;

	return o;
}

void destroyOperation(Operation* o)
{
	destroyCountry(o->country);
	free(o->operationType);

	free(o);
}

Operation* copyOperation(Operation* o)
{
	if (o == NULL)
		return NULL;

	Operation* newOp = createOperation(o->country, o->operationType);
	return newOp;
}

char* getOperationType(Operation* o)
{
	return o->operationType;
}

Country* getPlanet(Operation* o)
{
	return o->country;
}

OperationsStack* createStack()
{
	OperationsStack* s = (OperationsStack*)malloc(sizeof(OperationsStack));
	s->length = 0;

	return s;
}

void destroyStack(OperationsStack* s)
{
	if (s == NULL)
		return;

	for (int i = 0; i < s->length; i++)
	{
		destroyOperation(s->operasions[i]);
	}
	free(s);
}

void push(OperationsStack* s, Operation* o)
{
	if (isFull(s))
		return;

	s->operasions[s->length++] = copyOperation(o);
}

Operation* pop(OperationsStack* s)
{
	if (isEmpty(s))
		return NULL;

	s->length--;
	return s->operasions[s->length];
}

int isEmpty(OperationsStack* s)
{
	return (s->length == 0);
}

int isFull(OperationsStack* s)
{
	return (s->length == 100);
}