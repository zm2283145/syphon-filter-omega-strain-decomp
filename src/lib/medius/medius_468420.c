/*
 * lib/medius: 2 files, 00468420-00468470
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00468420 */
typedef struct { int a; int b; } P;
extern int D_00497CC4;
extern void *func_00468480(void);
void func_00468420(P *p)
{
    if (p->b == 1) D_00497CC4 = p->a;
    else D_00497CC4 = p->a;
    if (func_00468480() == 0) return;
    ((void (*)(int))func_00468480())(D_00497CC4);
}
/* merge_units: end func_00468420 */

/* merge_units: begin func_00468470 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
unsigned int D_00497E28[1] = { 0x0 };

void func_00468470(int arg0) {
    (*(int*)D_00497E28) = arg0;
}
/* merge_units: end func_00468470 */
