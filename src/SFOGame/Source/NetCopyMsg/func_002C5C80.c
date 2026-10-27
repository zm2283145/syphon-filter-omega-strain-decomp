#include "types.h"
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