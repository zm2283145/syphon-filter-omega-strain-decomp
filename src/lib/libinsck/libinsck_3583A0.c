/*
 * lib/libinsck: 3 files, 003583A0-00358438
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003583A0 */
typedef struct N81E0 { struct N81E0 *next; struct N81E0 *prev; int tid; int err; int x10; char x14[0x3C]; void *x50; } N81E0;
extern N81E0 *D_00492CD0;
extern N81E0 *D_00492CD4;
extern int D_00492CCC;
extern int D_00492CC8;
extern void func_0034B7E8(void *);
extern void func_00357D88(void *);
extern int func_003581C0(void);
extern int func_00358158(void);
extern int func_0010D050(void);
extern int DeleteSema(int);
extern int D_00492CE0;
extern int *func_00123320(void);

int func_003583A0(N81E0 *n, int err)
{
    n->err = err;
    if (D_00492CE0) *func_00123320() = err;
    func_003581C0();
    return err ? -1 : 0;
}
/* merge_units: end func_003583A0 */

/* merge_units: begin func_003583F0 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_003581C0();                                  
int func_003581E0(int);                               
int D_00492CE4 = 12;

int func_003583F0(void) {
    int temp_v0;

    temp_v0 = func_003581E0(1);
    if (temp_v0 == 0) {
        return &D_00492CE4;
    }
    func_003581C0();
    return temp_v0 + 0xC;
}
/* merge_units: end func_003583F0 */

/* merge_units: begin func_00358438 */
#pragma mpwc_relax on
                               
static const unsigned int dat_00492CE8[2] = { 0xFFFFFFFF, 0x0 };

int func_00358438(void) {
    int temp_v0;

    temp_v0 = func_003581E0(1);
    if (temp_v0 == 0) {
        return &(*(int*)dat_00492CE8);
    }
    func_003581C0();
    return temp_v0 + 0x10;
}
/* merge_units: end func_00358438 */
