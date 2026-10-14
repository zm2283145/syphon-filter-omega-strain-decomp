/*
 * main/gobj: range (2 files, 003CC8E0-003CC950)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_003CC8E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on

struct VC003CC8E0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(...); virtual int v25(...); };
extern "C" {

}
extern "C" int TeamTable_AreEnemies(char * arg0, char * arg1) {
    int var_v0;
    void **temp_a0;
    void **temp_s0;

    temp_s0 = (void **)(F_(arg0, 0x58, int));
    var_v0 = -1;
    if (temp_s0 != NULL) {
        temp_a0 = (void **)(F_(arg1, 0x58, int));
        if (temp_a0 != NULL) {
            var_v0 = ((VC003CC8E0 *)(temp_a0))->v24();
        }
        var_v0 = ((VC003CC8E0 *)(temp_s0))->v25(var_v0) & 0xFF;
    }
    return var_v0 != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC8E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC8E0 */

/* merge_units: begin func_003CC950 */
#pragma push /* merge_units */
#pragma cplusplus on
class C003CC950 { public: VPAD16(p0) VPAD8(p1)  virtual int f(); };
struct O003CC950 { char pad[0x58]; C003CC950* m; };
extern "C" int Controller_NotifySeen(O003CC950* self)
{
    C003CC950* m = self->m;
    int r = -0x1;
    if (m)
        r = m->f();
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CC950(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CC950 */
