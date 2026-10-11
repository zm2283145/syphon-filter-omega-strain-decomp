#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
typedef __int128 Q128;
#pragma mpwc_relax on
char * func_003E7560(char * arg0, char * arg1) {
    F_(arg0, 0x0, int) = F_(arg1, 0x0, int);
    F_(arg0, 0x4, int) = F_(arg1, 0x4, int);
    F_(arg0, 0x8, unsigned char) = F_(arg1, 0x8, unsigned char);
    { typedef char uf_chk_[sizeof(F_(arg0, 0x10, Q128)) == 16 ? 1 : -1]; VCopyF(&(F_(arg0, 0x10, Q128)), &(F_(arg1, 0x10, Q128))); }
    F_(arg0, 0x20, float) = F_(arg1, 0x20, float);
    return arg0;
}
