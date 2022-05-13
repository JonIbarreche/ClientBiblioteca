#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "UsuarioC++.h"

using namespace std;

namespace login
{
	Usuario::Usuario()
	{
		cUsuario = 0;
		strcpy(email, "mimail@gmail.com");
		strcpy(dni, "12345678A");
		strcpy(password, "miContrasenya");
		strcpy(nombre, "Jon");
		strcpy(apellido, "Ro");
	}

	Usuario::Usuario(int cUsuario, char email[30], char dni[20], char password[30], char nombre[20], char apellido[20])
	{
		this->cUsuario = cUsuario;
		strcpy(this->email, email);
		strcpy(this->dni, dni);
		strcpy(this->password, password);
		strcpy(this->nombre, nombre);
		strcpy(this->apellido, apellido);
	}

	// No se si hay que hacer asi el destructor
	Usuario::~Usuario()
	{
		delete[] email;
		delete[] dni;
		delete[] password;
		delete[] nombre;
		delete[] apellido;
	}

	int Usuario::getCUsuario()
	{
		return cUsuario;
	}
	void Usuario::setCUsuario(int cUsuario)
	{
		this->cUsuario = cUsuario;
	}
	char* Usuario::getEmail()
	{
		return email;
	}
	void Usuario::setEmail(char email[30])
	{
		strcpy(this->email, email);
	}
	char* Usuario::getDni()
	{
		return dni;
	}
	void Usuario::setDni(char dni[20])
	{
		strcpy(this->dni, dni);
	}
	char* Usuario::getPassword()
	{
		return password;
	}
	void Usuario::setPassword(char password[30])
	{
		strcpy(this->password, password);
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

	void Usuario::imprimirUsuario(Usuario r)
	{
		cout << r.getCUsuario() << endl;
		cout << r.getEmail() << endl;
		cout << r.getDni() << endl;
		cout << r.getPassword() << endl;
		cout << r.getNombre() << endl;
		cout << r.getApellido() << endl;
	}
}
