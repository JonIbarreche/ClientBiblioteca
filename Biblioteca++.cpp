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

namespace res
{
	Biblioteca::Biblioteca()
		{
		cBiblioteca = 0;
		nombre = "Biblioteca de Deusto";
		aforo = 100;
		estado = "10:00 - 20:00";
		genero = "Docencia";
		instalacion = "Zona estudio";
		barrio = "Deusto";
		}
	Biblioteca::Biblioteca(int cBiblioteca, string nombre, int aforo, string estado, string genero, string instalacion, string barrio)
		{
			this->cBiblioteca = cBiblioteca;
			this->nombre, nombre;
			this->aforo = aforo;
			this->estado, estado;
			this->genero, genero;
			this->instalacion, instalacion;
			this->barrio, barrio;
		}

		//Creo que este destructor hace lo que tiene que hacer, pero no estoy seguro
	Biblioteca::~Biblioteca()
		{

		}

		int Biblioteca::getCBiblioteca()
		{
			return cBiblioteca;
		}
		void Biblioteca::setCBiblioteca(int cBiblioteca)
		{
			this->cBiblioteca = cBiblioteca;
		}
		string Biblioteca::getNombre()
		{
			return nombre;
		}
		void Biblioteca::setNombre(string nombre)
		{
			this->nombre = nombre;
		}
		int Biblioteca::getAforo()
		{
			return aforo;
		}
		void Biblioteca::setAforo(int aforo)
		{
			this->aforo = aforo;
		}
		string Biblioteca::getEstado()
		{
			return estado;
		}
		void Biblioteca::setEstado(string estado)
		{
			this->estado = estado;
		}
		string Biblioteca::getGenero()
		{
			return genero;
		}
		void Biblioteca::setGenero(string genero)
		{
			this->genero = genero;
		}
		string Biblioteca::getInstalacion()
		{
			return instalacion;
		}
		void Biblioteca::setInstalacion(string instalacion)
		{
			this->instalacion = instalacion;
		}
		string Biblioteca::getBarrio()
		{
			return barrio;
		}
		void Biblioteca::setBarrio(string barrio)
		{
			this->barrio, barrio;
		}

		void Biblioteca::imprimirBiblioteca(Biblioteca b)
		{
			cout << "Codigo Biblioteca: " << b.getCBiblioteca() << endl;
			cout << "Nombre Biblioteca: " << b.getNombre() << endl;
			cout << "Aforo: " << b.getAforo() << endl;
			cout << "Horarios: " << b.getEstado() << endl;
			cout << "Genero: " << b.getGenero() << endl;
			cout << "Instalaciones: " << b.getInstalacion() << endl;
			cout << "Barrio: " <<b.getBarrio() << endl;
		}

		void Biblioteca::imprimirBibliotecas(Biblioteca* b, int tam)
		{
			int i;
			for(i = 0; i < tam; ++i){
				cout << "Codigo Biblioteca: " << i+1 << endl;
				cout << "Nombre Biblioteca: " << b[i].getNombre() << endl;
				cout << "Aforo: " << b[i].getAforo() << endl;
				cout << "Horarios: " << b[i].getEstado() << endl;
				cout << "Genero: " << b[i].getGenero() << endl;
				cout << "Instalaciones: " << b[i].getInstalacion() << endl;
				cout << "Barrio: " << b[i].getBarrio() << "\n\n" << endl;
			}

		}
}
