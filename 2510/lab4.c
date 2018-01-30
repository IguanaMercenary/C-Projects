#include <stdio.h>
#include <string.h>

int is_valid(const char s[]);

int main(void) {
	is_valid();
	return 1;
}

int is_valid(const char s[]){
	size_t len;
	size_t i;
	
	
	len = strlen(s);
	if((!(2 <= len && len <= 19)))
		return 0;
	
	
	for(i=0; s[i] !='\0'; i++;)
		if(!(isalpha(s[i]) || s == '-'))) 
			return 0;
		/*if the first letter or the last letter is "-"  then it is not valid */
		 
	
	return s[0] != '-' && s[len-1] != '-'; 	
}