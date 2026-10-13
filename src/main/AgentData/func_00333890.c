#include "types.h"

extern int String_ToLower(int c);
extern int strlen(const char* s);

int func_00333890(void* self, const char* a, const char* b, char wild)
{
    int i = 0;
    int j = 0;
    while (a[i] != 0 && b[j] != 0 && a[i] != wild) {
        if (String_ToLower(a[i++]) != String_ToLower(b[j++])) return 0;
    }
    i = strlen(a);
    j = strlen(b);
    while (i >= 0 && j >= 0 && a[i] != wild) {
        if (String_ToLower(a[i--]) != String_ToLower(b[j--])) return 0;
    }
    return 1;
}
