#include <stdio.h>
#include <ctype.h>
#define CHECK(PRED) printf("%s ... %s\n", (PRED) ? "Passed" : "Failed" , #PRED);

size_t str_find_last(const char s[], int c);
size_t str_replace_all(char s[], int oldc, int newc);
int str_all_digits(const char s[]);
int str_equal(const char s[], const char t[]);

int main(void){
	return 1;
}

/*
	Retruns the index of the last occurence of the character (scpecified by) c in the string s, 
	or returns -1 if the string does not contain c.
*/
size_t str_find_last(const char s[], int c){
	size_t i;
	size_t lastOccurance = -1;
	for(i = 0; s[i] != '\0'; i++){
		if(s[i] == c){
			lastOccurance = i;
		}
	}
	return lastOccurance;
}

/*
	Replaces all occurences of the character oldc in the string s by the character newc.
	Returns the number of replacments
*/
size_t str_replace_all(char s[], int oldc, int newc){
	size_t i;
	int count = 0;
	for(i=0; s[i] !='\0'; i++){
		if(s[i] == oldc){
			oldc = newc;
			count++;
		}
	}
	return count;
}

/*
	Returns 1 if the string s consists entirely of digits; otwerwise, returns 0.
*/
int str_all_digits(const char s[]){
	size_t i;
	for(i=0; s[i] !='\0'; i++){
		if(!(isdigit(s[i]))){
			return 0;
		}
	}
	return 1;
}

/*
	Returns 1 if the strings s and t have the same sequence of characters; otherwise, returns 0;
*/
int str_equal(const char s[], const char t[]){
	size_t i;
	for(i=0; s[i] != '\0'; i++){
		if(s[i] != t[i]){
			return 0;
		}
	}
	return (t[i] == '\0');
}