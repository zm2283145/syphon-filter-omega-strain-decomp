/*
 * lib/lgaud: 2 files, 00326408-00326470
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00326408 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
unsigned char func_003263E8(unsigned char);                               

void func_00326408(int arg0) {
    F_(arg0, 0x7, unsigned char) = func_003263E8(F_(arg0, 0x7, unsigned char));
    F_(arg0, 0x6, unsigned char) = func_003263E8(F_(arg0, 0x6, unsigned char));
    F_(arg0, 0x5, unsigned char) = func_003263E8(F_(arg0, 0x5, unsigned char));
    F_(arg0, 0x3, unsigned char) = func_003263E8(F_(arg0, 0x3, unsigned char));
    F_(arg0, 0x2, unsigned char) = func_003263E8(F_(arg0, 0x2, unsigned char));
    F_(arg0, 0x1, unsigned char) = func_003263E8(F_(arg0, 0x1, unsigned char));
}
/* merge_units: end func_00326408 */

/* merge_units: begin func_00326470 */
unsigned char func_003263B8(unsigned char);                               

void func_00326470(int arg0) {
    F_(arg0, 0x7, unsigned char) = func_003263B8(F_(arg0, 0x7, unsigned char));
    F_(arg0, 0x6, unsigned char) = func_003263B8(F_(arg0, 0x6, unsigned char));
    F_(arg0, 0x5, unsigned char) = func_003263B8(F_(arg0, 0x5, unsigned char));
    F_(arg0, 0x3, unsigned char) = func_003263B8(F_(arg0, 0x3, unsigned char));
    F_(arg0, 0x2, unsigned char) = func_003263B8(F_(arg0, 0x2, unsigned char));
    F_(arg0, 0x1, unsigned char) = func_003263B8(F_(arg0, 0x1, unsigned char));
}
/* merge_units: end func_00326470 */
