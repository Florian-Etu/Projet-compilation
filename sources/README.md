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
4) structbe.exe <exemple-strucit-backend.c

## Parsage back-end sous Linux
1) flex structfe.l
2) bison -dy structfe.y
3) gcc lex.yy.c y.tab.c -o structfe
4) ./structfe Minimal.c

## Parsage front-end sous Linux
1) flex structbe.l
2) bison -dy structbe.y
3) gcc lex.yy.c y.tab.c -o structbe
4) ./structbe <exemple-strucit-backend.c
