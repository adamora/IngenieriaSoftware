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
	cout << "aqui llega\n";

	Contacto* pacientes=new Contacto[num];
	cout << "reserva bien hecha\n";
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



	cout << "ni de coña\n";
}

Contacto& Agenda::buscarPaciente(const string dni)
{
	Contacto n;
	int num=getNumPacientes();
	if(num <= 0)
	{
		return _pacientes[0];
	}
	else{
		int i;

		for(i=0;i<getNumPacientes();i++)
		{
			if(_pacientes[i].getDNI()==dni)
			{
				return _pacientes[i];
			}
		}
		return _pacientes[0];
	}
}
}

