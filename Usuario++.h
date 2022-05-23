#include <iostream>
#include <string>

using namespace std;

#ifndef USUARIOC___H_
#define USUARIOC___H_

namespace logIn
{
class Usuario
	{
	private:
		int cUsuario;
		string nombre;
		string apellido;
		string nomUsuario;
		string contrasenya;

	public:
		Usuario();
		Usuario(int cUsuario,  string nombre, string apellido, string contrasenya, string nomUsuario);
		~Usuario();

		int getCUsuario();
		void setCUsuario(int cUsuario);
		string getNombre();
		void setNombre(string nombre);
		string getApellido();
		void setApellido(string apellido);
		string getNomUsuario();
		void setNomUsuario(string nomUsuario);
		string getContrasenya();
		void setContrasenya(string contrasenya);

		void imprimirUsuario(Usuario u);
	};
}

#endif /* USUARIOC___H_ */
