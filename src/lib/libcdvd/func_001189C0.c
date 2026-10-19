typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { unsigned int lsn; unsigned int size; char name[16]; unsigned char date[8]; unsigned int flag; } sceCdlFILE;
typedef struct { sceCdlFILE fp; char name[256]; void *dest; int layer; } SearchBuf;
extern int D_00487890;
extern volatile int D_004878A8;
extern int D_0048789C;
extern int D_004878C4;
extern int D_004E9D18;
extern int D_004E9D20;
extern RpcCd D_004E9F00;
extern SearchBuf D_004E9D80;
extern int D_004E9EC0;
extern char D_00498C60[];
extern char D_00498C80[];
extern char D_00498C98[];
extern char D_00498CA8[];
extern char D_00498CB8[];
extern void func_00118718(void);
extern int PollSema(int);
extern int SignalSema(int);
extern int ReferThreadStatus(int, void *);
extern int sceCdSync(int);
extern void func_0010FBC0(int);
extern void func_0010FB10(void *, int);
extern int sceSifBindRpc(RpcCd *cd, unsigned int id, int mode);
extern int sceSifCallRpc(RpcCd *, int, int, void *, int, void *, int, void *, void *);
extern void scePrintf(const char *, ...);

/* busy-wait; the nop has no C equivalent */
#define DELAY() { int j = 0x100000; do { j--; __asm__ volatile("nop"); } while (j != -1); }

int sceCdSearchFile(sceCdlFILE *fp, const char *name, int layer)
{
    int i;
    int ret;
    func_00118718();
    if (D_004878A8 != PollSema(D_004878A8)) return 0;
    D_0048789C = 1;
    ReferThreadStatus(D_004E9D18, &D_004E9D20);
    if (sceCdSync(1)) {
        SignalSema(D_004878A8);
        return 0;
    }
    func_0010FBC0(0);
    if (D_004878C4 < 0) {
        do {
            if (sceSifBindRpc(&D_004E9F00, 0x80000597, 0) < 0) {
                if (D_00487890 > 0) scePrintf(D_00498C60);
                DELAY();
                continue;
            }
            if (D_004E9F00.serve != 0) {
                D_004878C4 = 0;
                break;
            }
            DELAY();
        } while (1);
    }
    for (i = 0; i < 256 && (D_004E9D80.name[i] = name[i]) != 0; i++) ;
    if (i == 256) D_004E9D80.name[255] = 0;
    if (D_00487890 > 0) scePrintf(D_00498C80, D_004E9D80.name);
    D_004E9D80.layer = layer;
    D_004E9D80.dest = &D_004E9D80;
    func_0010FB10(&D_004E9D80, sizeof(SearchBuf));
    if (sceSifCallRpc(&D_004E9F00, 0, 0, &D_004E9D80, sizeof(SearchBuf), &D_004E9EC0, 4, 0, 0) < 0) {
        SignalSema(D_004878A8);
        return 0;
    }
    __builtin_memcpy(fp, (void *)((int)&D_004E9D80 | 0x20000000), sizeof(sceCdlFILE));
    if (D_00487890 > 0) scePrintf(D_00498C98, fp->name);
    if (D_00487890 > 0) scePrintf(D_00498CA8, fp->size);
    if (D_00487890 > 0) scePrintf(D_00498CB8, fp->lsn);
    ret = *(int *)((int)&D_004E9EC0 | 0x20000000);
    SignalSema(D_004878A8);
    return ret;
}
