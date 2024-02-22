

void redimensionar(usuario *&usus, int &longitud)
{
    longitud = longitud + 5;
    std::cout<<"\nEntro\n";
    usuario *aux = new usuario[longitud];
    std::cout<<"\nEntro\n";
    #pragma omp parallel for shared(aux, longitud)
        for(int i=longitud - 5 ;i<longitud;++i)
        {
            std::cout<<"\nEntro\n";
            aux[i].nombre = "zzzzzzzzzzzzzzzzzzzzzzz";
            aux[i].celular = 99999999999;
            aux[i].contrasenia = "zzzzzzzzzzzzzzzzzzz";
        }
    #pragma omp parallel for shared(aux,usus, longitud)
        for(int i = 0; i < longitud - 5 ; i++)
        {
            aux[i] = usus[i];
        }

    delete[] usus;

    usus = aux;
}
