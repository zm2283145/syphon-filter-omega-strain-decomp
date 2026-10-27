#pragma cplusplus on
#include "types.h"
extern "C" {
extern char* D_005061D0;
extern unsigned char g_IsMultiplayer;
extern char g_Game[];
void cGameSystem_SetClientPlayerLocation(char* a, int b, int c);
void func_002B1190(int a, int b, int c);
}
struct C_00323AD0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual bool v19(); };
typedef struct { char pad[0xC]; unsigned int flags; char pad10[0x48]; C_00323AD0* c; } O_00323AD0;
typedef struct { char pad[0x24]; int a; int b; } M_00323AD0;
static inline short R16_00323AD0(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_00323AD0(void) { unsigned short lo = R16_00323AD0(); return lo + ((unsigned short)R16_00323AD0() << 16); }
static inline int Idx_00323AD0(O_00323AD0* o) {
    if (g_IsMultiplayer) {
        unsigned char r = 0;
        if (o->c && o->c->v19()) r = 1;
        if (r) return ((o->flags & 0x7F000000) >> 24) - 1;
        return -1;
    }
    return 0;
}
extern "C" void cNetQuickChatMsg_UnpackAndProcess(M_00323AD0* m, O_00323AD0* o) {
    m->a = R32_00323AD0();
    m->b = R32_00323AD0();
    if (o) {
        if (m->a == -1) {
            cGameSystem_SetClientPlayerLocation(g_Game, Idx_00323AD0(o), m->b);
            return;
        }
        func_002B1190(m->a, Idx_00323AD0(o) + 1, m->b);
    }
}