#include "types.h"
typedef struct { char pad[0x48]; char sub[0x60]; int mA8; } T5D80;
extern void sceMpegCreate(T5D80* t, int a, int b);
extern void sceMpegAddCallback(T5D80* t, int id, void* cb, int z);
extern void viBufCreate(void* sub, int a, int b, int c, int d, int e);
extern void mpegError(void);
extern void mpegNodata(void);
extern void mpegStopDMA(void);
extern void mpegRestartDMA(void);
extern void mpegTS(void);
int videoDecCreate(T5D80* t, int a, int b, int c, int d, int e, int f, int g)
{
    sceMpegCreate(t, a, b);
    sceMpegAddCallback(t, 0, (void*)mpegError, 0);
    sceMpegAddCallback(t, 1, (void*)mpegNodata, 0);
    sceMpegAddCallback(t, 2, (void*)mpegStopDMA, 0);
    sceMpegAddCallback(t, 3, (void*)mpegRestartDMA, 0);
    sceMpegAddCallback(t, 5, (void*)mpegTS, 0);
    t->mA8 = 0;
    viBufCreate(t->sub, c, d, e, f, g);
    return 1;
}
