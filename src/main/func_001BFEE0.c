#include "types.h"
typedef struct { unsigned char len : 7; unsigned char isLong : 1; } SB_1BFEE0;
typedef union { unsigned int word; SB_1BFEE0 b; } SW_1BFEE0;
typedef struct { SW_1BFEE0 h; unsigned int length; char* data; } SS_1BFEE0;
void func_001BFEE0(char** out, SS_1BFEE0* s)
{
    char* d;
    unsigned int n;
    if (!(s->h.word & 1)) { d = (char*)s + 1; n = (unsigned char)(((unsigned long long)*(unsigned char*)s << 56) >> 57); }
    else { d = s->data; n = s->length; }
    *out = d + n;
}
