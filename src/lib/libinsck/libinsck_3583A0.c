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
extern void sceLibnetTerminate(void *);
extern void my_free(void *);
extern int unblock(void);
extern int func_00358158(void);
extern int GetThreadId(void);
extern int DeleteSema(int);
extern int D_00492CE0;
extern int *Newlib_Errno(void);

int Insck_SetErrno(N81E0 *n, int err)
{
    n->err = err;
    if (D_00492CE0) *Newlib_Errno() = err;
    unblock();
    return err ? -1 : 0;
}
/* merge_units: end func_003583A0 */

/* merge_units: begin func_003583F0 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int unblock();                                  
int Insck_GetThreadContext(int);                               
int D_00492CE4 = 12;

int func_003583F0(void) {
    int temp_v0;

    temp_v0 = Insck_GetThreadContext(1);
    if (temp_v0 == 0) {
        return &D_00492CE4;
    }
    unblock();
    return temp_v0 + 0xC;
}
/* merge_units: end func_003583F0 */

/* merge_units: begin func_00358438 */
#pragma mpwc_relax on
                               
static const unsigned int dat_00492CE8[2] = { 0xFFFFFFFF, 0x0 };

int func_00358438(void) {
    int temp_v0;

    temp_v0 = Insck_GetThreadContext(1);
    if (temp_v0 == 0) {
        return &(*(int*)dat_00492CE8);
    }
    unblock();
    return temp_v0 + 0x10;
}
/* merge_units: end func_00358438 */
