/*
 * SFOGame/Source/human: 6 files, 00184EB0-00185060
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00184EB0 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop

#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(func_00184EB0, D_004E01E0, D_004E0840, cMessage_dtor)
static inline void merge_flush_func_00184EB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00184EB0 */

/* merge_units: begin func_00184F20 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cNetShockMsg_dtor, D_004DA9F0, D_004DCF10, cMessage_dtor)
static inline void merge_flush_func_00184F20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00184F20 */

/* merge_units: begin func_00184F90 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad[0x20]; unsigned char on; char pad25[3]; float a; float b; } Msg_4F90;
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR(Msg_4F90*, void*);
#endif /* merge_units */
int cMessage_ctor_cMessageNameR(void*, void*); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) ((void)cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

void cNetMsg_GetChar(unsigned char*);
#if 0 /* merge_units */
void cNetMsg_GetFloat_floatR(float*);
#endif /* merge_units */
void cNetMsg_GetFloat_floatR(); /* merge_units */

#if 0 /* merge_units */
int cHuman_SubclassId(void);
#endif /* merge_units */
void * cHuman_SubclassId(); /* merge_units */

#if 0 /* merge_units */
int cGOBJ_CheckSubclassID(void*, int);
#endif /* merge_units */
int cGOBJ_CheckSubclassID(); /* merge_units */

void cHuman_Shock(void*, unsigned char, float, float, int);
#if 0 /* merge_units */
void cMessage_dtor(Msg_4F90*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

extern char D_004EF078[];
extern char D_004DA9F0[];
extern char D_004DCF10[];
/* net handler: shock the target to death when it accepts the request */
void Actor_OnShockMessage(void* target)
{
    Msg_4F90 m;
    cMessage_ctor_cMessageNameR(&m, D_004EF078);
    m.vt = D_004DA9F0;
    cNetMsg_GetChar(&m.on);
    cNetMsg_GetFloat_floatR(&m.a);
    cNetMsg_GetFloat_floatR(&m.b);
    if (target && cGOBJ_CheckSubclassID(target, cHuman_SubclassId())) cHuman_Shock(target, m.on, m.a, m.b, 0);
    m.vt = D_004DCF10;
    cMessage_dtor(&m, 0);
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00184F90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00184F90 */

/* merge_units: begin func_00185060 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern char g_HumanActorClassKey[];

int cGOBJ_CheckSubclassID(char* self, int* key) {
    return *(int*)(self + 76) == *key;
}

void* cHuman_SubclassId(void) {
    return g_HumanActorClassKey;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185060(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185060 */

/* merge_units: begin func_00185090 */
#pragma push /* merge_units */
extern unsigned char* D_005061D0; /* network read cursor */

static inline short read16(void)
{
    unsigned char lo = *D_005061D0++;
    unsigned char hi = *D_005061D0++;
    return lo + (hi << 8);
}

/* Reads a little-endian 32-bit float from the network read cursor. */
void cNetMsg_GetFloat_floatR(float* out)
{
    int bits[1];
    unsigned short lo = read16();
    bits[0] = lo + ((unsigned short)read16() << 16);
    *out = *(float*)bits;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185090(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185090 */

/* merge_units: begin func_00185140 */
#pragma push /* merge_units */
typedef struct { void* vtable; char base[0x18]; int size; unsigned char kind; char pad[3]; unsigned char value; unsigned char extra; char pad2[0xA]; } Msg_5140;
typedef struct { char pad[0x4C]; int classKey; char pad50[0x346B - 0x50]; unsigned char value; } Hum_5140;
#if 0 /* merge_units */
int cMessage_ctor_cMessageNameR(Msg_5140*, void*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

int QueueMessage_cMessageR_cSystemP_int(Msg_5140*, void*, int);
Hum_5140* cGOBJ_SOBJ_convert(int);
#if 0 /* merge_units */
int cMessage_dtor(Msg_5140*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((int)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

#if 0 /* merge_units */
extern int g_HumanActorClassKey;
#endif /* merge_units */
#define g_HumanActorClassKey (*(int*)&g_HumanActorClassKey) /* merge_units */


extern char D_004DA9D0[];
extern char D_004EEE98[];
extern unsigned char g_IsMultiplayer;
static inline void Set_5140(Hum_5140* self, unsigned char value, int silent) {
    Msg_5140 msg;
    self->value = value;
    if (g_IsMultiplayer && !silent) {
        cMessage_ctor_cMessageNameR(&msg, D_004EEE98);
        msg.vtable = D_004DA9D0;
        msg.extra = 1;
        msg.kind = 4;
        msg.size = 0x40;
        msg.value = value;
        QueueMessage_cMessageR_cSystemP_int(&msg, self, 0);
        msg.vtable = D_004DCF10;
        cMessage_dtor(&msg, 0);
    }
}
#pragma push
#pragma opt_propagation off
int Script_SetNotGasable(int* args)
{
    Hum_5140* s;
unsigned char v;
Hum_5140* g;
    v = args[1] != 0;
    g = cGOBJ_SOBJ_convert(args[0]);
    if (g && g->classKey == g_HumanActorClassKey) { s = g; Set_5140(s, v, 0); }
    return 0;
}
#pragma pop
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef g_HumanActorClassKey /* merge_units */
static inline void merge_flush_func_00185140(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00185140 */
