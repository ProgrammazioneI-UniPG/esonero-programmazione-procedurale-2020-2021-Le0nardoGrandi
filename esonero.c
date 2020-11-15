#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void inputk(char M[],char *k){ //dichiarazione della funzione per l'inserimento manuale della chiave
	printf("Inserisci la chiave di cifratura: "); //richiesta di inserimento della chiave
	do{
		fgets(k, 129, stdin); //inserimento della chiave
	}while(strlen(k)<strlen(M)); //do-while per fa rinserire la chiave finchè non sia più corta del messaggio in chiaro
}
void randomk(char M[],char *k){ //dichiarazione della funzione per la generazione automatica della chiave
	time_t t; //inizializzazione del generatore di numeri casuali utilizzando il tempo attuale
	srand((unsigned)time(&t)); //chiamata alla funzione per la generazione di numeri casuali
	for(int c=0; c<(strlen(M)-1); c++){ //ciclo che per far scorrere la stringa, carattere per carattere
		k[c]=rand()%(127)+32; //inserimento di valori casuali nella stringa
	}
	printf("Chiave generata automaticamente: \n%s\n", k); //output della chiave generata
}
void criptapazione(char M[],char *k, char *C){ //dichiarazione della funzione per la criptazione del messaggio
	for(int i=0; i<(strlen(M)-1);i++){ //ciclo che per far scorrere la stringa, carattere per carattere
		C[i]=M[i]^k[i]; //criptazione del messaggio
	}
	printf("Messaggio criptato: \n%s\n", C); //output del messaggio criptato
}
void decriptapazione(char *M,char *k, char *C){ //dichiarazione della funzione per la decriptazione del messaggio
	char MD[129]; //dichiarazione stringa per il messaggio decriptato
	int i=0;
	for(; i<(strlen(M)-1);i++){ //ciclo che per far scorrere la stringa, carattere per carattere
		MD[i]=C[i]^k[i]; //criptazione del messaggio
	}
	MD[i]='\0';
	printf("Messaggio decriptato: \n%s\n", MD); //output del messaggio decriptato
}
int main()
{
	char M[129],k[129],C[129]; //dichiarazione delle stringhe: messaggio in chiaro, chiave di criptazione, messaggio criptato
	int n; //dichiarazione della variabile utilizzata per il menù
	char c;
	printf("Inserisci il messaggio: "); //richiesta di inserimento del messaggio in chiaro
	fgets(M, 129, stdin); //input del messaggio in chiaro

	printf("Scegli se: \nInserire 1 per inserire la chiave di cifratura manualmente \nInserire 2 per generare casualmente la chiave\n"); //richiesta di inserimento per il menù
	do{
		scanf ("%d", &n); //input per la scelta di come inserire la chiave
		while((c= getchar()) != '\n' && c != EOF); //pulizia del buffer di input
	}while(n!=1&&n!=2); // do-while per fa rinserire il valore talvolta sia diverso da 1 o 2
	if(n==1){
		inputk(M,k); //chiamata alla funzione per inserire la chiave manualmente
	}
	if(n==2){
		randomk(M,k); //chiamata alla funzione per generare la chiave automaticamente
	}
	criptapazione(M,k,C); //chiamata alla funzione per la criptazione del messaggio
	decriptapazione(M,k,C); //chiamata alla funzione per la decriptazione del messaggio
	return 0;
}
