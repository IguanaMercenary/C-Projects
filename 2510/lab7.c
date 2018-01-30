#include <stdio.h>
#include <stdlib.h>

#ifndef BLOCK
	#define BLOCK 2
#endif


#define NAMESIZE 20

typedef struct {
	char last[NAMESIZE];
	char first[NAMESIZE];
} name;

typedef struct {
	name name;
	int score;
} record;

typedef struct record_list record_list;
struct record_list {
	record *data;
	size_t nalloc;
	size_t nused;
};

void list_init(record_list *plist);
void list_destroy(record_list *plist);
int list_insert(record_list *plist, const record *prec);


void list_init(record_list *plist) {
	plist->data = 0;
	plist->nused = 0;
	plist->nalloc = 0;
}

void list_destroy(record_list *plist) {
	free(plist);
	list_init(*plist);
}

int list_insert(record_list *plist, const record *prec) {
	
	if(plist->nused == plist->nalloc) {
		char *tmp = realloc(plist,(plist->nalloc + BLOCK)*sizeof(char*));
		if(tmp = 0) {
			return 0;
		}
		plist = tmp;
		plist->nalloc += BLOCK;
	}
	
	prec = plist;
}