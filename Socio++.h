#include <iostream>
#include <string>

using namespace std;

#ifndef SOCIOC___H_
#define SOCIOC___H_

namespace soc
{
class Socio
	{
	private:
		string nombre;
		string apellido;
		string DNI;
		string correo;
		string residencia;
		string codigoPostal;

	public:
		Socio();
		Socio(string nombre, string apellido, string DNI, string correo, string residencia, string codigoPostal);
		~Socio();

		string getNombre();
		void setNombre(string nombre);
		string getApellido();
		void setApellido(string apellido);
		string getDNI();
		void setDNI(string DNI);
		string getCorreo();
		void setCorreo(string correo);
		string getResidencia();
		void setResidencia(string residencia);
		string getCodigoPostal();
		void setCodigoPostal(string codigoPostal);

		void imprimirSocio(Socio* s, int tam);
	};
}

#endif /* SOCIO___H_ */
