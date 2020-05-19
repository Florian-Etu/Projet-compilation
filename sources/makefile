LEX = flex
YACC = bison -dy
CC = gcc

structfe: structbe structfe.c yaccfe lexfe
	$(CC) lex.yy.c y.tab.c -o structfe
	
yaccfe: structfe.y
	$(YACC) structfe.y
	
lexfe: structfe.l
	$(LEX) structfe.l
	
structbe: structbe.c yaccbe lexbe
	$(CC) lex.yy.c y.tab.c -o structbe
	
yaccbe: structfe.y
	$(YACC) structbe.y
	
lexbe: structfe.l
	$(LEX) structbe.l