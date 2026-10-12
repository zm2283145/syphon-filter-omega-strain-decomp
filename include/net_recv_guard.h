#ifndef NET_RECV_GUARD_H
#define NET_RECV_GUARD_H
/*
 * NetRecvGuard: scoped "inside net receive handler" flag (D_005723C8) used by
 * the network message receive handlers. The object is empty but non-trivial,
 * so it takes a stack slot at the top of the handler's locals.
 * The out-of-line destructor copy is weak and placed in ".dtors_drop"
 * (discarded by the link script), like alloc_guard.h.
 * Include from C++ sources only (#pragma cplusplus on before including).
 */
#ifdef __cplusplus
extern "C" {
extern unsigned char D_005723C8;
}
#pragma define_section NET_RECV_GUARD_DTOR ".dtors_drop" far_absolute RX
struct NetRecvGuard {
    NetRecvGuard() { if (!D_005723C8) D_005723C8 = 1; }
    /* order matters: weak first, then the section */
    __declspec(weak) __declspec(NET_RECV_GUARD_DTOR) ~NetRecvGuard() { D_005723C8 = 0; }
};
#endif /* __cplusplus */
#endif /* NET_RECV_GUARD_H */
