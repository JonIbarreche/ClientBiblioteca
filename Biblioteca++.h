/*
 * Biblioteca++.h
 *
 *  Created on: 13 may 2022
 *      Author: Unai
 */

#ifndef BIBLIOTECA___H_
#define BIBLIOTECA___H_

namespace bi {
class Biblioteca {
private:
	int cBiblioteca;
	char nombre[40];
	int aforo;
	char estado[20];
	char genero[15];
	char instalacion[20];
	char barrio[15];

public:
	Biblioteca();
	Biblioteca(int cBiblioteca, char nombre[40], int aforo, char estado[20], char genero[20], char instalacion[20], char barrio[15]);
	~Biblioteca();

	int getCBiblioteca();
	void setCBiblioteca(int cVuelo);
	char* getNombre();
	void setNombre(char nombre[40]);
	int getAforo();
	void setAforo(int aforo);
	char* getEstado();
	void setEstado(char estado[20]);
	char* getGenero();
	void setGenero(char genero[15]);
	char* getInstalacion();
	void setInstalacion(char instalacion[20]);
	char* getBarrio();
	void setBarrio(char barrio[20]);

	void imprimirBiblioteca(Biblioteca b);
};
}

#endif /* BIBLIOTECA___H_ */
