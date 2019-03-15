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

/*
Prints the menu
*/
void printMenu()
{
    printf("1. Get the firs n pairs of twin numbers\n");
    printf("2. Get the longest sequence of decreasing  numbers\n");
    printf("3.Print the first 8 numbers with the property\n");
    printf("0.Exit\n");
}
/*
Checks if the given command is valid
*/
int validCommand(int command)
{
    if (command < 0 || command > 3) return 0;
    return 1;
}
/*
Checks if a number is prime
Input:nr - natural number
Output:1 if the number is prime
        0 otherwise
*/
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
/*
Computes the first n pairs of twin numbers
Input:n - natural number, v - a vector of twin numbers
Output: ---
*/
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
/*
Print the first n pairs of twin numbers
*/
void printPairs(int n, twin v[])
{
    for(int i = 0; i < n; ++i)
        printf("%d %d \n",v[i].first,v[i].second);
}
/*
Reads a sequence of numbers until 0 is introduced and puts it into a vec type
Input:----
Output: v -vector
*/
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
/*
Gets the longest subsequence of decresing contigous numbers
Input:v - vec , start- a natural number(pointer),end - a natural number(pointer)
Output:---
*/
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
/*
Prints the longest sequence
*/
void printSequence(vec v,int start,int end)
{
    for(int i = start; i <= end; ++i)
        printf("%d\n",v.arr[i]);
}

int gcd(int a,int b)
{
    int c;
    while(a!=b)
    {
        if (a > b) a = a - b;
        else b = b - a;
    }
    return a;
}

void getNumbers()
{
    int nr = 3;
    int cnt = 1;
    vec v;
    v.length = 0;
    while(cnt <= 8)
    {
        int ok = 1;
        for(int i = 2; i < nr; ++i)
        {
            if (gcd(nr,i) == 1)
            {
                if (isPrime(i) == 0) ok = 0;
            }
        
        }
        
        if (ok == 1) 
        {
            printf("%d\n",nr);
            ++cnt;
        }
        ++nr;
    }

}

void printNumbers(vec v)
{
    for(int i = 0; i < v.length; ++i)
    {
        printf("%d",v.arr[i]);
    }
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
            case 3:
            {
                getNumbers();
                break;
            }
        }
    }
    return 0;
}
