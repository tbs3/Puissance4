#include <Xgeii.h>
#ifndef PUISSANCE4_H
#define PUISSANCE4_H

void splash();
void draw_rectangle(window window, unsigned int pos_x, unsigned int pos_y, unsigned int width, unsigned int height);
void draw_rectangle_full(window window, unsigned int pos_x, unsigned int pos_y, unsigned int width, unsigned int height);
void draw_board(window window);
void put_jeton(window window, unsigned short num_ligne, unsigned short num_colonne, unsigned short num_joueur);
short is_valid(unsigned short tableau[][7], unsigned short num_colonne);
void affiche_tableau(unsigned short tab[][7]);
unsigned short end_of_game(unsigned short t[][7], unsigned short c, unsigned short j, unsigned short l);


#endif // PUISSANCE4_H
