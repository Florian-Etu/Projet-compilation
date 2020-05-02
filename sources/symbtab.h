#define MAXSYMB 100

struct symtab {
    char *name;
    char *type;
	int size;
	int pos;
} symtab[MAXSYMB];

struct symtab *add();
struct symtab *find();
