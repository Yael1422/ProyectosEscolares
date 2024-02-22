import java.util.Scanner; //Importacion de la biblioteca Scanner

public class Practica2
{
	public static void main(String[] args)
	{
		//Declaracion de variables
		int n1, n2;
		int i;  //Indice para el recorrido del ciclo for
		int suma=0;
		int mayor,menor;

		//Creacion de un objeto Scanner para capturar desde la ventana de comandos
		Scanner entrada=new Scanner(System.in);
		
		//Pedir datos al usuario
		System.out.println("Por favor introduzca un numero entero");
		n1=entrada.nextInt();
		System.out.println("Introduzca otro numero entero");
		n2=entrada.nextInt();
		
		//Validar cual es el numero mayor o menor
		if(n1>=n2)
		{
			mayor=n1;
			menor=n2;
		}
		else
		{
			mayor=n2;
			menor=n1;
		}
		
		//Hacer un ciclo desde el menor hasta el mayor
		for(i=menor; i<=mayor; i++)
		{
			//Validar si es par para sumarlo
			if(i%2==0)
			{
				suma+=i;
				System.out.println("La suma actual es:" +suma);
			}
		}
		
		//Imprimir el resultado
		System.out.println("La suma de los pares entre " + n1 + " y " + n2 + " es " + suma);
		entrada.close();
	}
}