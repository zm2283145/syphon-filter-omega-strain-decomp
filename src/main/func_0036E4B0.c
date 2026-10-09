/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet (code follows the fileman.cc
 * range); functions are named by address until real names are known.
 */

#include "loose03_types.h"

extern int func_00129A70(char* dst, const char* src, int n); /* bounded string copy */
extern int func_003EBEF0(void*);

/* Constructor, kind bit 0x1; sets 0x4 when `extra` is non-zero. */
NamedEntry36E4B0* func_0036E4B0(NamedEntry36E4B0* self, const char* name, int a2, int extra) {
    func_003EBEF0(self->unk88);
    self->flags = 0;
    self->flags = 0;
    func_00129A70(self->name, name, 128);
    self->unk98 = a2;
    self->flags = self->flags | 1;
    if (extra != 0) {
        self->flags = self->flags | 4;
    }
    return self;
}

/* Constructor, kind bit 0x2; sets 0x4 when `extra` is non-zero. */
NamedEntry36E4B0* func_0036E540(NamedEntry36E4B0* self, const char* name, int a2, int extra) {
    func_003EBEF0(self->unk88);
    self->flags = 0;
    self->flags = 0;
    func_00129A70(self->name, name, 128);
    self->unk98 = a2;
    self->flags = self->flags | 2;
    if (extra != 0) {
        self->flags = self->flags | 4;
    }
    return self;
}

/* Default constructor. */
NamedEntry36E4B0* func_0036E5D0(NamedEntry36E4B0* self) {
    func_003EBEF0(self->unk88);
    self->flags = 0;
    return self;
}
