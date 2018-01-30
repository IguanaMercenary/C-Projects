#include <stdio.h>
#include <string.h>

#define LINESIZE 512
#define NAMESIZE 20
typdef struct {
	char last[NAMESIZE];
	char first[NAMESIZE];
} name;

typdef struct {
	name name;
	int score;
} record;

int get_record(const char *s, record *prec);
void print_record(const record, *prec);
int is_valid(const char s[]);
void string_toLower(char s[]);

int main (){
	char temp[LINESIZE];
	record rec;
	fgets(temp, LINESIZE, stdin);
	
}

int get_record(const char *s, record *prec) {
	int read;
	
	read = sscanf(s, "%s %s %d", prec->name.first, prec->name.last, prec->score);
	
	if(read < 3)
		return 0;
	
	if(!(score >= 0 && score <= 100))
		return 0;
	
	if(is_valid(prec->name.first) == 0)
		return 0;

	if(is_valid(prec->name.last) == 0)
		return 0;
	
	string_toLower(prec->name.first);
	string_toLower(prec->name.last);
	
	return 1;
}

void print_record(const record *prec) {
	printf("%s, %s: %d\n", prec->name.last, prec->name.fist, prec->score);
}

int is_valid(const char s[]){
	size_t len;
	size_t i;
	
	
	len = strlen(s);
	if((!(2 <= len && len <= (NAMESIZE-1)))
		return 0;
	
	
	for(i=0; s[i] !='\0'; i++;)
		if(!(isalpha(s[i]) || s == '-'))) 
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