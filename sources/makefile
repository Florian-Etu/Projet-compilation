LEX = flex
YACC = bison -dy
CC = gcc
FE = ./structfe
BE = ./structbe

structbe: structfe structbe.c yaccbe lexbe
	$(CC) lex.yy.c y.tab.c -o structbe
	$(FE) add.c compteur.c cond.c div.c expr.c functions.c listes.c loops.c mul.c neg.c pointeur.c sub.c variables.c
	$(BE) add_3.c compteur_3.c cond_3.c div_3.c expr_3.c functions_3.c listes_3.c loops_3.c mul_3.c neg_3.c pointeur_3.c sub_3.c variables_3.c
	
structfe: structfe.c yaccfe lexfe
	$(CC) lex.yy.c y.tab.c -o structfe
	
yaccfe: structfe.y
	$(YACC) structfe.y
	
lexfe: structfe.l
	$(LEX) structfe.l

yaccbe: structfe.y
	$(YACC) structbe.y
	
lexbe: structfe.l
	$(LEX) structbe.l
	