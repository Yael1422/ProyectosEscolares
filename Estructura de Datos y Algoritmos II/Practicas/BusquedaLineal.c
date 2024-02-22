#include<stdio.h>
#include<stdlib.h>

#define NUM_ELEMS 6

typedef int Item;


main()
{
	Item list[NUM_ELEMS]= {1,3,5,7,11,13};
	Item key=11;

	int i, pos;

	for(i=0; i<NUM_ELEMS; i++)
	{
		if (key==list[i])
		{
			return i;
		}
	}
	return -1;
}
