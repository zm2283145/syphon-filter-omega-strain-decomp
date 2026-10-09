/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int ListIter_NotEqual(ListIter*, ListIter*);
extern ListIter* ListIter_Next(ListIter*);
extern ListIter* func_001F3430(ListIter*);
extern void func_001F3470(void);

int func_001F33F0(ListIter* a, ListIter* b) {
    return ListIter_NotEqual(a, b);
}

ListIter* func_001F3400(ListIter* it) {
    func_001F3430(it);
    return it;
}

ListIter* func_001F3430(ListIter* it) {
    ListIter_Next(it);
    return it;
}

void func_001F3460(void) {
    func_001F3470();
}
