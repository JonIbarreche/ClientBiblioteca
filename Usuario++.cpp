#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Usuario++.h"

using namespace std;

namespace logIn
{
	Usuario::Usuario()
	{
		cUsuario = 0;
		nombre = "Unai";
		apellido = "Fernandez";
		nomUsuario = "Uni";
		contrasenya = "xxx";
	}

	Usuario::Usuario(int cUsuario, string nombre, string apellido, string nomUsuario, string contrasenya)
	{
		this->cUsuario = cUsuario;
		this->nombre = nombre;
		this->apellido = apellido;
		this->nomUsuario = nomUsuario;
		this->contrasenya = contrasenya;
	}

	Usuario::~Usuario()
	{

	}

	int Usuario::getCUsuario()
	{
		return cUsuario;
	}
	void Usuario::setCUsuario(int cUsuario)
	{
		this->cUsuario = cUsuario;
	}
	string Usuario::getNombre()
	{
		return nombre;
	}
	void Usuario::setNombre(string nombre)
	{
		this->nombre = nombre;
	}
	string Usuario::getApellido()
	{
		return apellido;
	}
	void Usuario::setApellido(string apellido)
	{
		this->apellido = apellido;
	}
	string Usuario::getNomUsuario()
	{
		return nomUsuario;
	}
	void Usuario::setNomUsuario(string nomUsuario)
	{
		this->nomUsuario = nomUsuario;
	}
	string Usuario::getContrasenya()
	{
		return contrasenya;
	}
	void Usuario::setContrasenya(string contrasenya)
	{
		this->contrasenya = contrasenya;
	}

	void Usuario::imprimirUsuario(Usuario u)
	{
		cout << u.getCUsuario() << endl;
		cout << u.getNombre() << endl;
		cout << u.getApellido() << endl;
		cout << u.getNomUsuario() << endl;
		cout << u.getContrasenya() << endl;
	}
}

