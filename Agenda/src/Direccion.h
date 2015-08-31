/*
 * Direccion.h
 *
 *  Created on: 28 de ago. de 2015
 *      Author: adam
 */

#ifndef DIRECCION_H_
#define DIRECCION_H_

#include <string>

using namespace std;

namespace Dentista {

		class Direccion {
		private:
			string _calle;
			int _numero;
			string _escalera;
			int _piso;
			char _puerta;
			int _cp;
			string _localidad;

		public:
			inline Direccion()
			{
				setCalle("NULL");
				setNumero(-1);
				setEscalera("NULL");
				setPiso(-1);
				setPuerta(' ');
				setCP(0);
				setLocalidad("NULL");

			}

			inline virtual ~Direccion() {};

			inline string getCalle() const {
				return _calle;
			}

			inline void setCalle(const string calle) {
				_calle=calle;
			}

			inline int getNumero() const {
				return _numero;
			}

			inline void setNumero(const int numero) {
				_numero=numero;
			}

			inline string getEscalera() const {
				return _escalera;
			}

			inline void setEscalera(const string escalera) {
				_escalera=escalera;
			}

			inline int getPiso() const {
				return _piso;
			}

			inline void setPiso(const int piso) {
				_piso=piso;
			}

			inline char getPuerta() const {
				return _puerta;
			}

			inline void setPuerta(const char puerta) {
				_puerta=puerta;
			}

			inline int getCP() const {
				return _cp;
			}

			inline void setCP(const int cp) {
				_cp = cp;
			}

			inline string getLocalidad() const {
				return _localidad;
			}

			inline void setLocalidad(const string localidad) {
				_localidad=localidad;
			}

	};

} /* namespace Dentista */

#endif /* DIRECCION_H_ */
