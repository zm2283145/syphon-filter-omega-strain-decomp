#include "types.h"
#include "message_pack.h"
extern int func_003FF330(void* e, int a1, int* type, int a3, int a4, unsigned int sz, void* buf);
#define Event_PackHeader func_003FF330
#define PACK_BODY(e, b) *(float*)(b + 0xC) = (float)MP_I(e, 0x2C);

DEFINE_MESSAGE_PACK_NOTYPE(func_003E6270, 16, D_0055A220, PACK_BODY)