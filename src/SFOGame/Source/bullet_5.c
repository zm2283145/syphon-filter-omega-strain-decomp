/*
 * SFOGame/Source/bullet: 2 files, 00278160-00278230
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00278160 */
#pragma push /* merge_units */
#include "types.h"

typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];   /* 0x048 */
    char partB[0xAC];   /* 0x0E4 */
} SoundRequest; /* size 0x190 */

typedef struct SoundMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag; /* 0x020 */
    char pad021[0x57];
    char partA[0x9C];   /* 0x078 */
    char partB[0xAC];   /* 0x114 */
} SoundMsg; /* size 0x1C0 */

typedef struct Hit08 {
    char pad00[8];
    float strength;     /* 0x08 */
} Hit08;

typedef struct HitFlags {
    char pad00[0x40];
    unsigned char flags; /* 0x40 */
} HitFlags;

extern void* D_004FFC34;
extern float D_004A9098;
extern char g_Game[];
extern char D_004DAE30[];
extern void cWaterFx_AddBody_cVectorR_float_float(void* fx, float a, float b);
extern void cSndFx_ctor_int_charP_cGOBJP_int(SoundRequest* req, int kind, void* name, int a, int b);
extern void cPlaySoundMsg_ctor_cSndFxR_cGOBJP(SoundMsg* msg, SoundRequest* req, Hit08* hit);
extern void QueueMessage_cMessageR_cSystemP_int(SoundMsg* msg, void* target, int flags);
extern void cFileMan_dtor(void* part, int flags);
extern void cMessage_dtor(SoundMsg* msg, int flags);

/* On a flagged hit, spawns a water splash and broadcasts the impact sound. */
void cBulletCollideContinueCallback_Trigger(void* self, Hit08* hit, HitFlags* info) {
    SoundMsg msg;
    SoundRequest req;
    if (info->flags & 0x80) {
        cWaterFx_AddBody_cVectorR_float_float(D_004FFC34, D_004A9098, hit->strength);
        cSndFx_ctor_int_charP_cGOBJP_int(&req, 1, "B_HIT_WATER", 0, 0);
        cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&msg, &req, hit);
        msg.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 1);
        msg.vtbl = D_004DAE30;
        cFileMan_dtor(msg.partB, -1);
        cFileMan_dtor(msg.partA, -1);
        cMessage_dtor(&msg, 0);
        cFileMan_dtor(req.partB, -1);
        cFileMan_dtor(req.partA, -1);
    }
}
static inline void merge_flush_func_00278160(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00278160 */

/* merge_units: begin func_00278230 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern char D_004FFE60[];
extern void __destroy_array(void*, void*, int, int);
extern int cBullet_dtor(int, int);

/* Constructs the static array D_004FFE60: 50 elements of 0x150 bytes with cBullet_dtor. */
void func_00278230(void) {
    __destroy_array(D_004FFE60, cBullet_dtor, 336, 50);
}
static inline void merge_flush_func_00278230(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00278230 */
