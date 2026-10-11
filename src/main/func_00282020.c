#include "types.h"
extern char* D_005061D0;
static inline void W16_00282020(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_00282020(int v) { W16_00282020((unsigned short)v); W16_00282020(v >> 16); }
typedef struct { char pad[0xC]; int id; } O_00282020;
void func_00282020(O_00282020* o) {
    if (o) {
        W32_00282020(o->id);
    } else {
        W32_00282020(-1);
    }
}