#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 10
int probabilita (int n_personaggi);
typedef struct {
  enum stato_giocatore{ astronauta, impostore, defenestrato, assassinato}stato;
  enum colore_giocatore{ rosso,giallo, blu, verde, viola, grigio, nero, marrone, rosa, bianco }colore;
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
		 giocatore[i].colore = personaggi[i];
		 printf("%d ",personaggi[i]);
	}
	for (int i = 0; i < n_personaggi; i++){
	switch(giocatore[i].colore){
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
  int n_impostori;
    probabilita(n_personaggi);
    n_impostori = probabilita(n_personaggi);
  int impostori[n_impostori];
    for (int i = 0; i < n_impostori; i++){
          int posizione = rand() % n_personaggi;
        impostori[i] = personaggi[posizione];
        giocatore[i].stato = 1;
        printf("personaggio %d è l'impostore%d\n",impostori[i],giocatore[i].stato);
        }
        int n_astronauti = n_personaggi - n_impostori;
        int astronauta[n_astronauti];
        int rimanenti;
        for (int i = 0; i < n_personaggi; i++){
          switch (n_impostori) {
            case 1:
              if (personaggi[i] != impostori[0]){
                astronauta [i] = personaggi[i];
                giocatore[i].stato = 0;
                printf("personaggio %d è l'Astronauta %d\n", astronauta[i],giocatore[i].stato);
          }
          break;
          case 2:
            if (personaggi[i] != impostori[0] && personaggi[i] != impostori[1]){
              astronauta [i] = personaggi[i];
              giocatore[i].stato = 0;
            printf("personaggio %d  è l'Astronauta %d\n",astronauta[i],giocatore[i].stato);
        }
        break;

       case 3:
         if (personaggi[i] != impostori[0] && personaggi[i] !=impostori[1] && personaggi[i] !=impostori[2]){
           astronauta [i] = personaggi[i];
           giocatore[i].stato = 0;
           printf("personaggio %d  è l'Astronauta %d \n", astronauta[i],giocatore[i].stato);

     }
     break;
    }
        }
      }
int  probabilita (int n_personaggi){
  int n_impostori;
  if ( 5<=n_personaggi <= 7){
          if ((rand()%100) < 15){
           n_impostori = 3;
        }
        else if ( 15 < (rand()%100) < 45){
         n_impostori = 2;
        }
        else if ( 45 < (rand()%100) < 100){
           n_impostori = 1;
    }
  }
  if ( 7< n_personaggi <= 10){
          if ((rand()%100) < 75){
           n_impostori = 3;
        }
        else if ( 15 < (rand()%100) < 25){
         n_impostori = 2;
        }
        else if ( 45 < (rand()%100) < 100){
           n_impostori = 1;
    }
  }

    return(n_impostori);
  }
