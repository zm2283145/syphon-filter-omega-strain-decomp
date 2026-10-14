/*
 * main/GuiEquipmentSetup: range (2 files, 002A3980-002A3A10)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "message_two_member_dtor.h"
#pragma pop

/* merge_units: begin func_002A3980 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(func_002A3980, D_004DAE10)
#pragma pop /* merge_units */
/* merge_units: end func_002A3980 */

/* merge_units: begin func_002A3A10 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Slot_3A10 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual unsigned char state(); };
typedef struct { char pad[0xC0]; int xC0; } O_3A10;
extern "C" {
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern int D_005721A8;
extern char D_0055C770[];
void func_002EBEC8(int* out, int a);
int func_002A3BA0(void*);
int func_0042B4E0(void);
Slot_3A10* PlayerSlots_Get(int);
}

static inline void Lower_3A10(O_3A10* o, int v) { if (v < o->xC0) o->xC0 = v; }
static inline int Ok_3A10(void) { return D_005721C8 ? D_005721C0 : 1; }
static inline int HostCount_3A10(void)
{
    if (D_005721C8) {
        int n;
        func_002EBEC8(&n, D_005721A8);
        return n;
    }
    return 1;
}

extern "C" void func_002A3A10(O_3A10* o) {
    int i;
    o->xC0 = 2;
    if (!D_005721C8) return;
    if (Ok_3A10()) {
        if (HostCount_3A10() > func_002A3BA0(D_0055C770)) o->xC0 = 0;
        if (func_0042B4E0()) o->xC0 = 0;
        if (HostCount_3A10() < 2) o->xC0 = 0;
    }
    for (i = 0; i < 4; i++) {
        Slot_3A10* p = PlayerSlots_Get(i);
        if (p) {
            unsigned char r = p->state();
            if (r == 0) o->xC0 = 0;
            else if (r == 1) Lower_3A10(o, 1);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A3A10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A3A10 */
