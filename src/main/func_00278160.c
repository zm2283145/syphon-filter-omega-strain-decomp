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
extern char D_004FFB50[];
extern char D_004DAE30[];
extern void WaterFx_PointSplash(void* fx, float a, float b);
extern void SoundRequest_Ctor(SoundRequest* req, int kind, void* name, int a, int b);
extern void SoundPosRequest_Ctor(SoundMsg* msg, SoundRequest* req, Hit08* hit);
extern void Event_Send(SoundMsg* msg, void* target, int flags);
extern void FileMan_Release(void* part, int flags);
extern void cMessage_dtor(SoundMsg* msg, int flags);

/* On a flagged hit, spawns a water splash and broadcasts the impact sound. */
void func_00278160(void* self, Hit08* hit, HitFlags* info) {
    SoundMsg msg;
    SoundRequest req;
    if (info->flags & 0x80) {
        WaterFx_PointSplash(D_004FFC34, D_004A9098, hit->strength);
        SoundRequest_Ctor(&req, 1, "B_HIT_WATER", 0, 0);
        SoundPosRequest_Ctor(&msg, &req, hit);
        msg.flag = 1;
        Event_Send(&msg, D_004FFB50, 1);
        msg.vtbl = D_004DAE30;
        FileMan_Release(msg.partB, -1);
        FileMan_Release(msg.partA, -1);
        cMessage_dtor(&msg, 0);
        FileMan_Release(req.partB, -1);
        FileMan_Release(req.partA, -1);
    }
}
