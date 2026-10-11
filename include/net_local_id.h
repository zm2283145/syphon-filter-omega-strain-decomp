#ifndef NET_LOCAL_ID_H
#define NET_LOCAL_ID_H
/* Inlined "local player net id" helpers (lazily initialised id in D_00494178).
   D_005721A8 is read before the D_005721C8 test: retail loads it ahead of the
   branch. Nested use (NetObjId) needs #pragma inline_depth(10) in the user. */
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
int func_002EBAF8(int*, int);
int func_002EBBA0(int, int*);

static inline int NetLocalId(void)
{
    int r;
    int a = D_005721A8;
    if (D_005721C8) {
        if (D_00494178 == -1) func_002EBAF8(&D_00494178, a);
        r = D_00494178;
    } else r = 0;
    return r;
}

/* local id when online or hosting, else ask the host */
static inline int NetObjId(void)
{
    int id;
    int ok = D_005721C8 ? D_005721C0 : 1;
    if (ok) {
        id = NetLocalId();
    } else {
        int tmp[1];
        func_002EBBA0(D_005721A8, tmp);
        id = tmp[0];
    }
    return id;
}
#endif