/*
 * Libs/SFOLib/Source/gobjController: 3 files, 003EA340-003EA430
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EA340 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}
struct P3EA340 { void* allocation; };
extern "C" P3EA340* cMemCard_dtor(P3EA340* self, short deleteFlag)
{
    if (self) {
        void* p = self->allocation;
        if (p) {
            AllocGuard guard;
            cMemMan_Deallocate(0, p, "MemCard.hh", 0x9B);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_003EA340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EA340 */

/* merge_units: begin func_003EA420 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int cGobjController_Enemy_cGOBJP(void) {
    return 0;
}
static inline void merge_flush_func_003EA420(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EA420 */

/* merge_units: begin func_003EA430 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma bool off
#define V8A430(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); \
    virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
class OA430 {
public:
    V8A430(a) V8A430(b) V8A430(c) V8A430(d) V8A430(e) V8A430(f) V8A430(g) V8A430(h)
    virtual unsigned char getState();
};
static inline unsigned char busyA430(unsigned char s)
{
    unsigned char r = 1;
    if (!(s == 2 || s == 3))
        r = 0;
    return r;
}
struct TA430 { char pad[0x30]; OA430* obj; };
extern "C" unsigned char cGobjController_WantsToBeActive(TA430* self)
{
    OA430* o = self->obj;
    unsigned char r;
    if (!o) r = 1;
    else r = !busyA430(o->getState());
    return r;
}
static inline void merge_flush_func_003EA430(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EA430 */
