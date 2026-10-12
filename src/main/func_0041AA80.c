#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

union Str_AA80 {
    struct { int w0; int len; char* data; } l;
    struct { unsigned char f : 1; unsigned char n : 7; } s;
    int Size() const { return (l.w0 & 1) ? l.len : (unsigned char)s.n; }
};
struct Target_AA80 {
    VPAD8(p) VPAD2(q) VPAD1(r)
    virtual void Activate();
};
struct O_AA80 {
    char pad[0x44];
    Target_AA80* target;
    Str_AA80 str;
    char pad54[0x30];
    int maxLen;
};
struct Ev_AA80 {
    unsigned short type;
    unsigned short mod;
    unsigned short pad4;
    unsigned short mod2;
    unsigned short key;
    char padA[6];
    unsigned char ch;
};
struct G_AA80 { char pad[0x52]; unsigned char alt; };
extern "C" G_AA80* func_004147A0(void);
extern "C" int func_0041A180(O_AA80* o, bool fwd);
extern "C" int func_0041A2C0(O_AA80* o, char* text);

static inline bool Is3(Ev_AA80* e, unsigned short t, unsigned short m, unsigned short m2) { return e->type == t && e->mod == m && e->mod2 == m2; }
static inline bool Is4(Ev_AA80* e, unsigned short t, unsigned short m, unsigned short k, unsigned short m2) { return e->type == t && e->mod == m && e->key == k && e->mod2 == m2; }
extern "C" int func_0041AA80(O_AA80* self, Ev_AA80* e)
{
    if (Is3(e, 2, 0, 0)) {
        if ((func_004147A0()->alt && e->key == 0x2A) || e->key == 0x4C ||
            (!func_004147A0()->alt && e->key == 8) || e->key == 0x804C) {
            func_0041A180(self, e->key == 0x4C || e->key == 0x804C);
            return 1;
        }
        if ((func_004147A0()->alt && e->key == 0x28) || (!func_004147A0()->alt && e->key == 0xA)) {
            self->target->Activate();
            return 1;
        }
        if (e->ch) {
            if (self->maxLen == -1 || self->str.Size() < self->maxLen) {
                char buf[2];
                buf[0] = e->ch;
                buf[1] = 0;
                func_0041A2C0(self, buf);
                return 1;
            }
        }
    }
    if (Is4(e, 1, 0, 0x40, 0)) {
        self->target->Activate();
        return 1;
    }
    return 0;
}

