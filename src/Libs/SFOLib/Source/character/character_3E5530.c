#include "types.h"

typedef struct { int words[3]; } Reader;
extern char D_0055A1E0[];
extern void cCharActionMsg_Scalar_NetCharActionScalarReq();
extern int NetRegisterMessageStart(void);
extern unsigned char cCharActionMsg_RegisterFields(void);
extern int NetMessageField(Reader* r, void* out, int size, int count);
extern int NetRegisterApplicationMessage(void* table, void (*cb)());

/* Startup check chain; returns 1 when every step succeeds. */
unsigned char cCharActionMsg_Scalar_InitNet(void)
{
    Reader r;
    int value;
    unsigned char ok = 0;
    if (NetRegisterMessageStart() == 0 && cCharActionMsg_RegisterFields() && NetMessageField(&r, &value, 4, 1) == 0
        && NetRegisterApplicationMessage(D_0055A1E0, cCharActionMsg_Scalar_NetCharActionScalarReq) == 0)
        ok = 1;
    return ok;
}
