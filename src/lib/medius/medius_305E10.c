/*
 * lib/medius: 4 files, 00305E10-00306018
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00305E10 */
typedef struct { int status; int f4; int f8; int fC; int f10; int f14; int f18; int pad[5]; } ScfThStat;
extern int ReferThreadStatus(int id, ScfThStat *st);
int func_00305E10(int *out)
{
    ScfThStat st;
    int cnt = 0;
    int i;
    int ret = 2;
    if (out == 0) return ret;
    *out = 0;
    for (i = 0; i < 256; i++) {
        if (ReferThreadStatus(i, &st) == -1) continue;
        if (st.status != 0) cnt++;
    }
    *out = cnt;
    return 0;
}
/* merge_units: end func_00305E10 */

/* merge_units: begin func_00305E98 */
int func_00305E98(int *out)
{
    ScfThStat st;
    int cnt = 0;
    int i;
    int ret = 2;
    if (out == 0) return ret;
    *out = 0;
    for (i = 0; i < 256; i++) {
        if (ReferThreadStatus(i, &st) == -1) continue;
        if (st.status != 0) continue;
        if (st.f18 != 0 || st.fC != 0) cnt++;
    }
    *out = cnt;
    return 0;
}
/* merge_units: end func_00305E98 */

/* merge_units: begin func_00305F30 */
typedef struct { unsigned char d[48]; } Info5f30;
extern void *memset(void *, int, unsigned int);
#if 0 /* merge_units */
extern int ReferThreadStatus(int id, Info5f30 *info);
#endif /* merge_units */
#define ReferThreadStatus(a0, a1) (ReferThreadStatus((a0), (ScfThStat *)(a1))) /* merge_units */


int func_00305F30(int id, Info5f30 *out, unsigned int size, int *len)
{
    Info5f30 info;
    if (len == 0) return 2;
    *len = 0;
    if (out == 0) return 2;
    if (size < sizeof(Info5f30)) return 2;
    memset(&info, 0, sizeof(info));
    if (ReferThreadStatus(id, &info) != -1) {
        *out = info;
        *len = sizeof(Info5f30);
    }
    return 0;
}
#undef ReferThreadStatus /* merge_units */
/* merge_units: end func_00305F30 */

/* merge_units: begin func_00306018 */
#include "types.h"

extern int func_00306030(int);

int func_00306018(int a0) {
    return func_00306030(a0);
}
/* merge_units: end func_00306018 */
