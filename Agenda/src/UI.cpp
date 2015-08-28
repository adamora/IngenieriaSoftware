/*
 * UI.cpp
 *
 *  Created on: 24 de ago. de 2015
 *      Author: adam
 */

#include "UI.h"
#include <string>

using namespace std;

namespace Dentista
{
	UI::UI(){

	}

	void introducirDatosContacto(Agenda& agenda){
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
		cin.ignore();
		getline(cin,nombre);
		c.setNombre(nombre);

		cout << "Inserte apellidos: ";
		getline(cin,apellidos);
		c.setApellidos(apellidos);

		cout << "Inserte DNI: ";
		cin >> dni;
		c.setDNI(dni);

		cout << "Inserte Telefono 1: ";
		cin >> tel1;
		c.setTel1(tel1);

		cout << "Inserte Telefono 2: ";
		cin >> tel2;
		c.setTel2(tel2);

		cout << "Inserte Correo 1: ";
		cin >> co1;
		c.setCorreo1(co1);

		cout << "Inserte Correo 2: ";
		cin >> co2;
		c.setCorreo2(co2);

		cout << "Inserte Nota: ";
		cin.ignore();
		getline(cin,nota);
		c.setAnotaciones(nota);

		char respuesta;
		int contador=0;
		string redS;
		string usuRed;
		RedSocial red;

		do{
			if(contador==0)
			{
				cout << "¿Desea agregar una red social? (S/N): ";
				cin >> respuesta;
				contador++;
			}
			else
			{
				cout << "¿Desea agregar otra red social? (S/N): ";
				cin >> respuesta;
			}

			if(respuesta=='S')
			{
				cout << "Introduzca el nombre de la red social: ";
				cin >> redS;
				cout << "Introduzca el nombre de usuario: ";
				cin >> usuRed;

				red.setNombreRed(redS);
				red.setUsuario(usuRed);
				c.insertarRedSocial(red);
			}
			else
			{
				cout << "Operación finalizada\n";
			}

		}while(respuesta=='S');

		agenda.insertarPaciente(c);
	}

	void modificarContacto(Contacto &contacto){
		int opcion;

		string nombre;
		string apellidos;

		string co1;
		string co2;
		string nota;
		int tel1,tel2;
		string redSocial;
		string usuRed;

		cout << "¿Que datos desea modificar?\n1) Nombre\n2) Apellidos\n3) Telefono 1\n4) Telefono 2\n5) Correo 1\n6) Correo 2\n7) Anotaciones\n8) Red Social\nOpcion: ";
		cin >> opcion;
		switch(opcion)
		{
			case 1:
				cout << "Introduzca el nuevo nombre: ";
				cin >> nombre;
				contacto.setNombre(nombre);
				break;
			case 2:
				cout << "Introduzca el nuevo apellido: ";
				cin >> apellidos;
				contacto.setApellidos(apellidos);
				break;
			case 3:
				cout << "Introduzca el nuevo Telefono 1: ";
				cin >> tel1;
				contacto.setTel1(tel1);
				break;
			case 4:
				cout << "Introduzca el nuevo Telefono 2: ";
				cin >> tel2;
				contacto.setTel1(tel2);
				break;
			case 5:
				cout << "Introduzca el nuevo Correo 1: ";
				cin >> co1;
				contacto.setCorreo1(co1);
				break;
			case 6:
				cout << "Introduzca el nuevo Correo 2: ";
				cin >> co2;
				contacto.setCorreo1(co2);
				break;
			case 7:
				cout << "Introduzca nuevas anotaciones: ";
				cin >> nota;
				contacto.setAnotaciones(nota);
				break;
			case 8:
			{
				cout << "Introduzca el nombre de la red social: ";
				cin >> redSocial;
				cout << "Introduzca el nombre de usuario de la red social: ";
				cin >> usuRed;

				RedSocial red;
				red.setNombreRed(redSocial);
				red.setUsuario(usuRed);

				contacto.insertarRedSocial(red);
			}
		}

		cout << "Operación realizada satisfactoriamente\n";
	}

	void visualizarAgenda(Agenda &agenda)//ME HE QUEDADO POR AQUI TRAS INSERTAR RED SOCIAL
	{
		int i;
		int j;
		cout << "Numero de pacientes: " << agenda.getNumPacientes() << "\n";
		for(i=0;i<agenda.getNumPacientes();i++){
			cout << i+1 << ") - Nombre y Apellidos: " << agenda[i].getNombre() << " " << agenda[i].getApellidos() << "; DNI: " << agenda[i].getDNI() << "; Telefono 1: " << agenda[i].getTel1() << "; Telefono 2: " << agenda[i].getTel2() << "; Correo 1: " << agenda[i].getCorreo1() << "; Correo 2: " << agenda[i].getCorreo2() << "; Notas: "<< agenda[i].getAnotaciones() << "; Redes Sociales:";

			if(agenda[i].getNumRedes()==0)
			{
				cout << "Ninguna\n";
			}
			else
			{
				for(j=0;j<agenda[i].getNumRedes();j++)
				{
					cout << " ··· Red Social: " << agenda[i].getRedSocial(j).getNombreRed() << "; Usuario: "<< agenda[i].getRedSocial(j).getUsuario();
				}
			}
			cout << "\n";

		}
		Contacto c;
	}

	void visualizarContacto(Contacto &c)
	{
		cout << "Nombre y apellidos: " << c.getNombre() << " " << c.getApellidos() << "\n";
		cout << "DNI: " << c.getDNI() << "\n";
		cout << "Telefono 1: " << c.getTel1() << "\n";
		cout << "Telefono 2: " << c.getTel2() << "\n";
		cout << "Correo 1: " << c.getCorreo1() << "\n";
		cout << "Correo 2: " << c.getCorreo2() << "\n";
		cout << "Anotaciones: " << c.getAnotaciones() << "\n";
		cout << "Redes Sociales:\n";
		for(int i=0;i<c.getNumRedes();i++)
		{
			cout << "  - Nombre Red: " << c.getRedSocial(i).getNombreRed() << "; Nombre usuario: " << c.getRedSocial(i).getUsuario() << "\n";
		}
	}

	void eliminarContacto(string dni, Agenda &agenda)
	{
		char tecla;
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
	}

	void agregarFavorito(Agenda& agenda, Contacto& c)
	{
		char tecla;

		if(c.getFavorito()==true)
			cout << "AVISO: El contacto introducido se contempla actualmente como favorito\n";
		else
		{
			visualizarContacto(c);
			cout << "Desea modifica el contacto? (S/N): ";
			while(tecla != 'S' && tecla != 'N'){
				cin >> tecla;
			}
			if(tecla=='S')
			{
				agenda.visualizarPaciente(c.getDNI()).setFavorito(true);
				cout << "Operación realizada exitosamente\n";
			}
			else
			{
				cout << "Operación cancelada\n";
			}
		}
	}
}
