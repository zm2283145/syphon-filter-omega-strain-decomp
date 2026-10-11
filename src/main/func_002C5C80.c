#include "types.h"
#include "message_pack.h"
typedef struct { float x, y, z, w; } V4f_5C80;
#define MP_F(p, off) (*(float*)((char*)(p) + (off)))
extern void func_002C5F20(void* d, void* s);
extern void func_002C5EE0(void* d, void* s);
extern void func_002C5E50(void* d, void* s);
extern void func_002C5E20(void* d, void* s);
extern void func_002C5D90(void* d, void* s);
#define PACK_BODY(e, b) \
    MP_I(b, 0x8) = MP_I(e, 0x24); \
    func_002C5F20((char*)(b) + 0x10, (char*)(e) + 0x30); \
    *(V4f_5C80*)((char*)(b) + 0x100) = *(V4f_5C80*)((char*)(e) + 0x120); \
    MP_F(b, 0x110) = MP_F(e, 0x130); \
    func_002C5EE0((char*)(b) + 0x120, (char*)(e) + 0x140); \
    func_002C5E50((char*)(b) + 0x150, (char*)(e) + 0x170); \
    func_002C5E20((char*)(b) + 0x1C0, (char*)(e) + 0x1E0); \
    MP_F(b, 0x1E0) = MP_F(e, 0x200); \
    func_002C5D90((char*)(b) + 0x1F0, (char*)(e) + 0x210); \
    func_002C5D90((char*)(b) + 0x230, (char*)(e) + 0x250); \
    func_002C5D90((char*)(b) + 0x270, (char*)(e) + 0x290); \
    func_002C5D90((char*)(b) + 0x2B0, (char*)(e) + 0x2D0);
DEFINE_MESSAGE_PACK(func_002C5C80, 0x2F0, D_0051EE50, PACK_BODY)