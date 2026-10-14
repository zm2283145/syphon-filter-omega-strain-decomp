/*
 * lib/medius: 3 files, 002CE8B0-002CE9E8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002CE8B0 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002CE748(int);                                 
int func_002CE768(int );                            

void func_002CE8B0(int arg0) {
    if (F_(arg0, 0x4, int) != 0) {
        func_002CE748(3);
        return;
    }
    if (F_(arg0, 0x0, int) == 0) {
        func_002CE748(3);
        return;
    }
    func_002CE768(arg0 + 8);
    func_002CE748(1);
}
/* merge_units: end func_002CE8B0 */

/* merge_units: begin func_002CE908 */
typedef struct { unsigned char b[76]; } BlkE908;
extern int D_0048C408;
extern BlkE908 D_0051F008;
void func_002CE908(int mode, BlkE908 *src)
{
    D_0048C408 = mode;
    if (mode == 0) D_0051F008 = *src;
}
/* merge_units: end func_002CE908 */

/* merge_units: begin func_002CE9E8 */
void func_002CE9E8(BlkE908 *dst)
{
    if (D_0048C408 == 0) *dst = D_0051F008;
}
/* merge_units: end func_002CE9E8 */
