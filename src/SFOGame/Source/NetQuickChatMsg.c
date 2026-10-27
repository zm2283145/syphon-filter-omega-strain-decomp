/*
 * SFOGame/Source/NetQuickChatMsg: 3 files, 003239A0-00323AD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003239A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int D_0052ACE0;

/* Message type id. */
int cNetQuickChatMsg_GetMsgId(void) {
    return D_0052ACE0;
}
static inline void merge_flush_func_003239A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003239A0 */

/* merge_units: begin func_003239B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_msg_clone.h"

/* Clone a network message. */
extern "C" { char D_004B7CA0[] = "NetQuickChatMsg.hh"; }
DEFINE_NET_MSG_CLONE(cNetQuickChatMsg_Clone, 0x2C, D_004B7CA0, 0x18, D_004DE630, NMC_W(0x24); NMC_W(0x28))
static inline void merge_flush_func_003239B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003239B0 */

/* merge_units: begin func_00323AD0 */
#pragma push /* merge_units */
#pragma cplusplus on
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
static inline void merge_flush_func_00323AD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00323AD0 */
