/*
 * Implementation of abbreviate functionality
 *
 * Details:
 * Convert a phrase to its acronym.
 *
 * Techies love their TLA (Three Letter Acronyms)!
 *
 * Help generate some jargon by writing a program that converts a long name
 * like Portable Network Graphics to its acronym (PNG)
 *
 *
 */
#include "acronym.h"

#define DELIM_LIST_SIZE 10
#define MAX_TLA_SIZE 32 /*
                         * Assumption here is what the smaller acro is not going to exceed MAX_TLA_SIZE
                         * This is supposed to be a TLA - Three Letter Acronym
                         */

char *abbreviate(const char *phrase)
{
    char *str_chunk = (char *)NULL, *input = (char *)NULL, *acro = (char *)NULL;
    const char delim[DELIM_LIST_SIZE] = " ;\t\n:-_,\\";
    int  step = 0, len = 0;

    /* Check input params */
    if (!phrase)
    {
        return (NULL);
    }
    /* Capture the length - once, and use later*/
    len = strlen(phrase)+1;
    /* We cannot strtok on const input string, so make a copy */
    input = calloc(len, sizeof(char));
    if (!input) return NULL;
    (void)memcpy(input,phrase,len-1);
    input[len] = 0;
    /* Start to break it up */
    str_chunk = strtok(input, delim);
    if (str_chunk == NULL)
    {
        free(input);
        return (NULL);
    }
    /*
     * Store off the acronym to return, caller will be required to free
     * This is assumed, we could also have created a static array here,
     * and passed it's location back. But that is not really
     * what would be expected
     * */
    acro = calloc(1, sizeof(char));
    if (!acro) return NULL;
    acro[step++] = toupper(str_chunk[0]);
    /* Continue until we have nothing else to process from the input arg */
    while (str_chunk)
    {
        str_chunk = strtok(NULL, delim);
        if (str_chunk)
        {
            acro = realloc(acro, sizeof(acro)+1);
            if (!acro) return NULL;
            acro[step++] = toupper(str_chunk[0]);
        }
    }
    /* NULL terminate */
    acro[step] = 0;
    /* Remove the copy */
    free(input);
    return (acro);
}


#if DEBUG_WITH_MAIN
#include <stdio.h>
void main(void)
{
    printf("TEST:%s\n", abbreviate("This_is;not-me"));
    return;
}
#endif
