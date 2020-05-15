/* Commentaire */
int a;
int main(){
int t2; 
int t1; 
int a;
int b;
int d;
a = 0;
b = 1;
t1 = a + b ;
c = t1;
/* Commentaire
  sur 
  plusieurs
  lignes */
t2 = b + c ;
d = t2;
if (a==0) goto Lelse1;
{
return 1;
}

Lelse1:
{
return 2;
}


goto Ltest1;

Lfor1:
i = 0;
i = i + 1 ;
printf(TEST);

Ltest1:
if (i<100) goto Lfor1;

if (b!=0) goto Lelse2;
{
return 3;
}

Lelse2:
{
return 4;
}

return 0;
}
