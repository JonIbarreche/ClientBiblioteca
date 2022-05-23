/*
 * Biblioteca++.h
 *
 *  Created on: 13 may 2022
 *      Author: Unai
 */
#include <iostream>
#include <string>

using namespace std;

#ifndef BIBLIOTECA___H_
#define BIBLIOTECA___H_

namespace res {
class Biblioteca {
private:
	int cBiblioteca;
	string nombre;
	int aforo;
	string estado;
	string genero;
	string instalacion;
	string barrio;

public:
	Biblioteca();
	Biblioteca(int cBiblioteca, string nombre, int aforo, string estado, string genero, string instalacion, string barrio);
	~Biblioteca();

	int getCBiblioteca();
	void setCBiblioteca(int cVuelo);
	string getNombre();
	void setNombre(string nombre);
	int getAforo();
	void setAforo(int aforo);
	string getEstado();
	void setEstado(string estado);
	string getGenero();
	void setGenero(string genero);
	string getInstalacion();
	void setInstalacion(string instalacion);
	string getBarrio();
	void setBarrio(string barrio);

	void imprimirBiblioteca(Biblioteca b);
	void imprimirBibliotecas(Biblioteca* b, int tam);
};
}

#endif /* BIBLIOTECA___H_ */
