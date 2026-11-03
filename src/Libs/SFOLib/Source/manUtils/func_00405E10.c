/*
 * Libs/SFOLib/Source/manUtils: 3 files, 00405E10-00406040
 * Original source run retained after quarantining undefined C at 00405A60.
 */
#include "types.h"
#include "SFOLobby_helpers.h"
int cMemMan_Deallocate();
typedef struct { int pad; int count; char** names; } List5E10;
typedef struct { __int128 name; char pad[0x10]; } Ent5F10;
typedef struct { char pad[0x50]; Ent5F10 ent[1]; } Obj5F10;
typedef struct { __int128 name; char pad[0x10]; } Ent6040;
typedef struct { char pad[0x50]; Ent6040 ent[1]; } Obj6040;

/* merge_units: begin func_00405E10 */
#pragma push /* merge_units */
typedef union { __int128 q; char s[16]; } Key5E10;

extern __int128 D_005716E0;
extern char* strchr(const char*, int);
extern void strCpyPad(char* dst, int n, char* src);
static inline int k5e10eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline void k5e10clear(__int128* keys, int n, __int128 key) {
    int j;
    __int128* p;
    j = 0;
    if (j < n) {
        p = keys;
        do {
            if (k5e10eq(key, *p)) {
                keys[j] = D_005716E0;
                return;
            }
            j++;
            p++;
        } while (j < n);
    }
}
#pragma push
#pragma opt_strength_reduction off
void SKL_HideLockedTex(void* self, List5E10* list, __int128* keys, int n) {
    int i;
    int total = list->count;
    for (i = 0; i < total; i++) {
        if (strchr(list->names[i], '.') == 0) {
            Key5E10 key;
            strCpyPad(key.s, 15, list->names[i]);
            k5e10clear(keys, n, key.q);
        }
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00405E10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00405E10 */

/* merge_units: begin func_00405F10 */
#pragma push /* merge_units */
static inline int k5f10eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline int k5f10find(__int128* keys, int n, __int128 key) {
    int j;
    __int128* p;
    j = 0;
    if (j < n) {
        p = keys;
        do {
            if (k5f10eq(key, *p))
                return j;
            j++;
            p++;
        } while (j < n);
    }
    return -1;
}
void SKL_UpgradeBigPatch(Obj5F10* o, int idx, __int128* keys, int n) {
    __int128 key;
    char* s;
    char* lo;
    char* hi;
    int k;
    key = o->ent[idx].name;
    if (k5f10find(keys, n, key) != -1)
        return;
    s = (char*)&key;
    lo = s + 12;
    hi = s + 11;
    for (k = 0; k < 32; k++) {
        if (*lo == '9') {
            (*hi)++;
            *lo = '0';
        } else {
            (*lo)++;
        }
        if (k5f10find(keys, n, key) != -1) {
            o->ent[idx].name = key;
            return;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00405F10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00405F10 */

/* merge_units: begin func_00406040 */
#pragma push /* merge_units */
static inline int k6040eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline int k6040find(__int128* keys, int n, __int128 key) {
    int j;
    __int128* p;
    j = 0;
    if (j < n) {
        p = keys;
        do {
            if (k6040eq(key, *p))
                return j;
            j++;
            p++;
        } while (j < n);
    }
    return -1;
}
void SKL_UpgradeSmallPatch(Obj6040* o, int idx, __int128* keys, int n) {
    __int128 key;
    char* s;
    char* lo;
    char* hi;
    int k;
    key = o->ent[idx].name;
    if (k6040find(keys, n, key) != -1)
        return;
    s = (char*)&key;
    lo = s + 13;
    hi = s + 12;
    for (k = 0; k < 32; k++) {
        if (*lo == '-') {
            if (*hi == '9') {
                *hi = '1';
                *lo = '0';
            } else {
                (*hi)++;
            }
        } else if (*lo == '9') {
            (*hi)++;
            *lo = '0';
        } else {
            (*lo)++;
        }
        if (k6040find(keys, n, key) != -1) {
            o->ent[idx].name = key;
            return;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00406040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00406040 */
