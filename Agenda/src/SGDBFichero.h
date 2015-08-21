/*
 * SGDBFichero.h
 *
 *  Created on: 21 de ago. de 2015
 *      Author: adam
 */

#ifndef SGDBFICHERO_H_
#define SGDBFICHERO_H_

#include<fstream>
#include<iostream>


#include "SGDB.h"


using namespace std;

namespace Dentista{

class SGDBFichero:public SGDB{

	private:

		string _fichero;

	public:
		//SGDBFichero() throw() {}
		inline SGDBFichero(string fichero)
		{
			_fichero=fichero;
		}
		virtual ~SGDBFichero(){};

		void guardar(const Agenda& agenda){
			int i;
			string fichAux="FichAux.tmp";
			ofstream fich(fichAux);

			fich.open(fichAux.c_str(),ios::in);
			Contacto* it = agenda._pacientes;

			for(i=0;i<agenda.getNumPacientes();i++)
			{
				fich << it[i].getNombre() << it[i].getApellidos() << it[i].getDNI() << it[i].getTel1() << it[i].getTel2() << it[i].getCorreo1() << it[i].getCorreo2() << it[i].getFavorito() << it[i].getAnotaciones() << it[i].getContadorAcceso();
			}

			fich.close();

			remove(_fichero.c_str());
			rename(fichAux.c_str(), _fichero.c_str());
		}

		void setFichero(std::string f) { _fichero = f; }
};

}


#endif /* SGDBFICHERO_H_ */
