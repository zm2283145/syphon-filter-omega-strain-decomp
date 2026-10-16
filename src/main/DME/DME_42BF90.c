/*
 * main/DME: 3 files, 0042BF90-0042C1D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042BF90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between DME.cc and nellymoser_wrapper.c (starts 0x0042C1E0).
 */

#include "types.h"

extern char D_00582630;
extern char D_00582640;
extern char D_00582650;
extern int D_00582668;
extern int D_00582670;
extern int D_00582678;

/* Clears three flags and three counters. */
void func_0042BF90(void) {
    D_00582630 = 0;
    D_00582640 = 0;
    D_00582650 = 0;
    D_00582668 = 0;
    D_00582670 = 0;
    D_00582678 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042BF90 */

/* merge_units: begin func_0042BFD0 */
#pragma push /* merge_units */
#pragma opt_propagation off
extern short D_005825BE;
extern char D_005825C0;
extern unsigned short D_005825C2;
extern unsigned char D_005825C4;
extern char* D_005825B0;
extern unsigned char* D_005825B8;
extern int D_00542D48;
extern int D_00582570;
void func_0031E180(int h, unsigned short* out);
void func_0031C3F0(int h, char** io);

static inline void Copy_BFD0(void* d0, void* s0, int n0)
{
    int n = n0;
    int t;
    int m;
    void* d = d0;
    void* s = s0;
    asm {
        .set noreorder
        blez n, done
        andi m, s, 0xF
        andi t, d, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
    quads:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu s, s, 0x10
        bgtz n, quads
        sq t, -0x10(d)
        b done
        nop
    bytes:
        lb t, 0(s)
        addiu d, d, 1
        addi n, n, -1
        addiu s, s, 1
        bgtz n, bytes
        sb t, -1(d)
    done:
        .set reorder
    }
}

static inline void Clear_BFD0(void* d0, int n0)
{
    int n = n0;
    int m;
    int q;
    void* d = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi m, d, 0xF
        andi q, n, 0xF
        or m, m, q
        nop
        bgtz m, bytes
        srl q, n, 4
        nop
        blez q, bytes
        nop
    quads:
        addi q, q, -1
        sq $zero, 0(d)
        bgtz q, quads
        addiu d, d, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(d)
        bgtz n, bytes
        addiu d, d, 1
    done:
        .set reorder
    }
}

int func_0042BFD0(char* in, char* out, char* flag)
{
    int n;
    unsigned short got;
    D_005825BE = 0;
    D_005825C0 = 0;
    D_005825C2 = 0;
    D_005825C4 = 0;
    Copy_BFD0(D_005825B0, in, 0x140);
    D_00542D48 = -1;
    func_0031C3F0(D_00582570, &D_005825B0);
    n = D_005825C2;
    func_0031E180(D_00582570, &got);
    *flag = got != 0;
    if (got)
        Copy_BFD0(out, D_005825B8, n);
    else
        Clear_BFD0(out, n);
    if (D_005825C4 > 0)
        *D_005825B8 = D_005825B8[n];
    D_005825C2 = 0;
    return n;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042BFD0 */

/* merge_units: begin func_0042C1D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after DME.cc (ends 0x0042ACD0),
 * before nellymoser_wrapper.c (starts 0x0042C1E0).
 */


void func_0042C1D0(void) {
}
#pragma pop /* merge_units */
/* merge_units: end func_0042C1D0 */
