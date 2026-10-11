#include "types.h"
#include "message_pack.h"
extern int func_003FF330(void* e, int a1, int* type, int a3, int a4, unsigned int sz, void* buf);
#define Event_PackHeader func_003FF330
#define PACK_BODY(e, b) MP_I(b, 0xC) = MP_I(e, 0x2C); MP_I(b, 0x10) = MP_I(e, 0x30);

DEFINE_MESSAGE_PACK_NOTYPE(func_003E60F0, 20, D_0055A1F8, PACK_BODY)