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

		//_numPacientes=agenda._numPacientes;
		setNumPacientes(agenda.getNumPacientes());
		_pacientes=new Contacto[getNumPacientes()];

		for(i=0;i<getNumPacientes();i++){
			_pacientes[i]=agenda._pacientes[i];
		}
		return *this;
	}

	void Agenda::insertarPaciente(Contacto &paciente)
	{
		if(this->buscarPaciente(paciente.getDNI()) == true)
		{
			cout << "No se ha agregado nuevo contacto. DNI introducido, coincide\n";
		}
		else{
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
					_pacientes[i].setContadorAcceso(_pacientes[i].getContadorAcceso()+1);
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
		return _pacientes[i];
	}

	void Agenda::eliminarPaciente(string dni)
	{
		int i,j=0;
		Contacto* auxiliar;
		if(getNumPacientes()==1)
		{
			setNumPacientes(0);
			delete[] _pacientes;
			_pacientes=NULL;
		}
		else
		{
			auxiliar=new Contacto[getNumPacientes()-1];

			for(i=0;i<this->getNumPacientes();i++)
			{
				if(_pacientes[i].getDNI()!=dni)
				{
					auxiliar[j]=_pacientes[i];
					j++;
				}
			}

			int num=(getNumPacientes()-1);
			setNumPacientes(num);

			delete[] _pacientes;
			_pacientes=new Contacto[_numPacientes];

			for(i=0;i<_numPacientes;i++){
				_pacientes[i]=auxiliar[i];
			}
			delete[] auxiliar;
		}
	}

	void Agenda::verFavoritos()
	{
		int i,contador=0;
		for(i=0;i<this->getNumPacientes();i++)
		{
			if(_pacientes[i].getFavorito()==true)
			{
				cout << "El paciente: " << _pacientes[i].getNombre() << " " << _pacientes[i].getApellidos() <<" con DNI: " << _pacientes[i].getDNI() << ", es favorito\n";
				contador++;
			}
		}
		if(contador==0)
		{
			cout << "No hay pacientes favoritos\n";
		}
	}

	void Agenda::verMasUsados()
	{
		int i,contador=0;
		Contacto *c=new Contacto[this->getNumPacientes()];
		for(i=0;i<this->getNumPacientes();i++)
		{
			if(_pacientes[i].getContadorAcceso()>=1)
			{
				//cout << "El paciente: " << _pacientes[i].getNombre() << " " << _pacientes[i].getApellidos() <<" con DNI: " << _pacientes[i].getDNI() << ", es frecuente\n";
				c[contador]=_pacientes[i];
				contador++;
			}
		}
		if(contador==0)
		{
			cout << "No hay pacientes frecuentes\n";
		}
		else
		{
			Contacto aux;
			int j=0;

			for(i=0; i<contador-1; i++)
			{
				for(j=i+1;j<contador; j++)
				{
					if(c[j].getContadorAcceso()>c[i].getContadorAcceso())
					{
						aux=c[i];
						c[i]=c[j];
						c[j]=aux;
					}
				}
			}

			for(i=0;i<contador;i++)
			{
				if(i<5)
				{
					cout << "El paciente: " << c[i].getNombre() << " " << c[i].getApellidos() <<" con DNI: " << c[i].getDNI() << ", es frecuente\n";
				}
			}
		}
	}

	void Agenda::modificarPaciente(string dni, Contacto paciente)
	{
		int i;
		for(i=0;i<this->getNumPacientes();i++)
		{
			if(dni==this->_pacientes[i].getDNI())
			{
				_pacientes[i]=paciente;
				break;
			}
		}
	}

	void Agenda::borrarAgenda()
	{
		if(_pacientes!=NULL){
			delete[]_pacientes;
		}
		_pacientes=NULL;
		_numPacientes=0;
	}

}
