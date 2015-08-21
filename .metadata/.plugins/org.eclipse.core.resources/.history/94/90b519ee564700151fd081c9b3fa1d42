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

using namespace std;
using namespace Dentista;

Contacto& Agenda::operator [] (int i)
{
	assert(i>=0 && i<_numPacientes);
	return _pacientes[i];
}

void Agenda::insertarPaciente(const Contacto &paciente)
{
	int i;
	int	num=getNumPacientes();
	num++;
	setNumPacientes(num);

	Contacto* pacientes=new Contacto[num];

	for(i=0;i<num;i++)
	{
		if(i==num-1){
			pacientes[i]=paciente;
		}else{
			pacientes[i]=_pacientes[i];
		}
	}

	setPacientes(*pacientes);
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


