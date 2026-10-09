/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiMLTextWidget.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

extern Iter* List_InsertBefore(Iter* result, void* list, Iter* pos, int value);

/* push_back on a list whose sentinel node is at +4. */
Iter* func_0043E0B0(void* list, int value) {
    Iter end;
    Iter result;

    end.p = (int*)((char*)list + 4);
    return List_InsertBefore(&result, list, &end, value);
}
