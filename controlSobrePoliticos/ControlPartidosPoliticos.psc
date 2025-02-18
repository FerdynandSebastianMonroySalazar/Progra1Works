Algoritmo ControlPartidosPoliticos
    Definir NUM_CANDIDATOS, NUM_AFILIADOS, NUM_RONDAS Como Entero
    NUM_CANDIDATOS <- 2
    NUM_AFILIADOS <- 50
    NUM_RONDAS <- 5
	
    Dimension candidatos[NUM_CANDIDATOS]
    Dimension votos[NUM_CANDIDATOS, NUM_RONDAS]
	
    Para i <- 1 Hasta NUM_CANDIDATOS Hacer
        Escribir "Ingrese el nombre del candidato ", i, ": "
        Leer candidatos[i]
    FinPara
	
    Repetir
        Para i <- 1 Hasta NUM_CANDIDATOS Hacer
            Para j <- 1 Hasta NUM_RONDAS Hacer
                votos[i, j] <- 0
            FinPara
        FinPara
		
        Para ronda <- 1 Hasta NUM_RONDAS Hacer
            Para afiliado <- 1 Hasta NUM_AFILIADOS Hacer
                voto <- Aleatorio(1, NUM_CANDIDATOS)
                votos[voto, ronda] <- votos[voto, ronda] + 1
            FinPara
        FinPara
		
        Escribir "Resultados de las votaciones:"
        Escribir "Candidato\t"
        Para ronda <- 1 Hasta NUM_RONDAS Hacer
            Escribir "Ronda ", ronda, "\t"
        FinPara
        Escribir ""
		
        Para i <- 1 Hasta NUM_CANDIDATOS Hacer
            Escribir candidatos[i], "\t\t"
            Para ronda <- 1 Hasta NUM_RONDAS Hacer
                Escribir votos[i, ronda], "\t\t"
            FinPara
            Escribir ""
        FinPara
		
        totalVotos1 <- 0
        totalVotos2 <- 0
        Para ronda <- 1 Hasta NUM_RONDAS Hacer
            totalVotos1 <- totalVotos1 + votos[1, ronda]
            totalVotos2 <- totalVotos2 + votos[2, ronda]
        FinPara
		
        Si totalVotos1 > totalVotos2 Entonces
            Escribir "El candidato a la presidencia ganador es: ", candidatos[1], " con ", totalVotos1, " votos."
            Escribir "El candidato con menos votos es: ", candidatos[2], " con ", totalVotos2, " votos."
        Sino
            Escribir "El candidato a la presidencia ganador es: ", candidatos[2], " con ", totalVotos2, " votos."
            Escribir "El candidato con menos votos es: ", candidatos[1], " con ", totalVotos1, " votos."
        FinSi
		
        Escribir "¿Desea realizar otra elección? (s/n): "
        Leer opcion
    Hasta Que opcion = 'n' O opcion = 'N'
FinAlgoritmo
