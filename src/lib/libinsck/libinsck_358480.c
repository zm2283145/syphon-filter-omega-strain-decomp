/*
 * lib/libinsck: 3 files, 00358480-00358500
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00358480 */
typedef struct N8480 { struct N8480 *next; int a; int id; } N8480;
unsigned int D_00492CD8[1] = { 0x0 };
N8480 *socket_info(int id)
{
    N8480 *n;
    for (n = (*(N8480 **)D_00492CD8); n; n = n->next)
        if (id == n->id) return n;
    return 0;
}
/* merge_units: end func_00358480 */

/* merge_units: begin func_003584B8 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00357150(int);                             
int memset(int, int, int);                                     

void conv_addr_to_inet(int arg0, int *arg1) {
    memset(arg0, 0, 0x10);
    F_(arg0, 0x4, int) = func_00357150(*arg1);
}
/* merge_units: end func_003584B8 */

/* merge_units: begin func_00358500 */
                             

void conv_addr_from_inet(int *arg0, int arg1) {
    *arg0 = func_00357150(F_(arg1, 0x4, int));
}
/* merge_units: end func_00358500 */
