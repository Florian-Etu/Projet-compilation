#define MAXSYMB 103

typedef struct tablesymboles{
    char* name;
    int type;
	int val;
	struct tablesymboles* suivant;
} tablesymboles;

tablesymboles* table[MAXSYMB];


tablesymboles* addTS(char* name, int type);
void reset();