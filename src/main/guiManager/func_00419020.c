#include "types.h"

extern void func_0036DEF0(void* f);
extern char* FileMan_ReadData(void* f);
extern void func_0036DEC0(void* f);
extern int func_00418FD0(void* self, char** cursor, int c);

static inline char Rd8_419020(char* volatile* c) { char* t = *c; char v = *t; *c = t + 1; return v; }

int func_00419020(void* self, void* file, int c)
{
    char* volatile p;
    char a;
    char b;
    char d;
    int r;
    func_0036DEF0(file);
    p = FileMan_ReadData(file);
    a = Rd8_419020(&p);
    b = Rd8_419020(&p);
    d = Rd8_419020(&p);
    if (a != 'G' || b != 'U' || d != 'I') return 0;
    p = (char*)(((int)p + 3) & ~3);
    p += 2;
    r = func_00418FD0(self, (char**)&p, c);
    func_0036DEC0(file);
    return r;
}


