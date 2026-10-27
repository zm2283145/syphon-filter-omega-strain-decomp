/*
 * SFOGame/Source/human: 3 files, 00185060-00185140
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00185060 */
#pragma push /* merge_units */
#include "types.h"

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
int cMessage_ctor_cMessageNameR(Msg_5140*, void*);
int QueueMessage_cMessageR_cSystemP_int(Msg_5140*, void*, int);
Hum_5140* cGOBJ_SOBJ_convert(int);
int cMessage_dtor(Msg_5140*, int);
#if 0 /* merge_units */
extern int g_HumanActorClassKey;
#endif /* merge_units */
#define g_HumanActorClassKey (*(int*)&g_HumanActorClassKey) /* merge_units */

extern char D_004DA9D0[];
extern char D_004DCF10[];
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
#undef g_HumanActorClassKey /* merge_units */
static inline void merge_flush_func_00185140(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00185140 */
