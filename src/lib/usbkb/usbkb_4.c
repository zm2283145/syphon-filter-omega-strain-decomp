/*
 * lib/usbkb: 2 files, 002232C0-00223310
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002232C0 */
typedef struct { int a; int b; int c; char pad[0x38-0xC]; } E002232C0;
typedef struct { int count; E002232C0* tbl; } T002232C0;
extern T002232C0 D_004F5780;
int func_002232C0(int i, unsigned int v)
{
    if (i >= D_004F5780.count) return -11;
    if (v < 2) {
        int off = i * sizeof(E002232C0);
        ((E002232C0*)(off + (int)D_004F5780.tbl))->b = v;
        return 0;
    }
    return -12;
}
/* merge_units: end func_002232C0 */

/* merge_units: begin func_00223310 */
typedef struct { int a; int b; int c; char pad[0x38-0xC]; } E00223310;
typedef struct { int count; E00223310* tbl; } T00223310;
#if 0 /* merge_units */
extern T00223310 D_004F5780;
#endif /* merge_units */
#define D_004F5780 (*(T00223310*)&D_004F5780) /* merge_units */

int func_00223310(int i, unsigned int v)
{
    if (i >= D_004F5780.count) return -11;
    if (v < 3) {
        int off = i * sizeof(E00223310);
        ((E00223310*)(off + (int)D_004F5780.tbl))->c = v;
        return 0;
    }
    return -12;
}
#undef D_004F5780 /* merge_units */
/* merge_units: end func_00223310 */
