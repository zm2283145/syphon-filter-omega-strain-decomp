#include "types.h"
typedef union { __int128 q; char s[16]; } KeyCA70;
typedef struct { __int128 q; char pad[0x10]; } EntCA70;
typedef struct { char pad[0xE0]; EntCA70 e[(0x2420 - 0xE0) / 0x20]; unsigned short count; } TblCA70;
typedef struct { char pad[0x8C]; TblCA70* tbl; char pad74[0x10C - 0x90]; char idx; } ObjCA70;
extern char D_004B9F80[];
extern void String_Copy(char* dst, const char* src);
static inline int kca70eq(__int128 m, __int128 a, __int128 b) {
    __int128 r;
    asm {
        pand r, m, a
        pand b, m, b
        pceqw r, r, b
        ppach r, r, r
    }
    return (long)r == -1;
}
static inline __int128 kca70q(__int128 v) { __int128 r; asm { pcpyld r, $zero, v } return r; }
void func_00341980(ObjCA70* self) {
    __int128 mask = kca70q(0xFFFFFFFF00);
    KeyCA70 key;
    int i;
    String_Copy(key.s, D_004B9F80);
    
    for (i = 0; i < self->tbl->count; i++) {
        if (kca70eq(mask, key.q, self->tbl->e[i].q)) {
            self->idx = i;
            return;
        }
    }
}



