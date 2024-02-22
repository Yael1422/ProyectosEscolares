import java.util.Hashtable;
import java.util.ArrayList;
import java.util.Scanner;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Enumeration;

public class Practica3
{
	public static void entradaArgs(String[] args)
	{
		//Recibe 3 palabras y las imprime en forma de listado.
		//Es necesario enviarlas desde la consola o el cmd.
		System.out.println(args[0]);
		System.out.println(args[1]);
		System.out.println(args[2]);
	}


	public static void usoArraysList()
	{
		ArrayList<Integer> arreglo = new ArrayList<Integer>();
		arreglo.add(1);  //Agregamos un elemento al array
		arreglo.add(8);
		arreglo.add(5);
		arreglo.add(1,9);  //De igual modo agregamos cada uno, en este caso agregamos dos
		System.out.println("Tamaño del arrayList: " +arreglo.size());  //Imprime el tamaño
		System.out.println("Elemento en la posicion 3: "+arreglo.get(3));  //Imprime la posicion que le indiquemos. Iniciamos en 0
		for(Integer elemento : arreglo) 	//for each
		{
			System.out.println(elemento);  //Imprime cada elemento del array.
		}

	}

	
	public static void usoAL_Math()
	{
		ArrayList<Integer> arreglo1 = new ArrayList<Integer>(); //Creamos array de enteros
		ArrayList<Double> arreglo2 = new ArrayList<Double>();  //Creamos array de dounbles
		ArrayList<Double> arreglo3 = new ArrayList<Double>();	//Creamos array de dounbles
		ArrayList<Float> arreglo4 = new ArrayList<Float>();	  //Creamos array de float
		String cadena1 = "Elementos generados aleatoriamente y almacenados en el ArrayList Integer arreglo1: \n";
		String cadena2 = "Elementos generados mediante la operacion i^2 y almacenados en el ArrayList Double arreglo2: \n";
		String cadena3 = "Elementos generados mediante la operacion sqrt(i) y almacenados en el ArrayList Double arreglo3: \n";
		String cadena4 = "Elementos generados mediante la operacion sqrt(i) y almacenados en el ArrayList Float arreglo3 (moldeado): \n";
		Float numFloat;

		for (int i=0; i<10; i++)
		{
			arreglo1.add(i, (int) (Math.random() * 10));  //Llenamos array con numeros aleatorios entre 0 y 10
			cadena1 += "|"+arreglo1.get(i)+"|";  

			arreglo2.add(i, Math.pow(i, 2.0d));  //Llenamos array con numeros elevados a su misma potencia (decimales)
			cadena2 += "|"+arreglo2.get(i)+"|";

			arreglo3.add(i, Math.sqrt(i));  //Llenamos array con la raiz de cada numero (iniciando en 0 y aumentando de +1)
			cadena3 += "|"+arreglo3.get(i);

			numFloat = new Float(Math.sqrt(i));  //Hacemos variable de manera separada para despues usarla en add()
			arreglo4.add(i, numFloat);  //Llenamos array de la misma manera que el arreglo3 pero con menor cantidad de decimales
			cadena4 += "|"+arreglo4.get(i);
		}
		//Imprimimos cada cadena con sus respectivos resultados
		System.out.println(cadena1);
		System.out.println(cadena2);
		System.out.println(cadena3);
		System.out.println(cadena4);

	}

	
	public static void usoStrings()
	{
		String s1 = "Hola que hace?";  //Creamos cadena
		char[] charArray = new char[5];
		System.out.printf("s1: %s", s1);  //Imprimimos cadena
		//evaluacion del metodo lenght:
		System.out.printf("%nLongitud de s1: %d", s1.length());
		//ciclo para recorrer s1 y revertir sus caracteres:
		System.out.printf("%nLa cadena invertida de s1 es: ");
		for(int k = s1.length() - 1; k >= 0; k--)
			System.out.printf("%c ", s1.charAt(k));
		//Copia de caracteres de String en charArray
		s1.getChars(0,5,charArray,0);
		System.out.printf("%nLos caracteres almacenados en charArray son: ");

		for(char character : charArray)
			System.out.print(character);

		System.out.println();

	}


	public static void Fechas()
	{
		//Lo que hace es imprimir la fecha, hora, dia mes y año en el momento en el que se ejecuta el programa
		Date fecha = new Date();
		System.out.println(fecha.toString());
		SimpleDateFormat formateador = new SimpleDateFormat("dd-MM-yyyy");
		System.out.println(formateador.format(fecha));

		Calendar calendario = Calendar.getInstance();
		String miFecha = "Hoy es día";
		miFecha += calendario.get(Calendar.DAY_OF_MONTH) + "del mes ";
		miFecha += calendario.get(Calendar.MONTH) + 1 + "de ";
		miFecha += calendario.get(Calendar.YEAR);
		System.out.println(miFecha);

	}


	public static void usoHashtable()
	{
		Hashtable<String, Integer>miTabla = new Hashtable<String, Integer>();  //Creamos lista ligada
		//Agregamos elementos a la lista con una "clave" y un numero
		miTabla.put("uno",1);
		miTabla.put("dos",2);
		miTabla.put("cinco",5);

		System.out.println("\nContiene a cuatro? " +miTabla.containsKey("cuatro"));  //Nos ayuda a saber si existe un elemento en la lista

		for(String clave : miTabla.keySet())
		{
			System.out.println(clave+"\n"); //Imprimimos la clave
		}
		for(Integer valor : miTabla.values())
		{
			System.out.println(valor);  //Imprimimos cada valor
		}
	}


	public static void usoHashtable2()
	{
		Hashtable<String, Integer>miTabla = new Hashtable<String, Integer>();
		//Agregamos elementos a la lista con una "clave" y un numero
		miTabla.put("uno",1);
		miTabla.put("dos",2);
		miTabla.put("cinco",5);

		String clave;
		Integer valor;
		Enumeration<String> claves = miTabla.keys();
		//Imprimimos la clave y su valor perteneciente de manera conjunta
		//en lugar de hacerlo por separado como en el usoHashtable()
		while(claves.hasMoreElements())
		{
			clave = claves.nextElement();
			valor = miTabla.get(clave);
			System.out.println("Clave : " + clave + "\tValor : " +valor);
		}
	}


	public static void menu()
	{
		String palabra;
		int estado=0;

		Scanner sc = new Scanner(System.in);
		
		while(estado!=7)  //Repetimos menu
		{
			//Opciones
			System.out.println("Elige la opción que quieres hacer:\n");
			System.out.println("1.- Uso Arreglo\n2.- Uso Matematicas\n3.- Usar una cadena");
			System.out.println("4.- Fechas\n5.- Listas Ligadas(forma1)\n6.- Listas Ligadas(forma2)\n");
			System.out.println("7.- Salir\n");

			estado = sc.nextInt();
			switch(estado)
			{
				case 1:
					usoArraysList();
					break;

				case 2:
					usoAL_Math();
					break;
				
				case 3:
					usoStrings();
					break;
				
				case 4:
					Fechas();
					break;
				
				case 5:
					usoHashtable();
					break;
				
				case 6:
					usoHashtable2();
					break;

				case 7:
					continue;

				default:
					System.out.println("\nLa opcion es erronea\n");
					continue;
			}
			System.out.println("\n");
		}
	}


	public static void main(String[] args)
	{
		entradaArgs(args);
		menu();
	}
}	