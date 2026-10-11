#include "types.h"

/* Lower-cased base name (no directory, no extension, max 16 chars) of a path. */
extern char* String_Copy(char* dst, const char* src);
extern char* strncpy(char* dst, const char* src, unsigned int n);
extern char* strchr(const char* s, int c);
extern char* strrchr(const char* s, int c);
extern int String_ToLower(int c);
extern unsigned int strlen(const char* s);

static inline unsigned int Min_3A5550(unsigned int a, unsigned int b) { return a < b ? a : b; }

void func_003A5550(char* out, const char* path, unsigned int n)
{
    char* p;
    char buf[0x80];
    unsigned int i;
    char* name;
    if (n == 0) {
        String_Copy(buf, path);
    } else {
        strncpy(buf, path, n);
        buf[n] = 0;
    }
    p = strchr(buf, '.');
    if (p)
        *p = 0;
    name = strrchr(buf, '\\');
    if (!name)
        name = buf;
    else
        name++;
    for (i = 0; i < Min_3A5550(strlen(name) + 1, 16); i++)
        *out++ = String_ToLower(name[i]);
}