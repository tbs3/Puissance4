#include <iostream>
#include <conio.h>
#include <Xgeii.h>

using namespace std;
//Dessine un rectangle
void draw_rectangle(window window, unsigned int pos_x, unsigned int pos_y, unsigned int width, unsigned int height){
    draw_line(window, pos_x, pos_y, pos_x, pos_y+height);
    draw_line(window, pos_x, pos_y, pos_x+width, pos_y);
    draw_line(window, pos_x+width, pos_y, pos_x+width, pos_y+height);
    draw_line(window, pos_x, pos_y+height, pos_x+width, pos_y+height);

}
//Dessine un rectangle plein
void draw_rectangle_full(window window, unsigned int pos_x, unsigned int pos_y, unsigned int width, unsigned int height){
    unsigned int i;
    for(i=0 ; i<=height ; i++){
        draw_line(window, pos_x, pos_y+i, pos_x+width, pos_y+i);
    }
}
//Affiche le splash "Puissance 4"
void splash()
{
    window w = create_splash(680, 384, 425, 100, "splash", blue);

    // Lettres en  jaune :
    change_color(w, yellow);
    //P
    draw_line(w, 25, 25, 25, 75);
    draw_line(w, 25, 25, 45, 37);
    draw_line(w, 25,49, 45, 37);

    //I
    draw_line(w, 105, 25, 105, 75);

    //S
    draw_line(w, 165, 25, 185, 25);
    draw_line(w, 165, 25, 165, 50);
    draw_line(w, 185, 50, 185, 75);
    draw_line(w, 165, 50, 185, 50);
    draw_line(w, 165, 75, 185, 75);
    //N
    draw_line(w, 245, 75, 245, 25);
    draw_line(w, 245, 25, 265, 75);
    draw_line(w, 265, 75, 265, 25);
    //C
    draw_line(w, 325, 25, 325, 75);
    draw_line(w, 325, 25, 345, 25);
    draw_line(w, 325, 75, 345, 75);
    draw_line(w, 325, 50, 345, 50);


    //lettres en rouge :
    change_color(w, red);
    //U
    draw_line(w, 65, 25, 65, 75);
    draw_line(w, 65, 75, 85, 75);
    draw_line(w, 85, 25, 85, 75);
    //S
    draw_line(w, 125, 25, 145, 25);
    draw_line(w, 125, 25, 125, 50);
    draw_line(w, 145, 50, 145, 75);
    draw_line(w, 125, 50, 145, 50);
    draw_line(w, 125, 75, 145, 75);
    //A
    draw_line(w, 205, 75, 215, 25);
    draw_line(w, 215, 25, 225, 75);
    draw_line(w, 210, 50, 220, 50);
    //C
    draw_line(w, 285, 25, 285, 75);
    draw_line(w, 285, 25, 305, 25);
    draw_line(w, 285, 75, 305, 75);
    //4
    draw_line(w, 365, 25, 365, 50);
    draw_line(w, 365, 50, 385, 50);
    draw_line(w, 375, 25, 375, 75);

    getch();
    close_window(w);
}
//Crée la fenêtre de jeu et dessine le plateau
void draw_board(window window){
    int a = 0, b = 0;
    change_color(window, blue);
    draw_rectangle_full(window, 50, 50, 700, 600);

    change_color(window, white);
    for(int l=0 ; l<=5 ; l++){
    for(int i=0; i<=6 ;i++){
        draw_disk(window, 100+a, 100+b, 40);
        a+=100;
    }
    b += 100;
    a=0;
    }
}
//Affiche le jeton joué sur le plateau de jeu
void put_jeton(window window, unsigned short num_ligne, unsigned short num_colonne, unsigned short num_joueur){
    if(num_joueur == 1){
        change_color(window, yellow);
    }
    else {
        change_color(window, red);
    }
    draw_disk(window, num_colonne*100, 700-num_ligne*100, 40);
}
//Teste la validité d'une colonne (existante ou pleine) et retourne la ligne jouable ou -1
short is_valid(unsigned short tableau[][7], unsigned short num_colonne){
    short num_ligne=1;
    if(num_colonne <1 || num_colonne >7){
        return -1;
    }
    while(num_ligne <= 6 && tableau[6-num_ligne][num_colonne-1] != 0){
        num_ligne++;
    }

    return num_ligne<=6?num_ligne:-1;
}
//Afficher le tableau correspondant au plateau (debug)
void affiche_tableau(unsigned short tab[][7]){
    for(int i=0;i<6;i++){
            for(int j=0;j<7;j++){
                cout << tab[i][j] << " ";
            }
            cout << endl;
        };
}
//Tester l'alignement de 4 jetons et si le tableau est plein sans alignement
unsigned short end_of_game(unsigned short t[][7], unsigned short c, unsigned short j,unsigned short l){
    int l0 = l, alig=0, c0;
    unsigned short inc = 0;
    //test en colonne
    if(l0>=4){
        alig = 0;
        while(l0 >= 1 && t[6-l0][c-1] == j){
            alig++;
            l0--;
    }}
    if(alig >=4){
        return 1;
    }

    //test en ligne
    //test de droite à gauche
    c0 = c;
    alig = 0;
    while(c0>=0 && t[6-l][c0-1] == j){
        c0--;
        alig++;
    }
    if(alig >=4){
        return 1;
    }
    //test de gauche à droite
    c0 = c+1;
    while(c0 <= 6 && t[6-l][c0-1] == j){
        c0++;
        alig++;
    }
    if(alig >=4){
        return 1;
    }

    //test diagonale gauche à droite
    c0 = c;
    l0 = l;
    alig = 0;
    while(c0>=1 && l0 >=1 && t[6-l0][c0-1] == j){
                  c0--;
                  l0--;
                  alig++;
              }
    c0 = c+1;
    l0=l+1;
    while(c0 <= 6 && l0 <= 6 && t[6-l0][c0-1] == j){
                  l0++;
                  c0++;
                  alig++;
              }
    if(alig >=4){
                  return 1;
              }
    //test diagonale droite à gauche
    c0 = c;
    l0 = l;
    alig = 0;
    while(c0<=6 && l0 >=1 && t[6-l0][c0] == j){
                  c0++;
                  l0--;
                  alig++;
              }
    c0 = c-1;
    l0=l+1;
    while(c0 >=1 && l0 <= 6 && t[6-l0][c0] == j){
                  l0++;
                  c0--;
                  alig++;
              }
    if(alig >=4){
                  return 1;
              }
   for(int i=0 ; i<7 ; i++){
       if(t[0][i] != 0){
       inc++;
   }}
       if(inc >= 7 && alig != 4){
           return 2;
       }
    return 0;
}
