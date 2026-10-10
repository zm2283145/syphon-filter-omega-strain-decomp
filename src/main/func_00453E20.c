#include "types.h"

typedef struct { char pad[0x1A]; unsigned char flag; char pad1B; } Slot;
typedef struct {
    Slot slots[13];
    char state[0x1EA4 - 0x16C];   /* cleared block starts here */
    int mode;
    char pad1EA8[0x23B5 - 0x1EA8];
    char name[0x20];
    unsigned char active;
    char pad23D6[0x2414 - 0x23D6];
    int unk2414;
    char pad2418[0x26AC - 0x2418];
} Game;
extern Game* D_00585E60;
extern char D_004C1940[];
extern void func_0044FA00(Slot* slot);
extern void* memset(void* p, int c, int n);
extern void func_0044F880(Slot* slot, int a, int b, int c);
extern char* String_Copy(char* dst, const char* src);

/* Game state constructor: builds the slots, clears the data block and sets defaults. */
Game* func_00453E20(Game* self)
{
    func_0044FA00(&self->slots[0]);
    func_0044FA00(&self->slots[1]);
    func_0044FA00(&self->slots[2]);
    func_0044FA00(&self->slots[3]);
    func_0044FA00(&self->slots[4]);
    func_0044FA00(&self->slots[5]);
    func_0044FA00(&self->slots[6]);
    func_0044FA00(&self->slots[7]);
    func_0044FA00(&self->slots[8]);
    func_0044FA00(&self->slots[9]);
    func_0044FA00(&self->slots[10]);
    func_0044FA00(&self->slots[11]);
    func_0044FA00(&self->slots[12]);
    D_00585E60 = self;
    memset(self->state, 0, (char*)(self + 1) - self->state);
    self->unk2414 = 0;
    self->mode = 8;
    self->active = 1;
    self->slots[1].flag = 1;
    func_0044F880(&self->slots[1], 0x40, 0, 0xAC);
    func_0044F880(&self->slots[2], 8, 0, 0x214);
    func_0044F880(&self->slots[3], 0x10, 0, 9);
    String_Copy(self->name, D_004C1940);
    return self;
}
