#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int first,second;
}twin;

typedef struct
{
    int length,arr[100];
}vec;


void printMenu()
{
    printf("1. Get the firs n pairs of twin numbers\n");
    printf("2. Get the longest sequence of decreasing  numbers\n");
    printf("0.Exit\n");
}

int validCommand(int command)
{
    if (command < 0 || command > 2) return 0;
    return 1;
}

int isPrime(int nr)
{
    if (nr < 2) return 0;
    if (nr == 2) return 1;
    if (nr % 2 == 0) return 0;
    for(int d = 3; d*d <= nr; d = d + 2)
    {
        if (nr % d == 0) return 0;
    }
    return 1;
}

void getPairs(int n, twin v[])
{
    int count = 0;
    int nr1 = 3, nr2 = 5;
    while(count < n)
    {
        if ((isPrime(nr1)==1) && (isPrime(nr2)==1) && nr2 - nr1 == 2)
        {
            v[count].first = nr1;
            v[count].second = nr2;
            ++count;
            nr1 = nr1 + 2;
            nr2 = nr2 + 2;
        }
        else
        {
            nr1 = nr1 + 2;
            nr2 = nr2 + 2;
        }
        
    }
}

void printPairs(int n, twin v[])
{
    for(int i = 0; i < n; ++i)
        printf("%d%d\n",v[i].first,v[i].second);
}

vec readNumbers()
{
    vec v;
    int nr;
    v.length = 0;
    scanf("%d",&nr);
    while(nr!=0)
    {
        v.arr[v.length] = nr;
        ++v.length;
        scanf("%d",&nr);
    }

    return v;
}

void getSequence(vec v,int *start,int *end)
{
    int count = 1;
    int mx = 1;
    for(int i = 0; i < v.length; ++i)
    {
        if (v.arr[i] > v.arr[i+1]) ++count;
        else
        {
            if (count > mx)
            {
                mx = count;
                *start = i - count + 1;
                *end = i;
                count = 1;
            }
        }
    }
}

void printSequence(vec v,int start,int end)
{
    for(int i = start; i <= end; ++i)
        printf("%d\n",v.arr[i]);
}

int main()
{
    while(1)
    {
        printMenu();
        int command;
        scanf("%d",&command);
        while(validCommand(command)!=1)
        {
            printf("Invalid command.Give another one.");
            scanf("%d",&command);
        }

        if (command == 0 ) break;

        switch(command)
        {
            case 1:
            {
                int n;
                printf("Give the number of pairs");
                scanf("%d",&n);
                twin v[100] = {0};
                getPairs(n,v);
                printPairs(n,v);
                break;
            }
            case 2:
            {
                vec v;
                v = readNumbers();
                int start = 0, end = 0;
                getSequence(v,&start,&end);
                printSequence(v,start,end);
                break;
            }
        }
    }
    return 0;
}
