void inicio(usuario *usus,int longitud){
	read_csv( "usuarios", usus, longitud);
}

void fin(usuario *usus, int longitud){
	std::vector<usuario> aux;
	for(int i = 0; i< longitud;i++){
		aux.push_back(usus[i]);
	}
	write_csv( "usuarios", aux);
}