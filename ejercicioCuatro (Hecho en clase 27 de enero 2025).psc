Algoritmo ejercicioCuatro
	Escribir 'Ingresar hora del día'
	Definir hora Como Entero
	Leer hora
	Si hora>-1 Y hora<6 Entonces
		Escribir 'Madrugada'
	SiNo
		Si hora>5 Y hora<=12 Entonces
			Escribir 'Mañana'
		SiNo
			Si hora>11 Y hora<14 Entonces
				Escribir 'Medio día'
			SiNo
				Si hora>13 Y hora<20 Entonces
					Escribir 'Tarde'
				SiNo
					Si hora>19 Y hora<24 Entonces
						Escribir 'Noche'
					SiNo
						Escribir 'Error, ingrese un número entre 0 y 23'
					FinSi
				FinSi
			FinSi
		FinSi
	FinSi
FinAlgoritmo
