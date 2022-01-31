#include <iostream>
#include <conio.h>
#include <Xgeii.h>
#include <puissance4.h>
using namespace std;

/*
//Test de la structure pour revenir sur un coup
struct retour {
    unsigned short tableau[6][7];
    string nom_joueur[2];
    unsigned short joueur;
    struct retour *psuivant;
};
typedef struct retour coup ; */

int main(){


    //Déclarations du tableau représentant le plateau et des différentes variables
    unsigned short plateau[6][7] = {{0}};
    unsigned short num_colonne, num_joueur=1, end;
    string nom_joueur[2];
    short num_ligne;

    //Appel de la fonction affichant le splash & fermeture lors d'un appui sur une touche
    splash();

    //Déclaration de la fenêtre plateau de jeu
    window w = create_window(850, 100, 800, 700, "Puissance 4", black);

    //Appel de la fonction qui dessine le plateau de jeu
    draw_board(w);

    cout << "Saisir le nom du joueur 1 : " << endl;
    cin >> nom_joueur[0];
    cout << "Saisir le nom du joueur 2 : " << endl;
    cin >> nom_joueur[1];

    while(true){

        //saisie de la colonne jouée
        do{
            cout << "Entrez un numéro de colonne valide" << endl;
              cin >> num_colonne;
            num_ligne = is_valid(plateau, num_colonne);
          } while(num_ligne <0);

          if(num_ligne != -1){
          //vérif' et placement dans la colonne jouée à la ligne la plus basse disponible
              put_jeton(w, num_ligne, num_colonne, num_joueur);
              plateau[6-num_ligne][num_colonne-1] = num_joueur;
           } else
                cout << "Colonne pleine, rejouez votre coup." << endl;

          end = end_of_game(plateau,num_colonne, num_joueur, num_ligne);
          if(end != 0){
            if(end == 1){
                cout << nom_joueur[num_joueur-1] << " a gagné" << endl;
                break;
            }
            else {
                cout << "match nul" << endl;
                break;
            }
          }

          //changement de joueur & retour aux conditions initiales du test de ligne dispo
          num_joueur = !(num_joueur-1)+1;
          cout << "Au tour de " << nom_joueur[num_joueur-1] << endl;
          num_ligne=1;
      }
          getch();
          close_window(w);
          return 0;
}
