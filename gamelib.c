#include <stdio.h>
#include <stdlib.h>
#include "gamelib.h"
#include <time.h>
#include <string.h>
Giocatore*player;                                                                  //puntatore  a struct Giocatore
Stanza*lista_stanze;                                                               //
Stanza*inizio_stanza;                                                              //puntatore a struct Stanza
unsigned short  quest_da_finire;                                                   // variabile che indica le quest da finire per terminare il gico;
int n_personaggi;
int turnop;                                                                            // variabile che rachiude il numero dei giocatori
static void stanza_principale(void);                                                     // crea la stanza iniziale
static void crea_giocatori(int n_personaggi);                                      // crea i giocatori necessari per giocare;
static void scelta_giocatori( int n_personaggi);                                   // assegna nomi diversi hai giocatori
static void colori(int personaggi);                                                // visualizza i nomi dei giocatori
static void select_impostore_astronauta(int n_personaggi);                         // sceglie se un giocatore sarà astronauta o impostore
static void stampa_giocatori(int n_personaggi);                                    // stampa nome  ruolo e posizione del giocatore
static int  probabilita (int n_personaggi);                                        // funzione che calcola la probabilità del numero di impostori
static void inizializzazione_stanza(Stanza*new_stanza);                                    // determina il tipo di una stanza
static void stanze(int type);                                                      // stampa il tipo della stanza creata
static void avanza(void);
static int esegui_quest(int quest_da_finire);
static void sabotaggio (void);
static int uccidi_astronauta(int n_personaggi);
//static int chiamata_emergenza(int n_personaggi);
//static void f_botola(void);
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
                  crea_giocatori(n_personaggi);
                  stanza_principale();
                  scelta_giocatori(n_personaggi);
                  select_impostore_astronauta(n_personaggi);
                  stampa_giocatori( n_personaggi);
                  break;
          case 5 :
                  printf("inserisci il numero di quest necessarie a terminare la partita\n");
                  scanf(" %hd",&quest_da_finire);
                  crea_giocatori(n_personaggi);
                  stanza_principale();
                  scelta_giocatori(n_personaggi);
                  select_impostore_astronauta(n_personaggi);
                  stampa_giocatori( n_personaggi);
                  break;
          case 6 :
                  printf("inserisci il numero di quest necessarie a terminare la partita\n");
                  scanf(" %hd",&quest_da_finire);
                  crea_giocatori(n_personaggi);
                  stanza_principale();
                  scelta_giocatori(n_personaggi);
                  select_impostore_astronauta(n_personaggi);
                  stampa_giocatori( n_personaggi);
                  break;
          case 7 :
                  printf("inserisci il numero di quest necessarie a terminare la partita\n");
                  scanf(" %hd",&quest_da_finire);
                  crea_giocatori(n_personaggi);
                  stanza_principale();
                  scelta_giocatori(n_personaggi);
                  select_impostore_astronauta(n_personaggi);
                  stampa_giocatori( n_personaggi);
                  break;
          case 8 :
                  printf("inserisci il numero di quest necessarie a terminare la partita\n");
                  scanf(" %hd",&quest_da_finire);
                  crea_giocatori(n_personaggi);
                  stanza_principale();
                  scelta_giocatori(n_personaggi);
                  select_impostore_astronauta(n_personaggi);
                  stampa_giocatori( n_personaggi);
                  break;
          case 9 :
                  printf("inserisci il numero di quest necessarie a terminare la partita\n");
                  scanf(" %hd",&quest_da_finire);
                  crea_giocatori(n_personaggi);
                  stanza_principale();
                  scelta_giocatori(n_personaggi);
                  select_impostore_astronauta(n_personaggi);
                  stampa_giocatori( n_personaggi);
                  break;
         case 10 :
                  printf("inserisci il numero di quest necessarie a terminare la partita\n");
                  scanf(" %hd",&quest_da_finire);
                  crea_giocatori(n_personaggi);
                  stanza_principale();
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
              }
void gioco (){
  time_t t;
  srand((unsigned) time(&t));
  int turno = 0;
  int val;
  int flag = 0;
  int n_impostori = 0;
  int n_astronauti = 0;
  int scelta = 0;
  lista_stanze = inizio_stanza;
    for (int i = 0; i < n_personaggi; i++){
      player[i].posizione = lista_stanze;
      printf("posizione dei giocatori %p\n",player[i].posizione);
      if (player[i].stato == 1){
        n_impostori++;
      }
      if(player[i].stato == 0){
        n_astronauti++;
      }
    }
    printf("n_impostori = %d e n_astronauti = %d\n", n_impostori, n_astronauti);
   do{
     turno++;
     for (int i = 0; i < n_personaggi; i++){
       colori(player[i].colore);
       printf(" ->  stato %d\n",player[i].stato);
     }
    for (int i = 0; i < n_personaggi; i++){
      if ( player[i].stato == 1){
        do {
        printf("è il %d° turno\n", turno);
        printf ("è il turno del giocatore %d", player[i].colore);
        turnop = i;
        colori(player[i].colore);
        printf ("il giocatore si trova nella stanza:\n");
        stanze((player[i].posizione) -> tipo_stanza);
        printf("i giocatori che si trovano in questa stanza sono:\n");
          for (int j = 0; j < n_personaggi; j++){
            if (player[i].posizione == player[j].posizione){
              if (player[j].colore != player[i].colore){
              colori(player[j].colore);
            }
          }
        }
        printf("scelga un opzione delle seguenti\n");
        while (getchar() != '\n');
        printf("1)premere 1 per avanzare\n  2) premere 2 per eseguire una chiamata d'emergenza\n 3) premere 3 per usare la botola\n");
        printf("4)premere 4 per uccidere un astronauta\n 5) premere 5 per sabotare la nave\n");
        scanf("%d", &scelta);
        switch (scelta) {
          case 1:
                avanza();
                break;
          case 2:
                  printf("chiamata d'emergenza\n");
                /*  if (player[i].posizione -> chiamata_emergenza == 0){
                    for (int j = 0; j < n_personaggi; j++){
                      if (player[i].posizione == player[j].posizione){
                        if (player[j].stato == 3){
                            chiamata_emergenza();
                          }
                        }
                      }
                    }
                 if (player[i].posizione -> chiamata_emergenza == 1){
                   printf("la chiamata d' emergenza può essere fatta una sola volta\n");
                   scelta = 0;
                 }*/
                  break;
          case 3:
                printf("usa botola\n");
                /*if (lista_stanze ->ptr_avanti != NULL || lista_stanze -> ptr_destra != NULL || lista_stanze -> ptr_sinistra != NULL ){
                  f_botola();
                }
                else {
                  scelta = 8 ;
                }*/
                  break;
          case 4:
                  sabotaggio();
                  break;
          case 5:
              if (n_astronauti != 0){
                  val = uccidi_astronauta(n_personaggi);
                  if (val == 0){
                    n_astronauti = n_astronauti - 1;
                  }
                  if (val == 1){
                    n_impostori = n_impostori - 1;
                  }
                  if (val == 3){
                    n_impostori = n_impostori - 1;
                    n_astronauti = n_astronauti - 1;
                  }
                }
              if  (n_astronauti == 0 || n_impostori == 1){
                  flag = 1;
                }
                  printf("sono rimast %d astronauti e %d impostori",n_astronauti,n_impostori);
                break;
          default:
                  printf("input non valido\n Riprova\n");
                }
                printf("la scelta %d\n", scelta);
              }
              while (scelta != 1 || scelta != 2 || scelta != 3 || scelta != 4 || scelta != 5);
            }
      if (player[i].stato == 0){
          printf("è il %d° turno\n", turno);
            turnop = i ;
          printf("è il turno del giocatore %d", player[i].colore);
          colori(player[i].colore);
          stanze((player[i].posizione) -> tipo_stanza);
          printf("i giocatori che si trovano in questa stanza sono:\n");
            for (int j = 0; j < n_personaggi; j++){
              if (player[i].posizione == player[j].posizione){
                if (player[j].colore != player[i].colore){
                colori(player[j].colore);
              }
            }
          }
          do{
          while (getchar() != '\n');
          printf("scelga un opzione delle seguenti\n");
          printf(" 1)premere 1 per avanzare\n 2) premere 2 per eseguire una chiamata d'emergenza\n 3) premere 3 per eseguire una quest\n");
          scanf("%d", &scelta);
        switch(scelta){
          case 1:
                avanza();
                break;
          case 2:
                printf("chiamata_emergenza\n");
              /*  if (player[i].posizione -> chiamata_emergenza == 0){
                  for (int j = 0; j < n_personaggi; j++){
                    if (player[i].posizione == player[j].posizione){
                      if (player[j].stato == 3){
                          chiamata_emergenza();
                        }
                      }
                    }
                  }
               if (player[i].posizione -> chiamata_emergenza == 1){
                 printf("la chiamata d' emergenza può essere fatta una sola volta\n");
                 scelta = 0;
               }*/
                break;
          case 3:
                  quest_da_finire = esegui_quest(quest_da_finire);
                  if (quest_da_finire == 0){
                    flag = 1;
                    printf("Game Over!!\n");
                    printf("Vittoria Astronauti\n");
                  }
                  break;
          default:
                  printf("input non valido\n Riprova\n");
                }
                printf("la scelta %d\n", scelta);
              }
              while ( scelta != 1 || scelta != 2 || scelta != 3);
            }
          }
        }
        while(flag != 1);
        printf("Game over");
      }
void termina_gioco(){
  printf("termina");
}
static void stanza_principale(void){
  inizio_stanza = (Stanza*) malloc (sizeof (Stanza));
  inizio_stanza -> ptr_avanti = NULL;
  inizio_stanza -> ptr_destra = NULL;
  inizio_stanza -> ptr_sinistra = NULL;
  inizio_stanza -> ptr_stanza_precendente = NULL;
  inizio_stanza -> tipo_stanza = 0;
}
static void crea_giocatori(int n_personaggi){
  player = (Giocatore*)malloc(n_personaggi* sizeof(Giocatore));
}
static void scelta_giocatori(int n_personaggi){
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
static int  probabilita (int n_personaggi){
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
}
static void stanze(int type){
  switch (type) {
    case 0 :
          printf("Stanza Vuota\n");
          break;
    case 1 :
          printf("In questa stanza c'è una Quest Semplice\n");
          break;
    case 2 :
          printf("In questa stanza c'è una Quest Complessa\n");
          break;
    case 3 :
          printf("In questa stanza c'è una Botola\n");
          break;
    }
}
static void avanza(void){
  int scelta = 0;
  Stanza* new_stanza;
  do{
  printf("bene ha scelto di avanzare\n");
  while (getchar() != '\n');
  printf("ora indichi in quale direzione vuole andare\n");
  printf("premi 1) per andare dritto\n 2) per avanzare a sinistra\n 3) per avanzare a destra\n");
  printf("premi 4) per restare fermo\n");
  scanf("%d", &scelta);
  switch (scelta) {
    case 1:
          printf("ha scelto di andare dritto\n");
          if (lista_stanze -> ptr_avanti == NULL || lista_stanze -> ptr_avanti == player[turnop].posizione){
              lista_stanze -> ptr_stanza_precendente = player[turnop].posizione;
              printf("il  player ora si trova = %p\n", lista_stanze -> ptr_stanza_precendente);
              new_stanza = (Stanza*) malloc(sizeof (Stanza));
              inizializzazione_stanza (new_stanza);
              player[turnop].posizione = new_stanza;
              lista_stanze -> ptr_avanti = new_stanza;
              printf("il player ora si trova = %p\n", player[turnop].posizione);
        }
        else{
          printf("il player ora si trova = %p\n", player[turnop].posizione);
          printf("stanza precedente %p",lista_stanze -> ptr_stanza_precendente);
          player[turnop].posizione = lista_stanze-> ptr_avanti;
          stanze((lista_stanze) -> tipo_stanza);
          printf("il  player ora si trova = %p\n", player[turnop].posizione );
        }
          return;
    case 2:
            printf("ha scelto di andare a sinistra\n");
            if (lista_stanze -> ptr_sinistra == NULL || lista_stanze -> ptr_sinistra == player[turnop].posizione){
                lista_stanze -> ptr_sinistra = player[turnop].posizione;
                printf("il player ora si trova = %p\n", lista_stanze -> ptr_sinistra);
                printf("stanza precedente %p",lista_stanze -> ptr_stanza_precendente);
                new_stanza = (Stanza*) malloc(sizeof (Stanza));
                inizializzazione_stanza (new_stanza);
                player[turnop].posizione = new_stanza;
                lista_stanze -> ptr_sinistra = new_stanza;
                printf("il  player ora si trova = %p\n", player[turnop].posizione);
          }
          else{
            printf("il  player ora si trova = %p\n", player[turnop].posizione);
            printf("stanza precedente %p",lista_stanze -> ptr_stanza_precendente);
            player[turnop].posizione = lista_stanze-> ptr_sinistra;
            stanze((lista_stanze) -> tipo_stanza);
            printf("il  player ora si trova = %p\n", player[turnop].posizione);
          }
          return;
   case 3:
          printf("ha scelto di andare a destra\n");
          if (lista_stanze -> ptr_destra == NULL || lista_stanze -> ptr_destra == player[turnop].posizione){
              lista_stanze -> ptr_destra = player[turnop].posizione;
              printf("il  player ora si trova = %p\n", lista_stanze -> ptr_destra);
              printf("stanza precedente %p",lista_stanze -> ptr_stanza_precendente);
              new_stanza = (Stanza*) malloc(sizeof (Stanza));
              inizializzazione_stanza (new_stanza);
              player[turnop].posizione = new_stanza;
              lista_stanze -> ptr_destra = new_stanza;
              printf("il  player ora si trova = %p\n", player[turnop].posizione);
        }
        else{
          printf("il  player ora si trova = %p\n", player[turnop].posizione);
          printf("stanza precedente %p",lista_stanze -> ptr_stanza_precendente);
          player[turnop].posizione = lista_stanze-> ptr_destra;
          stanze((lista_stanze) -> tipo_stanza);
          printf("il  player ora si trova = %p\n", player[turnop].posizione );
        }
         return;
   case 4:
            printf("il giocatore ha scelto di rimanere fermo\n");
    default :
          printf("input non valido\n");
          printf("la scelta %d\n", scelta);
  }
}
 while (scelta != 3 || scelta != 2 || scelta != 1 || scelta != 4);
}
static void inizializzazione_stanza(Stanza* new_stanza){
  time_t t;
  srand((unsigned) time(&t));
  new_stanza -> ptr_avanti = NULL;
  new_stanza -> ptr_destra = NULL;
  new_stanza -> ptr_sinistra = NULL;
  new_stanza -> ptr_stanza_precendente = lista_stanze;
  int type_room;
  type_room = rand() % 100;
  printf("tipo stanza %d\n", type_room);
  if (type_room <= 15){
    new_stanza -> tipo_stanza = 2;
    stanze(new_stanza -> tipo_stanza);
  }
  if (type_room > 15 && type_room <= 40){
    new_stanza -> tipo_stanza = 3;
    stanze(new_stanza -> tipo_stanza);
  }
  if (type_room > 40 && type_room <= 70){
    new_stanza -> tipo_stanza = 0;
    stanze(new_stanza -> tipo_stanza);
  }
  if (type_room > 70 && type_room <= 100){
    new_stanza -> tipo_stanza = 1;
    stanze(new_stanza -> tipo_stanza);
  }
}
static int esegui_quest(int quest_da_finire){
  if ( player[turnop].posizione -> tipo_stanza == 2){
     quest_da_finire = quest_da_finire - 2;
     printf("Quest da completare = %d", quest_da_finire);
  }
  if ( player[turnop].posizione -> tipo_stanza == 1){
     quest_da_finire = quest_da_finire - 1;
     printf("Quest da completare = %d", quest_da_finire);
  }
    return(quest_da_finire);
  }
static void sabotaggio(void){
    if (player[turnop].posizione -> tipo_stanza == 1 ||  player[turnop].posizione -> tipo_stanza  == 2 ){
        player[turnop].posizione -> tipo_stanza = 0;
      printf("quest eliminata\n");
    }
}
static int uccidi_astronauta(int n_personaggi){
  int scelta;
  int val;
  int astronauti_nella_stanza = 0;
  int astronauti_stanza_precedente = 0;
  for (int i = 0; i < n_personaggi; i++){
    if (player[turnop].posizione == player[i].posizione){
      if ( player[i].stato == 0){
        printf("i possibili gicocatori da assassinare sono:\n");
        colori(player[i].colore);
        printf("premere 0 per vedere la vittima successiva premere 1 per uccidere\n");
        scanf("%d",&scelta);
        if (scelta == 0){
          continue;
        }
        if (scelta == 1){
          player[i].stato = 3;
          printf("il");
          colori(player[i].colore);
          printf(" è stato assassinato\n");
          val = 0;
          break;
        }
      }
    }
  }
  for (int i = 0; i < n_personaggi; i++){
    if (player[turnop].posizione == player[i].posizione){
      if (player[i].stato == 0){
        astronauti_nella_stanza++;
      }
    }
    if (player[turnop].posizione == lista_stanze -> ptr_stanza_precendente){
      if (player[i].stato == 0){
      astronauti_stanza_precedente++;
      }
    }
  }
  int prob ;
  prob = (50 * (astronauti_nella_stanza)) + (20 * (astronauti_stanza_precedente));
  printf("%d\n", prob);
  if (prob > 50 ){
    player[turnop].stato = 2;
    val = 1;
    printf("l'impostore è stato defenestrato\n");
  }
  else {
    printf("l'impostore si è salvato\n");
  }
  for(int i = 0; i < n_personaggi; i++){
    printf("controllo morti\n");
  if (player[turnop].stato == 4 && player[i].stato == 3){
          val = 2;
  }
}
  return(val);
}
/*
int chiamata_emergenza(int n_personaggi){
   int n_astr = 0;
   int n_imp = 0;
   for (int i = 0; i < n_personaggi; i++){
     if (player[turnop].posizione == player[i].posizione){
       if (player[i].stato == 0){
         n_astr++;
       }
       else if (player[i].stato == 1){
         n_imp++;
       }
     }
   }
   int probabilita[n_personaggi];
   for (int i = 0; i < n_personaggi; i++){
     if (player[turnop].posizione == player[i].posizione){
       if (player[i].stato == 0){
        probabilita[i] = (30 + (20 * n_imp)) - (30 * n_astr);
      }
   if (player[i].stato == 1){
    probabilita[i] = (30 + (20 * n_astr)) - (30 * n_imp);
      }
    }
  }
}*/
/*void f_botola(void){
  do {
       if ((lista_stanze -> ptr_avanti)-> tipo_stanza == 3){
            player[turnop].posizione = lista_stanze -> ptr_avanti;
            printf("il giocatore è nella stanza %p",player[turnop].posizione);
       }
  }
  while (lista_stanze-> ptr_avanti == NULL);
  do{
       if ((lista_stanze -> ptr_destra)-> tipo_stanza == 3){
            player[turnop].posizione = lista_stanze -> ptr_destra;
            printf("il giocatore è nella stanza %p",player[turnop].posizione);
       }
  }
  while (lista_stanze-> ptr_destra == NULL);
  do{
       if ((lista_stanze -> ptr_sinistra)-> tipo_stanza == 3){
            player[turnop].posizione = lista_stanze -> ptr_sinistra;
            printf("il giocatore è nella stanza %p",player[turnop].posizione);
       }
  }
  while (lista_stanze-> ptr_sinistra == NULL);
}
*/
