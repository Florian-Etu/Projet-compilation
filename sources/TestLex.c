#include <stdio.h>
#include "TestLex.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

int main(void)
{
  int ntoken, vtoken;
  ntoken = yylex();
  while(ntoken)
    {
      if(ntoken<41 && ntoken>=0)
      printf("%d\n", ntoken);
      ntoken = yylex();
    }
  return 0;
}
