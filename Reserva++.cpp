/*
 * Reserva++.cpp
 *
 *  Created on: 13 may 2022
 *      Author: Unai
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Reserva++.h"

using namespace std;

namespace res
{
	Reserva::Reserva()
	{
		cReserva = 0;
		cUsuario = 0;
		cBiblioteca = 0;
	}

	Reserva::Reserva(int cReserva, int cUsuario, int cBiblioteca)
	{
		this->cReserva = cReserva;
		this->cUsuario = cUsuario;
		this->cBiblioteca = cBiblioteca;
	}
	Reserva::~Reserva()
	{

	}

	int Reserva::getCReserva()
	{
		return cReserva;
	}
	void Reserva::setCReserva(int cReserva)
	{
		this->cReserva = cReserva;
	}
	int Reserva::getCUsuario()
	{
		return cUsuario;
	}
	void Reserva::setCUsuario(int cUsuario)
	{
		this->cUsuario = cUsuario;
	}
	int Reserva::getCBiblioteca()
	{
		return cBiblioteca;
	}
	void Reserva::setCBiblioteca(int cBiblioteca)
	{
		this->cBiblioteca = cBiblioteca;
	}

	void imprimirReserva(Reserva r)
	{
		cout << r.getCReserva() << endl;
		cout << r.getCUsuario() << endl;
		cout << r.getCBiblioteca() << endl;
	}
}
