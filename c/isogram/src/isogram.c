/*
 * Implementation of is_isogram functionality
 *
 * Details:
 * Determine if a word or phrase is an isogram.
 *
 * An isogram (also known as a "nonpattern word") is a word or phrase without a repeating letter, however spaces and hyphens are allowed to appear multiple times.
 *
 * Examples of isograms:
 *
 *  - lumberjacks
 *  - background
 *  - downstream
 *  - six-year-old
 *
 * The word *isograms*, however, is not an isogram, because the s repeats.
 */
#include "isogram.h"

bool is_isogram(const char* phrase)
{
    char *step = 0, *compare = 0;
    if (!phrase)
    {
        return (false);
    }
    for (compare = (char *)phrase; *compare; compare++)
    {
        if (!isalpha(*compare)) continue;
        for (step = (char *)phrase; *step; step++)
        {
            if (step == compare) continue;
            if (!isalpha(*step)) continue;
            if (tolower(*step) == tolower(*compare))
            {
                return (false);
            }
        }
    }
    return (true);
}
