#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
  struct stanza* ptr_Stanza;
  enum stato_giocatore  { astronauta, impostore, defenestrato, assassinato}stato;
  enum nome_giocatore  {rosso, verde, blu, nero, bianco, viola, marrone, arancione, rosa, giallo}colore;
}player;
static int scelta_giocatori(int n_personaggi);
static void colori(int personaggio);
static void crea_giocatori(int n_personaggi);
static void scelta_ruolo_giocatore(int n_personaggi);
static int probabilita(int n_personaggi);
 player *giocatori;
int main(){
   int n_personaggi;
  do {
    printf("BENVENUTI NEL MENÙ D'IMPOSTAZIONE DEL GIOCO!\n");
    printf("Inserire il numero di giocatori\n con un minimo di 4 giocatori ed un massimo di 10\n ");
    printf("Ora inserisci il numero\n");
    scanf("%d",&n_personaggi);
    switch (n_personaggi) {

      case 4 :
             scelta_giocatori(n_personaggi);
             scelta_ruolo_giocatore( n_personaggi);
             break;
      case 5 :
             scelta_giocatori(n_personaggi);
             break;
      case 6 :
             scelta_giocatori(n_personaggi);
             break;
      case 7 :
             scelta_giocatori(n_personaggi);
             break;
      case 8 :
             scelta_giocatori(n_personaggi);
             break;
      case 9 :
             scelta_giocatori(n_personaggi);
             break;
      case 10 :
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
  static void crea_giocatori(int n_personaggi){
    giocatori = (player*)malloc(n_personaggi*sizeof(player));
  }
static int scelta_giocatori(int n_personaggi){
  time_t t;
  srand((unsigned) time(&t));
  crea_giocatori(n_personaggi);
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
     giocatori[i].colore = personaggi[i];
     printf("%d",giocatori[i].colore);
     colori(giocatori[i].colore);
}

}
static void colori (int personaggio ){
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
static void scelta_ruolo_giocatore(int n_personaggi){
int personaggi[n_personaggi];
  int n_impostori;
    n_impostori = probabilita(n_personaggi);
  int impostori[n_impostori];
  for (int i = 0; i < n_personaggi; i++){
  personaggi[i] = giocatori[i].colore;
  }
  for (int i = 0; i < n_personaggi; i++){
  printf("%d\n", personaggi[i]);
  }
    for (int i = 0; i < n_impostori; i++){
      int temp = personaggi[i];
      int posizione = rand() % n_personaggi;
          impostori[i] = personaggi[posizione];
          personaggi[posizione] = temp;
        }
        printf("1\n");
        for (int i = 0; i < n_personaggi; i++){
          if (impostori[i] == personaggi[i]){
          giocatori[i].stato = 1;
        printf("personaggio %d è l'impostore%d\n",impostori[i],giocatori[i].stato);
        }
        printf("2\n");
        }
        int n_astronauti = n_personaggi - n_impostori;
        int astronauta[n_astronauti];
        int rimanenti;
        printf("3\n");
          switch (n_impostori) {
            case 1:
            for(int i = 0; i < n_astronauti; i++){
              if (personaggi[i] != impostori[0]){
                astronauta [i] = personaggi[i];
                giocatori[i].stato = 0;
                printf("personaggio %d è l'Astronauta %d\n", astronauta[i],giocatori[i].stato);
          }
        }
          printf("4\n");
          break;
          case 2:
              for(int i = 0; i < n_astronauti; i++){
            if (personaggi[i] != impostori[0] && personaggi[i] != impostori[1]){
              astronauta [i] = personaggi[i];
              giocatori[i].stato = 0;
            printf("personaggio %d  è l'Astronauta %d\n",astronauta[i],giocatori[i].stato);
        }
      }
        printf("5\n");
        break;
       case 3:
           for(int i = 0; i < n_astronauti; i++){
         if (personaggi[i] != impostori[0] && personaggi[i] !=impostori[1] && personaggi[i] !=impostori[2]){
           astronauta [i] = personaggi[i];
           giocatori[i].stato = 0;
           printf("personaggio %d  è l'Astronauta %d \n", astronauta[i],giocatori[i].stato);
     }
   }
     printf("6\n");
     break;
    }
        }
int  probabilita (int n_personaggi){
  int n_impostori;
if (n_personaggi >= 4 && n_personaggi <= 6){
   if ((rand()%100) <= 5){
     n_impostori = 3;
   }
   else if ((rand()%100) >= 6 && (rand()%100) <= 45){
     n_impostori = 2;
   }
   else if ((rand()%100) >= 46 && (rand()%100) <= 100){
     n_impostori = 1;
   }
}
  if (n_personaggi > 6 && n_personaggi <= 7){
          if ((rand()%100) < 15){
           n_impostori = 3;
        }
        else if ( (rand()%100) >= 15 && (rand()%100) <= 65){
         n_impostori = 2;
        }
        else if ( (rand()%100) > 65 && (rand()%100) <=100){
           n_impostori = 1;
    }
  }
  if ( 7 < n_personaggi <= 10){
          if ((rand()%100) < 75){
           n_impostori = 3;
        }
        else if ( (rand()%100) >= 45 && (rand()%100) <= 100){
         n_impostori = 2;
        }
        else if ( (rand()%100)  >= 15 && (rand()%100) <= 25){
           n_impostori = 1;
    }
  }
    return(n_impostori);
  }
