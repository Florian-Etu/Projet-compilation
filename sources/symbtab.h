#define MAXSYMB 100

struct symtab {
    char *name;
    int value;
    char *type;
} symtab[MAXSYMB];

struct symtab *add();
struct symtab *find();
