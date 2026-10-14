/*
 * lib/medius: 4 files, 00313D90-00313F18
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00313D90 */
static const unsigned int dat_004B12F0[56] = { 0x5323, 0x0, 0x0, 0x0, 0x61654824, 0x3A726564, 0x72702F20, 0x63656A6F, 0x722F7374, 0x656D6974, 0x5356432F, 0x5F74722F, 0x70797263, 0x72732F74, 0x73702F63, 0x48532F32, 0x705F3141, 0x6674616C, 0x2E6D726F, 0x20762C63, 0x20362E31, 0x33303032, 0x2F30312F, 0x32203531, 0x30343A33, 0x2035353A, 0x69616D61, 0x70784520, 0x2420, 0x0, 0x61654824, 0x3A726564, 0x72702F20, 0x63656A6F, 0x722F7374, 0x656D6974, 0x5356432F, 0x5F74722F, 0x70797263, 0x72732F74, 0x48532F63, 0x705F3141, 0x6674616C, 0x2E6D726F, 0x20762C68, 0x20322E31, 0x33303032, 0x2F30312F, 0x32203531, 0x30343A33, 0x2035303A, 0x69616D61, 0x70784520, 0x2420, 0x0, 0x0 };
void func_00313D90(int *out)
{
    if (((*(unsigned short*)dat_004B12F0) >> 8) == 0x23) *out = 1;
    else *out = 0;
}
/* merge_units: end func_00313D90 */

/* merge_units: begin func_00313DB8 */
typedef struct { char pad[0x18]; unsigned int count; char pad2[0xA4 - 0x1C]; int sock; char pad3[0xFC - 0xA8]; int ids[64]; unsigned char busy; char pad4[3]; unsigned int cur; } Obj3DB8;
extern short D_00491432;
extern unsigned char D_00491430;
extern int func_00315028(int id, Obj3DB8 **out);
extern int func_002F5020(int sock, int h);
extern int func_00315E28(int r, int code);
int func_00313DB8(int id, unsigned int idx)
{
    Obj3DB8 *o;
    int ok;
    int r;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    if (idx >= 64) return 0x17;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    if (idx >= o->count) return 0x17;
    o->cur = idx;
    r = func_00315E28(func_002F5020(o->sock, o->ids[o->cur]), 0x2A);
    if (r == 0) o->busy = ok;
    return r;
}
/* merge_units: end func_00313DB8 */

/* merge_units: begin func_00313E70 */
typedef struct { char pad[0x18]; unsigned int count; char pad2[0xA4 - 0x1C]; int sock; char pad3[0xFC - 0xA8]; int ids[64]; unsigned char busy; } Obj3E70;
#if 0 /* merge_units */
extern int func_00315028(int id, Obj3E70 **out);
#endif /* merge_units */
#define func_00315028(a0, a1) (func_00315028((a0), (Obj3DB8 * *)(a1))) /* merge_units */

extern int func_002F5038(int sock, int h);
int func_00313E70(int id, unsigned int idx)
{
    Obj3E70 *o;
    int r;
    if (D_00491432 <= 0) return 0x11;
    if (D_00491430 != 1) return 0x11;
    if (idx >= 64) return 0x17;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    if (idx >= o->count) return 0x17;
    r = func_00315E28(func_002F5038(o->sock, o->ids[idx]), 0x2A);
    if (r == 0) o->busy = 0;
    return r;
}
#undef func_00315028 /* merge_units */
/* merge_units: end func_00313E70 */

/* merge_units: begin func_00313F18 */
typedef struct { int id; unsigned int idx; int val; } Res3F18;
typedef struct {
    char pad[0x18];
    unsigned int count;
    char pad2[0xA4 - 0x1C];
    int sock;
    char pad3[0x208 - 0xA8];
    unsigned char state;
    char pad4[3];
    Res3F18 res;
} Obj3F18;
#if 0 /* merge_units */
extern int func_00315028(int id, Obj3F18 **out);
#endif /* merge_units */
#define func_00315028(a0, a1) (func_00315028((a0), (Obj3DB8 * *)(a1))) /* merge_units */

extern int func_002F50C0(int sock, int (*cb)(), int arg);
extern int func_003158D8();
int func_00313F18(int id, unsigned int idx, Res3F18 *out)
{
    Obj3F18 *o;
    int ok;
    int r;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    if (out == 0) return 0x17;
    if (idx >= 64) return 0x17;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    if (idx >= o->count) return 0x17;
    o->state = ok;
    o->res.id = id;
    o->res.idx = idx;
    r = func_002F50C0(o->sock, func_003158D8, 0);
    if (o->state == ok) return 0x29;
    o->state = 0;
    r = func_00315E28(r, 0x2A);
    if (r != 0) return r;
    *out = o->res;
    return r;
}
#undef func_00315028 /* merge_units */
/* merge_units: end func_00313F18 */
