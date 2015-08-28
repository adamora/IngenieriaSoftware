/*
 * Contacto_unittest.cpp
 *
 *  Created on: 26 de ago. de 2015
 *      Author: adam
 */

#include "../src/Contacto.h"
#include "../gtest/gtest.h"

using namespace std;
using namespace Dentista;

TEST(Contacto, getYsetNombre){
	Contacto c;
	c.setNombre("Prueba");
	EXPECT_EQ("Prueba", c.getNombre());
}

TEST(CONTACTO, getYsetApellidos){
	Contacto c;
	c.setApellidos("Ambos Apellidos");
	EXPECT_EQ("Ambos Apellidos", c.getApellidos());
}

TEST(Contacto, getYsetDNI){
	Contacto c;
	c.setDNI("56565656A");
	EXPECT_EQ("56565656A", c.getDNI());
}

TEST(Contacto, getYsetTelefonos){
	Contacto c;
	c.setTel1(88889);
	c.setTel2(77778);
	EXPECT_EQ(88889, c.getTel1());
	EXPECT_EQ(77778, c.getTel2());
}

TEST(Contacto, getYsetCorreos){
	Contacto c;
	c.setCorreo1("88889");
	c.setCorreo2("77778");
	EXPECT_EQ("88889", c.getCorreo1());
	EXPECT_EQ("77778", c.getCorreo2());
}

TEST(Contacto, getYsetAnotaciones){
	Contacto c;
	c.setAnotaciones("Esto es una anotacion");
	EXPECT_EQ("Esto es una anotacion", c.getAnotaciones());
}
