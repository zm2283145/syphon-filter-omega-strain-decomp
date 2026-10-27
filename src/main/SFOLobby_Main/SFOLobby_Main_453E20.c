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
extern void SFOLobbyList_ctor(Slot* slot);
extern void* memset(void* p, int c, int n);
extern void SFOLobbyList_AllocList(Slot* slot, int a, int b, int c);
extern char* Libc_Strcpy(char* dst, const char* src);

/* Game state constructor: builds the slots, clears the data block and sets defaults. */
Game* SFOLobby_ctor(Game* self)
{
    SFOLobbyList_ctor(&self->slots[0]);
    SFOLobbyList_ctor(&self->slots[1]);
    SFOLobbyList_ctor(&self->slots[2]);
    SFOLobbyList_ctor(&self->slots[3]);
    SFOLobbyList_ctor(&self->slots[4]);
    SFOLobbyList_ctor(&self->slots[5]);
    SFOLobbyList_ctor(&self->slots[6]);
    SFOLobbyList_ctor(&self->slots[7]);
    SFOLobbyList_ctor(&self->slots[8]);
    SFOLobbyList_ctor(&self->slots[9]);
    SFOLobbyList_ctor(&self->slots[10]);
    SFOLobbyList_ctor(&self->slots[11]);
    SFOLobbyList_ctor(&self->slots[12]);
    D_00585E60 = self;
    memset(self->state, 0, (char*)(self + 1) - self->state);
    self->unk2414 = 0;
    self->mode = 8;
    self->active = 1;
    self->slots[1].flag = 1;
    SFOLobbyList_AllocList(&self->slots[1], 0x40, 0, 0xAC);
    SFOLobbyList_AllocList(&self->slots[2], 8, 0, 0x214);
    SFOLobbyList_AllocList(&self->slots[3], 0x10, 0, 9);
    Libc_Strcpy(self->name, "MediusLobby");
    return self;
}
