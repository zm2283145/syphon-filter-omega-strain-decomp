#ifndef VU_BYVAL_H
#define VU_BYVAL_H
/* By-value 16-byte parameter (passed by address): the callee copies it into a
 * stack local through its own pointer (lq free, sq unfolded), then works on the
 * local through p. Use with peephole/propagation/common_subs off (vc1).
 *   VU_BYVAL(V4, vp, p)  -> declares V4 v_; V4* p; and copies *vp into v_. */
#include "vc_copy.h"
#define VU_BYVAL(T, vp, p) T v_; T* p; T* d_; d_ = &v_; VCopyF(d_, (vp)); p = &v_;
#endif