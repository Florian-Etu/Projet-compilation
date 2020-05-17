## Test Lex sous Linux
1) lex ANSI-C.l
2) gcc TestLex.c lex.yy.c -o myTest
3) ./myTest <Minimal.c

## Parsage front-end sous Windows
1) flex structfe.l
2) bison -dy structfe.y
3) gcc lex.yy.c y.tab.c -o structfe.exe
4) structfe.exe Minimal.c

## Parsage back-end sous Windows
1) flex structbe.l
2) bison -dy structbe.y
3) gcc lex.yy.c y.tab.c -o structbe.exe
4) structbe.exe exemple-strucit-backend.c

## Parsage front-end sous Linux
1) flex structfe.l
2) bison -dy structfe.y
3) gcc lex.yy.c y.tab.c -o structfe
4) ./structfe Minimal.c

## Parsage back-end sous Linux
1) flex structbe.l
2) bison -dy structbe.y
3) gcc lex.yy.c y.tab.c -o structbe
4) ./structbe exemple-strucit-backend.c

## Executer le compilateur + parseur back-end sur tous les fichiers tests sous Windows
1) structfe.exe add.c compteur.c cond.c div.c expr.c functions.c listes.c loops.c mul.c neg.c pointeur.c sub.c threadr.c variables.c
2) structbe.exe add_3.c compteur_3.c cond_3.c div_3.c expr_3.c functions_3.c listes_3.c loops_3.c mul_3.c neg_3.c pointeur_3.c sub_3.c threadr_3.c variables_3.c

## Executer le compilateur + parseur back-end sur tous les fichiers tests sous Linux
1) ./structfe add.c compteur.c cond.c div.c expr.c functions.c listes.c loops.c mul.c neg.c pointeur.c sub.c threadr.c variables.c
2) ./structbe add_3.c compteur_3.c cond_3.c div_3.c expr_3.c functions_3.c listes_3.c loops_3.c mul_3.c neg_3.c pointeur_3.c sub_3.c threadr_3.c variables_3.c