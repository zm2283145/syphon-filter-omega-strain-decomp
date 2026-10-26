/*
 * lib/libnet: 13 files, 0034B7E8-0034BC68
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034B7E8 */
extern int sceSifMUnBindRpc(void *cd, int mode);
int sceLibnetTerminate(void *cd)
{
    int r, i;
    for (;;) {
        r = sceSifMUnBindRpc(cd, 0);
        if (r < 0) return -0x21C;
        if (r == 1) break;
        /* busy-wait delay: the nop is the loop body, C has no way to emit it */
        { int lim = -1; i = 0xffff; do { i -= 4; __asm__ volatile("nop"); } while (i != lim); }
    }
    return 0;
}
/* merge_units: end func_0034B7E8 */

/* merge_units: begin func_0034B868 */
extern int Libnet_CallRpc(void *cd, int fno, void *buf, int ssize, int rsize);
#define NET_RPC0(name, fno) int name(void *cd, unsigned int *buf) { if (Libnet_CallRpc(cd, fno, buf, 0, 4) < 0) return -0x21E; return buf[0]; }
#define NET_RPC1(name, fno) int name(void *cd, unsigned int *buf, unsigned int a) { buf[0] = a; if (Libnet_CallRpc(cd, fno, buf, 4, 4) < 0) return -0x21E; return buf[0]; }
#define NET_RPC2(name, fno) int name(void *cd, unsigned int *buf, unsigned int a, unsigned int b) { buf[0] = a; buf[1] = b; if (Libnet_CallRpc(cd, fno, buf, 8, 4) < 0) return -0x21E; return buf[0]; }

NET_RPC0(sceLibnetRegisterHandler, 0x1E)
/* merge_units: end func_0034B868 */

/* merge_units: begin func_0034B8A8 */
NET_RPC0(sceLibnetUnregisterHandler, 0x1F)
/* merge_units: end func_0034B8A8 */

/* merge_units: begin func_0034B8E8 */
NET_RPC1(sceLibnetSetConfiguration, 0x20)
/* merge_units: end func_0034B8E8 */

/* merge_units: begin func_0034B930 */
extern int MemcpyD(void *cd, void *buf, int idx, void *src, int len);
extern int MemcpyS(void *cd, void *dst, void *buf, int idx, int len);
extern int StrcpyS(void *cd, char *dst, void *buf, int idx);

#define NET_RPC_IO(name, fno) int name(void *cd, int *buf, int a, int b, void *data, int len) { int r; buf[0] = a; buf[1] = b; buf[2] = len; r = MemcpyD(cd, buf, 3, data, len); if (r < 0) return r; if (Libnet_CallRpc(cd, fno, buf, len + 12, len + 12) < 0) return -0x21E; r = MemcpyS(cd, data, buf, 3, len); if (r < 0) return r; return buf[0]; }
#define NET_RPC_LIST(name, fno, esz) int name(void *cd, int *buf, void *dst, int n) { int r; buf[0] = n; if (Libnet_CallRpc(cd, fno, buf, 4, n * esz + 4) < 0) return -0x21E; if (buf[0] < 0) return buf[0]; r = MemcpyS(cd, dst, buf, 1, buf[0] * esz); if (r < 0) return r; return buf[0]; }

int WaitInterface(void *cd, int *buf, int *dst, int n, int fno)
{
    int i;
    if (Libnet_CallRpc(cd, fno, buf, 0, n * 4 + 4) < 0) return -0x21E;
    for (i = 0; i < n; i++) dst[i] = buf[i + 1];
    return buf[0];
}
/* merge_units: end func_0034B930 */

/* merge_units: begin func_0034B9B8 */
#include "types.h"

#if 0 /* merge_units */
extern int WaitInterface(int, int, int, int, int);
#endif /* merge_units */
#define WaitInterface(a0, a1, a2, a3, a4) (WaitInterface((void *)(a0), (int *)(a1), (int *)(a2), (a3), (a4))) /* merge_units */


int WaitInterfaceAttached(int a0, int a1, int a2, int a3) {
    return WaitInterface(a0, a1, a2, a3, 33);
}
#undef WaitInterface /* merge_units */
/* merge_units: end func_0034B9B8 */

/* merge_units: begin func_0034B9D0 */
#if 0 /* merge_units */
extern int WaitInterface(int, int, int, int, int);
#endif /* merge_units */
#define WaitInterface(a0, a1, a2, a3, a4) (WaitInterface((void *)(a0), (int *)(a1), (int *)(a2), (a3), (a4))) /* merge_units */


int WaitInterfaceStarted(int a0, int a1, int a2, int a3) {
    return WaitInterface(a0, a1, a2, a3, 34);
}
#undef WaitInterface /* merge_units */
/* merge_units: end func_0034B9D0 */

/* merge_units: begin func_0034B9E8 */
extern int sceInetGetInterfaceList(void *cd, int *buf, void *dst, int n);
extern int sceInetInterfaceControl(void *cd, int *buf, int a, int b, void *data, int len);
int GetInterfaceID(void *cd, int *buf, int *out)
{
    int list[256];
    int st;
    int n, i;
    n = sceInetGetInterfaceList(cd, buf, list, 256);
    if (n < 0) return -1;
    if (n == 0) return -2;
    for (i = 0; i < n; i++) {
        if (sceInetInterfaceControl(cd, buf, list[i], 8, &st, 4) < 0) return -1;
        if (st & 2) break;
    }
    if (i == n) return -2;
    *out = list[i];
    return 0;
}
/* merge_units: end func_0034B9E8 */

/* merge_units: begin func_0034BAC8 */
#if 0 /* merge_units */
extern int sceInetInterfaceControl(int, int, int, int, int, int);
#endif /* merge_units */
#define sceInetInterfaceControl(a0, a1, a2, a3, a4, a5) (sceInetInterfaceControl((void *)(a0), (int *)(a1), (a2), (a3), (void *)(a4), (a5))) /* merge_units */


int GetMyAddress(int a0, int a1, int a2, int a3) {
    return sceInetInterfaceControl(a0, a1, a2, 9, a3, 16);
}
#undef sceInetInterfaceControl /* merge_units */
/* merge_units: end func_0034BAC8 */

/* merge_units: begin func_0034BAE8 */
extern int GetInterfaceID(void *cd, int *buf, int *out);
#if 0 /* merge_units */
extern int WaitInterfaceStarted(void *cd, int *buf, int *dst, int n);
#endif /* merge_units */
#define WaitInterfaceStarted(a0, a1, a2, a3) (WaitInterfaceStarted((int)(a0), (int)(a1), (int)(a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern int WaitInterfaceAttached(void *cd, int *buf, int *dst, int n);
#endif /* merge_units */
#define WaitInterfaceAttached(a0, a1, a2, a3) (WaitInterfaceAttached((int)(a0), (int)(a1), (int)(a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern int GetMyAddress(void *cd, int *buf, int id, int x);
#endif /* merge_units */
#define GetMyAddress(a0, a1, a2, a3) (GetMyAddress((int)(a0), (int)(a1), (a2), (a3))) /* merge_units */

int WaitGetAddressAutoUpIf(void *cd, int *buf, int *id, int n, int x)
{
    int r;
    if (GetInterfaceID(cd, buf, id) < 0) {
        r = WaitInterfaceStarted(cd, buf, id, n);
        if (r < 0) return r;
    }
    r = GetMyAddress(cd, buf, *id, x);
    if (r < 0) return r;
    return 0;
}
#undef WaitInterfaceStarted /* merge_units */
#undef WaitInterfaceAttached /* merge_units */
#undef GetMyAddress /* merge_units */
/* merge_units: end func_0034BAE8 */

/* merge_units: begin func_0034BB80 */
#if 0 /* merge_units */
extern int WaitInterfaceStarted(void *cd, int *buf, int *dst, int n);
#endif /* merge_units */
#define WaitInterfaceStarted(a0, a1, a2, a3) (WaitInterfaceStarted((int)(a0), (int)(a1), (int)(a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern int WaitInterfaceAttached(void *cd, int *buf, int *dst, int n);
#endif /* merge_units */
#define WaitInterfaceAttached(a0, a1, a2, a3) (WaitInterfaceAttached((int)(a0), (int)(a1), (int)(a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern int GetMyAddress(void *cd, int *buf, int id, int x);
#endif /* merge_units */
#define GetMyAddress(a0, a1, a2, a3) (GetMyAddress((int)(a0), (int)(a1), (a2), (a3))) /* merge_units */

int WaitGetAddressNoAutoUpIf(void *cd, int *buf, int *id, int n, int x)
{
    int r;
    r = WaitInterfaceStarted(cd, buf, id, n);
    if (r < 0) return r;
    r = GetMyAddress(cd, buf, *id, x);
    if (r < 0) return r;
    return 0;
}
#undef WaitInterfaceStarted /* merge_units */
#undef WaitInterfaceAttached /* merge_units */
#undef GetMyAddress /* merge_units */
/* merge_units: end func_0034BB80 */

/* merge_units: begin func_0034BBE8 */
#if 0 /* merge_units */
extern int WaitInterfaceStarted(void *cd, int *buf, int *dst, int n);
#endif /* merge_units */
#define WaitInterfaceStarted(a0, a1, a2, a3) (WaitInterfaceStarted((int)(a0), (int)(a1), (int)(a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern int WaitInterfaceAttached(void *cd, int *buf, int *dst, int n);
#endif /* merge_units */
#define WaitInterfaceAttached(a0, a1, a2, a3) (WaitInterfaceAttached((int)(a0), (int)(a1), (int)(a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern int GetMyAddress(void *cd, int *buf, int id, int x);
#endif /* merge_units */
#define GetMyAddress(a0, a1, a2, a3) (GetMyAddress((int)(a0), (int)(a1), (a2), (a3))) /* merge_units */

int sceLibnetWaitGetInterfaceID(void *cd, int *buf, int *id, int n)
{
    int r;
    if (id == 0) return -0x21C;
    if (GetInterfaceID(cd, buf, id) < 0) {
        r = WaitInterfaceAttached(cd, buf, id, n);
        if (r < 0) return r;
    }
    return 0;
}
#undef WaitInterfaceStarted /* merge_units */
#undef WaitInterfaceAttached /* merge_units */
#undef GetMyAddress /* merge_units */
/* merge_units: end func_0034BBE8 */

/* merge_units: begin func_0034BC68 */
#if 0 /* merge_units */
extern int WaitInterfaceStarted(void *cd, int *buf, int *dst, int n);
#endif /* merge_units */
#define WaitInterfaceStarted(a0, a1, a2, a3) (WaitInterfaceStarted((int)(a0), (int)(a1), (int)(a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern int WaitInterfaceAttached(void *cd, int *buf, int *dst, int n);
#endif /* merge_units */
#define WaitInterfaceAttached(a0, a1, a2, a3) (WaitInterfaceAttached((int)(a0), (int)(a1), (int)(a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern int GetMyAddress(void *cd, int *buf, int id, int x);
#endif /* merge_units */
#define GetMyAddress(a0, a1, a2, a3) (GetMyAddress((int)(a0), (int)(a1), (a2), (a3))) /* merge_units */

int sceLibnetWaitGetInterfaceEvent(void *cd, int *buf, int *p, int *q)
{
    if (Libnet_CallRpc(cd, 0x23, buf, 0, 0xC) < 0) return -0x21E;
    if (p) *p = buf[1];
    if (q) *q = buf[2];
    return buf[0];
}
#undef WaitInterfaceStarted /* merge_units */
#undef WaitInterfaceAttached /* merge_units */
#undef GetMyAddress /* merge_units */
/* merge_units: end func_0034BC68 */
