/*
 * lib/medius: 6 files, 0031DD70-0031DFA8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0031DD70 */
#include "types.h"
extern float D_004E1CA0;
int func_0031DD70(int n, float x) { int r = (int)(512.0f / x * D_004E1CA0 + 0.5f); if (n < r) r = n; return r; }
/* merge_units: end func_0031DD70 */

/* merge_units: begin func_0031DDB0 */
void func_0031DDB0(float* in, float* out)
{
    unsigned int i, j, k;
    out += 255;
    j = 0xA280;
    for (i = 255; i >= 0x57; i--) { j -= 0xA2; k = (((j >> 8) + 0x41) * i + 0xD1 >> 8) + 0x1D; *out-- = in[k]; }
    j = 0x457D;
    for (i = 0x57; i != 0; i--) { j -= 0xCB; *out-- = in[j >> 8]; }
}
/* merge_units: end func_0031DDB0 */

/* merge_units: begin func_0031DE38 */
int func_0031DE38(float x)
{
    if (x > 96.0f) return 0x105;
    if (x > 88.0f) return 0xF1;
    if (x > 80.0f) return 0xDD;
    if (x > 72.0f) return 0xC9;
    if (x > 64.0f) return 0xB5;
    if (x > 56.0f) return 0xA1;
    if (x > 48.0f) return 0xA1;
    if (x > 40.0f) return 0xA1;
    if (x > 32.0f) return 0xA1;
    return 0xA1;
}
/* merge_units: end func_0031DE38 */

/* merge_units: begin func_0031DEC8 */
extern float D_004E1C00;
extern float func_00121B18(float x);
float func_0031DEC8(float x) { return func_00121B18(x + 1.0f) * D_004E1C00; }
/* merge_units: end func_0031DEC8 */

/* merge_units: begin func_0031DEF8 */
typedef struct { char pad[0x4C]; void* p; } Inner_31D;
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    Inner_31D* inner;
} Handle_31D;
typedef struct {
    Handle_31D* owner;
    void* f4;
    void* f8;
    char pad0C[8];
    short f14;
    char pad16[8];
    unsigned char f1E;
    char pad1F;
} P_31D;
extern void* (*D_004E1D34)(int n, int size);
extern void (*D_004E1D38)(void*);
extern int func_0031ED08(void** p, short n, float x);
extern int func_0031E828(void** p);
int func_0031DEF8(Handle_31D* h)
{
    Inner_31D* in;
    P_31D* p;
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    in = h->inner;
    p = D_004E1D34(1, sizeof(P_31D));
    in->p = p;
    if (!p) return 0x1770;
    if (func_0031ED08(&p->f4, 160, 8000.0f)) return 0x1770;
    if (func_0031E828(&p->f8)) return 0x1770;
    p->owner = h;
    p->f14 = 0;
    p->f1E = 0;
    return 0;
}
/* merge_units: end func_0031DEF8 */

/* merge_units: begin func_0031DFA8 */
extern int func_0031EDC8(void** p);
extern int func_0031E8B0(void** p);
int func_0031DFA8(Handle_31D* h)
{
    P_31D* p;
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 10) return 0x17DE;
    p = h->inner->p;
    if (func_0031EDC8(&p->f4)) return 0x17E8;
    if (func_0031E8B0(&p->f8)) return 0x17E8;
    if (p) D_004E1D38(p);
    return 0;
}
/* merge_units: end func_0031DFA8 */
