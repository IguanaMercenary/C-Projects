/* Asn2. Compares two files word by word or char by char depending on the user's input of switches.
* author Michael O'Connell
* version 2016-11-05
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define WORDSIZE 256

int char_compare(FILE *fp1, FILE *fp2, int isCaseInsensitive, int maxCompare, int skipInFile1, int skipInFile2);
int compare_word(FILE *fp1, FILE *fp2, int isCaseInsensitive, int maxCompare, int skipInFile1, int skipInFile2);
void string_toLower(char s[]);

/* The main function. Drives the program. Takes in at least 3 arguments. */
int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;

    int i;
    int isWord = 0;
    int isCaseInsensitive = 0;
    int maxCompare = INT_MAX;
    int read;
    int numsInFile1;
    int numsInFile2;
    int skipInFile1 = 0;
    int skipInFile2 = 0;
    char dash, argument, comma;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s some_file_names\n", argv[0]);
        return 1;
    }
    
	/* Loops through the argc's to first check that there is a dash and then check what the switches are. */
    for (i = 1; i < argc; i++) {
        if(argv[i][0] != '-') {
            break;
        }
        if (strcmp("--", argv[i]) == 0) {
            i++;
            break;
        }
        if (strcmp("-w", argv[i]) == 0) {
            isWord = 1;
        }
        else if (strcmp("-i", argv[i]) == 0) {
            isCaseInsensitive = 1;
        }
		/* Scans the argv and assigns what is read to respective variables.*/
        else {
            read = sscanf(argv[i], "%c%c%d%c%d", &dash, &argument, &numsInFile1, &comma, &numsInFile2);
            if (read < 3) {
                return 2;
            }
            else {
                switch (argument) {
                case 'n':
                    maxCompare = numsInFile1;
                    break;
                case 's':
                    if (read == 3) {
                        skipInFile1 = numsInFile1;
                        skipInFile2 = numsInFile1;
                    }
                    else {
                        skipInFile1 = numsInFile1;
                        skipInFile2 = numsInFile2;
                    }
                    break;
                default:
                    return 2;
                }
            }
        }
    }
	if ((argc - i) != 2) {
		return 3;
	}
	if ((fp1 = fopen(argv[i], "rb")) == 0) {
        perror("fopen");
        return 2;
    }
    if ((fp2 = fopen(argv[i+1], "rb")) == 0) {
        perror("fopen");
        return 3;
    }

	/* If the -w switch is true then the program will compare word by word 
	   else it compares char by char*/
    if (isWord) {
        i = compare_word(fp1, fp2, isCaseInsensitive, maxCompare, skipInFile1, skipInFile2);
    }
    else {
        i = char_compare(fp1, fp2, isCaseInsensitive, maxCompare, skipInFile1, skipInFile2);
    }

    fclose(fp1);
    fclose(fp2);

    if (i == 0) {
        printf("ranges are equal\n");
        return 0;
    }
    else if (i == -1) {
        printf("EOF on %s\n", argv[argc - 2]);
    }
    else if (i == -2) {
        printf("EOF on %s\n", argv[argc - 1]);
    }
    else if (i > 0) {
        if (isWord) {
            printf("ranges differ: word %d\n", i);
        }
        else {
            printf("ranges differ: char %d\n", i);
        }
    }
    return 1;
}

/* Compares char by char. Takes in two files and the switch statement values. */
int char_compare(FILE *fp1, FILE *fp2, int isCaseInsensitive, int maxCompare, int skipInFile1, int skipInFile2) {
    int ch1, ch2;
    int charCount = 1;
    int i;

	/* First the function checks to see how many char's it should skip based on the switch values. */
    for (i = 0; i < skipInFile1; i++) {
        fgetc(fp1);
    }
    for (i = 0; i < skipInFile2; i++) {
        fgetc(fp2);
    }

	/* Loops through the files and gets the char of each. Increments charCount 
	   and returns it to indicate where the char's are different. */
    while (charCount <= maxCompare) {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);
        if (ch1 == EOF || ch2 == EOF) {
            if (ch2 != EOF)
                return -1;
            if (ch1 != EOF)
                return -2;
            return 0;
        }
        if (isCaseInsensitive == 1) {
            ch1 = tolower(ch1);
            ch2 = tolower(ch2);
        }
        if (ch1 != ch2) {
            return charCount;
        }
        charCount++;
    }
    return 0;
}

/* Compares word for word each file. Takes in parameters passed to it from main function. */
int compare_word(FILE *fp1, FILE *fp2, int isCaseInsensitive, int maxCompare, int skipInFile1, int skipInFile2) {
    char word1[WORDSIZE];
    char word2[WORDSIZE];
    int diffWord = 1;
    int i;
    int readWord1;
    int readWord2;

	/* Skips the number of words stated by the switch statement */
    for (i = 0; i < skipInFile1; i++) {
        fscanf(fp1, "%s", word1);
    }
    for (i = 0; i < skipInFile2; i++) {
        fscanf(fp2, "%s", word2);
    }

	/* Loops through while the number of words that are different are less than
       the maximum number of words set by the user or until a value is returned. */
    while (diffWord <= maxCompare) {
        readWord1 = fscanf(fp1, "%s", word1);
        readWord2 = fscanf(fp2, "%s", word2);
        if (readWord1 <= 0 || readWord2 <= 0) {
            if (readWord2 > 0)
                return -1;
            if (readWord1 > 0)
                return -2;
            return 0;
        }

        if (isCaseInsensitive == 1) {
            string_toLower(word1);
            string_toLower(word2);
        }
		/* strcmp returns 0 when the words are equal so this if remains false
		   as long as the words continue to be equal. Once they are not equal it returns the
		   spot where the two words are different. */
        if (strcmp(word1, word2)) {
            return diffWord;
        }
        diffWord++;
    }
    return 0;
}

/* Converts the char array to lower case letters and stores it back in the array. 
   Function is called when case insensitive switch is selected.*/
void string_toLower(char s[]) {
    size_t i;
    for (i = 0; s[i] != '\0'; i++) {
        s[i] = tolower(s[i]);
    }
}