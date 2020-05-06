#define MAXSYMB 103

typedef struct _symbtab{
    	char *name;
    	char *type;
	int val;
	struct symbtab *next;
} symbtab;

symbtab *table[MAXSYMB];


symbtab *add(char *name);
void reset();

