/*
 * SGDBFichero.h
 *
 *  Created on: 21 de ago. de 2015
 *      Author: adam
 */

#ifndef SGDBFICHERO_H_
#define SGDBFICHERO_H_

#include <string>
#include <list>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>


#include "SGDB.h"


using namespace std;

namespace Dentista{

class SGDBFichero:public SGDB{

	private:

		string _fichero;

	public:
		SGDBFichero() throw() {}

		SGDBFichero(string fichero) throw ()
		{
			_fichero=fichero;
		}

		virtual ~SGDBFichero(){};

		void setFichero(string f)
		{
			_fichero = f;
		}

		inline string getFichero() const
		{
			return _fichero;
		}

		inline void guardar(Agenda& agenda){
			int i;
			string fichAux="FichAux.tmp";
			ofstream fich(fichAux.c_str(),ios::out);

			//fich.open(fichAux.c_str(),ios::out);

			//Contacto* agenda = agenda.getPacientes();

			//Contacto personaAux;

			for(i=0;i<agenda.getNumPacientes();i++)
			{
				/*personaAux = agenda[i];
				fich.wragendae((char *) (&personaAux), sizeof(Contacto));*/
				fich << agenda[i].getNombre() << endl << agenda[i].getApellidos() << endl << agenda[i].getDNI() << endl << agenda[i].getTel1() << endl << agenda[i].getTel2() << endl << agenda[i].getCorreo1() << endl << agenda[i].getCorreo2() << endl << agenda[i].getFavorito() << endl << agenda[i].getAnotaciones() << endl << agenda[i].getContadorAcceso() << endl;

			}
			fich << endl;
			/*for(i=0;i<agenda.getNumPacientes();i++)
			{
				fich << agenda[i].getNombre() << agenda[i].getApellidos() << agenda[i].getDNI() << agenda[i].getTel1() << agenda[i].getTel2() << agenda[i].getCorreo1() << agenda[i].getCorreo2() << agenda[i].getFavoragendao() << agenda[i].getAnotaciones() << agenda[i].getContadorAcceso();
			}*/

			fich.close();

			remove(_fichero.c_str());
			rename(fichAux.c_str(), _fichero.c_str());
		}

		inline Agenda& cargar(){
			Contacto aux;
			int contador = 0;
			Agenda agAux;

			ifstream fich(this->getFichero().c_str(),ios::in);

			//fich.read((char *) (&aux), sizeof(Contacto));


			string nombre,apellidos,DNI,Correo1,Correo2,Anotaciones;
			int Tel1, Tel2,ContadorAcceso;
			bool Favorito;


			while(!fich.eof())
			{
				fich >> nombre >> apellidos >> DNI >> Tel1 >> Tel2 >> Correo1 >> Correo2 >> Favorito >> Anotaciones >> ContadorAcceso;

				aux.setNombre(nombre);
				aux.setApellidos(apellidos);
				aux.setDNI(DNI);
				aux.setTel1(Tel1);
				aux.setTel2(Tel2);
				aux.setCorreo1(Correo1);
				aux.setCorreo2(Correo2);
				aux.setFavorito(Favorito);
				aux.setAnotaciones(Anotaciones);
				aux.setContadorAcceso(ContadorAcceso);

				agAux.insertarPaciente(aux);
				//fich.read((char*) (&aux), sizeof(Contacto));
				contador++;
			}

			//cout << "EL NOMBRE ES: " << aux.getNombre();
			fich.close();

			agAux.setNumPacientes(contador-1);

			return agAux;
		}

};

}


#endif /* SGDBFICHERO_H_ */