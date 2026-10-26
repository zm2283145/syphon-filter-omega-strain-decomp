/*
 * lib/libkernl: 2 files, 001158F8-00115958
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001158F8 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int SetVTLBRefillHandler(int, int *);                            
unsigned int D_00486598[2] = { 0x0, 0x0 };
extern int func_00115E40;

int SetTLBHandler(int arg0) {
    (*(int*)D_00486598) = arg0;
    SetVTLBRefillHandler(1, &func_00115E40);
    SetVTLBRefillHandler(2, &func_00115E40);
    SetVTLBRefillHandler(3, &func_00115E40);
    return arg0;
}
/* merge_units: end func_001158F8 */

/* merge_units: begin func_00115958 */
const unsigned int D_004865A0[16] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
extern char D_00116080[];
#if 0 /* merge_units */
extern int SetVTLBRefillHandler(int, void *);
#endif /* merge_units */
#define SetVTLBRefillHandler(a0, a1) (SetVTLBRefillHandler((a0), (int *)(a1))) /* merge_units */

extern int SetVCommonHandler(int, void *);

unsigned int SetDebugHandler(int n, int h)
{
    int old;
    if ((unsigned int)(n - 1) >= 13) return 0xFFFFFFFF;
    old = ((int*)D_004865A0)[n];
    ((int*)D_004865A0)[n] = h;
    if ((unsigned int)(n - 1) < 3) {
        SetVTLBRefillHandler(n, D_00116080);
    } else {
        SetVCommonHandler(n, D_00116080);
    }
    return old;
}
#undef SetVTLBRefillHandler /* merge_units */
/* merge_units: end func_00115958 */
