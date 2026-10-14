/*
 * lib/lgaud: 3 files, 00326080-00326130
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00326080 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_001115B0(int *, int);                          
int func_00111838(int);                               
int func_00111BF0(int, signed char *, int);                      
extern signed char D_004914A8;

signed char *func_00326080(void) {
    int temp_v0;

    if (D_004914A8 == 0) {
        temp_v0 = func_001115B0(((int*)"rom0:ROMVER"), 1);
        if (temp_v0 >= 0) {
            func_00111BF0(temp_v0, &D_004914A8, 0xE);
            func_00111838(temp_v0);
        }
    }
    return &D_004914A8;
}
/* merge_units: end func_00326080 */

/* merge_units: begin func_003260F0 */
#define NULL 0
#pragma mpwc_relax on
#if 0 /* merge_units */
int func_00326080();
#endif /* merge_units */
#define func_00326080() ((int)func_00326080()) /* merge_units */


int func_003260F0(void) {
    if (F_(&D_004914A8, 0x0, signed char) == 0) {
        func_00326080();
    }
    return F_(&D_004914A8, 0x4, signed char) == 0x54;
}
#undef func_00326080 /* merge_units */
/* merge_units: end func_003260F0 */

/* merge_units: begin func_00326130 */
extern void func_0010D210(void *);
extern int func_003260F0(void);
extern unsigned char D_004914A4;
int func_00326130(void)
{
    unsigned int c;
    int r;
    func_0010D210(&c);
    if (func_003260F0()) {
        r = D_004914A4;
    } else {
        func_0010D210(&c);
        if (((c >> 13) & 7) == 0) r = (c >> 4) & 1;
        else r = (c >> 16) & 0x1F;
    }
    return r;
}
/* merge_units: end func_00326130 */
