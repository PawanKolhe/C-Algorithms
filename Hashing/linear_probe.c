//open addressing

#include<stdio.h>
#include<stdbool.h>

#define M 14

struct Dataitem
{
    int key;
    int value;
} HT[M];


void initialize()
{
    for( int i = 0 ; i<M ; i++)
    {
        HT[i].key = 0;
    }
}

float loadFactor()
{
    int count = 0;
    for(int i = 0 ; i< M ; i++)
    {
        if( HT[i].key != 0)
        {
            count++;
        }
    }
        float d = (float)count/M;
        return (float)d;
}


void insert(int item)
{
    if(loadFactor()==1)
    {
        printf("NO SPACE");
        return;
    }
    int ha = item % M ;

    if(HT[ha].key == 0)
    {
        HT[ha].key = item;
        return;
    }

    int nha = ha+1;
    do
    {
        if(HT[nha].key == 0)
        {
            HT[nha].key = item;
            return;
        }
        else
        {
            ha++;
        }
    }while(nha<M);

    nha = ha-1;
    do
    {
        if(HT[nha].key == 0)
        {
            HT[nha].key = item;
            return;
        }
        else
        {
            ha--;
        }
    }while(nha>=0);
}


bool search(int item)
{
    if(loadFactor()==0)
    {
        printf(" \nNO ELEMENT IN HASHTABLE ");
        return false;
    }
    int ha = item % M ;

    if(HT[ha].key == item)
    {
        printf("TRUE");
        return true;
    }

    int nha = ha+1;
    do
    {
        int k = nha % M;     /////////////////
        if(HT[k].key == item)
        {
            printf("TRUE");
            return true;
        }
        nha++; //////////////////////

    }while(nha<M);

    nha = ha-1;
    do
    {
        int k = nha % M;
        if(HT[k].key == item)
        {
            printf("TRUE");
            return true;
        }
        nha--;

    }while(nha>=0);

    printf("FAIL");
    return false;
}

bool deleted(int item)
{
    if(!loadFactor())
    {
        printf("NO ITEM");
        return false;
    }

    int ha = item % M;

    if( HT[ha].key == item)
    {
        HT[ha].key = 0;
        return true;
    }

    int nha = ha+1;
    do
    {
        int k = nha % M; /////////////
        if( HT[k].key == item)
        {
            HT[k].key = 0;
            return true;
        }
        nha++;
    }while(nha < M);

    nha = ha-1;
    do
    {
        int k = nha % M;  ////////////////
        if( HT[k].key == item )
        {
            HT[k].key = 0;
            return true;
        }
        nha--;
    }while(nha >= 0);

    printf("NOT FOUND");
    return false;
}

void print()
{
    for(int i = 0  ; i< M ; i++)
    {
        printf("%5d" , HT[i].key);
    }
    printf("\n");
}

int main()
{
    insert(11);
    insert(7);
    insert(21);
    print();
   // search(7);
    deleted(21);
    print();
}

