/*
 * lib/libkernl: 2 files, 001158F8-00115958
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001158F8 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_0010CE10(int, int *);                            
unsigned int D_00486598[2] = { 0x0, 0x0 };
extern int func_00115E40;

int func_001158F8(int arg0) {
    (*(int*)D_00486598) = arg0;
    func_0010CE10(1, &func_00115E40);
    func_0010CE10(2, &func_00115E40);
    func_0010CE10(3, &func_00115E40);
    return arg0;
}
/* merge_units: end func_001158F8 */

/* merge_units: begin func_00115958 */
const unsigned int D_004865A0[16] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
extern char D_00116080[];
#if 0 /* merge_units */
extern int func_0010CE10(int, void *);
#endif /* merge_units */
#define func_0010CE10(a0, a1) (func_0010CE10((a0), (int *)(a1))) /* merge_units */

extern int func_0010CE20(int, void *);

unsigned int func_00115958(int n, int h)
{
    int old;
    if ((unsigned int)(n - 1) >= 13) return 0xFFFFFFFF;
    old = ((int*)D_004865A0)[n];
    ((int*)D_004865A0)[n] = h;
    if ((unsigned int)(n - 1) < 3) {
        func_0010CE10(n, D_00116080);
    } else {
        func_0010CE20(n, D_00116080);
    }
    return old;
}
#undef func_0010CE10 /* merge_units */
/* merge_units: end func_00115958 */
