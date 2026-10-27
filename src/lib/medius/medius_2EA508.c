/*
 * lib/medius: 65 files, 002EA508-002ECF08
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002EA508 */
extern unsigned char D_0048C4D7, D_0048C4DC;
extern char D_005253F0[];
extern int rt_mutex_lock(void *, int);
extern int rt_mutex_unlock(void *, int);
extern int NetIAssignLocalServer(void *, void *);
int NetAssignLocalServer(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIAssignLocalServer(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA508 */

/* merge_units: begin func_002EA5B0 */
extern int NetISetDefaultConnectParams(void *);
int NetSetDefaultConnectParams(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISetDefaultConnectParams(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA5B0 */

/* merge_units: begin func_002EA648 */
extern int NetIConnect(void *, void *);
int NetConnect(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIConnect(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA648 */

/* merge_units: begin func_002EA6F0 */
extern int NetISetDefaultHostPeerToPeerParams(void *);
int NetSetDefaultHostPeerToPeerParams(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISetDefaultHostPeerToPeerParams(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA6F0 */

/* merge_units: begin func_002EA788 */
extern int NetIHostPeerToPeer(void *, void *);
int NetHostPeerToPeer(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIHostPeerToPeer(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA788 */

/* merge_units: begin func_002EA830 */
extern int NetISetNATServiceAddr(void *);
int NetSetNATServiceAddr(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISetNATServiceAddr(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA830 */

/* merge_units: begin func_002EA8C8 */
extern int NetISetDefaultResolveAddrParams(void *);
int NetSetDefaultResolveAddrParams(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISetDefaultResolveAddrParams(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA8C8 */

/* merge_units: begin func_002EA960 */
extern int NetIResolveAddr(void *, void *);
int NetResolveAddr(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIResolveAddr(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EA960 */

/* merge_units: begin func_002EAA08 */
extern int NetISetDefaultIncomingClientParams(void *);
int NetSetDefaultIncomingClientParams(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISetDefaultIncomingClientParams(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EAA08 */

/* merge_units: begin func_002EAAA0 */
extern int NetIIncomingClient(void *, void *);
int NetIncomingClient(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIIncomingClient(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EAAA0 */

/* merge_units: begin func_002EAB48 */
extern int NetISetMyClientReceiveBroadcast(void *, void *);
int NetSetMyClientReceiveBroadcast(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISetMyClientReceiveBroadcast(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EAB48 */

/* merge_units: begin func_002EABF0 */
extern int NetISetDefaultJoinParams(void *);
int NetSetDefaultJoinParams(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISetDefaultJoinParams(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EABF0 */

/* merge_units: begin func_002EAC88 */
extern int NetIJoin(void *, void *);
int NetJoin(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIJoin(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EAC88 */

/* merge_units: begin func_002EAD30 */
extern int NetIRequestServersOnSubnet(void *);
int NetRequestServersOnSubnet(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIRequestServersOnSubnet(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EAD30 */

/* merge_units: begin func_002EADC8 */
extern int NetIPing(void *, void *, void *);
int NetPing(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIPing(a, b, c);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EADC8 */

/* merge_units: begin func_002EAE80 */
extern int NetIPingIP(void *, void *);
int NetPingIP(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIPingIP(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EAE80 */

/* merge_units: begin func_002EAF28 */
extern int NetICreateObject(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
int NetCreateObject(void *a, void *b, void *c, void *d, void *e, void *f, void *g, void *h, void *i, void *j)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetICreateObject(a, b, c, d, e, f, g, h, i, j);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EAF28 */

/* merge_units: begin func_002EB038 */
extern int NetIRequestCreateRemoteNamedObject(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
int NetRequestCreateRemoteNamedObject(void *a, void *b, void *c, void *d, void *e, void *f, void *g, void *h, void *i, void *j, void *k)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIRequestCreateRemoteNamedObject(a, b, c, d, e, f, g, h, i, j, k);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB038 */

/* merge_units: begin func_002EB150 */
extern int NetIOpenDataStream(void *, void *, void *, void *, void *, void *, void *, unsigned short, unsigned short);
int NetOpenDataStream(void *a, void *b, void *c, void *d, void *e, void *f, void *g, unsigned short h, unsigned short i)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIOpenDataStream(a, b, c, d, e, f, g, h, i);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB150 */

/* merge_units: begin func_002EB260 */
extern int NetIAddToDataStream(void *, void *, void *);
int NetAddToDataStream(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIAddToDataStream(a, b, c);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB260 */

/* merge_units: begin func_002EB318 */
extern int NetIEndDataStream(void *);
int NetEndDataStream(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIEndDataStream(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB318 */

/* merge_units: begin func_002EB3B0 */
extern int NetISendObjectFullUpdate(void *, void *);
int NetSendObjectFullUpdate(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISendObjectFullUpdate(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB3B0 */

/* merge_units: begin func_002EB458 */
extern int NetISendMyClientUpdate(void *, void *);
int NetSendMyClientUpdate(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISendMyClientUpdate(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB458 */

/* merge_units: begin func_002EB500 */
extern int NetIIpStringToBinary(void *, void *);
int NetIpStringToBinary(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIIpStringToBinary(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB500 */

/* merge_units: begin func_002EB5A8 */
extern int NetIIpBinaryToString(void *, void *);
int NetIpBinaryToString(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIIpBinaryToString(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB5A8 */

/* merge_units: begin func_002EB650 */
extern int NetIGetObject(void *, void *);
int NetGetObject(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetObject(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB650 */

/* merge_units: begin func_002EB6F8 */
extern int NetIGetDataStream(void *, void *);
int NetGetDataStream(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetDataStream(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB6F8 */

/* merge_units: begin func_002EB7A0 */
extern int NetIGetClientStatus(void *, void *, void *);
int NetGetClientStatus(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetClientStatus(a, b, c);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB7A0 */

/* merge_units: begin func_002EB858 */
extern int NetIGetClient(void *, void *, void *);
int NetGetClient(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetClient(a, b, c);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB858 */

/* merge_units: begin func_002EB910 */
extern int NetIGetMyIpAddress(void *);
int NetGetMyIpAddress(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetMyIpAddress(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB910 */

/* merge_units: begin func_002EB9A8 */
extern int NetIGetClientIpAddress(void *, void *, void *);
int NetGetClientIpAddress(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetClientIpAddress(a, b, c);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EB9A8 */

/* merge_units: begin func_002EBA60 */
extern int NetIGetCurrentUDPSourceBinaryIP(void *);
int NetGetCurrentUDPSourceBinaryIP(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetCurrentUDPSourceBinaryIP(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBA60 */

/* merge_units: begin func_002EBAF8 */
extern int NetIGetMyClientIndex(void *, void *);
int NetGetMyClientIndex(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetMyClientIndex(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBAF8 */

/* merge_units: begin func_002EBBA0 */
extern int NetIGetPeerToPeerHostClientIndex(void *, void *);
int NetGetPeerToPeerHostClientIndex(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetPeerToPeerHostClientIndex(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBBA0 */

/* merge_units: begin func_002EBC48 */
extern int NetIGetLocalTime(void *);
int NetGetLocalTime(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetLocalTime(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBC48 */

/* merge_units: begin func_002EBCE0 */
extern int NetIGetTime(void *);
int NetGetTime(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetTime(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBCE0 */

/* merge_units: begin func_002EBD78 */
extern int NetIGetSessionMasterClientIndex(void *, void *);
int NetGetSessionMasterClientIndex(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetSessionMasterClientIndex(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBD78 */

/* merge_units: begin func_002EBE20 */
extern int NetIGetConnectStatus(void *, void *);
int NetGetConnectStatus(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetConnectStatus(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBE20 */

/* merge_units: begin func_002EBEC8 */
extern int NetIGetValidClientCount(void *, void *);
int NetGetValidClientCount(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetValidClientCount(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBEC8 */

/* merge_units: begin func_002EBF70 */
extern int NetIGetConnectionStatus(void *, void *);
int NetGetConnectionStatus(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetConnectionStatus(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EBF70 */

/* merge_units: begin func_002EC018 */
extern int NetIDataStreamBytesFree(void *, void *);
int NetDataStreamBytesFree(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIDataStreamBytesFree(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC018 */

/* merge_units: begin func_002EC0C0 */
extern int NetIGetServerVersion(void *, void *);
int NetGetServerVersion(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetServerVersion(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC0C0 */

/* merge_units: begin func_002EC168 */
extern int NetISetBufferSize(void *, void *);
int NetSetBufferSize(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISetBufferSize(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC168 */

/* merge_units: begin func_002EC210 */
extern int NetISetMyClientObject(void *);
int NetSetMyClientObject(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISetMyClientObject(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC210 */

/* merge_units: begin func_002EC2A8 */
extern int NetIFreeObject(void *);
int NetFreeObject(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIFreeObject(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC2A8 */

/* merge_units: begin func_002EC340 */
extern int NetIFreeAllObjects(void);
int NetFreeAllObjects(void)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIFreeAllObjects();
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC340 */

/* merge_units: begin func_002EC3C8 */
extern int NetIRequestObjectPrivateOwnership(void *);
int NetRequestObjectPrivateOwnership(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIRequestObjectPrivateOwnership(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC3C8 */

/* merge_units: begin func_002EC460 */
extern int NetIReleaseObjectPrivateOwnership(void *);
int NetReleaseObjectPrivateOwnership(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIReleaseObjectPrivateOwnership(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC460 */

/* merge_units: begin func_002EC4F8 */
extern int NetIUpdate(void);
int NetUpdate(void)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIUpdate();
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC4F8 */

/* merge_units: begin func_002EC580 */
extern int NetIGetNetUpdateErrors(void *);
int NetGetNetUpdateErrors(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetNetUpdateErrors(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC580 */

/* merge_units: begin func_002EC618 */
extern int NetITick(void);
int NetTick(void)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetITick();
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC618 */

/* merge_units: begin func_002EC6A0 */
extern int NetILeave(void *);
int NetLeave(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetILeave(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC6A0 */

/* merge_units: begin func_002EC738 */
extern int NetIDisconnect(void *);
int NetDisconnect(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIDisconnect(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC738 */

/* merge_units: begin func_002EC7D0 */
extern int NetIStreamMediaJoinChannel(void *, void *);
int NetStreamMediaJoinChannel(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIStreamMediaJoinChannel(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC7D0 */

/* merge_units: begin func_002EC878 */
extern int NetIStreamMediaQuitChannel(void *, void *);
int NetStreamMediaQuitChannel(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIStreamMediaQuitChannel(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC878 */

/* merge_units: begin func_002EC920 */
extern int NetIStreamMediaGetChannelInfo(void *, void *, void *);
int NetStreamMediaGetChannelInfo(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIStreamMediaGetChannelInfo(a, b, c);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC920 */

/* merge_units: begin func_002EC9D8 */
extern int NetIStreamMediaGetClientInfo(void *, void *, void *);
int NetStreamMediaGetClientInfo(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIStreamMediaGetClientInfo(a, b, c);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002EC9D8 */

/* merge_units: begin func_002ECA90 */
extern int NetIStreamMediaEndRecording(void *, void *);
int NetStreamMediaEndRecording(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIStreamMediaEndRecording(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECA90 */

/* merge_units: begin func_002ECB38 */
extern int NetIStreamMediaGetCurrentChannelState(void *, void *);
int NetStreamMediaGetCurrentChannelState(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIStreamMediaGetCurrentChannelState(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECB38 */

/* merge_units: begin func_002ECBE0 */
extern void *memset(void *, int, unsigned int);
int NetStreamMediaSetDefaultIgnoreParams(int *p)
{
    int r;
    unsigned char v;
    if (D_0048C4D7 != 1) return 0x11;
    v = D_0048C4DC;
    if (v != D_0048C4D7) return 0x2B;
    if (p == 0) return 0x17;
    r = rt_mutex_lock(D_005253F0, 0);
    if (r) return 0x2B;
    memset(p, 0, 0x10);
    *p = v;
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECBE0 */

/* merge_units: begin func_002ECC98 */
extern int NetIStreamMediaSetIgnoreState(void *);
int NetStreamMediaSetIgnoreState(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIStreamMediaSetIgnoreState(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECC98 */

/* merge_units: begin func_002ECD30 */
extern int NetISetDefaultStreamMediaParams(void *);
int func_002ECD30(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISetDefaultStreamMediaParams(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECD30 */

/* merge_units: begin func_002ECDC8 */
extern int NetISetFieldChanged(void *, void *);
int NetSetFieldChanged(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISetFieldChanged(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECDC8 */

/* merge_units: begin func_002ECE70 */
extern int NetISendFieldUpdates(void *);
int func_002ECE70(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISendFieldUpdates(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECE70 */

/* merge_units: begin func_002ECF08 */
extern int NetIGetClientBufferStatus(void *, void *, void *, void *, void *, void *);
int NetGetClientBufferStatus(void *a, void *b, void *c, void *d, void *e, void *f)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetClientBufferStatus(a, b, c, d, e, f);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
/* merge_units: end func_002ECF08 */
