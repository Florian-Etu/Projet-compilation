#define MAXSYMB 103

typedef struct tablesymboles{
    char* name;
    char* type;
	int val;
	struct tablesymboles *next;
} tablesymboles;

tablesymboles* table[MAXSYMB];


tablesymboles* add(char *name);
void reset();