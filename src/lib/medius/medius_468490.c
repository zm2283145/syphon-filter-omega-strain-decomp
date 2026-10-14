/*
 * lib/medius: 3 files, 00468490-004684E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00468490 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern int D_00497E28;

void func_00468490(void) {
    D_00497E28 = 0;
}
/* merge_units: end func_00468490 */

/* merge_units: begin func_004684A0 */
typedef void (*Fn4684)(int);
extern Fn4684 func_004684F0(void);
void func_004684A0(int a)
{
    if (func_004684F0()) func_004684F0()(a);
}
/* merge_units: end func_004684A0 */

/* merge_units: begin func_004684E0 */
int D_00497E2C = 0;

void func_004684E0(int arg0) {
    D_00497E2C = arg0;
}
/* merge_units: end func_004684E0 */
