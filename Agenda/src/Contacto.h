/*
 * Contacto.h
 *
 *  Created on: 13 de ago. de 2015
 *      Author: adam
 */

#ifndef CONTACTO_H_
#define CONTACTO_H_

#include <string>
using namespace std;

namespace Dentista {

	class Contacto {

	private:

		string _nombre;
		string _dni;
		string _apellidos;
		int _telefono1;
		int _telefono2;
		string _correo1;
		string _correo2;
		//direcciones
		string _anotaciones;
		int _contadorAcceso;
		bool _favorito;
		//redesSociales


	public:

		Contacto(){
			setNombre("");
			setDNI("");
			setApellidos("");
			setTel1(0);
			setTel2(0);
			setCorreo1("");
			setCorreo2("");
			//setDirecciones
			setAnotaciones("");
			setContadorAcceso(0);
			setFavorito(false);
			//setRedesSociales
		}

		const string& getNombre() const {
			return _nombre;
		}

		void setNombre(const string& nombre) {
			this->_nombre=nombre;
		}

		const string& getApellidos() const {
			return _apellidos;
		}

		void setApellidos(const string& apellidos) {
			this->_apellidos=apellidos;
		}

		const string& getDNI() const {
			return _dni;
		}

		void setDNI(const string& dni){
			this->_dni=dni;
		}

		const int getTel1() const {
			return _telefono1;
		}

		const int getTel2() const {
			return _telefono2;
		}

		void setTel1(const int telefono) {
			this->_telefono1=telefono;
		}

		void setTel2(const int telefono) {
			this->_telefono2=telefono;
		}

		const string& getCorreo1() const {
			return _correo1;
		}

		const string& getCorreo2() const {
			return _correo2;
		}

		void setCorreo1(const string& correo) {
			this->_correo1=correo;
		}

		void setCorreo2(const string& correo) {
			this->_correo2=correo;
		}

		const string& getAnotaciones() const {
			return _anotaciones;
		}

		void setAnotaciones(const string& anotaciones){
			this->_anotaciones=anotaciones;
		}

		const int getContadorAcceso() const {
			return _contadorAcceso;
		}

		void setContadorAcceso(const int contador){
			this->_contadorAcceso=contador;
		}

		const bool getFavorito() const {
			return _favorito;
		}

		void setFavorito(const bool favorito){
			this->_favorito=favorito;
		}
	};
}




#endif /* CONTACTO_H_ */
