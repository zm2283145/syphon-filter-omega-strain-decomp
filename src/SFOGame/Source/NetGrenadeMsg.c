/*
 * SFOGame/Source/NetGrenadeMsg: 4 files, 0027BED0-0027C1A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027BED0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"
#include "v4_asm_copy.h"

/* Clone a network message (16-byte vector at 0x30, float at 0x40). */
#define NMC_F(off) (*(float*)((char*)p + (off)) = *(float*)((char*)self + (off)))
extern "C" { char D_004A92D0[] = "netGrenadeMsg.hh"; }
DEFINE_NET_MSG_CLONE(cNetGrenadeMsg_Clone, 0x50, D_004A92D0, 0x18, D_004DCDC0,
                     NMC_W(0x24);
                     { char* d = (char*)p + 0x30; char* s = (char*)self + 0x30; V4Copy(d, s); }
                     NMC_F(0x40))
static inline void merge_flush_func_0027BED0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027BED0 */

/* merge_units: begin func_0027C000 */
#pragma push /* merge_units */
typedef struct Msg {
    void* vtable;
    char base[0x20];
    int value;    /* 0x24 */
    char pad[0x28];
} Msg;
extern char D_00504068[];
extern char D_004DCDC0[];
extern char D_004DCF10[];
extern void cMessage_ctor_cMessageNameR(Msg* msg, void* name);
#if 0 /* merge_units */
extern void cNetGrenadeMsg_UnpackAndProcess(Msg* msg, void* target);
#endif /* merge_units */
void cNetGrenadeMsg_UnpackAndProcess(); /* merge_units */

extern void cMessage_dtor(Msg* msg, int flags);
/* Builds a message on the stack and dispatches it to target. */
void cNetGrenadeMsg_NetReceive(void* target)
{
    Msg msg;
    cMessage_ctor_cMessageNameR(&msg, D_00504068);
    msg.vtable = D_004DCDC0;
    msg.value = -1;
    cNetGrenadeMsg_UnpackAndProcess(&msg, target);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
static inline void merge_flush_func_0027C000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027C000 */

/* merge_units: begin func_0027C070 */
#pragma push /* merge_units */
extern unsigned char* D_005061D0;
static inline void W16_0027C070(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_0027C070(int v) { W16_0027C070((unsigned short)v); W16_0027C070(v >> 16); }
static inline void WF_0027C070(float f) { W32_0027C070(*(int*)&f); }
static inline short R16_0027C070(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_0027C070(void) { unsigned short lo = R16_0027C070(); return lo + ((unsigned short)R16_0027C070() << 16); }
static inline float RF_0027C070(void) { int i = R32_0027C070(); return *(float*)&i; }
typedef struct { char pad[0x4C]; int kind; } T_0027C070;
typedef struct { char pad[0x24]; int id; char p28[8]; float pos[4]; float f; } M_0027C070;
extern int g_HumanActorClassKey;
extern void cNetMsg_GetID(int* p);
extern float cNetMsg_GetFloat_void(void);
extern void cHuman_ThrowGrenade(float f, T_0027C070* t, int* id, float* pos);
void cNetGrenadeMsg_UnpackAndProcess(M_0027C070* m, T_0027C070* t) {
    cNetMsg_GetID(&m->id);
    m->pos[0] = cNetMsg_GetFloat_void();
    m->pos[1] = cNetMsg_GetFloat_void();
    m->pos[2] = cNetMsg_GetFloat_void();
    m->pos[3] = 1.0f;
    m->f = RF_0027C070();
    if (t && t->kind == g_HumanActorClassKey) cHuman_ThrowGrenade(m->f, t, &m->id, m->pos);
}
static inline void merge_flush_func_0027C070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027C070 */

/* merge_units: begin func_0027C1A0 */
#pragma push /* merge_units */
static inline void W16_0027C1A0(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_0027C1A0(int v) { W16_0027C1A0((unsigned short)v); W16_0027C1A0(v >> 16); }
static inline void WF_0027C1A0(float f) { W32_0027C1A0(*(int*)&f); }
typedef struct { char pad[0x24]; int id; char pad28[8]; float x; float y; float z; char pad3c[4]; float w; } M_0027C1A0;
extern void cNetMsg_PutFloat(float f);
void cNetGrenadeMsg_Pack(M_0027C1A0* m) {
    W32_0027C1A0(m->id);
    cNetMsg_PutFloat(m->x);
    cNetMsg_PutFloat(m->y);
    cNetMsg_PutFloat(m->z);
    WF_0027C1A0(m->w);
}
static inline void merge_flush_func_0027C1A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027C1A0 */
