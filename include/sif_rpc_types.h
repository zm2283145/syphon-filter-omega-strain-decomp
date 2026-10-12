#ifndef SIF_RPC_TYPES_H
#define SIF_RPC_TYPES_H

/*
 * SIF RPC client data (EE side of sceSifBindRpc/sceSifCallRpc), re-derived by
 * ~25 src/lib files as `struct { char pad[0x24]; int serve; }`.
 * Plain C for ee-gcc (any lib kind); also fine in MW C/C++.
 * Usual bind idiom:
 *   while (bind(&cd, SERVER_ID, 0) >= 0 && !cd.server) delay loop;
 * Some files declare the object padded to 0x40 because the next global
 * follows it; the extern's size does not change codegen.
 */
typedef struct SifRpcHeader {
    void* pkt_addr;          /* +0x00 */
    unsigned int rpc_id;     /* +0x04 */
    int sema_id;             /* +0x08 */
    unsigned int mode;       /* +0x0C */
} SifRpcHeader;

typedef struct SifRpcClientData {
    SifRpcHeader hdr;        /* +0x00 */
    unsigned int command;    /* +0x10 */
    void* buff;              /* +0x14 */
    void* cbuff;             /* +0x18 */
    void (*end_function)(void*); /* +0x1C */
    void* end_param;         /* +0x20 */
    void* server;            /* +0x24 nonzero once bound ("serve") */
} SifRpcClientData; /* 0x28 */

typedef char sif_rpc_client_data_size[(sizeof(SifRpcClientData) == 0x28) ? 1 : -1];

#endif /* SIF_RPC_TYPES_H */
