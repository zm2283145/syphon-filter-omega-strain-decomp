#include "types.h"
extern void* D_00532FE0;
extern char D_004B99D8[];
extern int sprintf(char*, const char*, ...);
extern char* Loc_LookupText(char*);
extern void func_0033D6A0(void*, char*, char*, char*, int, int);
extern char* String_CStr(void*);
char* func_0033CE30(void* self, unsigned char id, char* a, char* b, int c, int d) {
    char buf[16];
    char* t;
    if (!D_00532FE0) return D_004B99D8;
    sprintf(buf, "LOBBY_STR%d", id);
    t = Loc_LookupText(buf);
    if (!t) return D_004B99D8;
    func_0033D6A0(D_00532FE0, t, a, b, c, d);
    return String_CStr(D_00532FE0);
}
