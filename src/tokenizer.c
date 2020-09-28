#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
int space_char(char c) {
    return (c == ' ' || c == '\t') ? 1 : 0;
}
/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c) {
    return (c == ' ' || c == '\t') ? 0 : 1;
}

/* Returns a pointer to the first character of the next
   space-separated word in zero-terminated str.  Return a zero pointer if
   str does not contain any words. */
char *word_start(char *str) {
    for (char *s = str; *s != '\0'; ++s)
        if (space_char(*s))
            if (non_space_char(*(s+1)))
                return s+1;
    return NULL;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word) {
    char *s = word;
    for (; *s != '\0'; ++s)
        if (space_char(*s))
            return s;
    return s; // return the null terminator at end of string
}

/* Counts the number of words in the string argument. */
int count_words(char *str) {
    unsigned short i=1; // last word
    for(char *s = str; *s != '\0'; ++s) {
        if (space_char(*s))
            ++i;
    }
    return i; // will be more robust later
}

/* Returns a freshly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
    unsigned short c = 0;
    char *outStr = (char*)malloc(sizeof(char)*len+1);
    for (char *i=inStr, *o=outStr; c < len; ++i, ++o, ++c)
        *o = *i;
    *(outStr+len) = '\0';
    return outStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char **tokenize(char* str) {
    unsigned short m = count_words(str);
    char **tokens = (char**)malloc(sizeof(char*)*(m+1));
    char *l = str, *r = str;
    for(char **t = tokens; (int)(t-tokens) < m; ++t) {
        r = word_terminator(l);
        *t = copy_str(l, (int)(r-l));
        l = word_start(r);
    }
    *(tokens+m) = NULL;
    return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens) {
    for (char **t = tokens; *t != NULL; ++t)
        printf("%s\n", *t);
    return;
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);
