#include "types.h"
typedef struct { char pad[0xC]; unsigned char ready; } Sub;
typedef struct {
    int unk0;           /* 0x00 */
    int owner;          /* 0x04 */
    unsigned char flag; /* 0x08 */
    char pad9[3];
    int unkC;           /* 0x0C */
    Sub sub;            /* 0x10 */
    char pad1D[3];
    char list[0xC];     /* 0x20 */
    int count;          /* 0x2C */
    int state;          /* 0x30 */
    char pad34[0x8C];
    int unkC0;          /* 0xC0 */
} S;
extern char D_004F8350[];
extern void func_002666F0(Sub*);
extern void func_00266B80(void*);
extern void func_002666D0(void* registry, S** self);
/* Constructor: initialises members and registers the object in the global registry. */
S* func_00266630(S* self, int owner)
{
    Sub* sub = &self->sub;
    func_002666F0(sub);
    sub->ready = 1;
    func_00266B80(self->list);
    self->state = -2;
    self->count = 0;
    self->owner = owner;
    self->flag = 0;
    self->unk0 = 0;
    self->unkC = 0;
    self->unkC0 = 0;
    func_002666D0(D_004F8350, &self);
    return self;
}
