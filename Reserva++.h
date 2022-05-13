/*
 * Reserva++.h
 *
 *  Created on: 13 may 2022
 *      Author: Unai
 */

#ifndef RESERVAC___H_
#define RESERVAC___H_

namespace res
{
class Reserva
	{
	private:
		int cReserva;
		int cUsuario;
		int cBiblioteca;

	public:
		Reserva();
		Reserva(int cReserva, int cUsuario, int cVuelo);
		~Reserva();

		int getCReserva();
		void setCReserva(int cReserva);
		int getCUsuario();
		void setCUsuario(int cUsuario);
		int getCBiblioteca();
		void setCBiblioteca(int cBiblioteca);

		void imprimirReserva(Reserva r);
	};
}

#endif /* RESERVAC___H_ */
