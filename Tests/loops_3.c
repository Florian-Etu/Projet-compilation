extern int printd(int i);
int main(){
int t2; 
int t1; 
int i;
i = 0;

goto Ltest3;

Lfor3:
{
printd(i);
i = i + 2 ;
}

Ltest3:
if (i<10) goto Lfor3;

t1 = -10;
i = t1;

goto Ltest4;

Lfor4:
i = i + 1 ;
printd(i);

Ltest4:
if (i<=10) goto Lfor4;

i = 0;

goto Ltest5;

Lfor5:
t2 = -20;
{
printd(i);
i = i + 1 ;
}

Ltest5:
if (i>=t2) goto Lfor5;

return 0;
}
