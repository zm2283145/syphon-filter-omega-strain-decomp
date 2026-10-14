/*
 * lib/medius: 3 files, 003028E8-003029B8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003028E8 */
typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
extern void func_002F94D0(int a);
extern void func_002F95F8(int a);
extern void func_00306F98(int h);
extern int func_002FB3C0(void *pp);
int func_003028E8(UpnpObj *o)
{
    UpnpObj *h = 0;
    int ret = 2;
    if (o == 0) return ret;
    h = o;
    func_002F94D0(-1);
    func_002F95F8(-1);
    func_00306F98(h->h180);
    if (h->f190) func_002FB3C0(&h->f190);
    if (h->ent) func_002FB3C0(&h->ent);
    func_002FB3C0(&h);
    return 0;
}
/* merge_units: end func_003028E8 */

/* merge_units: begin func_00302968 */
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; char pad2[0x1C]; int f1B0; } UpnpObj_00302968;

extern int func_00307328(int h, int a, int b);
int func_00302968(UpnpObj_00302968 *o, int a, int x)
{
    int ret = 2;
    if (o == 0) return ret;
    if (x == 0) return ret;
    if (func_00307328(o->h180, a, x) != 0) return 5;
    o->f1B0 = x;
    return 0;
}
/* merge_units: end func_00302968 */

/* merge_units: begin func_003029B8 */
int func_003029B8(UpnpObj *o, int idx, int *out)
{
    UpnpEnt *e;
    int ret = 2;
    if (out == 0) return ret;
    *out = -1;
    if (o == 0) return ret;
    if (idx < 0 || idx >= o->count) return 8;
    if (o->ent[idx].f4 != -1) *out = 0;
    else if (o->ent[idx].f8 != -1) *out = 1;
    return 0;
}
/* merge_units: end func_003029B8 */
