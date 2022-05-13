//BORRAR
#ifndef USUARIOC___H_
#define USUARIOC___H_

namespace login
{
class Usuario
	{
	private:
		int cUsuario;
		char email[30];
		char dni[20];
		char password[30];
		char nombre[20];
		char apellido[20];

	public:
		Usuario();
		Usuario(int cUsuario, char email[30], char dni[20], char password[30], char nombre[20], char apellido[20]);
		~Usuario();

		int getCUsuario();
		void setCUsuario(int cUsuario);
		char* getEmail();
		void setEmail(char email[30]);
		char* getDni();
		void setDni(char dni[20]);
		char* getPassword();
		void setPassword(char password[30]);
		char* getNombre();
		void setNombre(char nombre[20]);
		char* getApellido();
		void setApellido(char apellido[20]);

		void imprimirUsuario(Usuario r);
	};
}

#endif /* USUARIOC___H_ */
