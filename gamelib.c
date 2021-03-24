#include <stdio.h>
#include <stdlib.h>
#include "gamelib.h"
#include <time.h>
#include <string.h>
void  scelta_giocatori( int n_personaggi);
/*static void colori(int* ptr_personaggi);
static void select_impostore_astronauta();
unsigned short  quest_da_finire;*/
void imposta_gioco(){
  time_t t;
  srand((unsigned) time(&t));
   int n_personaggi;
  do {
    printf("BENVENUTI NEL MENÙ D'IMPOSTAZIONE DEL GIOCO!\n");
    printf("Inserire il numero di giocatori\n con un minimo di 4 giocatori ed un massimo di 10\n ");
    printf("Ora inserisci il numero\n");
    scanf("%d",&n_personaggi);
    switch (n_personaggi) {

          case 4 :
                  scelta_giocatori(n_personaggi);

                  break;
      /*    case 5 :
                  printf(" 5 giocatori");
                  break;
          case 6 :
          printf(" 6 giocatori");
                  break;
          case 7 :
          printf(" 7 giocatori");
                  break;
          case 8 :
          printf(" 8 giocatori");
                  break;
          case 9 :
          printf(" 9 giocatori");
                  break;*/
        default :
              if (n_personaggi < 4)
                  printf ("giocatori insufficienti\n riprova\n");
              else if(n_personaggi > 9)
                   printf ("troppi giocatori\n riprova\n");
                  break;
    }
  }
  while( n_personaggi < 4);
  }
void gioco (){
  printf("gioco");
}
void termina_gioco(){
  printf("termina");
}
void scelta_giocatori(int n_personaggi){
  time_t t;
  srand((unsigned) time(&t));
  printf("%d", n_personaggi);
  int personaggi[n_personaggi];
  for (int i = 0; i <= n_personaggi; i++){
     personaggi[i] = 0;
  }
  for (int i = 0; i <= n_personaggi; i++){
     personaggi[i] = i;
  }
   for (int i = 0; i < n_personaggi; i++){
     int temp = personaggi[i];
     int random = rand() % n_personaggi;
     personaggi[i] = personaggi[random];
     personaggi[random] = temp;
   }
   for (int i = 0; i <= n_personaggi; i++){
    printf("%d", personaggi[i]);
  }
  printf("5");
}
/*void colori ( int* ptr_personaggi){
  switch(*ptr_personaggi){
    case rosso:
    printf("rosso\n");
    break;
    case verde:
    printf("verde\n");
    break;
    case blu:
    printf("blu\n");
    break;
    case nero:
    printf("nero\n");
    break;
    case bianco:
    printf("bianco\n");
    break;
    case viola:
    printf("viola\n");
    break;
    case marrone:
    printf("marrone\n");
    break;
    case arancione:
    printf("arancione\n");
    break;
    case rosa:
    printf("rosa\n");
    break;
    case giallo:
    printf("giallo\n");
    break;
  }
}*/
  //void select_impostore_astronauta(){
//  }
