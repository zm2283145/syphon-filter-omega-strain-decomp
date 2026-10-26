#include "types.h"
#include "message_pack.h"

#define BASE_BODY(e, b) MP_I(b, 0xC) = MP_I(MP_P(e, 0x24), 0xC); MP_S(b, 8) = 0;
DEFINE_MESSAGE_PACK_INLINE(GeneratorMessageBase_Pack, 0x14, D_004F56C8, BASE_BODY)

#define PACK_TAIL(e, b) MP_H(b, 0x10) = MP_U(e, 0x28); MP_S(b, 8) = 3;
DEFINE_MESSAGE_PACK_DERIVED(cGeneratorMessage_Pack, 0x14, GeneratorMessageBase_Pack, PACK_TAIL)
