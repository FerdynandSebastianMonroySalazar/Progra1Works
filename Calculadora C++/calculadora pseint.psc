Algoritmo calculadora
	Definir operacion Como Cadena
	Definir primerNumero, segundoNumero, resultado Como Real
	Escribir 'Ingrese la operación (+, -, *, /):'
	Leer operacion
	Escribir 'Ingrese el primer número:'
	Leer primerNumero
	Escribir 'Ingrese el segundo número:'
	Leer segundoNumero
	Según operacion Hacer
		'+':
			resultado <- primerNumero+segundoNumero
			Escribir 'Resultado: ', resultado
		'-':
			resultado <- primerNumero-segundoNumero
			Escribir 'Resultado: ', resultado
		'*':
			resultado <- primerNumero*segundoNumero
			Escribir 'Resultado: ', resultado
		'/':
			Si segundoNumero<>0 Entonces
				resultado <- primerNumero/segundoNumero
				Escribir 'Resultado: ', resultado
			SiNo
				Escribir 'Error: División por cero no permitida.'
			FinSi
		De Otro Modo:
			Escribir 'Operación no válida.'
	FinSegún
FinAlgoritmo
