#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Material.h"
#include "Reserva.h"
#include "Fecha.h"
#include "Disco.h"
#include "Libro.h"
#include "Software.h"
using namespace std;
//declaramos variables
int main()
{
	Material *materiales[30];
	Libro libros[30];
	Disco discos[30];
	Software software[30];
	Reserva reservaciones[60];
	string linea, var2 = "";
	int espacio, contador = 0, contF = 0, var1 = 0,x;
  bool verifica = true;
  Fecha fechaConsulta;
//abrir los .txt
	ifstream archEnt("Material.txt");
	ifstream archEnt1("Reserva.txt");
  //leemos lineas del archivo, llena el arreglo de apuntadores de materiales
	while(!archEnt.eof())
	{
		getline(archEnt, linea);
		espacio = linea.find(" ");
		int a = stoi(linea.substr(0, espacio)); 
		linea.erase(0, espacio + 1);
		espacio = linea.find(" ");
		string b = linea.substr(0, espacio);
		linea.erase(0, espacio + 1);
		espacio = linea.find(" ");
		if(linea.substr(0, espacio) == "L")
		{
			linea.erase(0, espacio + 1);
			espacio = linea.find(" ");
			var1 = stoi(linea.substr(0, espacio));
			linea.erase(0, espacio + 1);
			espacio = linea.find(" ");
			var2 = linea.substr(0, espacio);
			Libro lib(a, b, var1, var2);
			libros[contador] = lib;
			materiales[contador] = &libros[contador];
		}
		else if(linea.substr(0, espacio) == "D")
		{
			linea.erase(0, espacio + 1);
			espacio = linea.find(" ");
			var1 = stoi(linea.substr(0, espacio));
			linea.erase(0, espacio + 1);
			espacio = linea.find(" ");
			var2 = linea.substr(0, espacio);
			Disco disc(a, b, var1, var2);
			discos[contador] = disc;
			materiales[contador] = &discos[contador];
		}
		else if(linea.substr(0, espacio) == "S")
		{
			linea.erase(0, espacio + 1);
			espacio = linea.find(" ");
			var1 = stoi(linea.substr(0, espacio));
			linea.erase(0, espacio + 1);
			espacio = linea.find(" ");
			var2 = linea.substr(0, espacio);
			Software sof(a, b, var1, var2);
			software[contador] = sof;
			materiales[contador] = &software[contador];
		}

		contador++;
	}
//leemos lineas y llenamos  el arreglo de reservaciones
	while(!archEnt1.eof())
	{
		getline(archEnt1, linea);
		espacio = linea.find(" ");
		Fecha f;

		int num = 0;
		num = stoi(linea.substr(0, espacio));
		f.setdd(num); //leer id .txt
		linea.erase(0, espacio + 1);
		espacio = linea.find(" ");

		num = stoi(linea.substr(0, espacio));
		f.setmm(num); //leer id .txt
		linea.erase(0, espacio + 1);
		espacio = linea.find(" ");

		num = stoi(linea.substr(0, espacio));
		f.setaa(num); //leer id .txt
		linea.erase(0, espacio + 1);
		espacio = linea.find(" ");

		int id = 0;
		id = stoi(linea.substr(0, espacio));
		linea.erase(0, espacio + 1);
		espacio = linea.find(" ");

		int clien = 0;
		clien = stoi(linea.substr(0, espacio));
		linea.erase(0, espacio + 1);
		espacio = linea.find(" ");

		Reserva res(id, clien, f);

		reservaciones[contF] = res;

		contF++;
	}

	char opcion;
	int i;


	while(opcion != 'f')
	{
		cout << "\n\nElija una opcion:" << endl;
		cout << "a. Consultar la lista de Materiales." << endl;
		cout << "b. Consultar la lista de reservaciones." << endl;
		cout << "c. Consultar las reservsciones de un material dado." << endl;
		cout << "d. Consultar las reservaciones de una fecha dada." << endl;
		cout << "e. Hacer una reservacion." << endl;
		cout << "f. Terminar.\n--> ";
		cin >> opcion;

		switch(opcion)
		{
      //consultar lista
		case'a':
			for(i = 0; i < contador; i++)
			{
				materiales[i]->muestraDatos();
				cout << endl;
			}
			break;

		case 'b':
      //va imprimiendo las resevaciones, y para saber cuando vencen, checa el tipo de material y y dependiendo del material se establecia una fecha de vencimiento
			for(i = 0; i < contF; i++)
			{
				cout << "IdMaterial: " << reservaciones[i].getidMaterial() << "\t IdCliente: " << reservaciones[i].getidCliente()  << "\nInicio: " << reservaciones[i].getfechaReservacion().getdd() << "/" << reservaciones[i].getfechaReservacion().getmm() << "/" << reservaciones[i].getfechaReservacion().getaa();
				for(int j = 0; j < contador; j++)
				{
					if(materiales[j]->getidMaterial() == reservaciones[i].getidMaterial())
					{
						cout << "\tFin: " << reservaciones[i].calculaFechaFinReserva(materiales[j]->cantidadDiasPrestamo()).getdd() << "/" << reservaciones[i].calculaFechaFinReserva(materiales[j]->cantidadDiasPrestamo()).getmm() << "/" << reservaciones[i].calculaFechaFinReserva(materiales[j]->cantidadDiasPrestamo()).getaa() << endl << endl;
					}
				}
			}
			break;

		case'c':
    //ponemos un id, va con cada material guardado y busca el id, ya que lo encuentra imprime el titulo el inicio y fin de reserva, en caso de no encontrarlo vuelve a pedir el id
			int j, pres;
      verifica=true;
			while(verifica)
			{
				cout << "\nIngresa idMaterial -> ";
				cin >> x;
				for(j = 0; j < contador; j++)
				{
					if(materiales[j]->getidMaterial() == x)
					{
						cout << materiales[j]->gettitulo();
						pres = materiales[j]->cantidadDiasPrestamo();
					}
				}
				for(int i = 0; i < contF; i++)
				{
					if(reservaciones[i].getidMaterial() == x)
					{
						verifica = false;
						cout << "\nInicio: " << reservaciones[i].getfechaReservacion().getdd() << "/" << reservaciones[i].getfechaReservacion().getmm() << "/" << reservaciones[i].getfechaReservacion().getaa() << "\tFin: " << reservaciones[i].calculaFechaFinReserva(pres).getdd() << "/" << reservaciones[i].calculaFechaFinReserva(pres).getmm() << "/" << reservaciones[i].calculaFechaFinReserva(pres).getaa() << endl << endl;
					}
				}
			}
			break;

		case'd':
    //se ingresa una fecha, y se pone en un objeto de tipo fecha, con el operador que se sobrecargo se compara si es igual a la de un material reservado
			int dd, mm, aa;
			cout << "\n\nConsulta las reservaciones de una fecha dada." << endl;
			cout << "\nIngrese la fecha cuya reservaciones desea consultar." << endl;
			cout << "Ingrese el dia: ";
			cin >> dd;
			cout << "Ingrese el mes: ";
			cin >> mm;
			cout << "Ingrese el año: " ;
			cin >> aa;

			fechaConsulta.setFecha(dd,mm,aa);
			cout << "\n";

			for (int i = 0; i < contF; i++)
			{
				for (int j = 0; j < contador; j++)
				{
					if (reservaciones[i].getidMaterial() == materiales[j]->getidMaterial())
					{
						if (fechaConsulta == reservaciones[i].getfechaReservacion()| (fechaConsulta > reservaciones[i].getfechaReservacion() && fechaConsulta < reservaciones[i].calculaFechaFinReserva(materiales[j]->cantidadDiasPrestamo())) )
						{
							cout << "El material " << materiales[j]->gettitulo() << " esta reservado por el cliente " << reservaciones[i].getidCliente() << endl;
						}
					}
				}
			}
			cout << "\n\n";
			break;

		case'e':
    //primero te pide tu id de cliente, despues se ingresa el id del material, luego verifica si existe el material, se ingresa la fecha y compara de que no este reservado
			int id;
			cout << "\n\nHacer una reservacion." << endl;
			cout << "\nIngrese su ID: ";
			cin >> x;
			int iVerifica = 0;
			int iReservado = 0;

			do
			{
				cout << "\n\nIngrese el ID del material que desea reservar: ";
				cin >> id;

				for (int j = 0; j < contador; j++)
				{
					if (materiales[j]->getidMaterial() == id)
					{
						iVerifica = 1;

					}
				}

				if (iVerifica == 0)
				{
					cout << "No se encuentra. Intenta otro ID.";
				}

			}
			while (iVerifica == 0);


			do
			{
				cout << "\n\nIngrese la fecha en la que desea reservar el material." << endl;
				cout << "\nIngrese el dia: ";
				cin >> dd;
				cout << "Ingrese el mes: ";
				cin >> mm;
				cout << "Ingrese el año: ";
				cin >> aa;
				Fecha fReserva;

				fReserva.setFecha(dd, mm, aa);


				for (int i = 0; i < contF; i++)
				{

					if (reservaciones[i].getidMaterial() == id)
					{

						for (int j = 0; j < 20 && j < contador; j++)
						{
							if (materiales[j]->getidMaterial() == id)
							{
								if ( (fReserva < reservaciones[i].getfechaReservacion()) | (fReserva > reservaciones[i].calculaFechaFinReserva(materiales[j]->cantidadDiasPrestamo())) )
								{
									iReservado = 1;
								}
							}
						}
					}
				}
				if (iReservado == 0)
				{
					cout << "\nEse material se encuentra reservado en esa fecha." << endl;
				}
				if (iReservado == 1)
				{
					Reserva rNueva(id, x, fReserva);

					if (contF < 50)
					{

						reservaciones[contF] = rNueva;
						cout << "\n\nEl material fue reservado exitosamente\n" << endl;
						contF++;
						contador++;
					}
				}
			}
			while (iReservado == 0);
      break;
		}

  }

  archEnt.close();
	archEnt1.close();

return 0;
}
