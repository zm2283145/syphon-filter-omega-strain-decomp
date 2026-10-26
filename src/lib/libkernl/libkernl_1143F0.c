/*
 * lib/libkernl: 3 files, 001143F0-001144E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001143F0 */
extern int D_00486258;
extern char D_004E6000[];
extern int D_004E6040[];
extern int D_004E6080[];
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);

int sceSifAllocIopHeap(int a0)
{
    if (D_00486258 < 0) return 0;
    D_004E6080[0] = a0;
    if (sceSifCallRpc(D_004E6000, 1, 0, D_004E6080, 4, D_004E6040, 4, 0, 0) < 0) return 0;
    return D_004E6040[0];
}
/* merge_units: end func_001143F0 */

/* merge_units: begin func_00114460 */
int sceSifAllocSysMemory(int a0, int a1, int a2)
{
    if (D_00486258 < 0) return 0;
    D_004E6080[0] = a1;
    D_004E6080[1] = a0;
    D_004E6080[2] = a2;
    if (sceSifCallRpc(D_004E6000, 4, 0, D_004E6080, 12, D_004E6040, 4, 0, 0) < 0) return 0;
    return D_004E6040[0];
}
/* merge_units: end func_00114460 */

/* merge_units: begin func_001144E0 */
int sceSifFreeSysMemory(int a0)
{
    if (D_00486258 < 0) return 0;
    D_004E6080[0] = a0;
    if (sceSifCallRpc(D_004E6000, 2, 0, D_004E6080, 4, D_004E6040, 4, 0, 0) < 0) return -1;
    return D_004E6040[0];
}
/* merge_units: end func_001144E0 */
