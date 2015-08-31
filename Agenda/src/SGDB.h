/*
 * SGDB.h
 *
 *  Created on: 21 de ago. de 2015
 *      Author: adam
 */

#ifndef SGDB_H_
#define SGDB_H_

#include "Agenda.h"

namespace Dentista{
	class SGDB{
	public:

		virtual ~SGDB(){};

		virtual void guardar(Agenda& pacientes) = 0;

		virtual void cargar(Agenda& agAux) = 0;
	};
}


#endif /* SGDB_H_ */
