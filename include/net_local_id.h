#ifndef NET_LOCAL_ID_H
#define NET_LOCAL_ID_H
/* Inlined "local player net id" helpers (lazily initialised id in D_00494178).
   D_005721A8 is read before the g_IsMultiplayer test: retail loads it ahead of the
   branch. Nested use (NetObjId) needs #pragma inline_depth(10) in the user. */
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
int NetGetMyClientIndex(int*, int);
int NetGetPeerToPeerHostClientIndex(int, int*);

static inline int NetLocalId(void)
{
    int r;
    int a = D_005721A8;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a);
        r = D_00494178;
    } else r = 0;
    return r;
}

/* local id when online or hosting, else ask the host */
static inline int NetObjId(void)
{
    int id;
    int ok = g_IsMultiplayer ? D_005721C0 : 1;
    if (ok) {
        id = NetLocalId();
    } else {
        int tmp[1];
        NetGetPeerToPeerHostClientIndex(D_005721A8, tmp);
        id = tmp[0];
    }
    return id;
}
#endif