#include "types.h"
extern int func_00438340(void);
extern int func_002EC7D0(int, int);
extern int func_0042B1A0(int);
extern int func_0042BB50(void*);
extern void func_00437DB0(void*, int);
extern unsigned char D_00582B88;
extern unsigned char D_005721D0;
extern unsigned char D_00582D00;
extern int D_005721A8;
extern int D_00497558;
extern int D_00497550;
extern int D_00582D10;
extern int D_00582D18;
extern unsigned char D_00582D20;
extern unsigned char D_00582D28;
extern char D_00494230[];
extern char D_00495710[];
extern char* D_00497560;

void func_00438770(int force)
{
    char buf[0x140];
    int now;
    int acc;
    int n;

    if (!func_00438340()) return;
    if (!D_00582B88) return;
    if (!D_005721D0 && !force) return;
    if (!D_00582D00 && D_005721D0 && !force) {
        if (!func_002EC7D0(D_005721A8, 0)) D_00582D00 = 1;
        D_00497558 = 0;
        D_00497550 = D_005721A8;
    }
    if (!D_00582D00) return;
    now = func_0042B1A0(1);
    acc = D_00582D18 + (now - D_00582D10);
    if (acc < 20) return;
    D_00582D18 = acc % 20;
    n = acc / 20;
    if (n > 8) n = 1;
    if (n > 0) {
    do {
        int r;
        if ((r = func_0042BB50(buf)) > 0) {
            func_00437DB0(buf, r);
        } else if (D_00582D20) {
            int len = 0x200;
            if ((int)D_00494230 + 0x14DE - (int)D_00497560 < 0x200) len = (int)D_00494230 + 0x14DE - (int)D_00497560;
            func_00437DB0(D_00497560, len);
            D_00497560 += len;
            if (D_00497560 - D_00494230 >= 0x14DE) {
                D_00582D20 = 0;
                D_00497560 = D_00495710;
            }
        } else if (D_00582D28) {
            int len = 0x200;
            if ((int)D_00495710 + 0x1E2E - (int)D_00497560 < 0x200) len = (int)D_00495710 + 0x1E2E - (int)D_00497560;
            func_00437DB0(D_00497560, len);
            D_00497560 += len;
            if (D_00497560 - D_00495710 >= 0x1E2E) {
                D_00582D28 = 0;
                D_00497560 = D_00494230;
            }
        } else {
            break;
        }
    } while (--n > 0);
    }
    D_00582D10 = now;
}








