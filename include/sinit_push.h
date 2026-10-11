#ifndef SINIT_PUSH_H
#define SINIT_PUSH_H

/*
 * Static-initialiser bodies at the end of .text: store addresses into
 * global objects and register an object with pushFn (FreeList_Push).
 * Plain C.
 *   DEFINE_SINIT_STORE1(name, slot, val)            slot = val
 *   DEFINE_SINIT_PUSH1(name, slotA, valA, slotB, valB, pushFn)
 *       slotA = valA; slotB = valB; pushFn(&slotB)  (tail call)
 *   DEFINE_SINIT_PUSH2 / _PUSH3: two / three such groups in a row.
 */
#define SINIT_DECL2(slot, val) \
    extern char val[];         \
    extern void* slot;

#define DEFINE_SINIT_STORE1(name, slot, val) \
    SINIT_DECL2(slot, val)                   \
    void name(void) { slot = val; }

#define SINIT_PUSH_DECL(slotA, valA, slotB, valB, pushFn) \
    SINIT_DECL2(slotA, valA)                              \
    SINIT_DECL2(slotB, valB)                              \
    extern void pushFn(void* node);

#define SINIT_PUSH_BODY(slotA, valA, slotB, valB, pushFn) \
    slotA = valA;                                         \
    slotB = valB;                                         \
    pushFn(&slotB);

#define DEFINE_SINIT_PUSH1(name, slotA, valA, slotB, valB, pushFn) \
    SINIT_PUSH_DECL(slotA, valA, slotB, valB, pushFn)              \
    void name(void) { SINIT_PUSH_BODY(slotA, valA, slotB, valB, pushFn) }

#define DEFINE_SINIT_PUSH2(name, sA1, vA1, sB1, vB1, sA2, vA2, sB2, vB2, pushFn) \
    SINIT_PUSH_DECL(sA1, vA1, sB1, vB1, pushFn)                                  \
    SINIT_PUSH_DECL(sA2, vA2, sB2, vB2, pushFn)                                  \
    void name(void)                                                              \
    {                                                                            \
        SINIT_PUSH_BODY(sA1, vA1, sB1, vB1, pushFn)                              \
        SINIT_PUSH_BODY(sA2, vA2, sB2, vB2, pushFn)                              \
    }

#define DEFINE_SINIT_PUSH3(name, sA1, vA1, sB1, vB1, sA2, vA2, sB2, vB2, sA3, vA3, sB3, vB3, pushFn) \
    SINIT_PUSH_DECL(sA1, vA1, sB1, vB1, pushFn)                                  \
    SINIT_PUSH_DECL(sA2, vA2, sB2, vB2, pushFn)                                  \
    SINIT_PUSH_DECL(sA3, vA3, sB3, vB3, pushFn)                                  \
    void name(void)                                                              \
    {                                                                            \
        SINIT_PUSH_BODY(sA1, vA1, sB1, vB1, pushFn)                              \
        SINIT_PUSH_BODY(sA2, vA2, sB2, vB2, pushFn)                              \
        SINIT_PUSH_BODY(sA3, vA3, sB3, vB3, pushFn)                              \
    }

#endif /* SINIT_PUSH_H */