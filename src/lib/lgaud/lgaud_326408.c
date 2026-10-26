/*
 * lib/lgaud: 2 files, 00326408-00326470
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00326408 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
unsigned char frombcd(unsigned char);                               

void convertfrombcd(int arg0) {
    F_(arg0, 0x7, unsigned char) = frombcd(F_(arg0, 0x7, unsigned char));
    F_(arg0, 0x6, unsigned char) = frombcd(F_(arg0, 0x6, unsigned char));
    F_(arg0, 0x5, unsigned char) = frombcd(F_(arg0, 0x5, unsigned char));
    F_(arg0, 0x3, unsigned char) = frombcd(F_(arg0, 0x3, unsigned char));
    F_(arg0, 0x2, unsigned char) = frombcd(F_(arg0, 0x2, unsigned char));
    F_(arg0, 0x1, unsigned char) = frombcd(F_(arg0, 0x1, unsigned char));
}
/* merge_units: end func_00326408 */

/* merge_units: begin func_00326470 */
unsigned char tobcd(unsigned char);                               

void converttobcd(int arg0) {
    F_(arg0, 0x7, unsigned char) = tobcd(F_(arg0, 0x7, unsigned char));
    F_(arg0, 0x6, unsigned char) = tobcd(F_(arg0, 0x6, unsigned char));
    F_(arg0, 0x5, unsigned char) = tobcd(F_(arg0, 0x5, unsigned char));
    F_(arg0, 0x3, unsigned char) = tobcd(F_(arg0, 0x3, unsigned char));
    F_(arg0, 0x2, unsigned char) = tobcd(F_(arg0, 0x2, unsigned char));
    F_(arg0, 0x1, unsigned char) = tobcd(F_(arg0, 0x1, unsigned char));
}
/* merge_units: end func_00326470 */
