Algoritmo calculadora
	Definir operacion Como Cadena
	Definir primerNumero, segundoNumero, resultado Como Real
	Escribir 'Ingrese la operaci�n (+, -, *, /):'
	Leer operacion
	Escribir 'Ingrese el primer n�mero:'
	Leer primerNumero
	Escribir 'Ingrese el segundo n�mero:'
	Leer segundoNumero
	Seg�n operacion Hacer
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
				Escribir 'Error: Divisi�n por cero no permitida.'
			FinSi
		De Otro Modo:
			Escribir 'Operaci�n no v�lida.'
	FinSeg�n
FinAlgoritmo
