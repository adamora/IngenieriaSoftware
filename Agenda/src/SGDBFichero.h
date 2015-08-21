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

		void guardar(Agenda& agenda){
			int i;
			string fichAux="FichAux.tmp";
			ofstream fich(fichAux.c_str());

			fich.open(fichAux.c_str(),ios::in);
			Contacto* it = agenda.getPacientes();

			Contacto personaAux;
			for(i=0;i<agenda.getNumPacientes();i++)
			{
				personaAux = it[i];
				cout << "DATO: " << personaAux.getNombre() << "\n";
				fich.write(personaAux.getNombre().c_str(),sizeof(char *));
			}

			/*for(i=0;i<agenda.getNumPacientes();i++)
			{
				fich << it[i].getNombre() << it[i].getApellidos() << it[i].getDNI() << it[i].getTel1() << it[i].getTel2() << it[i].getCorreo1() << it[i].getCorreo2() << it[i].getFavorito() << it[i].getAnotaciones() << it[i].getContadorAcceso();
			}*/

			fich.close();

			remove(_fichero.c_str());
			rename(fichAux.c_str(), _fichero.c_str());
		};

		void setFichero(string f) { _fichero = f; }
};

}


#endif /* SGDBFICHERO_H_ */
