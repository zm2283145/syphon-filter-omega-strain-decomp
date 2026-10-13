typedef struct { char pad[0x24]; int serve; } RpcCd;
extern RpcCd D_004E6000;
unsigned int D_00486258[2] = { 0xFFFFFFFF, 0x0 };
extern int sceSifBindRpc(RpcCd*, unsigned int, int);
int func_00114368(void) {
    int n;
    for (;;) {
        if (sceSifBindRpc(&D_004E6000, 0x80000003, 0) < 0) return -1;
        if (D_004E6000.serve) break;
        n = 0x100000;
        while (n--) {}
    }
    (*(int*)D_00486258) = 0;
    /* Keep the completion store before the return-value setup. */
    __asm__ __volatile__("" ::: "memory");
    return 0;
}

