#include <stdio.h>
#include <stdlib.h>
#include "gamelib.h"
#include <time.h>
#include <string.h>
Giocatore*player;
Stanza*lista_stanze;
Stanza*inizio_stanza;
static void crea_stanza(void);
static void crea_giocatori(int n_personaggi);
static void scelta_giocatori( int n_personaggi);
static void colori(int personaggi);
static void select_impostore_astronauta(int n_personaggi);
static void stampa_giocatori(int n_personaggi);
static int  probabilita (int n_personaggi);
static void  esegui_quest(void);
static void avanza(void);
static void destra(void);
static void sinistra(void);
static void usa_botola(void);
static int chiamata_emergenza(void);
static void uccidi_astronauta(void);
//static int tipologia_stanza(void);
unsigned short  quest_da_finire;
int n_personaggi;
int flag = 0;
void imposta_gioco(){
  time_t t;
  srand((unsigned) time(&t));
  do {
    printf("BENVENUTI NEL MENÙ D'IMPOSTAZIONE DEL GIOCO!\n");
    printf("Inserire il numero di giocatori\n con un minimo di 4 giocatori ed un massimo di 10\n ");
    printf("Ora inserisci il numero\n");
    scanf("%d",&n_personaggi);
    switch (n_personaggi) {
          case 4 :
                  printf("inserisci il numero di quest necessarie a terminare la partita\n");
                  scanf(" %hd",&quest_da_finire);
                  crea_stanza();
                  scelta_giocatori(n_personaggi);
                  select_impostore_astronauta(n_personaggi);
                  stampa_giocatori( n_personaggi);
                  break;
          case 5 :
                  printf("inserisci il numero di quest necessarie a terminare la partita\n");
                  scanf(" %hd",&quest_da_finire);
                  crea_stanza();
                  scelta_giocatori(n_personaggi);
                  select_impostore_astronauta(n_personaggi);
                  stampa_giocatori( n_personaggi);
                  break;
          case 6 :
                  printf("inserisci il numero di quest necessarie a terminare la partita\n");
                  scanf(" %hd",&quest_da_finire);
                  crea_stanza();
                  scelta_giocatori(n_personaggi);
                  select_impostore_astronauta(n_personaggi);
                  stampa_giocatori( n_personaggi);
                  break;
          case 7 :
                  printf("inserisci il numero di quest necessarie a terminare la partita\n");
                  scanf(" %hd",&quest_da_finire);
                  crea_stanza();
                  scelta_giocatori(n_personaggi);
                  select_impostore_astronauta(n_personaggi);
                  stampa_giocatori( n_personaggi);
                  break;
          case 8 :
                  printf("inserisci il numero di quest necessarie a terminare la partita\n");
                  scanf(" %hd",&quest_da_finire);
                  crea_stanza();
                  scelta_giocatori(n_personaggi);
                  select_impostore_astronauta(n_personaggi);
                  stampa_giocatori( n_personaggi);
                  break;
          case 9 :
                  printf("inserisci il numero di quest necessarie a terminare la partita\n");
                  scanf(" %hd",&quest_da_finire);
                  crea_stanza();
                  scelta_giocatori(n_personaggi);
                  select_impostore_astronauta(n_personaggi);
                  stampa_giocatori( n_personaggi);
                  break;
         case 10 :
                  printf("inserisci il numero di quest necessarie a terminare la partita\n");
                  scanf(" %hd",&quest_da_finire);
                  crea_stanza();
                  scelta_giocatori(n_personaggi);
                  select_impostore_astronauta(n_personaggi);
                  stampa_giocatori( n_personaggi);
                  break;
        default :
                 if (n_personaggi < 4){
                    printf ("giocatori insufficienti\n riprova\n");
                  }
                 if(n_personaggi > 10){
                        printf ("troppi giocatori\n riprova\n");
                      }
                        break;
                }
              }
              while( n_personaggi < 4);
              for(int i = 0; i < n_personaggi; i++){
                inizio_stanza[i].ptr_avanti = NULL;
                inizio_stanza[i].ptr_destra = NULL;
                inizio_stanza[i].ptr_sinistra = NULL;
                inizio_stanza[i].ptr_stanza_precendente = NULL;
              }
            if (flag == 0){
                printf("Prima di giocare si deve impostare il gioco!!\n");
                imposta_gioco();
              }
              }
void gioco (){
  int turno;
  int scelta;
  int chiamata_eme = 0;
  do{
    for (int i = 0; i < n_personaggi; i++){
      int temp = player[i].colore;
      int random = rand() % n_personaggi;
       player[i].colore = player[random].colore;
       player[random].colore = temp;
    }
  for (int i = 0; i < n_personaggi; i++){
    printf("il primo giocatore a giocare è %d",player[i].colore);
    if (player[i].stato == 1){
      printf("\n+----------------------------------------------------------------------------+\n");
     printf("|                        %d° GIOCATORE                                       |\n", player[i].colore);
     printf("+----------------------------------------------------------------------------+\n");
     while (getchar() != '\n');
     printf("\n");
     do {
     printf("scelga un opzione delle seguenti\n");
     printf("1)premere 1 per avanzare\n 2) premere 2 per avanzare a sinistra\n 3) premere 3 per avanzare a destra\n 4) premere 4 per eseguire una chiamata d'emergenza\n 5) premere 5 per eseguire una quest\n");
     printf(" 6)premere 6 per uccidere un astronauta\n 7) premere 7 per sabotare la nave\n");
     scanf("%d",&scelta);
      switch(scelta){
        case 1:
              avanza();
              break;
        case 2:
              destra();
              break;
        case 3:
              sinistra();
              break;
        case 4:
              if (chimata_eme == 0){
                chimata_eme = chiamata_emergenza();
                break;
              }
              if (chimata_eme == 1){
              printf("la chiamata d' emergenza può essere fatta una sola volta\n");
              break;
            }
        case 5:
              usa_botola();
              break;
        case 6:
              uccidi_astronauta();
              break;
        case 7:
              sabotaggio();
              break;
        default:
                printf("input non valido\n Riprova\n");
      }
      while (scelta != 7);
    }
  }
  if (player[i].stato == 0){
    printf("\n+----------------------------------------------------------------------------+\n");
   printf("|                        %d° GIOCATORE                                       |\n", player[i].colore);
   printf("+----------------------------------------------------------------------------+\n");
   while (getchar() != '\n');
   printf("\n");
   do {
   printf("scelga un opzione delle seguenti\n");
   printf(" 1)premere 1 per avanzare\n 2) premere 2 per avanzare a sinistra\n 3) premere 3 per avanzare a destra\n 4) premere 4 per eseguire una chiamata d'emergenza\n 5) premere 5 per eseguire una quest\n");
   scanf("%d",&scelta);
    switch(scelta){
      case 1:
            avanza();
            break;
      case 2:
            destra();
            break;
      case 3:
            sinistra();
            break;
      case 4:
            if (chimata_eme == 0){
              chimata_eme = chiamata_emergenza();
              break;
            }
            if (chimata_eme == 1){
              printf("la chiamata d' emergenza può essere fatta una sola volta\n");
              break;
            }
      case 5:
            esegui_quest();
            break;
      default:
              printf("input non valido\n Riprova\n");
    }
    while (scelta != 5);
    }
 }
 }
 }
}
void termina_gioco(){
  printf("termina");
}
static void crea_stanza(void){
  inizio_stanza = (Stanza*) malloc (sizeof (Stanza));
}
static void crea_giocatori(int n_personaggi){
  player = (Giocatore*)malloc(n_personaggi* sizeof(Giocatore));
}
static void scelta_giocatori(int n_personaggi){
  crea_giocatori(n_personaggi);
  //printf("%d", n_personaggi);
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
      player[i].colore = personaggi[i];
  }
}
static void colori ( int personaggi){
  switch(personaggi){
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
    printf("= arancione\n");
    break;
    case rosa:
    printf("= rosa\n");
    break;
    case giallo:
    printf("= giallo\n");
    break;
  }
}
static void select_impostore_astronauta(int n_personaggi){
  int personaggi[n_personaggi];
  int n_impostori;
  probabilita(n_personaggi);
  n_impostori =   probabilita(n_personaggi);
  int impostori[n_impostori];
  time_t t;
  srand((unsigned) time(&t));
   for (int i = 0; i < n_personaggi; i++){
     personaggi[i] = player[i].colore;
    }
   for (int i = 0; i < n_impostori; i++){
      int posizione = rand() % n_personaggi;
      impostori[i] = personaggi[posizione];
      player[posizione].stato = 1;
    }
      for (int i = 0; i < n_personaggi; i++){
        switch (n_impostori) {
          case 1:
            if (player[i].colore != impostori[0]){
              player[i].stato = 0;
        }
        break;
        case 2:
          if (player[i].colore != impostori[0] && personaggi[i] != impostori[1]){
          player[i].stato = 0;
      }
      break;

     case 3:
       if (player[i].colore != impostori[0] && personaggi[i] != impostori[1] && personaggi[i] != impostori[2]){
         player[i].stato = 0;
   }
   break;
  }
      }
    }
int  probabilita (int n_personaggi){
  int n_impostori;
  int probablity;
  probablity = (rand()%100);
    printf ("%d\n", probablity);
  if (n_personaggi >= 4 && n_personaggi <= 6){
     if ( probablity <= 5){
       n_impostori = 3;
     }
     else if (probablity >= 6 && probablity <= 45){
       n_impostori = 2;
     }
     else if (probablity >= 46 && probablity <= 100){
       n_impostori = 1;
     }
  }
    if (n_personaggi > 6 && n_personaggi <= 7){
            if (probablity < 15){
             n_impostori = 3;
          }
          else if ( probablity >= 15 && probablity <= 65){
           n_impostori = 2;
          }
          else if ( probablity > 65 && probablity <=100){
             n_impostori = 1;
      }
    }
    if ( n_personaggi > 7 && n_personaggi <= 10){
            if (probablity < 75){
             n_impostori = 3;
          }
          else if ( probablity >= 75 && probablity <= 100){
           n_impostori = 2;
          }
          else if ( probablity  >= 15 && probablity <= 25){
             n_impostori = 1;
      }
    }
    return(n_impostori);
  }
static void stampa_giocatori(int n_personaggi){
 for (int i = 0; i < n_personaggi; i++){
   printf("\n il giocatore %d",player[i].colore);
   colori(player[i].colore);
   if (player[i].stato == 1){
     printf(" è l'impostore\n");
   }
  if (player[i].stato == 0){
     printf(" è l'astronauta\n");
   }
   player[i].posizione = inizio_stanza;
 }

 printf("le quest da finire sono %d\n", quest_da_finire);
 flag = 1;
}
/*static int tipologia_stanza(void){
  int t_stanza;
  t_stanza = rand() % 100;
      if (t_stanza <= 15){
        Stanza.tipo_stanza = 3;
        return(Stanza.tipo_stanza);
      }
      if (t_stanza > 15 && t_stanza <= 40){
          Stanza.tipo_stanza = 4;
          return(Stanza.tipo_stanza);
      }
      if (t_stanza > 40 && t_stanza <= 70){
          Stanza.tipo_stanza = 2;
          return(Stanza.tipo_stanza);
    }
      if (t_stanza > 70 && t_stanza <= 100){
          Stanza.tipo_stanza = 1;
          return(Stanza.tipo_stanza);
        }
 }
*/
static void  esegui_quest(void){
  printf("esegui quest\n");
}
static void avanza(void){
  printf("vai  avanti\n");
}
static void destra(void){
  printf("vai a destra\n");
}
static void sinistra(void){
  printf("vai a sinistra\n");
}
static void usa_botola(void){
  printf("usa botola\n");
}
static int chiamata_emergenza(void){
  return(1);
}
static void uccidi_astronauta(void){
  printf("ucciso\n");
}
