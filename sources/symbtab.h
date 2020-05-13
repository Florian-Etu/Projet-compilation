#define MAXSYMB 103

typedef enum {INT_TYPE, VOID_TYPE, ID_TYPE, STRUCT_TYPE} type_t; 

typedef struct tablesymboles{
    char* name;
    int type;
	int val;
	struct tablesymboles* suivant;
} tablesymboles;

tablesymboles* table[MAXSYMB];

tablesymboles* addTS(char* name);
tablesymboles* addDTS(char* name);
tablesymboles* findTS(char* id);
void reset();