#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 10
typedef enum stato_giocatore{ astronauta, impostore, defenestrato, assassinato};
typedef enum colore_giocatore{ rosso,giallo, blu, verde, viola, grigio, nero, marrone, rosa, bianco };
typedef struct {
	stato_giocatore stato;
  colore_giocatore colore;
}player;

int main(){
  player giocatore[max];
	int n_personaggi;
	scanf ("%d", &n_personaggi);
	time_t t;
	srand((unsigned) time(&t));
	int personaggi[n_personaggi];
	for (int i = 0; i < n_personaggi; i++){
		 personaggi[i] = 0;
	}

	for (int i = 0; i < n_personaggi; i++){
		 personaggi[i] = i;
	}

	 for (int i = 0; i < n_personaggi; i++){
		 int temp = personaggi[i];
		 int random = rand() % n_personaggi;
		 personaggi[i] = personaggi[random];
		 personaggi[random] = temp;
	 }
	 for (int i = 0; i < n_personaggi; i++){
		 giocatore -> colore = personaggi[i];
		 printf("%d ",personaggi[i]);
	}
	for (int i = 0; i < n_personaggi; i++){
	switch(personaggi[i]){
		case rosso:
		printf("= rosso\n");
		break;
		case verde:
		printf("= verde\n");
		break;
		case blu:
		printf("= blu\n");
		break;
		case nero:
		printf("= nero\n");
		break;
		case bianco:
		printf("= bianco\n");
		break;
		case viola:
		printf("= viola\n");
		break;
		case marrone:
		printf("= marrone\n");
		break;
		case grigio:
		printf("= sirena\n");
		break;
		case rosa:
		printf("= rosa\n");
		break;
		case giallo:
		printf("= giallo\n");
		break;
		}
	}
}
