/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiMLTextWidget.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "guiMLTextWidget.h"

extern Iter* List_InsertBefore(Iter* result, void* list, Iter* pos, int value);

/* push_back on the line list (sentinel node at +4). */
Iter* MLTextLineList_PushBack(MLTextLineList* list, int text) {
    Iter end;
    Iter result;

    end.p = (int*)&list->last;
    return List_InsertBefore(&result, list, &end, text);
}
