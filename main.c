#include <stdio.h>
#include <stdlib.h>
#include "gamelib.h"
#include <time.h>
int main(){
  int scelta = 3;
  while(getchar() != '\n');

  printf("  # Benvenuti nel gioco Trannoi   #   \n");
  printf(" \n");
  printf("*breve storia del gioco*\n");
  do{
    //while(getchar() != '\n');
   printf("scelga un opzione delle seguenti\n");
   printf("scegli se:\n 1)premere 1 per impostare il gioco\n 2) premere 2 per giocare\n 3) premere 3 per terminare il gioco\n");
   scanf("%d",&scelta);
    switch(scelta){
      case 1:
          imposta_gioco();
          break;
      case 2 :
          gioco();
          break;
      case 3 :
          termina_gioco();
          break;
      default :
          printf ("input non valido\n");
          break;
   }
 }
  while(scelta != 3);
   return 0;
}
