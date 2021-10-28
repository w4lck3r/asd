
Le module ArbreBinaire permet de manipuler des arbres binaires. Afin
de vérifier que les arbres produits sont ceux auxquels vous vous
attendez, nous fournissons également une primitive qui prend un arbre,
le transforme en un fichier au format "gv" qui permet la visualisation
de l'arbre grâce au programme "dot".

Vous observerez attentivement la documentation dans ArbreBinaire.h
pour comprendre le fonctionnement des primitives.

Par exemple, le fichier exemple1_arbre.c contient la construction d'un
arbre puis produit le fichier "gv" de cet arbre. Pour construire cet
arbre et le visualiser, il suffit d'exécuter les commandes suivantes :

make exemple1_arbre
./exemple1_arbre # produit exemple1.gv
make exemple1.pdf # produit exemple1.pdf si exemple1.gv existe

Vous pouvez alors visualiser le pdf produit avec l’outil de votre choix.

Pour compiler le programme de test Test_arbre.c il suffira d'exécuter
make Test_arbre

et on pourra lancer ce programme grâce à
./Test_arbre
