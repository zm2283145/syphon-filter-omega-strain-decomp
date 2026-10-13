#include "types.h"
int String_ToLower(int c);
unsigned int strlen(const char* s);
int MemCardWrap_MatchName(char* pat, char* str)
{
    char* p;
    char* q;
    p = pat;
    q = str;
    while (*p != 0 && *q != 0 && *p != '*') {
        if (*p != '?') {
            if (String_ToLower(*p) != String_ToLower(*q))
                return 0;
        }
        p++;
        q++;
    }
    p = pat + strlen(pat) - 1;
    q = str + strlen(str) - 1;
    while (p >= pat && q >= str && *p != '*') {
        if (*p != '?') {
            if (String_ToLower(*p) != String_ToLower(*q))
                return 0;
        }
        p--;
        q--;
    }
    return 1;
}
