/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiTextListWidget.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "guiTextListWidget_types.h"

extern void* func_0013D680(void* dst, void* src);

/* TextListEntry copy constructor. */
TextListEntry* func_00421210(TextListEntry* self, TextListEntry* src) {
    func_0013D680(self, src);
    self->unk0C = src->unk0C;
    self->unk10 = src->unk10;
    return self;
}

TextListEntry* func_00421260(TextListEntryVec* v, int i) {
    return v->data + i;
}

int func_00421280(char* self) {
    return *(int*)(self + 4);
}
