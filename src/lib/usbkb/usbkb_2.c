/*
 * lib/usbkb: 2 files, 00222E38-00222EE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00222E38 */
typedef struct { char pad[0x90]; int x90; int x94; void *x98; } KbState;
extern int D_0048AB18;
extern char D_004F5820[];
extern char D_004F5880[];
extern char D_004F58C0[];
extern KbState D_004F5780;
extern int WaitSema(int);
extern int scePrintf(const char *, ...);
extern void func_00223400(void *);
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);

int sceUsbKbGetInfo(void *info)
{
    int r;
    if (D_0048AB18 == -1) return -1;
    WaitSema(D_0048AB18);
    r = sceSifCallRpc(D_004F5820, 1, 1, D_004F5880, 0x10, D_004F58C0, 0x90, func_00223400, 0);
    if (r != 0) {
        scePrintf("sceUsbKbGetInfo: sceSifCallRpc -> %d
", r);
        return -2;
    }
    D_004F5780.x90 = 1;
    D_004F5780.x98 = info;
    return 0;
}
/* merge_units: end func_00222E38 */

/* merge_units: begin func_00222EE0 */
typedef struct { unsigned int max; char pad[0x8C]; int x90; int x94; void *x98; } KbState_00222EE0;
#if 0 /* merge_units */
extern unsigned char D_004F5880[];
#endif /* merge_units */
#define D_004F5880 ((unsigned char*)&D_004F5880) /* merge_units */

#if 0 /* merge_units */
extern KbState_00222EE0 D_004F5780;
#endif /* merge_units */
#define D_004F5780 (*(KbState_00222EE0*)&D_004F5780) /* merge_units */


int sceUsbKbRead(unsigned int port, void *data)
{
    KbState_00222EE0 *st;
    int r;
    if (D_0048AB18 == -1) return -1;
    st = &D_004F5780;
    if (port >= (unsigned int)st->max) return -0xB;
    D_004F5880[0] = port;
    WaitSema(D_0048AB18);
    r = sceSifCallRpc(D_004F5820, 2, 1, D_004F5880, 0x10, D_004F58C0, 0x50, func_00223400, 0);
    if (r != 0) {
        scePrintf("sceUsbKbRead: sceSifCallRpc -> %d
", r);
        return -2;
    }
    st->x98 = data;
    st->x94 = port;
    st->x90 = 2;
    return 0;
}
#undef D_004F5880 /* merge_units */
#undef D_004F5780 /* merge_units */
/* merge_units: end func_00222EE0 */
