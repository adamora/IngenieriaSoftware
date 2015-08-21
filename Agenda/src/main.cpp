/*
 * main.cpp
 *
 *  Created on: 20 de ago. de 2015
 *      Author: adam
 */

#include "Agenda.h"
#include "SGDBFichero.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace Dentista;

void insertarNuevoPaciente(Agenda& agenda){
	//system("clear");
	string nombre;
	string apellidos;
	string dni;
	string co1;
	string co2;
	string nota;
	int tel1,tel2;

	Contacto c;


	cout << "Inserte nombre: ";
	cin >> nombre;
	c.setNombre(nombre);

	cout << "Inserte apellidos: ";
	cin >> apellidos;
	c.setApellidos(apellidos);

	cout << "Inserte DNI: ";
	cin >> dni;
	c.setDNI(dni);

	cout << "Inserte Telefono 1:";
	cin >> tel1;
	c.setTel1(tel1);

	cout << "Inserte Telefono 2:";
	cin >> tel2;
	c.setTel2(tel2);

	cout << "Inserte Correo 1:";
	cin >> co1;
	c.setCorreo1(co1);

	cout << "Inserte Correo 2:";
	cin >> co2;
	c.setCorreo2(co2);

	cout << "Inserte Nota:";
	cin >> nota;
	c.setAnotaciones(nota);

	agenda.insertarPaciente(c);
}

void modificarPaciente(string dni,Agenda &agenda){
	int opcion;

	string nombre;
	string apellidos;

	string co1;
	string co2;
	string nota;
	int tel1,tel2;

	cout << "¿Que datos desea modificar?\n1) Nombre\n2) Apellidos\n3) Telefono 1\n4) Telefono 2\n5) Correo 1\n6) Correo 2\n7) Anotaciones\nOpcion: ";
	cin >> opcion;
	switch(opcion)
	{
		case 1:
			cout << "Introduzca el nuevo nombre: ";
			cin >> nombre;
			agenda.visualizarPaciente(dni).setNombre(nombre);
			break;
		case 2:
			cout << "Introduzca el nuevo apellido: ";
			cin >> apellidos;
			agenda.visualizarPaciente(dni).setApellidos(apellidos);
			break;
		case 3:
			cout << "Introduzca el nuevo Telefono 1: ";
			cin >> tel1;
			agenda.visualizarPaciente(dni).setTel1(tel1);
			break;
		case 4:
			cout << "Introduzca el nuevo Telefono 2: ";
			cin >> tel2;
			agenda.visualizarPaciente(dni).setTel1(tel2);
			break;
		case 5:
			cout << "Introduzca el nuevo Correo 1: ";
			cin >> co1;
			agenda.visualizarPaciente(dni).setCorreo1(co1);
			break;
		case 6:
			cout << "Introduzca el nuevo Correo 2: ";
			cin >> co2;
			agenda.visualizarPaciente(dni).setCorreo1(co2);
			break;
		case 7:
			cout << "Introduzca nuevas anotaciones: ";
			cin >> nota;
			agenda.visualizarPaciente(dni).setAnotaciones(nota);
			break;
	}
	cout << "Operación realizada satisfactoriamente\n";
}

int main(void)
{
	Agenda agenda;

	int opcion;
	char tecla;
	string dni;

	do{
		tecla='b';
		//system("clear");
		cout << ">>>>>>>MENÚ PRINCIPAL<<<<<<<\n";
		cout << "1. Ver Agenda Completa\n";
		cout << "2. Insertar Paciente\n";
		cout << "3. Buscar Paciente\n";
		cout << "4. Eliminar Paciente\n";
		cout << "5. Modificar Paciente\n";
		cout << "6. Ver Favoritos\n";
		cout << "7. Agregar Favorito\n";
		cout << "8. Guardar en Fichero\n";
		cout << "0. Salir\n";
		cout << "Opción: ";
		cin >> opcion;
		switch(opcion)
		{
			case 1:
				//system("clear");

				int i;
				cout << "Numero de pacientes: " << agenda.getNumPacientes() << "\n";
				for(i=0;i<agenda.getNumPacientes();i++){
					cout << i+1 << ") - Nombre: " << agenda[i].getNombre() << "\n";
				}

				cout << "Presione --intro-- para continuar";
				while(tecla != '\n'){
					tecla=cin.get();
					tecla=cin.get();
				}
				break;

			case 2:
				//system("clear");
				cout << ">>>>>>>AGREGAR NUEVO PACIENTE<<<<<<<\n";
				insertarNuevoPaciente(agenda);

				cout << "Presione --intro-- para continuar";
				while(tecla != '\n'){
					tecla=cin.get();
					tecla=cin.get();
				}
				break;

			case 3:
				//system("clear");

				cout << ">>>>>>>BUSQUEDA DE PACIENTES<<<<<<<\n";
				cout << "Introduzca DNI: ";
				cin >> dni;

				if(agenda.buscarPaciente(dni)==true)
					cout << "El contacto se llama: " << agenda.visualizarPaciente(dni).getNombre() << "\n";
				else
					cout << "No existe el contacto\n";


				cout << "Presione --intro-- para continuar";
				while(tecla != '\n'){
					tecla=cin.get();
					tecla=cin.get();
				}
				break;

			case 4:
				cout << ">>>>>>>ELIMINAR PACIENTE<<<<<<<\n";
				cout << "Introduzca DNI del contacto que desee eliminar: ";
				cin >> dni;

				if(agenda.buscarPaciente(dni)==true)
				{
					cout << "El contacto se llama: " << agenda.visualizarPaciente(dni).getNombre() << "\n";
					cout << "Desea eliminar al contacto? (S/N): ";
					while(tecla != 'S' && tecla != 'N'){
						cin >> tecla;
					}
					if(tecla=='S')
					{
						agenda.eliminarPaciente(dni);
						cout << "Operación realizada exitosamente\n";
					}
					else
					{
						cout << "Operación cancelada\n";
					}
				}
				else
					cout << "No existe el contacto\n";

				cout << "Presione --intro-- para continuar";
				while(tecla != '\n'){
					tecla=cin.get();
					tecla=cin.get();
				}

				break;

			case 5:
				cout << ">>>>>>>MODIFICAR PACIENTE<<<<<<<\n";
				cout << "Introduzca DNI del contacto que desee modificar: ";
				cin >> dni;

				if(agenda.buscarPaciente(dni)==true)
				{
					cout << "El contacto se llama: " << agenda.visualizarPaciente(dni).getNombre() << "\n";
					cout << "Desea modifica el contacto? (S/N): ";
					while(tecla != 'S' && tecla != 'N'){
						cin >> tecla;
					}
					if(tecla=='S')
					{
						modificarPaciente(dni,agenda);
					}
					else
					{
						cout << "Operación cancelada\n";
					}
				}
				else
					cout << "No existe el contacto\n";

				cout << "Presione --intro-- para continuar";
				while(tecla != '\n'){
					tecla=cin.get();
					tecla=cin.get();
				}

				break;

			case 6:
				cout << ">>>>>>>VER FAVORITOS<<<<<<<\n";
				agenda.verFavoritos();

				cout << "Presione --intro-- para continuar";
				while(tecla != '\n'){
					tecla=cin.get();
					tecla=cin.get();
				}
				break;

			case 7:
				cout << ">>>>>>>AGREGAR FAVORITO<<<<<<<\n";
				cout << "Introduzca DNI del contacto que desee modificar: ";
				cin >> dni;

				if(agenda.buscarPaciente(dni)==true)
				{
					cout << "El contacto se llama: " << agenda.visualizarPaciente(dni).getNombre() << "\n";
					cout << "Desea modifica el contacto? (S/N): ";
					while(tecla != 'S' && tecla != 'N'){
						cin >> tecla;
					}
					if(tecla=='S')
					{
						agenda.visualizarPaciente(dni).setFavorito(true);
						cout << "Operación realizada exitosamente\n";
					}
					else
					{
						cout << "Operación cancelada\n";
					}
				}
				else
					cout << "No existe el contacto\n";

				cout << "Presione --intro-- para continuar";
				while(tecla != '\n'){
					tecla=cin.get();
					tecla=cin.get();
					}
				break;

			case 8:
				cout << ">>>>>>>GENERAR FICHERO<<<<<<<\n";

				string nomFich;
				cout << "Introduzca nombre del fichero: ";
				cin >> nomFich;

				SGDBFichero nuevo(nomFich);
				nuevo.guardar(agenda);

				cout << "Operación realizada exitosamente\n";

				cout << "Presione --intro-- para continuar";
				while(tecla != '\n'){
					tecla=cin.get();
					tecla=cin.get();
					}

				break;
			case 0:
				cout << "Saliendo del programa...\n";
				exit(0);

			default:
				cout << "Opcion incorrecta\n";
				cout << "Presione --intro-- para continuar";
				while(tecla != '\n'){
					tecla=cin.get();
					tecla=cin.get();
				}
				break;
		}

	}while(opcion!=0);

	return 0;
}

