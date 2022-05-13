/*
 * Biblioteca++.cpp
 *
 *  Created on: 13 may 2022
 *      Author: Unai
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Biblioteca++.h"

using namespace std;

namespace bi
{
	Biblioteca::Biblioteca()
		{
		cBiblioteca = 0;
		strcpy(nombre, "Biblioteca de Deusto");
		aforo = 100;
		strcpy(estado, "10:00 - 20:00");
		strcpy(genero, "Docencia");
		strcpy(instalacion, "Zona fumadores");
		strcpy(barrio, "Deusto");
		}
	Biblioteca::Biblioteca(int cBiblioteca, char nombre[40], int aforo, char estado[20], char genero[15], char instalacion[20], char barrio[15])
		{
			this->cBiblioteca = cBiblioteca;
			strcpy(this->nombre, nombre);
			this->aforo = aforo;
			strcpy(this->estado, estado);
			strcpy(this->genero, genero);
			strcpy(this->instalacion, instalacion);
			strcpy(this->barrio, barrio);
		}

		//Creo que este destructor hace lo que tiene que hacer, pero no estoy seguro
	Biblioteca::~Biblioteca()
		{
			delete[] nombre;
			delete[] estado;
			delete[] genero;
			delete[] instalacion;
			delete[] barrio;
		}

		int Biblioteca::getCBiblioteca()
		{
			return cBiblioteca;
		}
		void Biblioteca::setCBiblioteca(int cBiblioteca)
		{
			this->cBiblioteca = cBiblioteca;
		}
		char* Biblioteca::getNombre()
		{
			return nombre;
		}
		void Biblioteca::setNombre(char nombre[40])
		{
			strcpy(this->nombre, nombre);
		}
		int Biblioteca::getAforo()
		{
			return aforo;
		}
		void Biblioteca::setAforo(int aforo)
		{
			this->aforo = aforo;
		}
		char* Biblioteca::getEstado()
		{
			return estado;
		}
		void Biblioteca::setEstado(char estado[20])
		{
			strcpy(this->estado, estado);
		}
		char* Biblioteca::getGenero()
		{
			return genero;
		}
		void Biblioteca::setGenero(char genero[15])
		{
			strcpy(this->genero, genero);
		}
		char* Biblioteca::getInstalacion()
		{
			return instalacion;
		}
		void Biblioteca::setInstalacion(char instalacion[20])
		{
			strcpy(this->instalacion, instalacion);
		}
		char* Biblioteca::getBarrio()
		{
			return barrio;
		}
		void Biblioteca::setBarrio(char barrio[15])
		{
			strcpy(this->barrio, barrio);
		}

		void Biblioteca::imprimirBiblioteca(Biblioteca b)
		{
			cout << b.getCBiblioteca() << endl;
			cout << b.getNombre() << endl;
			cout << b.getAforo() << endl;
			cout << b.getEstado() << endl;
			cout << b.getGenero() << endl;
			cout << b.getInstalacion() << endl;
			cout << b.getBarrio() << endl;
		}
}
