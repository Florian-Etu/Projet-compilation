## Test Lex sous Linux
1) lex ANSI-C.l
2) gcc TestLex.c lex.yy.c -o myTest
3) ./myTest <Minimal.c

## Parsage front-end sous Windows
1) flex structfe.l
2) bison -dy structfe.y
3) gcc lex.yy.c y.tab.c -o structfe.exe
4) structfe.exe <Minimal.c

Note : un message devrait afficher si le parsage s'est bien effectué correctement (ou non)