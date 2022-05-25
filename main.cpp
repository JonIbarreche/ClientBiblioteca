// IMPORTANT: Winsock Library ("ws2_32") should be linked

#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#include <string>
#include "Biblioteca++.h"
#include "Reserva++.h"
#include "Usuario++.h"
#include "Socio++.h"

using namespace std;
using namespace res;
using namespace soc;
using namespace logIn;

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

void menuPrincipal() {
	cout << "\n";
	cout << "|--------------------------------------|" << endl;
	cout << "|          BIBLIOTECAS BILBAO          |" << endl;
	cout << "|--------------------------------------|" << endl;
	cout << "|1. Iniciar Sesion                     |" << endl;
	cout << "|2. Registrarse                        |" << endl;
	cout << "|3. Salir                              |" << endl;
	cout << "|--------------------------------------|" << endl;
	cout << " Opcion: ";
}

void registroSocio(SOCKET s) {
	Socio o;

	string nombre;
	string apellido;
	string DNI;
	string correo;
	string residencia;
	string codigoPostal;

	cout << "Escribe tu nombre:" << endl;
	cin.ignore(1, '\n');
	getline(cin, nombre);
	cout << "Escribe tu apellido:" << endl;
	getline(cin, apellido);
	cout << "Escribe tu NIF:" << endl;
	getline(cin, DNI);
	cout << "Escribe tu correo:" << endl;
	getline(cin, correo);
	cout << "Escribe donde residas:" << endl;
	getline(cin, residencia);
	cout << "Escribe tu codigo postal:" << endl;
	getline(cin, codigoPostal);

	o.setNombre(nombre);
	o.setApellido(apellido);
	o.setDNI(DNI);
	o.setCorreo(correo);
	o.setResidencia(residencia);
	o.setCodigoPostal(codigoPostal);

	char sendBuff[512];

	strcpy(sendBuff, "ANYADIRSOCIO");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, o.getNombre().c_str());
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, o.getApellido().c_str());
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, o.getDNI().c_str());
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, o.getCorreo().c_str());
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, o.getResidencia().c_str());
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, o.getCodigoPostal().c_str());
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "ANYADIRSOCIO-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	cout << "\nRegistro con exito...\n" << endl;
}

void reservarBiblioteca(SOCKET s, int cUsuario) {
	int asiento = 1;
	int tam = 0;
	int aforo;
	int i;
	int op;

	cout << "Biliotecas disponibles en Bilbao: \n" << endl;

	char sendBuff[512], recvBuff[512];
	Biblioteca *bibliotecas = (Biblioteca*) malloc(sizeof(Biblioteca) * 20);
	strcpy(sendBuff, "GETBIBLIOTECAS");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "GETBIBLIOTECAS-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	for (i = 0; i < 50; i++) {
		recv(s, recvBuff, sizeof(recvBuff), 0);

		if (strcmp(recvBuff, "FINBUSCA") == 0) {
			recv(s, recvBuff, sizeof(recvBuff), 0);
			bibliotecas[i].setCBiblioteca(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s1 = recvBuff;
			bibliotecas[i].setNombre(s1);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			bibliotecas[i].setAforo(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s2 = recvBuff;
			bibliotecas[i].setEstado(s2);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s3 = recvBuff;
			bibliotecas[i].setGenero(s3);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s4 = recvBuff;
			bibliotecas[i].setInstalacion(s4);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s5 = recvBuff;
			bibliotecas[i].setBarrio(s5);
		} else if (strcmp(recvBuff, "FINBUSCA-END") == 0) {
			tam = i;
			i = 50;
		}
	}

	bibliotecas[0].Biblioteca::imprimirBibliotecas(bibliotecas, tam);
	cout << "|-----------------------------------------------|" << endl;
	cout << "|  Si no sale la biblioteca que desea pulse 99. |" << endl;
	cout << "|  Si quiere seguir con el proceso pulse 98.    |" << endl;
	cout << "|-----------------------------------------------|" << endl;
	cout << " Que desea: (99/98)" << endl;
	cin >> op;

	if (op == 99) {
		cout << "\nSentimos las molestias." << endl;
	} else if (op == 98) {

		cout << "En que Biblioteca quiere hacer una reserva:" << endl;
		cin >> asiento;

		cout << "\n\t\tLa biblioteca seleccionada dispone de " << bibliotecas[asiento - 1].getAforo() << " asientos." << endl;
		cout << "\nCuantas plazas vas a reservar? (En este momento solo se puede reservar un asiento)" << endl;
		cin >> aforo;

		if (aforo == 1) {
			cout << "\n\t\tGracias por su colaboracion!\n" << endl;
			Reserva r;

			r.setCReserva(1);
			r.setCBiblioteca(bibliotecas[asiento - 1].getAforo());

			char dat1[8], dat2[20], dat3[20];
			sprintf(dat1, "%d", r.getCReserva());
			sprintf(dat2, "%d", r.getCUsuario());
			sprintf(dat3, "%d", r.getCBiblioteca());

			strcpy(sendBuff, "MENOSAFORO");
			send(s, sendBuff, sizeof(sendBuff), 0);
			strcpy(sendBuff, dat1);
			send(s, sendBuff, sizeof(sendBuff), 0);
			strcpy(sendBuff, dat2);
			send(s, sendBuff, sizeof(sendBuff), 0);
			strcpy(sendBuff, dat3);
			send(s, sendBuff, sizeof(sendBuff), 0);
			strcpy(sendBuff, "MENOSAFORO-END");
			send(s, sendBuff, sizeof(sendBuff), 0);

			cout << "\nAsiento reservado correctamente...\n" << endl;

			r.setCBiblioteca(bibliotecas[asiento - 1].getAforo() - 1);
		} else if (aforo > 1) {
			cout << "Lo sentimos, no puede seleccionar mas de 1 asiento en este momento." << endl;
		}
	} else if (op != 99 && op != 98) {
		cout << "\t¡Opcion incorrecta, vuelva a ingresar un numero!" << endl;
	}
	cout << "\n";
}

void menuConsultarReservas(SOCKET s, int cUsuario) {
	char sendBuff[512], recvBuff[512];
	Reserva *reservas = (Reserva*) malloc(sizeof(Reserva) * 50);
	Biblioteca *bibliotecas = (Biblioteca*) malloc(sizeof(Biblioteca) * 50);
	Reserva r;
	Biblioteca b;
	strcpy(sendBuff, "GETRESERVAS");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "GETRESERVAS-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	// RECEIVING response from the server
	int i = 0, tamReservas = 0;
	for (i = 0; i < 50; i++) {
		recv(s, recvBuff, sizeof(recvBuff), 0);

		if (strcmp(recvBuff, "FINRESERVAS")) {
			r.setCReserva(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			r.setCUsuario(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			r.setCBiblioteca(atoi(recvBuff));
			if (r.getCUsuario() == cUsuario) {
				reservas[tamReservas] = r;
				tamReservas++;
			}
		} else {
			i = 50;
		}
	}

	strcpy(sendBuff, "GETBIBLIOTECAS");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "GETBIBLIOTECAS-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	// RECEIVING response from the server
	int j = 0, tamBibliotecas = 0;
	for (j = 0; j < 50; j++) {
		recv(s, recvBuff, sizeof(recvBuff), 0);

		if (strcmp(recvBuff, "FINBUSCA") == 0) {
			recv(s, recvBuff, sizeof(recvBuff), 0);
			bibliotecas[i].setCBiblioteca(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s1 = recvBuff;
			bibliotecas[i].setNombre(s1);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			bibliotecas[i].setAforo(atoi(recvBuff));
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s2 = recvBuff;
			bibliotecas[i].setEstado(s2);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s3 = recvBuff;
			bibliotecas[i].setGenero(s3);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s4 = recvBuff;
			bibliotecas[i].setInstalacion(s4);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s5 = recvBuff;
			bibliotecas[i].setBarrio(s5);

			i = 0;
			for (i = 0; i < tamReservas; i++) {
			bibliotecas[tamBibliotecas] = b;
				tamBibliotecas++;
			}

		} else {
			j = 50;
		}
	}

	cout << "RESERVAS:\n" << endl;

	i = 0, j = 0;
	for (i = 0; i < tamReservas; i++) {
		cout << "Codigo de reserva: " << reservas[i].getCReserva() << endl;
		cout << "Nombre de usuario: " << reservas[i].getCUsuario() << endl;
		cout << "Nombre de biblioteca: " << reservas[i].getCBiblioteca() << endl;

		for (j = 0; j < tamBibliotecas; j++) {
			if (bibliotecas[j].getCBiblioteca() == reservas[i].getCBiblioteca()) {
				cout << "Nombre Biblioteca: " << bibliotecas[i].getNombre() << endl;
				cout << "Aforo: " << bibliotecas[i].getAforo() - 1 << endl;
			}
		}
	}
}

void menuSecundario(SOCKET s, int cUsuario) {
	int op;
	do {
		cout << "|--------------------------------------|" << endl;
		cout << "|          BIBLIOTECAS BILBAO          |" << endl;
		cout << "|--------------------------------------|" << endl;
		cout << "|1. Darse de alta como Socio           |" << endl;
		cout << "|2. Gestionar una reserva              |" << endl;
		cout << "|3. Consultar mis reservas             |" << endl;
		cout << "|4. Salir                              |" << endl;
		cout << "|--------------------------------------|" << endl;
		cout << " Opcion: ";


		cin >> op;
		cout << "\n";
		switch (op) {
		case 1:
			registroSocio(s);
			break;
		case 2:
			reservarBiblioteca(s, cUsuario);
			break;
		case 3:
			menuConsultarReservas(s, cUsuario);
			break;
		case 4:
			cout << "|--------------------------------------|" << endl;
			cout << "|   Esta seguro de cerrar su sesion?   |" << endl;
			cout << "|           (1 = SI. 0 = NO)           |" << endl;
			cout << "|--------------------------------------|" << endl;
			cout << " Opcion: ";
			cin >> op;
			if (op == 0) {

			} else if (op == 1) {
				cout << "Su sesion ha sido finalizada..." << endl;
				exit(0);
			}
			break;
		default:
			cout << "Por favor, seleccione otra opcion." << endl;
			break;
		}
	} while (op != 4);
}

void inicioSesionMenu(SOCKET s) {
	int op;
	string nomUsuario, contrasenya;

	char sendBuff[512], recvBuff[512];
	Usuario *usuarios = (Usuario*) malloc(sizeof(Usuario) * 50);

	strcpy(sendBuff, "GETUSUARIOS");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "GETUSUARIOS-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	// RECEIVING response from the server
	int i = 0;
	for (i = 0; i < 50; i++) {
//		printf("a");
		recv(s, recvBuff, sizeof(recvBuff), 0);
//		printf("b");
//		cout << recvBuff;

		if (strcmp(recvBuff, "USERDATA") == 0) {
//			cout << "h0";
			recv(s, recvBuff, sizeof(recvBuff), 0);
			usuarios[i].setCUsuario(atoi(recvBuff));
//			printf("1");
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s1 = recvBuff;
			usuarios[i].setNombre(s1);
//			printf("2");
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s2 = recvBuff;
			usuarios[i].setApellido(s2);
//			printf("3");
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s3 = recvBuff;
			usuarios[i].setNomUsuario(s3);
//			printf("4");
			recv(s, recvBuff, sizeof(recvBuff), 0);
			string s4 = recvBuff;
			usuarios[i].setContrasenya(s4);
//			printf("5");
			//recv(s, recvBuff, sizeof(recvBuff), 0);
		}
		if (strcmp(recvBuff, "ENDUSERDATA") == 0) {
//			printf("19");
			i = 50;
		}
	}

	cout << "Introduzca su nombre de USUARIO:" << endl;
	cin.ignore(1, '\n');
	getline(cin, nomUsuario);
	cout << "Introduzca su contrasenya:" << endl;
	getline(cin, contrasenya);

	i = 0;
	for (i = 0; i < 50; i++) {
		if (nomUsuario == usuarios[i].getNomUsuario()
				&& contrasenya == usuarios[i].getContrasenya()) {
			cout << "\nDatos correctos. Inicio de sesion...\n" << endl;
			int cUsuario = usuarios[i].getCUsuario();
			i = 51;
			menuSecundario(s, cUsuario);
		}
	}
	if (i == 50) {
		cout << "Datos incorrectos.\n" << endl;
		cout << "|--------------------------------------|" << endl;
		cout << "|      Quiere volver a intentarlo?     |" << endl;
		cout << "|            (1 = SI. 0 = NO)          |" << endl;
		cout << "|--------------------------------------|" << endl;
		cout << " Opcion: ";
		cin >> op;
		if (op == 0) {
			//Va al menu principal
		} else if (op == 1) {
			inicioSesionMenu(s);
		}
	}
}

void registroMenu(SOCKET s) {
	Usuario u;

	string nombre;
	string apellido;
	string nomUsuario;
	string contrasenya;

	cout << "Escribe tu nombre:" << endl;
	cin.ignore(1, '\n');
	getline(cin, nombre);
	cout << "Escribe tu apellido:" << endl;
	getline(cin, apellido);
	cout << "Escribe el nombre de USUARIO que quieras tener:" << endl;
	getline(cin, nomUsuario);
	cout << "Escribe la contrasenya con la que accederas a la sesion:" << endl;
	getline(cin, contrasenya);

	u.setCUsuario(0);
	u.setNombre(nombre);
	u.setApellido(apellido);
	u.setNomUsuario(nomUsuario);
	u.setContrasenya(contrasenya);

	char sendBuff[512];
	char chars[4];
	sprintf(chars, "%d", u.getCUsuario());

	strcpy(sendBuff, "ANYADIRUSUARIO");
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, chars);
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, u.getNombre().c_str());
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, u.getApellido().c_str());
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, u.getNomUsuario().c_str());
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, u.getContrasenya().c_str());
	send(s, sendBuff, sizeof(sendBuff), 0);
	strcpy(sendBuff, "ANYADIRUSUARIO-END");
	send(s, sendBuff, sizeof(sendBuff), 0);

	cout << "\nRegistro con exito...\n" << endl;
}

int main(int argc, char *argv[]) {
	WSADATA wsaData;
	SOCKET s;
	int op;
	struct sockaddr_in server;

	printf("\nInitialising Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		printf("Failed. Error Code : %d", WSAGetLastError());
		return -1;
	}

	printf("Initialised.\n");

	//SOCKET creation
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("Could not create socket : %d", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//CONNECT to remote server
	if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR) {
		printf("Connection error: %d", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return -1;
	}

	printf("Connection stablished with: %s (%d)\n", inet_ntoa(server.sin_addr),
			ntohs(server.sin_port));

	//SEND and RECEIVE data (CLIENT/SERVER PROTOCOL)
	do {
		menuPrincipal();

		cin >> op;
		cout << "\n\n";
		switch (op) {
		case 1:
			inicioSesionMenu(s);
			break;
		case 2:
			registroMenu(s);
			break;
		case 3:
			cout << "Fin del programa..." << endl;
			exit(0);
			break;

		default:
			cout << "Por favor, seleccione otra opcion." << endl;
			menuPrincipal();
			cin >> op;
			cout << "\n";
			break;
		}
	} while (op != '3');

	// CLOSING the socket and cleaning Winsock...
	closesocket(s);
	WSACleanup();

	return 0;
}
