struct Giocatore{
  struct stanza* ptr_Stanza;
  enum stato_giocatore  { astronauta, impostore, defenestrato, assassinato};
  enum nome_giocatore  {rosso, verde, blu, nero, bianco, viola, marrone, arancione, rosa, giallo};
};
struct  Stanza{
  struct stanza* ptr_avanti;
  struct stanza* ptr_destra;
  struct stanza* ptr_sinistra;
  struct stanza* ptr_stanzaprecendente;
  enum stato_stanza { vuota, quest_semplice, quest_complessa, botola };
};
void termina_gioco(void);
void gioco(void);
void imposta_gioco(void);
