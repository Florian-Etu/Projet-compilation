Le fichier suivant contient les instructions à entrer dans le terminal pour executer le compilateur front-end (vérification lexicale et syntaxique + générant un fichier de sortie) et back-end (vérification lexicale + syntaxique)
Note : Le makefile devrait permettre d'exécuter toutes les instructions présentes ici automatiquement (sous reserve que les fichiers tests soient dans le même dossier sinon il faudra le faire à la main)
Note 2 : lors de l'étape 4 du parsage front-end on propose ici de parser tous les tests d'un coup, il est bien sur possible d'indiquer uniquement ceux que l'on souhaite tester le cas échéant
# Important : normalement tous les fichiers tests réussissent le parsage (front-end et back-end)

# Sous Linux (testé sous la distrubution Ubuntu)
## Parsage front-end pour tous les fichiers tests (Linux)
1) flex structfe.l
2) bison -dy structfe.y
3) gcc lex.yy.c y.tab.c -o structfe
4) ./structfe add.c compteur.c cond.c div.c expr.c functions.c listes.c loops.c mul.c neg.c pointeur.c sub.c variables.c
# ATTENTION : les noms de fichiers doivent constitués les arguments de la ligne de commande, si on place un symbole de type < le parseur s'executera correctement mais il n'y aura alors aucun fichier généré (résultat sur la sortie standard uniquement)

## Parsage back-end sous Linux
1) flex structbe.l
2) bison -dy structbe.y
3) gcc lex.yy.c y.tab.c -o structbe
4) ./structbe add_3.c compteur_3.c cond_3.c div_3.c expr_3.c functions_3.c listes_3.c loops_3.c mul_3.c neg_3.c pointeur_3.c sub_3.c variables_3.c

# Sous Windows
## Parsage front-end sous Windows
1) flex structfe.l
2) bison -dy structfe.y
3) gcc lex.yy.c y.tab.c -o structfe.exe
4) structfe.exe add.c compteur.c cond.c div.c expr.c functions.c listes.c loops.c mul.c neg.c pointeur.c sub.c variables.c

## Parsage back-end sous Windows
1) flex structbe.l
2) bison -dy structbe.y
3) gcc lex.yy.c y.tab.c -o structbe.exe
4) structbe.exe add_3.c compteur_3.c cond_3.c div_3.c expr_3.c functions_3.c listes_3.c loops_3.c mul_3.c neg_3.c pointeur_3.c sub_3.c variables_3.c
