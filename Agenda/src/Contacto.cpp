//============================================================================
// Name        : Contacto.cpp
// Author      : Adam
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Contacto.h"

namespace Dentista{

	Contacto Contacto::operator = (const Contacto &p)
	{
		setNombre(p.getNombre());
		setDNI(p.getDNI());
		setApellidos(p.getApellidos());
		setTel1(p.getTel1());
		setTel2(p.getTel2());
		setCorreo1(p.getCorreo1());
		setCorreo2(p.getCorreo2());
		//setDirecciones
		setAnotaciones(p.getAnotaciones());
		setContadorAcceso(p.getContadorAcceso());
		setFavorito(p.getFavorito());
		//setRedesSociales

		return *this;
	}
}
