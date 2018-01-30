#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NAMESIZE 20

typedef struct {
	char last[NAMESIZE];
	char first[NAMESIZE];
} name;

typedef struct {
	name name;
	int score;
} record;

typedef struct node node;
struct node {
	record data;
	node *next;
};

typedef node *record_list;
void print_record(const record *rec);
int is_valid(const char s[]);
void string_toLower(char s[]);
int get_record(const char *s, record *rec);
int list_insert_sorted(record_list *list, const record *rec);
int asc_name_desc_score(const void *a, const void *b);

int main (){
	char temp[NAMESIZE];
	record rec;
	if (fgets(temp, NAMESIZE, stdin) != 0) {
		get_record(temp, rec);
	}
	
	return 1;
}

void print_record(const record *rec) {
	printf("%s, %s: %d\n", rec->name.last, rec->name.fist, rec->score);
}

int is_valid(const char s[]){
	size_t len;
	size_t i;
	
	len = strlen(s);
	if((!(2 <= len && len <= (NAMESIZE-1)))) {
		return 0;
	}
	
	for(i=0; s[i] !='\0'; i++)
		if(!(isalpha(s[i]) || s == '-')) 
			return 0;
		/*if the first letter or the last letter is "-"  then it is not valid */
	
	return s[0] != '-' && s[len-1] != '-'; 	
}

void string_toLower(char s[]) {
    size_t i;
    for (i = 0; s[i] != '\0'; i++) {
        s[i] = tolower(s[i]);
    }
}

int get_record(const char *s, record *rec) {
	char first[NAMESIZE];
	char last[NAMESIZE];
	int score;
	int num_arg = sscanf(s, "%s %s %d", first, last, &score);
	
	if(num_arg < 3) {
		return 0;
	}
	
	if(is_valid(last) == 0) {
		return 0;
	}
	
	if(is_valid(first) == 0) {
		return 0;
	}
	
	if(score < 0 || score > 100) {
		return 0;
	}
	
	tolowercase(first);
	tolowercase(last);
	
	strcpy(prec -> name.first, first);
	strcpy(prec -> name.last, last);
	prec -> score = score;

	return 1;
}

int list_insert_sorted(record_list *list, const record *rec) {
	node **tracer;
	node *newnode;
	for(tracer = list; *tracer !=0; tracer = &(*tracer)->next) {
		if(asc_name_desc_score(&(*tracer)->data, rec)) {
			break;
		}
		newnode = malloc(sizeof(node));
		if(newnode == 0) {
			return 0;
		}
		newnode->data = *rec;
		newnode->next = *tracer;
		*tracer = newnode;
	}
	return 1;
}

int asc_name_desc_score(const void *a, const void *b) {
	const record *rec_A = a;
	const record *rec_B = b;
	int p;
	int q;
	
    p = strcmp(rec_A -> name.last, rec_B -> name.last);
	
    if (p != 0) {
        return p;
    } 
	
	q = strcmp(rec_A -> name.first, rec_B -> name.first);
	
	if(q != 0) {
		return q;
	}
	
	return (rec_B -> score - rec_A -> score);
}

