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
extern char D_004A9228[];
extern char D_004FFB50[];
extern char D_004DAE30[];
extern void WaterFx_PointSplash(void* fx, float a, float b);
extern void SoundRequest_Ctor(SoundRequest* req, int kind, void* name, int a, int b);
extern void func_0020F860(SoundMsg* msg, SoundRequest* req, Hit08* hit);
extern void Event_Send(SoundMsg* msg, void* target, int flags);
extern void func_0036E220(void* part, int flags);
extern void cMessage_dtor(SoundMsg* msg, int flags);

/* On a flagged hit, spawns a water splash and broadcasts the impact sound. */
void func_00278160(void* self, Hit08* hit, HitFlags* info) {
    SoundMsg msg;
    SoundRequest req;
    if (info->flags & 0x80) {
        WaterFx_PointSplash(D_004FFC34, D_004A9098, hit->strength);
        SoundRequest_Ctor(&req, 1, D_004A9228, 0, 0);
        func_0020F860(&msg, &req, hit);
        msg.flag = 1;
        Event_Send(&msg, D_004FFB50, 1);
        msg.vtbl = D_004DAE30;
        func_0036E220(msg.partB, -1);
        func_0036E220(msg.partA, -1);
        cMessage_dtor(&msg, 0);
        func_0036E220(req.partB, -1);
        func_0036E220(req.partA, -1);
    }
}
