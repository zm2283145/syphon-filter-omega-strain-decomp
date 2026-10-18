#pragma cplusplus on
#include "types.h"

struct Arc_8E10 { char pad0[0x84]; int f84; char pad88[0xC0]; char* f148; };
struct FME_8E10 {
    int flags;
    char name[128];
    short h84;
    int a88;
    int a8C;
    int a90;
    unsigned char b94;
    Arc_8E10* a98;
};
#include "vslot_pad.h"
struct VB_8E10 { VPAD32(a) VPAD32(b) virtual unsigned char State(); };
struct Voice_8E10 : VB_8E10 {
    char pad4[0x8];
    int serial;
    char pad10[0x39];
    unsigned char b49;
    char pad4A[0x16];
    char x60[0x2D68];
    int x2DC8;
};
struct Req_8E10 {
    int type;
    char pad4[0xC];
    char name[0x10];
    Voice_8E10* voice;
    int voiceId;
    char pad28[0x18];
    int x40;
    unsigned char state;
    char pad45[3];
    FME_8E10 a;
    FME_8E10 b;
    int x180;
    short x184;
    unsigned char x186;
    char pad187[9];
};
struct Ent_8E10 { char pad0[0x14]; unsigned char x14; char pad15[0xB]; Req_8E10 sub; };
struct Self_8E10 {
    char pad0[0x20];
    unsigned char x20;
    char pad21[0xF];
    Ent_8E10 ent[50];
    char pad5490[0x20];
    Arc_8E10* hog;
};

extern "C" {
extern char D_0049F530[];
extern char D_0049F538[];
extern char D_0049F548[];
extern char D_004FFC90[];
extern int D_004FFC2C;
int sprintf(char*, const char*, ...);
int strlen(const char*);
int String_CompareNoCase(const char*, const char*);
void String_Copy(char*, const char*);
int Hog_FindFileNoCase(Arc_8E10*, char*, int);
int Hog_GetMemberOffset(Arc_8E10*, int);
void SoundMgr_GetVolumePan(Self_8E10*, Req_8E10*, int*, int*);
void snd_StopVAGStreamsInGroup(int);
int snd_GetMasterVolume(int);
void snd_StopSound(int);
void snd_FlushSoundCommands(void);
void HudObject_Subtitle(int, char*, int, int);
int FileMan_ReadData(FME_8E10*);
void Lpd_Init(void*, int, int);
void SoundMgr_OnStreamReply(void);
int snd_PlayVAGStream(int, int, int, int, int, int, int, int, int, long long, void (*)(void), unsigned long long);
int snd_RestartVAGStream(int, int, int, int, int, int, void (*)(void), unsigned long long);
}

static inline int Off(Arc_8E10* a, int idx) { return *(int*)(a->f148 + 0x10) + Hog_GetMemberOffset(a, idx); }
static inline bool IsIdle(Req_8E10* r) { return r->state == 0; }
static inline bool IsDone(Req_8E10* r) { return r->state == 1 || r->state == 3; }
static inline bool IsActive(Req_8E10* r) { return !IsIdle(r) && !IsDone(r); }
static inline int FSec(FME_8E10* f) { Arc_8E10* a = f->a98; int s = Off(a, Hog_FindFileNoCase(a, f->name, 0)) / 2048; const int b = a->f84; return b + s; }
static inline void Release(Req_8E10* r) { if (!r->state && r->x40) { snd_StopSound(r->x40); r->x40 = 0; } }
static inline void Release2(Req_8E10* r) { if (r->x40) { snd_StopSound(r->x40); r->x40 = 0; } }
static inline bool IsLoading(Req_8E10* r) { return r->state == 2 || r->state == 4; }
static inline Voice_8E10* GetVoice(Req_8E10* r)
{
    Voice_8E10* t = r->voice;
    bool isNull = !t;
    bool ok = true;
    if (!isNull)
        if (t->serial != r->voiceId)
            ok = false;
    return ok ? t : 0;
}

static inline Voice_8E10* GetVoice2(Req_8E10* r)
{
    bool ok = true;
    Voice_8E10* t = r->voice;
    bool isNull = !t;
    if (!isNull)
        if (t->serial != r->voiceId)
            ok = false;
    return ok ? t : 0;
}
extern "C" void SoundMgr_Frame(Self_8E10* self)
{
    int vol;
    int pan;
    char buf[0x40];
    char tmp[0x10];
    int i;
    for (i = 0; i < 50; i++) {
        Req_8E10* r = &self->ent[i].sub;
        if (r->type == 5) {
            if (IsLoading(r) && self->hog && !self->x20) {
                if (String_CompareNoCase(r->name, D_0049F530) == 0) {
                    sprintf(buf, D_0049F538, D_004FFC90);
                    if (Hog_FindFileNoCase(self->hog, buf, 0) == -1) {
                        String_Copy(tmp, D_004FFC90);
                        tmp[strlen(tmp) - 1] = 0;
                        sprintf(buf, D_0049F538, tmp);
                    }
                } else {
                    sprintf(buf, D_0049F548, r->name);
                }
                if (Hog_FindFileNoCase(self->hog, buf, 0) != -1) {
                    snd_StopVAGStreamsInGroup(2);
                    int s = Off(self->hog, Hog_FindFileNoCase(self->hog, buf, 0)) / 2048; const int b = self->hog->f84; int sec = b + s;
                    snd_PlayVAGStream(sec, 0, 0, 0, 0x400, -1, 1, 0, 0, self->ent[i].x14 ? 4 : 0, SoundMgr_OnStreamReply, (unsigned int)r);
                    r->state = 1;
                }
            }
        } else if (IsActive(r)) {
            Voice_8E10* v = GetVoice(r);
            SoundMgr_GetVolumePan(self, r, &vol, &pan);
            if (r->type == 4) {
                if (IsLoading(r) && (!v || (v && v->State() != 3))) {
                    snd_StopVAGStreamsInGroup(4);
                    snd_StopVAGStreamsInGroup(0x4000);
                    int sec = FSec(&r->a);
                    if (snd_GetMasterVolume(2)) {
                        if (!v)
                            snd_PlayVAGStream(sec, 0, 0, 0, vol, pan, 2, 0, 0, 0, SoundMgr_OnStreamReply, (unsigned int)r);
                        else
                            snd_PlayVAGStream(sec, 0, 0, 0, vol, pan, 0xE, 0, 0, 0, SoundMgr_OnStreamReply, (unsigned int)r);
                    }
                    if (r->x186 && D_004FFC2C)
                        HudObject_Subtitle(D_004FFC2C, r->name, 0, 0);
                    if (r->state == 4 && v && r->b.b94 && v->b49 == 2)
                        Lpd_Init(v->x60, FileMan_ReadData(&r->b), 0);
                    r->state = 1;
                }
                if (r->state == 6 && v && v->State() == 3)
                    r->state = 0;
            }
            if (r->state == 6 && r->x40) {
                if (r->type == 4 && !r->b.b94) {
                    Voice_8E10* v2 = GetVoice2(r);
                    if (v2 && v2->b49 == 2)
                        v2->x2DC8 = 0;
                }
                snd_RestartVAGStream(r->x40, 5, vol, pan, 0, 0, SoundMgr_OnStreamReply, (unsigned int)r);
                r->state = 1;
            }
        }
    }
    for (int j = 0; j < 50; j++) {
        Req_8E10* r = &self->ent[j].sub;
        if (!r->state && r->x40) {
            snd_StopSound(r->x40);
            r->x40 = 0;
        }
    }
    snd_FlushSoundCommands();
}
