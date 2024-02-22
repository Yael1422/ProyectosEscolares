#include<stdlib.h>
#include<stdio.h>

#include<stdbool.h>
//bool,true,false

#include<iso646.h>
//and,or,not

enum {ASCENDING = 0, DESCENDING = 1};

//(Actividad 3)
typedef int Item;


void Ordenar(Item list[], size_t num_elems, Item direction);
void MergeSort(Item list[], Item aux[], size_t first, size_t last, Item direction);
static void Merge_asc(Item list[], Item aux[], size_t first, size_t mid, size_t last);
static void Merge_desc(Item list[], Item aux[], size_t first, size_t mid, size_t last);

//funcion auxiliar. No es parte del algoritmo
void print(Item list[], size_t num_elems)
{
	for(size_t i=0; i<num_elems; ++i)
	{
		printf("%d, ", list[i]);
	}
	printf("\n");
}

//(Actividad 2)
void MergeSort(Item list[], Item aux[], size_t first, size_t last, Item direction)
{
	if(direction==ASCENDING)
    {
        if(first<last)
		{
			size_t mid=(first+last)/2;
			MergeSort(list,aux,first,mid,ASCENDING);
			MergeSort(list,aux,mid+1,last,ASCENDING);
			Merge_asc(list,aux,first,mid,last);
		}
    }
    else if(direction==DESCENDING)
    {
    	if(first<last)
		{
			size_t mid=(first+last)/2;
			MergeSort(list,aux,first,mid,DESCENDING);
			MergeSort(list,aux,mid+1,last,DESCENDING);
			Merge_desc(list,aux,first,mid,last);
		}
    }
    else
    {
        printf("Error");
    }	
}

void Merge_asc(Item list[],Item aux[], size_t first, size_t mid, size_t last)
{
	size_t x0 = first;
	size_t x1 = mid;
	size_t x2 = mid+1;
	size_t x3 = last;
	size_t index = first;
	
	while((x0<=x1) and (x2<=x3))
	{
		if(list[x0]<list[x2])
		{
			aux[index++] = list[x0++];
		} else
		{
			aux[index++] =list[x2++];
		}
	}
	
	while(x0<=x1)
	{
		aux[index++] =list[x0++];
	}
	
	while(x2<=x3)
	{
		aux[index++] =list[x2++];
	}
	for(size_t i=first; i<=last; ++i)
	{
		list[i] = aux[i];
	}
	
}
//end::Merge

//tag::Merge_Desc (Actividad 1)
void Merge_desc(Item list[],Item aux[], size_t first, size_t mid, size_t last)
{
	size_t x0 = first;
	size_t x1 = mid;
	size_t x2 = mid+1;
	size_t x3 = last;
	size_t index = first;
	
	while((x0<=x1) and (x2<=x3))
	{
		if(list[x0]>list[x2])
		{
			aux[index++] = list[x0++];
		} else
		{
			aux[index++] =list[x2++];
		}
	}
	
	while(x0<=x1)
	{
		aux[index++] =list[x0++];
	}
	
	while(x2<=x3)
	{
		aux[index++] =list[x2++];
	}
	for(size_t i=first; i<=last; ++i)
	{
		list[i] = aux[i];
	}
	
}

void Ordenar(Item list[], size_t num_elems, Item direction)
{
	if(direction==ASCENDING)
    {
        int aux[num_elems];
		//C99 permite declarar el tamaño del arreglo de esta forma
	
		MergeSort(list, aux, 0, num_elems-1, ASCENDING);
    }
    else if(direction==DESCENDING)
    {
        int aux[num_elems];
		//C99 permite declarar el tamaño del arreglo de esta forma
	
		MergeSort(list, aux, 0, num_elems-1, DESCENDING);
    }
    else
    {
        printf("Error");
    }
}

Item main()
{
	Item lista[8]={-12,-8,-3,2,1,5,-4,-20};
	
	print(lista,8);
	
	Ordenar(lista,8,ASCENDING);
	
	print(lista,8);
	
	Ordenar(lista,8,DESCENDING);
	
	print(lista,8);
}
