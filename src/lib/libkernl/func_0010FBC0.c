typedef struct {
    int pid;
    void *pkt_table;
    int pkt_table_len;
    int unused1;
    int unused2;
    unsigned char *rdata_table;
    int rdata_table_len;
    unsigned char *client_table;
    int client_table_len;
    int rdata_table_idx;
} SifRpcData;

typedef struct {
    int psize;
    void *dest;
    int cid;
    int opt;
} SifCmdHeader;

typedef struct {
    SifCmdHeader header;
    char body[48];
} SifRpcPkt;

extern int D_004861B0;
extern SifRpcPkt D_004E2F80[32];
extern int D_004E3780[512];
extern int D_004E3F80[512];
extern SifRpcData D_004E4780;

extern int DIntr(void);
extern int EIntr(void);
extern void sceSifInitCmd(void);
extern void sceSifAddCmdHandler(unsigned int, void *, void *);
extern int sceSifGetReg(unsigned int);
extern int sceSifSetReg(unsigned int, int);
extern int sceSifSendCmd(unsigned int, void *, int, void *, void *, int);
extern int sceSifGetSreg(int);
extern void _request_end_void(void);
extern void _request_bind(void);
extern void _request_call(void);
extern void _request_rdata(void);

void sceSifInitRpc(int mode)
{
    SifCmdHeader *hdr;

    DIntr();
    if (D_004861B0 != 0) {
        EIntr();
        return;
    }
    D_004861B0 = 1;
    EIntr();
    sceSifInitCmd();
    DIntr();
    D_004E4780.pkt_table = (void *)((unsigned int)D_004E2F80 | 0x20000000);
    D_004E4780.pkt_table_len = 32;
    D_004E4780.unused1 = 0;
    D_004E4780.unused2 = 0;
    D_004E4780.rdata_table = (unsigned char *)((unsigned int)D_004E3780 | 0x20000000);
    D_004E4780.rdata_table_len = 32;
    D_004E4780.client_table = (unsigned char *)((unsigned int)D_004E3F80 | 0x20000000);
    D_004E4780.client_table_len = 32;
    D_004E4780.rdata_table_idx = 0;
    D_004E4780.pid = 1;
    sceSifAddCmdHandler(0x80000008, _request_end_void, &D_004E4780);
    sceSifAddCmdHandler(0x80000009, _request_bind, &D_004E4780);
    sceSifAddCmdHandler(0x8000000A, _request_call, &D_004E4780);
    sceSifAddCmdHandler(0x8000000C, _request_rdata, &D_004E4780);
    EIntr();
    if (sceSifGetReg(0x80000002) != 0) {
        return;
    }
    hdr = &D_004E2F80[1].header;
    hdr->opt = 1;
    sceSifSendCmd(0x80000002, hdr, 0x10, 0, 0, 0);
    while (sceSifGetSreg(0) == 0) {}
    sceSifSetReg(0x80000002, 1);
}
