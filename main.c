#include <stdio.h>
#include <stdlib.h>
#include "gamelib.h"
#include <time.h>
int main(){
  int scelta = 0;
  int flag = 0;
  printf("\nBenvenuto in...");
  printf("\npremere invio per continuare\n");
  while (getchar() != '\n');

printf("████████╗██████╗░░█████╗░███╗░░██╗███╗░░██╗░█████╗░██╗\n");
printf("╚══██╔══╝██╔══██╗██╔══██╗████╗░██║████╗░██║██╔══██╗██║\n");
printf("░░░██║░░░██████╔╝███████║██╔██╗██║██╔██╗██║██║░░██║██║\n");
printf("░░░██║░░░██╔══██╗██╔══██║██║╚████║██║╚████║██║░░██║██║\n");
printf("░░░██║░░░██║░░██║██║░░██║██║░╚███║██║░╚███║╚█████╔╝██║\n");
printf("░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝╚═╝░░╚══╝░╚════╝░╚═╝\n");
  while (getchar() != '\n');
  printf(" \n");
  printf("Un gruppo di Astronauti si trova in viagggio sull' astronave Skelt,\n il loro obbiettivo è il mantenimento della nave per arrivare a destinazione.\n tra di loro però ci sono anche degli impostori,\n ");
  printf("il loro scopo è eliminare gli astronauti senza farsi scoprire da quest'ultimi\n ce la faranno gli astronauti ad arrivare a destinazione senza essere decimanti?\n ");
  while (getchar() != '\n');
  do{
    printf("\n+----------------------------------------------------------------------------+\n");
   printf("|                        BENVENUTO NEL MENU' PRINCIPALE                      |\n");
   printf("+----------------------------------------------------------------------------+\n");
   while (getchar() != '\n');
   printf("\n");
   printf("scelga un opzione delle seguenti\n");
   printf("scegli se:\n 1)premere 1 per impostare il gioco\n 2) premere 2 per giocare\n 3) premere 3 per terminare il gioco\n");
   scanf("%d",&scelta);
    switch(scelta){
      case 1:
          imposta_gioco();
          flag = 1;
          break;
      case 2 :
      if (flag == 1){
          gioco();
        }
        else {
          printf("Attenzione\n");
          printf("Prima deve impostare il gioco, per giocare\n");
          break;
        }
          break;
      case 3 :
          termina_gioco();
          break;
      default :
      if (scelta == 0){
          printf ("Attenzione, il valore digitato non è corretto");
          break;
        }
   }
 }
  while(scelta != 3);
   return 0;
}
