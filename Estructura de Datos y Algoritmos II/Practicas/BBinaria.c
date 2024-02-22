#include<stdio.h>
#include<stdlib.h>

#define NUM_ELEMS 6

typedef int Item;

BBinaria(Item lista[], Item tam, Item key)
{
    int inf=0;
    int sup=tam-1;
    int c;

    while(inf<=sup)
    {
        c=((sup-inf)/2)+inf;
        if(lista[c]==key)
        {
            return c;
        }
        else if (key<lista[c])
        {
            if(sup==inf)
            {
                sup=c;
                return -1;
            }
        }
        else
        {
            inf=c+1;
        }
    }
}


main()
{
    Item list[NUM_ELEMS]={1,2,9,13,22,29,30,38};
    Item key=30;

    int inf=0;
    int sup=NUM_ELEMS-1;
    int c;

    while(inf<=sup)
    {
        c=((sup-inf)/2)+inf;
        if(list[c]==key)
        {
            return c;
        }
        else if (key<list[c])
        {
            if(sup==inf)
            {
                sup=c;
                return -1;
            }
        }
        else
        {
            inf=c+1;
        }
    }
    //BBinaria(list,NUM_ELEMS,key);

}
