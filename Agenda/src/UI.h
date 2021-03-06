/*
 * UI.h
 *
 *  Created on: 24 de ago. de 2015
 *      Author: adam
 */

#ifndef UI_H_
#define UI_H_

#include <iostream>
#include "Agenda.h"

using namespace std;

namespace Dentista
{

	class UI {
	public:
		UI();
		virtual ~UI(){};
	};

	void introducirDatosContacto(Agenda& agenda);
	void modificarContacto(Contacto &contacto);
	void visualizarAgenda(Agenda &agenda);
	void visualizarContacto(Contacto &c);
	void eliminarContacto(string dni, Agenda &agenda);
	void agregarFavorito(Agenda& agenda, Contacto& c);
	void insertarRedes(Contacto& c);
	void insertarDireccion(Contacto& c);

}

#endif /* UI_H_ */
