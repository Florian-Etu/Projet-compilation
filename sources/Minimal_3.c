/* Commentaire */
int a;
int main()/* int a ; */
{
int t1; 
int a;
int b;
a = 0;
b = 1;
t1 = a + b ;
c = t1;
/* Commentaire
  sur 
  plusieurs
  lignes */
if (a==0) goto Lelse1;
{
{
int t2; 
int d;
t2 = b + c ;
d = t2;
return 1;
}
}

Lelse1:
{
return 2;
}

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
