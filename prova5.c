#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"gamelib.h"
int *scelta_giocatori(int n_personaggi);
//void colori(int personaggio);
int main(){
   int n_personaggi;
   int *p;
  do {
    printf("BENVENUTI NEL MENÙ D'IMPOSTAZIONE DEL GIOCO!\n");
    printf("Inserire il numero di giocatori\n con un minimo di 4 giocatori ed un massimo di 10\n ");
    printf("Ora inserisci il numero\n");
    scanf("%d",&n_personaggi);
    switch (n_personaggi) {

      case 4 :
             printf(" 4 giocatori\n");
              p = scelta_giocatori(n_personaggi);
               printf("\n");
             for (int i = 0; i < n_personaggi; i++){
               printf("%d",*p);
             }
             break;
      case 5 :
             printf(" 5 giocatori\n");
             scelta_giocatori(n_personaggi);
             break;
      case 6 :
             printf(" 6 giocatori\n");
             scelta_giocatori(n_personaggi);
             break;
      case 7 :
             printf(" 7 giocatori\n");
             scelta_giocatori(n_personaggi);
             break;
      case 8 :
             printf(" 8 giocatori\n");
             scelta_giocatori(n_personaggi);
             break;
      case 9 :
             printf(" 9 giocatori\n");
             scelta_giocatori(n_personaggi);
             break;
      case 10 :
              printf(" 10 giocatori\n");
              scelta_giocatori(n_personaggi);
              break;
        default :
              if (n_personaggi < 4)
                  printf ("giocatori insufficienti\n riprova\n");
              else if(n_personaggi > 10)
                   printf ("troppi giocatori\n riprova\n");
                  break;
    }
  }
  while( n_personaggi < 4);
  }
int *scelta_giocatori(int n_personaggi){
  time_t t;
  srand((unsigned) time(&t));
  int personaggi[n_personaggi];
  int* ptr_personaggi;
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
     printf("%d ",personaggi[i]);
  }
  return personaggi;
}
/*void colori (int personaggio ){
  switch(personaggio){
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
    case arancione:
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
*/
