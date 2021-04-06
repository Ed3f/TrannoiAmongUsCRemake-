typedef struct{
  struct Stanza* ptr_avanti;
  struct Stanza* ptr_destra;
  struct Stanza* ptr_sinistra;
  struct Stanza* ptr_stanza_precendente;
  enum stato_stanza { vuota, quest_semplice, quest_complessa, botola }tipo_stanza;
}Stanza;
typedef struct {
  Stanza* posizione;
  enum stato_giocatore  { astronauta, impostore, defenestrato, assassinato}stato;
  enum nome_giocatore  {rosso, verde, blu, nero, bianco, viola, marrone, arancione, rosa, giallo}colore;
}Giocatore;
void termina_gioco(void);
void gioco(void);
void imposta_gioco(void);
