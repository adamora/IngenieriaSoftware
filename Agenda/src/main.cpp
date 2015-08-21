/*
 * main.cpp
 *
 *  Created on: 20 de ago. de 2015
 *      Author: adam
 */

#include "Agenda.h"

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

	cout << ">>>>>>>AGREGANDO NUEVO PACIENTE<<<<<<<\n";

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
	cout << "Numero casillas agenda " << agenda.getNumPacientes() << "\n";

	agenda.insertarPaciente(c);
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
		cout << "MENÚ PRINCIPAL\n";
		cout << "1. Ver Agenda Completa\n";
		cout << "2. Insertar Paciente\n";
		cout << "3. Buscar Paciente\n";
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
					cout << i << "Nombre: " << agenda[i].getNombre() << "\n";
				}

				cout << "Presione --intro-- para continuar";
				while(tecla != 'a'){
					cin >> tecla;
				}
				break;

			case 2:

				//system("clear");

				insertarNuevoPaciente(agenda);

				cout << "Presione --intro-- para continuar";
				while(tecla != 'a'){
					cin >> tecla;
				}
				break;

			case 3:
				//system("clear");

				cout << "BUSQUEDA -> Introduzca DNI: ";
				cin >> dni;

				cout << "El contacto se llama: " << agenda.buscarPaciente(dni).getNombre() << "\n";

				cout << "No existe el contacto\n";


				cout << "Presione --intro-- para continuar";
				while(tecla != 'a'){
					cin >> tecla;
				}
				break;

			case 0:
				cout << "Saliendo del programa...\n";
				exit(0);

			default:
				cout << "Opcion incorrecta\n";
				cout << "Presione --intro-- para continuar";
				while(tecla != 'a'){
					cin >> tecla;
				}
				break;
		}

	}while(opcion!=0);

	return 0;
}

