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
		setRedesSociales(p);

		return *this;
	}

	void Contacto::insertarRedSocial(const RedSocial& red)
	{
		int i;
		int	num=this->getNumRedes();
		num++;
		this->setNumRedes(num);


		RedSocial* redes=new RedSocial[num];

		for(i=0;i<num;i++)
		{
			if(i==num-1){
				redes[i]=red;
			}else{
				redes[i]=_redesSociales[i];
			}
		}


		delete[] _redesSociales;
		_redesSociales=new RedSocial[_numRedes];

		for(i=0;i<_numRedes;i++){
			_redesSociales[i]=redes[i];
		}
		delete[] redes;
	}

	void Contacto::setRedesSociales(const Contacto &p)
	{
		for(int i=0;i<p.getNumRedes();i++)
		{
			this->insertarRedSocial(p.getRedSocial(i));
		}
	}
}


