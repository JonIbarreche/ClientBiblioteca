#ifndef USUARIOC___H_
#define USUARIOC___H_

namespace logIn
{
class Usuario
	{
	private:
		int cUsuario;
		char nombre[20];
		char apellido[20];
		char nomUsuario[20];
		char contrasenya[20];

	public:
		Usuario();
		Usuario(int cUsuario,  char nombre[30], char apellido[20], char contrasenya[20], char nomUsuario[20]);
		~Usuario();

		int getCUsuario();
		void setCUsuario(int cUsuario);
		char* getNombre();
		void setNombre(char nombre[20]);
		char* getApellido();
		void setApellido(char apellido[20]);
		char* getNomUsuario();
		void setNomUsuario(char nomUsuario[20]);
		char* getContrasenya();
		void setContrasenya(char contrasenya[20]);

		void imprimirUsuario(Usuario u);
	};
}

#endif /* USUARIOC___H_ */
