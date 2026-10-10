#include "types.h"
typedef void (*FuncListFn)(void);
void FunctionList_CallEach(FuncListFn* begin, FuncListFn* end) {
    FuncListFn* p;
    for (p = begin; p < end; p++) {
        (*p)();
    }
}