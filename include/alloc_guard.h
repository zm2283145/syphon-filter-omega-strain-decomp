#ifndef ALLOC_GUARD_H
#define ALLOC_GUARD_H

/*
 * AllocGuard: the scoped allocator lock used around Mem_Alloc/Mem_Free.
 *
 * The original code wraps allocator calls in a small C++ object whose
 * constructor takes the allocator lock and whose destructor releases it.
 * Because the destructor is non-trivial, every function that uses it gets
 * a 16-byte stack slot for the object, which C cannot reproduce.
 *
 * The destructor is inlined into each user. CodeWarrior also emits an
 * out-of-line copy per translation unit; the original link merged them into
 * the single copy at 0x0012F530 (func_0012F530). Here each per-unit copy is
 * weak and placed in ".dtors_drop", which the link script discards, so the
 * users stay byte-identical and no extra code reaches the image. (The unit
 * that owns the real copy at 0x0012F530 should define it without these
 * attributes once it is matched.)
 *
 * Include from C++ sources only (#pragma cplusplus on before including).
 */
#ifdef __cplusplus

extern "C" {
extern unsigned char D_00533880; /* allocator locking enabled */
extern int D_00533888;           /* allocator lock depth */
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
}

#pragma define_section ALLOC_GUARD_DTOR ".dtors_drop" far_absolute RX

struct AllocGuard {
    AllocGuard() {
        if (D_00533880) Alloc_Lock(9);
        D_00533888++;
    }
    /* order matters: weak first, then the section */
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~AllocGuard() {
        if (D_00533880) Alloc_Unlock(9);
        D_00533888--;
    }
};

#endif /* __cplusplus */
#endif /* ALLOC_GUARD_H */
