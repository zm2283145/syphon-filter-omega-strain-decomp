/*
 * SFOGame/Source/path: 3 files, 001644B0-00164670
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001644B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_propagation off
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern "C" {
#if 0 /* merge_units */
char *cMemMan_Allocate(int, int, char *, int);
#endif /* merge_units */
void* cMemMan_Allocate(int pool, int size, char* file, int line); /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) ((char *)cMemMan_Allocate((a0), (a1), (a2), (a3))) /* merge_units */

int std_list_deleter_voidPtr_erase_listdeleter_listdeleter(int *, char *, int *, char **);
int std_list_cPathSystemRequestPtr_push_back(char *, char **, int *);
extern char D_0049C1B8;
extern int D_004EA798;
extern int g_NpcRegionTable;
extern int D_004ED9C4;
extern int D_004ED9C8;
extern int D_004ED9CC;
extern signed char D_004ED9D0;
}
static inline void clr16(char *arg0) { int r; int f; char *l; l = arg0 + 0x30; f = F_(arg0, 0x34, int); std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&r, arg0 + 0x2C, &f, &l); }
struct Id{volatile int value;Id(int v):value(v){}};
static inline int* Identity(int*p){return p;}
static inline int* set16(char *t, int *pv) { F_(t, 0x4, int) = *pv; return pv;}
static inline void push16(char *arg0, char **pp, char *t) { std_list_cPathSystemRequestPtr_push_back(arg0 + 0x2C, pp, set16(t, Identity((int*)&Id(-1)))); }
#pragma push
#pragma opt_propagation off
extern "C" void cPathSystem_Init(char *arg0) {
    char *sp6C;
    int var_s2;
    char *temp_v1;
    char *temp_s1;
    char *var_s0;

    clr16(arg0);
    {
        AllocGuard g;
        temp_s1 = cMemMan_Allocate(0, 0x6100, &D_0049C1B8, 0x28);
    }
    var_s2 = 0;
    var_s0 = arg0;
    F_(arg0, 0x38, int) = (int)(temp_s1);
    sp6C = (char *)(F_(arg0, 0x38, int));
    do {
        F_(var_s0, 0x3C, int) = (int)(sp6C);
        temp_v1 = (char *)(F_(var_s0, 0x3C, int));
        F_(temp_v1, 0x0, int) = 0;
        push16(arg0, &sp6C, temp_v1);
        var_s2 += 1;
        var_s0 += 4;
        sp6C += 0x610;
    } while (var_s2 < 0x10);
    D_004ED9D0 = 0;
    g_NpcRegionTable = -1;
    D_004ED9C4 = -1;
    D_004ED9C8 = -1;
    D_004ED9CC = -1;
    D_004EA798 = 0;
}
#pragma pop
#undef cMemMan_Allocate /* merge_units */
static inline void merge_flush_func_001644B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001644B0 */

/* merge_units: begin func_00164620 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * PathReceiver constructor.
 */

#include "path_types.h"

extern char D_004D96C0[]; /* PathReceiver vtable */
extern char g_NpcRouteMgr[]; /* receiver registration data */
extern void* cSystem_ctor(void* self, void* info);
extern PathList* std_list_deleter_voidPtr_ctor_void(PathList* list);

PathReceiver* cPathSystem_ctor(PathReceiver* self) {
    cSystem_ctor(self, g_NpcRouteMgr);
    self->vtable = D_004D96C0;
    std_list_deleter_voidPtr_ctor_void(&self->listA);
    std_list_deleter_voidPtr_ctor_void(&self->listB);
    return self;
}
static inline void merge_flush_func_00164620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00164620 */

/* merge_units: begin func_00164670 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004D9760[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cPathMessage_Clone, 0x30, "path.hh", 0x34)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004D9760;
    F(char, 0x24) = S(char, 0x24);
    F(int, 0x28) = S(int, 0x28);
    F(int, 0x2C) = S(int, 0x2C);
MSG_CLONE_END
static inline void merge_flush_func_00164670(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00164670 */
