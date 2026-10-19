/*
 * main/GuiAgentInfo: range (5 files, 00363810-00363990)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00363810 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
inline void* operator new(unsigned int, void* p) { return p; }
struct Key_3810b { float v; float s; Key_3810b() {} };
struct Crv_3810b { Key_3810b k[2]; float dur; float inv; };
/* constant curve: both keys = (*a, *b * dur), store duration and its inverse */
#pragma push
#pragma opt_unroll_loops off
extern "C" Crv_3810b* Curve_InitConstant_363810(Crv_3810b* c, float* a, float* b, float dur)
{
    float va = *a; float vs = *b * dur;
    { Key_3810b* e = c->k; do { new (e) Key_3810b; } while (++e != c->k + 2); }
    c->k[0].v = va;
    c->k[0].s = vs;
    c->k[1].v = va;
    c->k[1].s = vs;
    c->dur = dur;
    c->inv = (dur != 0.0f) ? 1.0f / dur : 0.0f;
    return c;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_00363810 */

/* merge_units: begin func_00363890 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_00363890)
#pragma pop /* merge_units */
/* merge_units: end func_00363890 */

/* merge_units: begin func_003638E0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_003638E0)
#pragma pop /* merge_units */
/* merge_units: end func_003638E0 */

/* merge_units: begin func_00363930 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00363930, func_001AF8E0)
#pragma pop /* merge_units */
/* merge_units: end func_00363930 */

/* merge_units: begin func_00363990 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_00363990)
#pragma pop /* merge_units */
/* merge_units: end func_00363990 */
