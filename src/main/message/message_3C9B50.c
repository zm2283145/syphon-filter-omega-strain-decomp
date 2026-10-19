/*
 * main/message: 9 files, 003C9B50-003C9FE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003C9B50 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_003C9B20(int *, int);                        
int func_003C9B30(char *);                             
char * func_003C9B40();                           
extern char D_005435C0;
extern char D_005435C4;

int MsgQueue_CountPending(int *arg0) {
    int sp4C;
    int var_s1;
    char * temp_v0;
    char * var_s0;

    var_s1 = 0;
    var_s0 = (char *)(F_(func_003C9B40(&D_005435C4), 0x4, int));
    func_003C9B20(&sp4C, func_003C9B30(&D_005435C0));
    if ((int)(var_s0) != (int)(sp4C)) {
        do {
            temp_v0 = (char *)(F_(var_s0, 0xC, int));
            if ((temp_v0 != NULL) && (*(int *)F_(temp_v0, 0x4, int) == *arg0)) {
                var_s1 += 1;
            }
            var_s0 = (char *)(F_(var_s0, 0x4, int));
            func_003C9B20(&sp4C, func_003C9B30(&D_005435C0));
        } while ((int)(var_s0) != (int)(sp4C));
    }
    return var_s1;
}
#pragma pop /* merge_units */
/* merge_units: end func_003C9B50 */

/* merge_units: begin func_003C9C10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

#if 0 /* merge_units */
extern int D_005435C0;
#endif /* merge_units */
#define D_005435C0 (*(int*)&D_005435C0) /* merge_units */


int func_003C9C10(void) {
    return D_005435C0;
}

int Event_GetType(Word* self) {
    return self[1].value;
}
#undef D_005435C0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C9C10 */

/* merge_units: begin func_003C9C30 */
#pragma push /* merge_units */
extern int func_002E9A98(void* hdr, void* dst, int size, int count);
unsigned char func_003C9C30(char* s) {
    unsigned char ok = 0;
    if (func_002E9A98(s, s, 4, 1) != 0) goto out;
    if (func_002E9A98(s, s + 4, 4, 1) != 0) goto out;
    ok = 1;
out:
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_003C9C30 */

/* merge_units: begin func_003C9CA0 */
#pragma push /* merge_units */
typedef struct HdrBitsEP { unsigned int type : 2; unsigned int time : 30; } HdrBitsEP;
typedef union HdrEP { HdrBitsEP b; unsigned int raw; } HdrEP;
typedef struct PacketEP { unsigned int hdr; int data; } PacketEP;
typedef struct EventEP { char pad[0x18]; int type; } EventEP;
extern unsigned int Net_GetClock(int a);
int Event_PackHeader(EventEP* e, int data, int a2, int a3, int a4, unsigned int size, void* buf)
{
    HdrEP h;
    if (size >= 8 && buf) {
        PacketEP* out = (PacketEP*)buf;
        if (e->type < 4) {
            h.b.type = e->type;
        } else {
            h.b.type = 3;
        }
        h.b.time = Net_GetClock(0);
        out->hdr = h.raw;
        out->data = data;
    }
    return -1;
}
#pragma pop /* merge_units */
/* merge_units: end func_003C9CA0 */

/* merge_units: begin func_003C9D60 */
#pragma push /* merge_units */
extern void operator_delete(void*);
extern int D_004DFD80;
typedef struct { void* vt; } cMessageD4;
cMessageD4* cMessage_dtor(cMessageD4* p, short flag)
{
    if (p) {
        p->vt = &D_004DFD80;
        if (flag > 0) operator_delete(p);
    }
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_003C9D60 */

/* merge_units: begin func_003C9DB0 */
#pragma push /* merge_units */
typedef struct { unsigned int kind : 2; unsigned int time : 30; } MsgStamp;
typedef struct { MsgStamp stamp; int target; } MsgInfo;
typedef struct {
    void* vtable;
    int sender;
    char pad8[4];
    unsigned int time;
    char pad10[4];
    int target;
    unsigned int kind;
    int unk1C;
    unsigned char type;
} cMessage;

#if 0 /* merge_units */
extern char D_004DFD80[];
#endif /* merge_units */
#define D_004DFD80 ((char*)&D_004DFD80) /* merge_units */

extern void DME_AddLatencySample(unsigned int dt);

/* cMessage constructor (type 5). */
cMessage* cMessage_ctor5(cMessage* self, int sender, MsgInfo* info)
{
    MsgStamp stamp;
    self->vtable = D_004DFD80;
    self->sender = sender;
    self->target = info->target;
    self->unk1C = 0;
    self->type = 5;
    *(int*)&stamp = *(int*)&info->stamp;
    self->time = stamp.time;
    self->kind = stamp.kind;
    DME_AddLatencySample(Net_GetClock(0) - self->time);
    return self;
}
#undef D_004DFD80 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C9DB0 */

/* merge_units: begin func_003C9E30 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char D_004DFD80[];
#endif /* merge_units */
#define D_004DFD80 ((char*)&D_004DFD80) /* merge_units */

extern char g_IsMultiplayer[];
extern char D_005721D0[];
#if 0 /* merge_units */
extern int Net_GetClock(int);
#endif /* merge_units */
#define Net_GetClock(a0) ((int)Net_GetClock((a0))) /* merge_units */


int Event_Construct(int a0, int a1) {
    int s0, v0, v1;
    int cond;

    v1 = (int)D_004DFD80;
    v0 = 0 + 5;
    *(int*)(char*)a0 = v1;
    *(int*)((char*)a0 + 4) = a1;
    *(int*)((char*)a0 + 24) = 0;
    *(int*)((char*)a0 + 28) = 0;
    *(char*)((char*)a0 + 32) = v0;
    v0 = *(unsigned char*)(char*)g_IsMultiplayer;
    cond = v0 == 0;
    s0 = a0;
    if (cond) goto L003C9E88;
    v0 = *(unsigned char*)(char*)D_005721D0;
    cond = v0 == 0;
    a0 = 0;
    if (cond) goto L003C9E88;
    v0 = Net_GetClock(a0);
    *(int*)((char*)s0 + 12) = v0;
L003C9E88:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
#undef D_004DFD80 /* merge_units */
#undef Net_GetClock /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C9E30 */

/* merge_units: begin func_003C9EA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "object_list_erase_file.h"

extern "C" { char D_004BD198[] = "allocator.hh"; }
DEFINE_OBJECT_LIST_ERASE_RANGE_FILE(func_003C9EA0, D_004BD198)
#pragma pop /* merge_units */
/* merge_units: end func_003C9EA0 */

/* merge_units: begin func_003C9FE0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_OBJECT_LIST_ERASE_ONE_FILE(func_003C9FE0, D_004BD198)
#pragma pop /* merge_units */
/* merge_units: end func_003C9FE0 */
