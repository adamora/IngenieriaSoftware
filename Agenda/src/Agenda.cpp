//============================================================================
// Name        : Agenda.cpp
// Author      : Adam
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Agenda.h"
#include <fstream>
#include <cassert>

namespace Dentista{

Contacto& Agenda::operator [] (int i)
{
	assert(i>=0 && i<_numPacientes);
	return _pacientes[i];
}

Agenda& Agenda::operator = (Agenda &agenda)
{
	int i;

	if(_pacientes!=NULL)
		delete[] _pacientes;

	_numPacientes=agenda._numPacientes;
	_pacientes=new Contacto[_numPacientes];

	for(i=0;i<_numPacientes;i++){
		_pacientes[i]=agenda._pacientes[i];
	}
	return *this;
}

void Agenda::insertarPaciente(const Contacto &paciente)
{
	int i;
	int	num=this->getNumPacientes();
	num++;
	this->setNumPacientes(num);


	Contacto* pacientes=new Contacto[num];

	for(i=0;i<num;i++)
	{
		if(i==num-1){
			pacientes[i]=paciente;
		}else{
			pacientes[i]=_pacientes[i];
		}
	}


	delete[] _pacientes;
	_pacientes=new Contacto[_numPacientes];

	for(i=0;i<_numPacientes;i++){
		_pacientes[i]=pacientes[i];
	}
	delete[] pacientes;
}

bool Agenda::buscarPaciente(const string dni)
{
	int num=getNumPacientes();
	if(num <= 0)
	{
		return false;
	}
	else{
		int i;

		for(i=0;i<getNumPacientes();i++)
		{
			if(_pacientes[i].getDNI()==dni)
			{
				return true;
			}
		}
		return false;
	}
}

Contacto& Agenda::visualizarPaciente(const string dni)
{
	int i;

	for(i=0;i<this->getNumPacientes();i++)
	{
		if(_pacientes[i].getDNI()==dni)
		{
			return _pacientes[i];
		}
	}
}

void Agenda::eliminarPaciente(string dni)
{
	int i,j=0;
	Contacto* auxiliar=new Contacto[getNumPacientes()-1];

	for(i=0;i<this->getNumPacientes();i++)
	{
		if(_pacientes[i].getDNI()!=dni)
		{
			auxiliar[j]=_pacientes[i];
			j++;
		}
	}

	int num=this->getNumPacientes()-1;
	this->setNumPacientes(num);

	delete[] _pacientes;
	_pacientes=new Contacto[_numPacientes];

	for(i=0;i<_numPacientes;i++){
		_pacientes[i]=auxiliar[i];
	}
	delete[] auxiliar;
}

void Agenda::verFavoritos()
{
	int i,contador=0;
	for(i=0;i<this->getNumPacientes();i++)
	{
		if(_pacientes[i].getFavorito()==true)
		{
			cout << "El paciente: " << _pacientes[i].getNombre() << " es favorito\n";
			contador++;
		}
	}
	if(contador==0)
	{
		cout << "No hay pacientes favoritos\n";
	}
}

}

