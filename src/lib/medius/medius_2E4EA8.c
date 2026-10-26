/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
extern int D_0048C458;
extern int *D_0048C4A8;
extern unsigned char D_0048C4AC;
extern int D_0048C4B0;
extern int NetDisablePingIPs(void);
extern int NetGetConnInfo(int, void **);
extern int NetIDisconnect(int);
int __attribute__((weak, section(".dtors_drop"))) NetIFreeAllObjects(void) { return 0; }
extern int NetFreeAllClients(void), NetFreeClientPointers(void), rt_parse_shutdown(void);
extern int NetFreeAllDataStreams(void);
extern int DmeFree(void *);
extern int NetDestroyClientInfo(int, int);
extern int NetDestroyConnInfo(int);
extern int NetCleanupClientPingInfoArray(void);
extern int rt_p2p_destroy(int);
extern int rt_msg_client_shutdown(void), NetStreamMediaShutdown(void);
int NetIClose(void)
{
    void *p = 0;
    int i, j, r;
    if (D_0048C458 != 1) return 0x11;
    NetDisablePingIPs();
    for (j = 0; j < 4; j++) {
        r = NetGetConnInfo(j, &p);
        if (r != 0) return r;
        if (p != 0 && *(int *)((char *)p + 0x438) == 1) NetIDisconnect(j);
    }
    NetIFreeAllObjects();
    NetFreeAllClients();
    NetFreeClientPointers();
    rt_parse_shutdown();
    if (D_0048C4A8) {
        NetFreeAllDataStreams();
        DmeFree(&D_0048C4A8);
        D_0048C4A8 = 0;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 0x100; j++) NetDestroyClientInfo(i, j);
        NetDestroyConnInfo(i);
    }
    NetCleanupClientPingInfoArray();
    if (D_0048C4AC) {
        rt_p2p_destroy(D_0048C4B0);
        D_0048C4AC = 0;
    }
    rt_msg_client_shutdown();
    NetStreamMediaShutdown();
    D_0048C458 = 0;
    return 0;
}
