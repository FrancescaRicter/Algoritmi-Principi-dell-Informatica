# Prova Finale Algoritmi e Principi dell'Informatica - Anno Accademico 2021/2022

Obiettivi
• Applicazione pratica delle tecniche apprese nel modulo di algoritmi e strutture dati del corso di 'Algoritmi e Principi dell'Informatica'
• Implementazione di una soluzione ad un problema prestando attenzione ad aspetti concreti di efficienza del codice

Realizzazione
• Linguaggio C (C11, VLA ammessi)
• Nessuna libreria esterna al di là della libreria standard C
• No multithreading
• Dati in ingresso ricevuti via stdin, risultati da fornire via stdout


GraphRanker
L'obiettivo del progetto è la gestione di una classifica tra grafi diretti pesati:
• La classifica tiene traccia dei k "migliori" grafi

Il programma da realizzare riceve in ingresso:
• due parametri, una sola volta (sulla prima riga del file, separati da spazio): 
  - d: il numero di nodi dei grafi
  - k: la lunghezza della classifica
• Una sequenza di comandi tra:
  - AggiungiGrafo [matrice-di-adiacenza] 
  - TopK
  
d, k e il numero di grafi sono rappresentabili con interi a 32 bit.

Criteri di valutazione
• La correttezza e l'efficienza della soluzione proposta sono valutate con batterie di test automatizzate
• Verranno forniti input/output d'esempio per poter collaudare la soluzione in locale
• Il sistema di verifica calcola il tempo macchina e la memoria utilizzati
