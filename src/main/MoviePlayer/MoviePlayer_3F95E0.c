/*
 * main/MoviePlayer: 3 files, 003F95E0-003F96B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F95E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

Word* func_003F95E0(Word* self, int value) {
    self->value = value;
    return self;
}

void* func_003F95F0(char* self) {
    return self + 4;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F95E0 */

/* merge_units: begin func_003F9600 */
#pragma push /* merge_units */
typedef struct N9600 { int m0; struct N9600* next; char name[4]; } N9600;
extern N9600* func_003F9520(void* list);
#if 0 /* merge_units */
extern void* func_003F95F0(void* self);
#endif /* merge_units */
#define func_003F95F0(a0) (func_003F95F0((char *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void func_003F95E0(N9600** out, void* v);
#endif /* merge_units */
#define func_003F95E0(a0, a1) ((void)func_003F95E0((Word *)(a0), (int)(a1))) /* merge_units */

extern int String_CompareNoCase(const char* a, const char* b);
char* func_003F9600(char* self, const char* name)
{
    N9600* e;
    N9600* n;
    for (n = func_003F9520(self + 4)->next; func_003F95E0(&e, func_003F95F0(self)), n != e; n = n->next) {
        if (!String_CompareNoCase(n->name, name))
            return n->name;
    }
    return 0;
}
#undef func_003F95F0 /* merge_units */
#undef func_003F95E0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9600 */

/* merge_units: begin func_003F96B0 */
#pragma push /* merge_units */
extern L4Archive* Archive_Open(int, int, int, int);

/* Opens an archive and sets the byte at +0x168 on the returned handle. */
L4Archive* func_003F96B0(int a0, int a1, int a2) {
    L4Archive* ar = Archive_Open(a0, a1, a2, 0);

    ar->unk168 = 1;
    return ar;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F96B0 */
