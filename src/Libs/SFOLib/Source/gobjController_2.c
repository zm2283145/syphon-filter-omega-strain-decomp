/*
 * Libs/SFOLib/Source/gobjController: 3 files, 003EA4A0-003EA590
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EA4A0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
class B4Obj4 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual int IsForced();
    char pad[0x1C];
    float f20;
    float f24;
};
extern "C" int Libc_Rand(void);
extern "C" { float D_00493988 = 0.9f; }
extern "C" bool cGobjController_ShouldHitTarget(B4Obj4* p) {
    float chance;
    if (!p->IsForced() && p->f20 < D_00493988) return 0;
    chance = p->f20 * p->f24;
    return (float)Libc_Rand() / 2147483648.0f < chance;
}
static inline void merge_flush_func_003EA4A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EA4A0 */

/* merge_units: begin func_003EA550 */
#pragma push /* merge_units */
typedef struct Target {
    char pad[0xC];
    int serial;
} Target;

/* Weak reference: object pointer plus the serial it had when stored. */
typedef struct WeakRef {
    char pad[0x28];
    Target* obj;
    int serial;
} WeakRef;

/* Returns the referenced object, or 0 if it was replaced (serial mismatch). */
Target* cGobjController_GetTarget(WeakRef* ref) {
    Target* obj = ref->obj;
    unsigned char valid = 1;
    if (!((obj != 0) ^ 1)) {
        if (obj->serial != ref->serial) {
            valid = 0;
        }
    }
    return valid ? obj : 0;
}
static inline void merge_flush_func_003EA550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EA550 */

/* merge_units: begin func_003EA590 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#pragma exceptions off

struct VObj {
    virtual void v00(); virtual void v01();
    virtual void Method10(); /* +0x10 */
};

struct Owner { char pad[0x30]; VObj* child; };

/* Forwards to virtual method +0x10 of the object held at +0x30. */
extern "C" void cGobjController_ScriptGetObjectId(Owner* o)
{
    o->child->Method10();
}
static inline void merge_flush_func_003EA590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EA590 */
