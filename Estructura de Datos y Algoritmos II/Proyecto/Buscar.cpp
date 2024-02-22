int Bbinaria_recursiva(usuario *list, std::string key,  int inf, int sup, int c){
	if(inf==sup || inf>sup){
		return -1;
	}
	//std::cout<<list[c].nombre<<"\n";
	if((list[c].nombre).compare(key)==0){
		return c;
	} else if(strcmp(key.c_str(), (list[c].nombre).c_str())<0){
		c = Bbinaria_recursiva(list, key, inf,c,(c+inf)/2);  			
	} else{
		c = Bbinaria_recursiva(list, key, c+1,sup,(sup+c+1)/2);
	}
	return c;
}