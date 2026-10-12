#include "types.h"
typedef struct { char d[0x9C]; } Str_00212C80;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_00212C80 s78;
    Str_00212C80 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) Snd_00212C80;
typedef struct {
    void* vt;
    char pad4[0x74];
    Str_00212C80 s78;
    Str_00212C80 s114;
    char pad1B0[0x20];
} __attribute__((aligned(16))) Snd2_00212C80;
typedef struct SndObj_00212C80 {
    char pad0[0x60]; char preset[0x1F0 - 0x60]; unsigned char playing; char pad1F1; unsigned char local;
} SndObj_00212C80;
extern int D_004F5440;
extern int g_cEnableMsgClass;
extern int g_cDisableMsgClass;
extern int D_004FFC0C;
extern char D_004FFB50[];
extern char D_004DAE30[];
extern char D_004DADF0[];
extern int* Event_GetType(void* ev);
extern void Event_Send(void* m, void* target, int immediate);
extern void cMessage_dtor(void* m, int flags);
extern void SoundEvent_CtorFromPreset(Snd_00212C80* e, void* preset, void* owner);
extern void func_0020EBA0(Snd2_00212C80* e, void* preset, void* owner);
extern void func_0036E220(Str_00212C80* s, int flag);
extern void func_001C6700();
extern int Object_HandleMessage(SndObj_00212C80* self, void* ev);
static inline SndObj_00212C80* Owner_00212C80(SndObj_00212C80* o) { return o->local ? o : 0; }
static inline void Play_00212C80(SndObj_00212C80* self, Snd_00212C80* s)
{
    SndObj_00212C80* owner = Owner_00212C80(self);
    if (!self->playing) {
        self->playing = 1;
        SoundEvent_CtorFromPreset(s, self->preset, owner);
        if (!func_001C6700)
            s->flag = 1;
        Event_Send(s, D_004FFB50, 1);
        s->vt = D_004DAE30;
        func_0036E220(&s->s114, -1);
        func_0036E220(&s->s78, -1);
        cMessage_dtor(s, 0);
    }
}
int cSoundGOBJ_v01(SndObj_00212C80* self, void* ev)
{
    Snd_00212C80 a;
    Snd_00212C80 b;
    Snd2_00212C80 c;
    int t = *Event_GetType(ev);
    if (t == D_004F5440) {
        Play_00212C80(self, &a);
        return 1;
    }
    t = *Event_GetType(ev);
    if (t == g_cEnableMsgClass) {
        if (!self->local) {
            Play_00212C80(self, &b);
            return 1;
        }
    } else {
        t = *Event_GetType(ev);
        if (t == g_cDisableMsgClass && !self->local) {
            SndObj_00212C80* owner;
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
            return 1;
        }
    }
    return Object_HandleMessage(self, ev);
}