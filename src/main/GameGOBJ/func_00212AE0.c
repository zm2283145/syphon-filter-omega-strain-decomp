#include "types.h"
typedef struct { char d[0x9C]; } Str_00212AE0;
typedef struct {
    void* vt;
    char pad4[0x74];
    Str_00212AE0 s78;
    Str_00212AE0 s114;
    char pad1B0[0x20];
} __attribute__((aligned(16))) Snd2_00212AE0;
typedef struct SndObj_00212AE0 {
    char pad0[0x60]; char preset[0x1F0 - 0x60]; unsigned char playing; unsigned char active; unsigned char local;
} SndObj_00212AE0;
extern int D_004FFC0C;
extern char D_004FFB50[];
extern char D_004DADF0[];
extern void Event_Send(void* m, void* target, int immediate);
extern void cMessage_dtor(void* m, int flags);
extern void func_0020EBA0(Snd2_00212AE0* e, void* preset, void* owner);
extern void func_0036E220(Str_00212AE0* s, int flag);
extern void Object_Deactivate(SndObj_00212AE0* self, int arg);
void cSoundGOBJ_v16(SndObj_00212AE0* self, int arg)
{
    Snd2_00212AE0 c;
    if (self->active) {
        SndObj_00212AE0* owner;
        if (self->local)
            owner = self;
        else if (D_004FFC0C)
            owner = 0;
        else
            owner = self;
        func_0020EBA0(&c, self->preset, owner);
        Event_Send(&c, D_004FFB50, 1);
        c.vt = D_004DADF0;
        func_0036E220(&c.s114, -1);
        func_0036E220(&c.s78, -1);
        cMessage_dtor(&c, 0);
        self->playing = 0;
    }
    Object_Deactivate(self, arg);
}
