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
		strcpy(nombre, "Unai");
		strcpy(apellido, "Fernandez");
		strcpy(nomUsuario, "Uni");
		strcpy(contrasenya, "xxx");
	}

	Usuario::Usuario(int cUsuario, char nombre[30], char apellido[20], char nomUsuario[30], char contrasenya[20])
	{
		this->cUsuario = cUsuario;
		strcpy(this->nombre, nombre);
		strcpy(this->apellido, apellido);
		strcpy(this->nomUsuario, nomUsuario);
		strcpy(this->contrasenya, contrasenya);
	}

	Usuario::~Usuario()
	{
		delete[] nombre;
		delete[] apellido;
		delete[] nomUsuario;
		delete[] contrasenya;
	}

	int Usuario::getCUsuario()
	{
		return cUsuario;
	}
	void Usuario::setCUsuario(int cUsuario)
	{
		this->cUsuario = cUsuario;
	}
	char* Usuario::getNombre()
	{
		return nombre;
	}
	void Usuario::setNombre(char nombre[20])
	{
		strcpy(this->nombre, nombre);
	}
	char* Usuario::getApellido()
	{
		return apellido;
	}
	void Usuario::setApellido(char apellido[20])
	{
		strcpy(this->apellido, apellido);
	}
	char* Usuario::getNomUsuario()
	{
		return nomUsuario;
	}
	void Usuario::setNomUsuario(char nomUsuario[30])
	{
		strcpy(this->nomUsuario, nomUsuario);
	}
	char* Usuario::getContrasenya()
	{
		return contrasenya;
	}
	void Usuario::setContrasenya(char contrasenya[20])
	{
		strcpy(this->contrasenya, contrasenya);
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

