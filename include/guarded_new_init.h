#ifndef GUARDED_NEW_INIT_H
#define GUARDED_NEW_INIT_H

/*
 * "new T" factories (see guarded_new.h) whose inline constructor runs
 * baseCtor(p), stores the class vtable and then initialises members:
 *   DEFINE_GUARDED_NEW_VT_INIT(name, size, fileSym, baseCtor, vtableSym, init)
 * init is a statement list using GN_B / GN_W / GN_F(off, v) and GN_VT(sym)
 * (a later inlined constructor level) on p.
 * C++ only (#pragma cplusplus on before including).
 */
#include "guarded_new.h"

#define GN_B(off, v) (*(unsigned char*)((char*)p + (off)) = (v))
#define GN_W(off, v) (*(int*)((char*)p + (off)) = (v))
#define GN_F(off, v) (*(float*)((char*)p + (off)) = (v))
#define GN_VT(sym) (p->vtable = (sym))

#define DEFINE_GUARDED_NEW_VT_INIT(name, size, fileSym, baseCtor, vtableSym,  \
                                   init)                                      \
    extern "C" {                                                              \
    extern char fileSym[];                                                    \
    extern char vtableSym[];                                                  \
    void baseCtor(void* self);                                                \
    }                                                                         \
    extern "C" GuardedNewObject* name(void)                                   \
    {                                                                         \
        GuardedNewObject* p;                                                  \
        {                                                                     \
            AllocGuard guard;                                                 \
            p = (GuardedNewObject*)cMemMan_Allocate(0, (size), fileSym, 0x2A);       \
        }                                                                     \
        if (p) {                                                              \
            baseCtor(p);                                                      \
            p->vtable = vtableSym;                                            \
            init;                                                             \
        }                                                                     \
        return p;                                                             \
    }

#endif /* GUARDED_NEW_INIT_H */