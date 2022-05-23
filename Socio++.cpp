/*
 * Socio++.cpp
 *
 *  Created on: 23 may 2022
 *      Author: Unai
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Socio++.h"

using namespace std;

namespace soc
{
	Socio::Socio()
	{
	nombre = "Unai";
	apellido = "Fernandez";
	DNI = "98234798D";
	correo = "unaifj@opendeuesto.es";
	residencia = "Avenida San Adrian";
	codigoPostal = "48003";
	}

	Socio::Socio(string nombre, string apellido, string DNI, string correo, string residencia, string codigoPostal)
	{
		this->nombre = nombre;
		this->apellido = apellido;
		this->DNI = DNI;
		this->correo = correo;
		this->residencia = residencia;
		this->codigoPostal = codigoPostal;
	}

	Socio::~Socio()
	{

	}

	string Socio::getNombre()
	{
		return nombre;
	}
	void Socio::setNombre(string nombre)
	{
		this->nombre = nombre;
	}
	string Socio::getApellido()
	{
		return apellido;
	}
	void Socio::setApellido(string apellido)
	{
		this->apellido = apellido;
	}
	string Socio::getDNI()
	{
		return DNI;
	}
	void Socio::setDNI(string DNI)
	{
		this->DNI = DNI;
	}
	string Socio::getCorreo()
	{
		return correo;
	}
	void Socio::setCorreo(string correo)
	{
		this->correo = correo;
	}
	string Socio::getResidencia()
	{
		return residencia;
	}
	void Socio::setResidencia(string residencia)
	{
		this->residencia = residencia;
	}
	string Socio::getCodigoPostal()
	{
		return codigoPostal;
	}
	void Socio::setCodigoPostal(string codigoPostal)
	{
		this->codigoPostal = codigoPostal;
	}

	void imprimirSocio(Socio* s, int tam)
	{
		int i;
		for (i = 0; i < tam; i++){
		cout << "Nombre: " << s[i].getNombre() << endl;
		cout << "Apellido: " << s[i].getApellido() << endl;
		cout << "DNI: " << s[i].getDNI() << endl;
		cout << "Correo: " << s[i].getCorreo() << endl;
		cout << "Residencia: " << s[i].getResidencia() << endl;
		cout << "Codigo Postal: " << s[i].getCodigoPostal() << endl;
		}
	}
}
