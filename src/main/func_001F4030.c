/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int ListIter_NotEqual(ListIter*, ListIter*);
extern ListIter* ListIter_Next(ListIter*);
extern ListIter* func_001F4070(ListIter*);
extern void func_001F40B0(void);

int func_001F4030(ListIter* a, ListIter* b) {
    return ListIter_NotEqual(a, b);
}

ListIter* func_001F4040(ListIter* it) {
    func_001F4070(it);
    return it;
}

ListIter* func_001F4070(ListIter* it) {
    ListIter_Next(it);
    return it;
}

void func_001F40A0(void) {
    func_001F40B0();
}
