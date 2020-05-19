extern int printd(int i);
int main(){
int i;
i = 0;

goto Ltest1;

Lfor1:
i = i + 1 ;
{
printd(i);
}

Ltest1:
if (i<1000) goto Lfor1;

return 0;
}
