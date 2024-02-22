void swap( usuario * val1, usuario * val2 )
{
	usuario  tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}


void heapify_max( usuario  *list, int tam, int k )
{
	int left = (2*k)+1;
	int rigth = (2*k)+2;
	int largest = 0;

	if((left<tam) && ((list[left].nombre)> (list[k].nombre))){
		largest = left;
	} else {
		largest = k;
	}
	if((rigth<tam)&&((list[rigth].nombre)>(list[largest].nombre))){
		largest = rigth;
	}

	if(largest!=k){
		swap(&list[k],&list[largest]);
		heapify_max(list,tam,largest);
		//print(list, tam, "Cambios heapify: ");
	}
}


void build_max_heap( usuario  *list, int num_elems )
{
	for(int k = (num_elems/2); k>=1;k--){
		heapify_max(list, num_elems, k-1);
		//print(list, num_elems, "Cambios: ");
	}
}


void Heap_Sort( usuario  *list, int num_elems) {

        build_max_heap(list, num_elems);
	    for(int i = num_elems; i>=1; i--){
	            swap(&list[0], &list[i-1]);
  	            heapify_max(list, i-1, 0);
	    }
   	
}