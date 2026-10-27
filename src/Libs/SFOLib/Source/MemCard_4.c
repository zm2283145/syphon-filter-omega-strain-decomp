/*
 * Libs/SFOLib/Source/MemCard: 7 files, 0040DB10-0040E320
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040DB10 */
#pragma push /* merge_units */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"

typedef struct { char pad0[0x540]; int mode; char pad1[0x59E - 0x544]; unsigned char ok; unsigned char pad2; unsigned char done; } PDB10;
typedef struct { PDB10* p; unsigned char busy; char pad[3]; void (*cb)(void); unsigned char state; } CDB10;
extern int MemCard_MemCardMain(PDB10* p);
/* Runs the session state machine until it settles; returns its result flag. */
int cMemCard_Format(CDB10* c) {
    PDB10* p = c->p;
    p->mode = 1;
    p->done = 0;
    c->state = 5;
    do {
        c->busy = MemCard_MemCardMain(c->p) != 0;
        if (!c->busy)
            c->state = 0;
        if (c->cb)
            c->cb();
    } while (!((c->busy != 0) ^ 1) || !c->p->done);
    return c->p->ok != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040DB10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040DB10 */

/* merge_units: begin func_0040DBB0 */
#pragma push /* merge_units */
typedef struct { char pad0[0x14]; int value; char pad1[0x4]; char item[0x1C]; } EDBB0;
typedef struct { EDBB0 e[(0x560) / 0x38]; char pad[0x560 - (0x560 / 0x38) * 0x38]; int count; } PDBB0;
typedef struct { PDBB0* p; } ODBB0;
extern int WildcardCompare(void* key, void* item);
static inline int dbb0find(PDBB0* p, void* key) {
    int i;
    for (i = 0; i < p->count; i++) {
        if (!((WildcardCompare(key, p->e[i].item) != 0) ^ 1))
            return i;
    }
    return -1;
}
/* Returns the value of the entry whose item matches key, or 0. */
int cMemCard_GetFileSize(ODBB0* o, void* key) {
    int i = dbb0find(o->p, key);
    if (i < 0)
        return 0;
    return o->p->e[i].value;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040DBB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0040DBB0 */

/* merge_units: begin func_0040DC80 */
#pragma push /* merge_units */
typedef struct { char pad0[0x1C]; char item[0x1C]; } EDC80;
typedef struct { EDC80 e[0x540 / 0x38]; int mode; char pad1[0x560 - 0x544]; int count; int sel; char pad2[0x59C - 0x568]; unsigned char failed; unsigned char pad3; unsigned char ok; unsigned char pad4; unsigned char done; } PDC80;
typedef struct { PDC80* p; unsigned char busy; char pad[3]; void (*cb)(void); unsigned char state; } CDC80;
#if 0 /* merge_units */
extern int MemCard_MemCardMain(PDC80* p);
#endif /* merge_units */
#define MemCard_MemCardMain(a0) (MemCard_MemCardMain((PDB10 *)(a0))) /* merge_units */


static inline int dc80find(PDC80* p, void* key) {
    int i;
    for (i = 0; i < p->count; i++) {
        if (!((WildcardCompare(key, p->e[i].item) != 0) ^ 1))
            return i;
    }
    return -1;
}
/* Selects the entry matching key and runs the state machine until it settles. */
int cMemCard_DeleteFile(CDC80* c, void* key) {
    PDC80* p;
    int i = dc80find(c->p, key);
    if (i < 0)
        return 0;
    c->p->sel = i;
    p = c->p;
    p->mode = 6;
    p->done = 0;
    do {
        c->busy = MemCard_MemCardMain(c->p) != 0;
        if (!c->busy)
            c->state = 0;
        if (c->cb)
            c->cb();
    } while (!((c->busy != 0) ^ 1) || !c->p->done);
    return c->p->failed == 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040DC80(void) {}
#undef MemCard_MemCardMain /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040DC80 */

/* merge_units: begin func_0040DDC0 */
#pragma push /* merge_units */
typedef struct { char pad0[0x1C]; char item[0x1C]; } EDDC0;
typedef struct { EDDC0 e[0x540 / 0x38]; int mode; char pad1[0x560 - 0x544]; int count; int sel; char pad2[0x57C - 0x568]; char name[0x59C - 0x57C]; unsigned char failed; unsigned char pad3; unsigned char ok; unsigned char pad4; unsigned char done; } PDDC0;
typedef struct { PDDC0* p; unsigned char busy; char pad[3]; void (*cb)(void); unsigned char state; } CDDC0;
#if 0 /* merge_units */
extern int MemCard_MemCardMain(PDDC0* p);
#endif /* merge_units */
#define MemCard_MemCardMain(a0) (MemCard_MemCardMain((PDB10 *)(a0))) /* merge_units */


static inline int dDC0find(PDDC0* p, void* key) {
    int i;
    for (i = 0; i < p->count; i++) {
        if (!((WildcardCompare(key, p->e[i].item) != 0) ^ 1))
            return i;
    }
    return -1;
}
/* Selects the entry matching key, stores its name and runs the state machine until it settles. */
int cMemCard_RenameFile(CDDC0* c, void* key, void* name) {
    PDDC0* p = c->p;
    int i = dDC0find(p, key);
    if (i >= 0)
        Libc_Strcpy(p->name, name);
    p->sel = i;
    p->mode = 9;
    p->done = 0;
    do {
        c->busy = MemCard_MemCardMain(c->p) != 0;
        if (!c->busy)
            c->state = 0;
        if (c->cb)
            c->cb();
    } while (!((c->busy != 0) ^ 1) || !c->p->done);
    return c->p->failed == 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0040DDC0(void) {}
#undef MemCard_MemCardMain /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040DDC0 */

/* merge_units: begin func_0040DF00 */
#pragma push /* merge_units */
typedef struct { char pad0[0x14]; int size; char pad18[4]; char item[0x1C]; } EDF00;
typedef struct { EDF00 e[0x540 / 0x38]; int mode; char pad1[0x558 - 0x544]; void* buf; char pad55C[4]; int count; int sel; char pad2[0x59C - 0x568]; unsigned char failed; unsigned char pad3; unsigned char ok; unsigned char pad4; unsigned char done; } PDF00;
typedef struct { PDF00* p; unsigned char busy; char pad[3]; void (*cb)(void); unsigned char state; } CDF00;
#if 0 /* merge_units */
extern int MemCard_MemCardMain(PDF00* p);
#endif /* merge_units */
#define MemCard_MemCardMain(a0) (MemCard_MemCardMain((PDB10 *)(a0))) /* merge_units */


static inline int df00find(PDF00* p, void* key) {
    int i;
    for (i = 0; i < p->count; i++) {
        if (!((WildcardCompare(key, p->e[i].item) != 0) ^ 1))
            return i;
    }
    return -1;
}
/* Selects the entry matching key and reads it into buf when bufSize can hold it. */
int cMemCard_LoadFile(CDF00* c, void* key, void* buf, int bufSize) {
    PDF00* p;
    int i = df00find(c->p, key);
    if (i < 0)
        return 0;
    p = c->p;
    if (bufSize < p->e[i].size)
        return 0;
    p->sel = i;
    c->p->buf = buf;
    p = c->p;
    p->mode = 5;
    p->done = 0;
    c->state = 3;
    do {
        c->busy = MemCard_MemCardMain(c->p) != 0;
        if (!c->busy)
            c->state = 0;
        if (c->cb)
            c->cb();
    } while (!((c->busy != 0) ^ 1) || !c->p->done);
    return c->p->failed == 0;
}
#undef MemCard_MemCardMain /* merge_units */
static inline void merge_flush_func_0040DF00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040DF00 */

/* merge_units: begin func_0040E090 */
#pragma push /* merge_units */
typedef struct { char pad0[0x14]; int size; short type; char pad1A[2]; char item[0x1C]; } E090;
typedef struct { E090 e[0x540 / 0x38]; int mode; char pad1[0x558 - 0x544]; void* buf; char pad55C[4]; int count; int sel; char pad2[0x59C - 0x568]; unsigned char failed; unsigned char pad3; unsigned char ready; unsigned char present; unsigned char done; } P090;
typedef struct { P090* p; unsigned char busy; char pad[3]; void (*cb)(void); unsigned char state; } C090;
#if 0 /* merge_units */
extern int MemCard_MemCardMain(P090* p);
#endif /* merge_units */
#define MemCard_MemCardMain(a0) (MemCard_MemCardMain((PDB10 *)(a0))) /* merge_units */


static inline int e090find(P090* p, void* key) {
    int i;
    for (i = 0; i < p->count; i++) {
        if (!((WildcardCompare(key, p->e[i].item) != 0) ^ 1))
            return i;
    }
    return -1;
}
static inline int e090add(P090* p, void* key, int size) {
    if (p->count < 18) {
        if (e090find(p, key) < 0) {
            int k = p->count;
            Libc_Strcpy(p->e[k].item, key);
            p->e[k].size = size;
            p->e[k].type = 3;
            return k;
        }
    }
    return -1;
}
/* Writes buf as the entry matching key (creating it when absent); optionally waits for the state machine. */
int cMemCard_SaveFile(C090* c, void* key, void* buf, int size, unsigned char wait) {
    P090* p = c->p;
    int i;
    int mode;
    int state;
    if (!p->ready || !p->present)
        return 0;
    i = e090find(p, key);
    mode = 3;
    state = 1;
    if (i < 0) {
        i = e090add(c->p, key, size);
    } else {
        c->p->e[i].size = size;
        mode = 4;
        state = 2;
    }
    if (i >= 0) {
    c->p->sel = i;
    c->p->buf = buf;
    p = c->p;
    p->mode = (unsigned char)mode;
    p->done = 0;
    c->state = state;
    if (wait) {
        do {
            c->busy = MemCard_MemCardMain(c->p) != 0;
            if (!c->busy)
                c->state = 0;
            if (c->cb)
                c->cb();
        } while (!((c->busy != 0) ^ 1) || !c->p->done);
    }
    return c->p->failed == 0;
    }
    return 0;
}
#undef MemCard_MemCardMain /* merge_units */
static inline void merge_flush_func_0040E090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040E090 */

/* merge_units: begin func_0040E320 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * MemCard.cc
 */

#include "MemCard_types.h"

#if 0 /* merge_units */
extern int MemCard_MemCardMain(int a0);
#endif /* merge_units */
#define MemCard_MemCardMain(a0) (MemCard_MemCardMain((PDB10 *)(a0))) /* merge_units */


/* Refresh the "present" flag from MemCard_MemCardMain; clear unk0C when absent. */
void cMemCard_NextFrame(MemCardState* state) {
    state->present = MemCard_MemCardMain(state->unk00) != 0;
    if ((state->present != 0) ^ 1) { /* C++ "!bool" codegen */
        state->unk0C = 0;
    }
}
#undef MemCard_MemCardMain /* merge_units */
static inline void merge_flush_func_0040E320(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040E320 */
