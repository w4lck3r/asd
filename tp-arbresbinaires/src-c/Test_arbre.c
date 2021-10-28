#include <stdio.h>
#include <stdlib.h>

#include "ArbreBinaire.h"

#define max(a,b) ((a)>(b)?(a):(b))

#define DEBUT_ARBRE_MYSTERIEUX 12
#define FIN_ARBRE_MYSTERIEUX 24

/* Manipulation d'arbres binaires */

Noeud_t arbre1 (void) {
   
   Noeud_t arbre, sous_arbre_gauche, sous_arbre_droit;
   
   arbre = CreerNoeud(12) ;
   sous_arbre_gauche = CreerNoeud(9) ;
   AjouterGauche(arbre,sous_arbre_gauche);
   sous_arbre_droit = CreerNoeud(8) ;
   AjouterDroite(arbre,sous_arbre_droit);
   return arbre ;
}

Noeud_t arbre2 (void) {
   
   Noeud_t arbre, sous_arbre_gauche, f_sous_arbre_droite, f2_sous_arbre_gauche;

   arbre = CreerNoeud(12) ;
   sous_arbre_gauche = CreerNoeud(9) ;
   AjouterGauche(arbre,sous_arbre_gauche);
   f_sous_arbre_droite = CreerNoeud(5);
   AjouterDroite(sous_arbre_gauche,f_sous_arbre_droite);
   f2_sous_arbre_gauche = CreerNoeud(7);
   AjouterGauche(f_sous_arbre_droite,f2_sous_arbre_gauche);
   return arbre;
}

Noeud_t arbre3 (void) {
   
   Noeud_t arbre, gauche, droite, gauche1, droite1, droite2,gauche2, droite3;

   arbre = CreerNoeud(12);
   gauche = CreerNoeud(9);
   AjouterGauche(arbre,gauche);
   droite= CreerNoeud(8);
   AjouterDroite(arbre,droite);
   gauche1 = CreerNoeud(1);
   AjouterGauche(gauche,gauche1);
   droite1= CreerNoeud(5);
   AjouterDroite(gauche,droite1);
   droite2 = CreerNoeud(4);
   AjouterDroite(droite,droite2);
   gauche2= CreerNoeud(7);
   AjouterGauche(droite2,gauche2);
   droite3= CreerNoeud(6);
   AjouterDroite(droite2,droite3);

   return arbre;
}

void imprimer (Noeud_t a) {
   if(! EstVide(a)){
      imprimer(Gauche(a));
      printf("%ld ", ValeurDuNoeud(a));
      imprimer(Droite(a));
   }
}

int taille (Noeud_t a) {
   int cpt=0;
   if(EstVide(a)){cpt=cpt+0;}
   else{
      if(EstFeuille(a)){cpt++;}
      cpt=1+(taille(Gauche(a))+taille(Droite(a)));
   }
   
   return cpt;
}

int hauteur (Noeud_t a) {
   if(EstVide(a)){return -1;}
   else{
      return 1+max(hauteur(Gauche(a)),hauteur(Droite(a)));
   }
}

int nbFeuilles(Noeud_t a) {
   int cpt=0;
   if(EstVide(a)){
      cpt=cpt+0;
   }
   else{
      if(EstFeuille(a)){cpt=cpt+1;}
      else{cpt= cpt+ nbFeuilles(Gauche(a))+nbFeuilles(Droite(a));}
   }
   return cpt;
}



/* Comptage d'arbres */

int nbArbres(int n) {
   int i;
   int cn=0;
   if (n==0) return 1;
   else{
      for(i=0;i<n;i++){
         cn+=nbArbres(i)*nbArbres(n-1-i);
      }
   }
   return cn;
}

int nbArbresEfficace(int n){
   int i,k;
   int cn[20];
   if (n==0){ 
      return 1;
   }
   else{
      cn[0]=1;
      for(k=1;k<=n;k++){
         cn[k]=0;
         for(i=0;i<k;i++){
         cn[k]+=cn[i]*cn[k-i-1];
      }
      } 
   }
   return cn[n];
}
    
/* Manipulation d'arbres binaires de recherche */

Noeud_t abr1 (void) {
   Noeud_t arbre,sous_arbre_gauche,sous_arbre_gauche1,sous_arbre_droit,sous_arbre_droit_gauche,sous_arbre_gauche2;

   arbre= CreerNoeud(6);
   sous_arbre_gauche= CreerNoeud(4);
   AjouterGauche(arbre,sous_arbre_gauche);
   sous_arbre_gauche1 = CreerNoeud(2);
   AjouterGauche(sous_arbre_gauche,sous_arbre_gauche1);
   sous_arbre_droit = CreerNoeud(7);
   AjouterDroite(arbre,sous_arbre_droit);
   sous_arbre_droit_gauche = CreerNoeud(5);
   AjouterDroite(sous_arbre_gauche,sous_arbre_droit_gauche);
   sous_arbre_gauche2 = CreerNoeud(1);
   AjouterGauche(sous_arbre_gauche1,sous_arbre_gauche2);
   return arbre;
}




/*
Noeud_t ajouter (value_t v, Noeud_t a) {
   Noeud_t arbre;

   arbre=CreerNoeud(v);
   if(EstVide(a)){
      return arbre;
   }
   else{
      if(ValeurDuNoeud(a)>=v){
      AjouterGauche(a,arbre)
      }
      else{
         AjouterDroite(a,arbre);
      }
   }
   ajouter(v,gauche(a));
   ajouter(v,droite(a));
   return a;
}
*/

Noeud_t ajouter (value_t v, Noeud_t a) {
   
   Noeud_t n_v;
   if(EstVide(a)){
      a = CreerNoeud(v);
   }
   else if(v>ValeurDuNoeud(a)){
      
      n_v = ajouter(v,Droite(a));
      RemplacerDroite(a,n_v);
   }
   else{
      n_v = ajouter(v,Gauche(a));
      RemplacerGauche(a,n_v);
   }

   return a;
}

Noeud_t abr2 (void) {
   Noeud_t arbre;

   arbre=CreerNoeud(5);
   ajouter(4,arbre);
   ajouter(2,arbre);
   ajouter(7,arbre);
   ajouter(6,arbre);
   ajouter(1,arbre);
   
   return arbre;
}

Noeud_t abr3 (void) {
   Noeud_t arbre;
   
   arbre = CreerNoeud(7);
   ajouter(1,arbre);
   ajouter(4,arbre);
   ajouter(5,arbre);
   ajouter(6,arbre);
   ajouter(2,arbre);
   return arbre;
}


int appartient (value_t v, Noeud_t a) {
   int res;
   if (EstVide(a)) res=0;
   else{
       if (v==ValeurDuNoeud(a)) res=1;
         else{
            if(v>ValeurDuNoeud(a)){
             res = appartient(v,Droite(a));
            }  
            if(v<ValeurDuNoeud(a)){
               res = appartient(v,Gauche(a));
            }
         }
   }
   return res;

}

int nb_cmp (value_t v, Noeud_t a) {
   int res=0;
   if (EstVide(a)) res=0;
   else{
      res+=1;
      if (v==ValeurDuNoeud(a)){}
      else{
         res +=1;  
         if(v<ValeurDuNoeud(a)){
            res += nb_cmp(v,Gauche(a));
         }
         else{ 
            res +=1;
            if(v>ValeurDuNoeud(a)){
               res += nb_cmp(v,Droite(a));
               }
            }
         
        
         }
   }
   return res;

}

int valeur_minimale (Noeud_t abr) {
   int min;
   if(EstVide(abr)){
      min=-1;
   }
   
   else{
      min = ValeurDuNoeud(abr);
      if (! EstVide(Gauche(abr))){
         min= valeur_minimale(Gauche(abr));
      }
   }
   return min;
}
   

int valeur_maximale (Noeud_t abr) {
   int max;
   if(EstVide(abr)){
      max=-1;
   }
   
   else{
      max = ValeurDuNoeud(abr);
      if (! EstVide(Droite(abr))){
         max= valeur_minimale(Droite(abr));
      }
   }
   return max;
}

/* Entier mysterieux */

/*Noeud_t construitArbreEntierMysterieux (value_t i, value_t j) { 
   
   Noeud_t arbre , gauche , droite;
   value_t mediane=(i+j)/2;
   if(i==j){
      return CreerNoeud(mediane);
   }
   else{
      if(i!=0 && j!=0){
         arbre= CreerNoeud(mediane);

         gauche= CreerNoeud(mediane/2);
         AjouterGauche(arbre, gauche);

         droite= CreerNoeud(i);
         AjouterDroite(arbre, droite);

         construitArbreEntierMysterieux(i,j);

      }
   }
   
   return arbre;
}*/

Noeud_t construitArbreEntierMysterieux (value_t i, value_t j) { 
   value_t mediane ;
   Noeud_t racine, gauche, droite;
   if(i>j){
      racine= CreerArbreVide();
   }
   else{
      mediane = (i+j)/2;
      if(mediane!=0){
         racine = CreerNoeud(mediane);
         gauche = construitArbreEntierMysterieux(i,mediane-1);
         AjouterGauche(racine, gauche);
         droite = construitArbreEntierMysterieux(mediane+1, j);
         AjouterDroite(racine, droite);
      }
   }
   return racine;
}

void jouer (int i, int j,int entierMystere) {
   int gagne = 0;
   Noeud_t arbre = construitArbreEntierMysterieux(i, j);
   if(!appartient(entierMystere, arbre)){
      printf("l'entier doit etre compris entre %d et %d !\n", i, j);
      exit(EXIT_FAILURE);
   }else{
      while(!gagne){
         printf("est-ce %ld ?\n", ValeurDuNoeud(arbre));
         if(entierMystere<ValeurDuNoeud(arbre)){
            printf("trop grand\n");
            arbre = Gauche(arbre);
         }
         else if(entierMystere>ValeurDuNoeud(arbre)){
            printf("trop petit\n");
            arbre = Droite(arbre);
         }
         else{
            printf("gagne!\n");
            gagne = 1;
         }
      }
   }
}

/* Tests sur les arbres binaires */

void testArbreBinaire(Noeud_t a) {
   imprimer(a); printf("\n");
   printf("Taille     = %d\n",(taille(a)));
   printf("Hauteur    = %d\n",(hauteur(a)));
   printf("nbFeuilles = %d\n",(nbFeuilles(a)));
}

/* Tests sur les arbres binaires de recherche */
void testABR (Noeud_t a) {
   int i;
   imprimer(a); printf("\n");
   printf("Taille     = %d\n",(taille(a)));
   printf("Hauteur    = %d\n",(hauteur(a)));
   printf("nbFeuilles = %d\n",(nbFeuilles(a)));
   printf("Valeurs présentes dans l'arbre : ");
   for (i = 0; i <= 10; i++) {
      if (appartient(i,a)) {
         printf("%d ",i);
      }
   }
   printf("\n");
   printf("Le nombre de comparaisons pour trouver le 0 est  : ");
   printf("%d", nb_cmp(0,a));
   printf("\n");
   printf("La valeur minimale du noeud est : ");
   printf("%d", valeur_minimale(a));
   printf("\n");
   printf("La valeur maximale du noeud est : ");
   printf("%d", valeur_maximale(a));
   printf("\n");

}
  
/* Programme principal */
int main (int argc, char **argv) {

   int i;

   Noeud_t a1 = arbre1();
   Noeud_t a2 = arbre2();
   Noeud_t a3 = arbre3();
   
   testArbreBinaire(a1);
   testArbreBinaire(a2);
   testArbreBinaire(a3);

   DetruireArbre(a1);
   DetruireArbre(a2);
   DetruireArbre(a3);

   for (i = 0; i <= 19; i++) {
      printf("Le nombre d'arbres à %d noeuds est %d\n",i,(nbArbresEfficace(i)));
   }

   a1 = abr1();
   a2 = abr2();
   a3 = abr3();
   
   testABR(a1);
   testABR(a2);
   testABR(a3);

   DetruireArbre(a1);
   DetruireArbre(a2);
   DetruireArbre(a3);

   printf("Arbre mysterieux entre %d et %d:\n", DEBUT_ARBRE_MYSTERIEUX, FIN_ARBRE_MYSTERIEUX);
   imprimer(construitArbreEntierMysterieux(DEBUT_ARBRE_MYSTERIEUX, FIN_ARBRE_MYSTERIEUX));
   printf("\n");
  
   jouer(DEBUT_ARBRE_MYSTERIEUX, FIN_ARBRE_MYSTERIEUX,15);

   return 0;
   
}
