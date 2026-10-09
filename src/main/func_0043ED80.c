/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after guiMLTextWidget.cc (ends 0x0043E330),
 * before SFOLobby_Mission.cc (starts 0x00442510).
 */

#include "types.h"

void* func_0043ED80(char* self) {
    return self + 4;
}

List* func_0043ED90(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
