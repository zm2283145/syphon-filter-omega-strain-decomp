/*
 * SFOGame/Source/NetCopyMsg: 2 files, 002C5B80-002C5C80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C5B80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class Ctl5B80 {
public:
    VPAD8(p) VPAD4(q) VPAD2(r) VPAD1(s)
    virtual int isActive();          /* slot 15 */
    VPAD16(t)
    virtual unsigned char kind();    /* slot 32 */
};
struct Obj5B80 { char pad[0x58]; Ctl5B80* ctl; };
struct Src5B80 { int a; int b; int id; };
struct Msg5B80 { void* vtable; char pad[0x2C]; char payload[0x2E0]; };
extern "C" {
extern unsigned char D_005723C8;
extern unsigned char D_005721D0;
extern char D_004DE110[];
void cNetCopyMsg_ctor(Msg5B80* m, Src5B80* src);
Obj5B80* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
void cNetNPC_ConvertToNpc(Ctl5B80* c, void* payload);
void func_0042CE10(int* id);
void cMessage_dtor(void* self, int flags);
}
extern "C" int cNetCopyMsg_CopyMsgCallback(int a, int b, int c, Src5B80* src)
{
    if (!D_005723C8)
        D_005723C8 = 1;
    if (D_005721D0) {
        Msg5B80 m;
        int id[2];
        Obj5B80* o;
        id[0] = src->id;
        cNetCopyMsg_ctor(&m, src);
        o = nGobjManager_LookupGOBJ_cObjectIdR(id);
        if (o && o->ctl && o->ctl->isActive() && o->ctl->kind() == 2)
            cNetNPC_ConvertToNpc(o->ctl, m.payload);
        func_0042CE10(id);
        m.vtable = D_004DE110;
        cMessage_dtor(&m, 0);
    }
    D_005723C8 = 0;
    return 0x2F0;
}
static inline void merge_flush_func_002C5B80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C5B80 */

/* merge_units: begin func_002C5C80 */
#pragma push /* merge_units */
#include "message_pack.h"
typedef struct { float x, y, z, w; } V4f_5C80;
#define MP_F(p, off) (*(float*)((char*)(p) + (off)))
extern void cNpcTransfer_opAssign(void* d, void* s);
extern void cAiTargetTransfer_opAssign(void* d, void* s);
extern void cPathNavigatorTransfer_opAssign(void* d, void* s);
extern void cPathTransfer_opAssign(void* d, void* s);
extern void cTargetAwareness_opAssign(void* d, void* s);
#define PACK_BODY(e, b) \
    MP_I(b, 0x8) = MP_I(e, 0x24); \
    cNpcTransfer_opAssign((char*)(b) + 0x10, (char*)(e) + 0x30); \
    *(V4f_5C80*)((char*)(b) + 0x100) = *(V4f_5C80*)((char*)(e) + 0x120); \
    MP_F(b, 0x110) = MP_F(e, 0x130); \
    cAiTargetTransfer_opAssign((char*)(b) + 0x120, (char*)(e) + 0x140); \
    cPathNavigatorTransfer_opAssign((char*)(b) + 0x150, (char*)(e) + 0x170); \
    cPathTransfer_opAssign((char*)(b) + 0x1C0, (char*)(e) + 0x1E0); \
    MP_F(b, 0x1E0) = MP_F(e, 0x200); \
    cTargetAwareness_opAssign((char*)(b) + 0x1F0, (char*)(e) + 0x210); \
    cTargetAwareness_opAssign((char*)(b) + 0x230, (char*)(e) + 0x250); \
    cTargetAwareness_opAssign((char*)(b) + 0x270, (char*)(e) + 0x290); \
    cTargetAwareness_opAssign((char*)(b) + 0x2B0, (char*)(e) + 0x2D0);
DEFINE_MESSAGE_PACK(cNetCopyMsg_Pack, 0x2F0, D_0051EE50, PACK_BODY)
static inline void merge_flush_func_002C5C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C5C80 */
