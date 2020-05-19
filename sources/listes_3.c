/* Description d'une liste chainee */
extern int printd(int i);
void *affiche(void* p){
void* t1; 

if (p==0) goto Lelse1;
t1 = p + 0;
printd(t1);

return p;
}
/* Fonctions externes utilisées */
extern void *malloc(int size);
extern void free(void *ptr);
/* Allocation du prochain element de la liste */
void *allouer(void* p){

if (p==0) goto Lelse2;
{
void* t3; 
void* t2; 
t2 = p + 4;
t2 = malloc(4);
t3 = p + 4;
return t3;
}

Lelse2:
{
p = malloc(4);
return p;
}

}
/* Desallocation de l'element courant de la liste */
void *desallouer(void* p){
void* t4; 
void *q;
t4 = p + 4;
q = t4;
free(p);
return q;
}
/* Iterateur sur la liste. Applique la fonction f sur chaque element */
void *parcours(void* l,void* p){
int i;
void *p;
void *tete;
f(l);
p = f;
tete = p;
i = 0;

goto Ltest1;

Lfor1:
i = i + 1 ;
{
void* t5; 
f(p);
p = f;

if (p==0) goto Lelse3;
t5 = p + 0;
t5 = i;

}

Ltest1:
if (i<100) goto Lfor1;

return tete;
}
/* Alloue une liste chainee puis la desalloue */
int main(){
void *tete;
void *t;
parcours(0,0);
tete = parcours;
t = tete;
parcours(t,t);
parcours(tete,tete);
return 0;
}
