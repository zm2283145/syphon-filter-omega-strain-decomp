#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int, int, char*, int);
void* Mem_Alloc(int, int, char*, int);
int strlen(const char*);
void String_Copy(char*, char*);
extern char D_004C1EB0;
}
typedef struct { char pad[0x50]; int buf; int n; } S_459500;
extern "C" int func_00458A30(S_459500*);

static inline void Clear_459500(S_459500* s)
{
    int p = s->buf;
    if (p != 0) {
        {
            AllocGuard g;
            Mem_Free(0, p, &D_004C1EB0, 0x3F);
        }
        s->buf = 0;
    }
    s->n = 0;
}

extern "C" int func_00459500(S_459500* s, char* text)
{
    int len;
    int p;
    if (!text || !*text)
        return 0;
    Clear_459500(s);
    len = strlen(text) + 1;
    {
        AllocGuard g;
        p = (int)Mem_Alloc(0, len, &D_004C1EB0, 0x2E);
    }
    s->buf = p;
    String_Copy((char*)s->buf, text);
    s->n = 0;
    if (!func_00458A30(s))
        return 0;
    return 1;
}
