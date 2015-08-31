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
		setDirecciones(p);
		setNumDirecciones(p.getNumDirecciones());
		setAnotaciones(p.getAnotaciones());
		setContadorAcceso(p.getContadorAcceso());
		setFavorito(p.getFavorito());
		setRedesSociales(p);
		setNumRedes(p.getNumRedes());

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

		if(_redesSociales!=NULL)
			delete[] _redesSociales;
		_redesSociales=new RedSocial[_numRedes];

		for(i=0;i<_numRedes;i++){
			_redesSociales[i]=redes[i];
		}
		delete[] redes;
	}

	void Contacto::setRedesSociales(const Contacto &p)
	{
		delete[] _redesSociales;
		_redesSociales=new RedSocial[p.getNumRedes()];

		if(p._redesSociales == NULL)
		{
			_redesSociales = NULL;
		}
		else
		{
			for(int i=0;i<p.getNumRedes();i++)
			{
				this->insertarRedSocial(p.getRedSocial(i));
			}
		}
	}

	void Contacto::insertarDireccion(const Direccion& direc)
	{
		int i;
		int	num=this->getNumDirecciones();
		num++;
		this->setNumDirecciones(num);

		Direccion* direcciones=new Direccion[num];

		for(i=0;i<num;i++)
		{
			if(i==num-1){

				direcciones[i]=direc;
			}else{
				direcciones[i]=_direcciones[i];
			}
		}

		if(_direcciones!=NULL)
			delete[] _direcciones;

		_direcciones=new Direccion[num];

		for(i=0;i<num;i++){
			_direcciones[i]=direcciones[i];
		}
		delete[] direcciones;
	}

	void Contacto::setDirecciones(const Contacto &p)
	{

		delete []_direcciones;
		_direcciones=new Direccion[p.getNumDirecciones()];

		if(p._direcciones == NULL)
		{
			_direcciones = NULL;
		}
		else
		{
			for(int i=0;i<p.getNumDirecciones();i++)
			{
				this->insertarDireccion(p.getDireccion(i));
			}
		}
	}
}


