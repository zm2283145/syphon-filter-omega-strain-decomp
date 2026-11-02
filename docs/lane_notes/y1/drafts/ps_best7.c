/* cGameSound_PlaySound (gameSound.cc; prototype cGameSound::PlaySound(const cSndFx&) at early 0x1BED90). */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"
#include "alloc_guard.h"

typedef __int128 u_long128;
struct cHogFile;
struct cSystem;
struct cGOBJ { char p0[0xC]; int serial; char p10[0x49 - 0x10]; unsigned char type; };
struct cSafePtr { cGOBJ* obj; int serial; };
struct cFSHandle { int a; int b; int c; unsigned char d; };
struct cFileMan {
    unsigned int mEncodeFlags;
    char mFname[128];
    short mFileIndex;
    int sh_a; int sh_b; int sh_c; unsigned char sh_d;
    union { cHogFile* mHogFile; void* mFileIO; };
    cHogFile* Hog() const { return mHogFile; }
};
static inline cHogFile* GH(const cFileMan& f) { return f.mHogFile; }
struct cSndFx {
    int mBankID;
    char p4[0xC];
    u_long128 mSndID;
    cSafePtr mRefGobj;
    char p28[8];
    float mSrcLoc[4];
    unsigned int m989Handle;
    unsigned char mHandle;
    char p45[3];
    cFileMan mSndFile;
    cFileMan mLipFile;
    int mPriority;
    short mPlayListIndex;
    char p186[0x190 - 0x186];
};
struct cGameSoundSlot { char p0[0x20]; cSndFx fx; };
struct cBankArr { int data[6]; int& operator[](int i) { return data[i]; } };
struct cGameSound {
    char p0[0x30];
    cGameSoundSlot slots[50];
    cBankArr mBankHandles;
    cHogFile* mHogA;
    cHogFile* mHogB;
};
struct cMessageX { void* vt; char p4[0x1C]; unsigned char immediate; char p21[0xF]; cSndFx fx; };

extern "C" {
extern unsigned char g_GameState;
extern char g_Game[];
extern char D_004F53C8[];
extern char D_004DAE10[], D_004DAE30[];
extern char D_0049F520[], D_0049F528[];
cSndFx* cGameSound_AddToPlaylist(cGameSound* self, const cSndFx* fx, unsigned char flag);
void cGameSound_StopVAG(cGameSound* self, int bank, cSndFx* fx, int f);
int func_003C9C10(void);
int MsgQueue_CountPending(void* q);
void MsgQueue_EraseFirstPending(void* q);
void SoundMsg_WrapAction(cMessageX* m, const cSndFx* fx);
void EffectMsg_WrapRequest(cMessageX* m, const cSndFx* fx);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* to, int immediate);
void cFileMan_dtor(cFileMan* f, int flags);
void cMessage_dtor(void* m, int flags);
void cFileMan_ctor_void(cFileMan* f);
int sprintf(char* d, const char* f, ...);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(cFileMan* f, char* name, cHogFile* h, int b);
int cHogFile_GetBlockIndex(cHogFile* h, char* name, int b);
void* GetFileStreamMan(void);
void cFileStreamMan_StreamRequest(void* m, cFileMan* f, void* cb, cSndFx* user, int a, int b, int c);
void SoundMgr_OnLpdLoaded(void);
void SoundMgr_OnStreamReply(void);
void triggerSndCB(void);
int snd_GetSoundUserData_CB(int bank, long long b, int c, u_long128 id, void* e, void* cb, unsigned long long user);
int snd_PlaySoundByNameVolPanPMPB_CB(int bank, long long b, u_long128 id, int vol, int pan, short f1, short f2, void* cb, unsigned long long user);
void cGameSound_CalcVolPan(cGameSound* self, cSndFx* fx, int* vol, int* pan);
}

struct cPlaySoundMsg : cMessageX {
    cPlaySoundMsg(const cSndFx& f) { SoundMsg_WrapAction(this, &f); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~cPlaySoundMsg() { vt = D_004DAE10; cFileMan_dtor(&fx.mLipFile, -1); cFileMan_dtor(&fx.mSndFile, -1); cMessage_dtor(this, 0); }
};
struct cEffectMsg : cMessageX {
    cEffectMsg(const cSndFx& f) { EffectMsg_WrapRequest(this, &f); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~cEffectMsg() { vt = D_004DAE30; cFileMan_dtor(&fx.mLipFile, -1); cFileMan_dtor(&fx.mSndFile, -1); cMessage_dtor(this, 0); }
};
struct cFileManL : cFileMan {
    cFileManL() { cFileMan_ctor_void(this); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~cFileManL() { cFileMan_dtor(this, -1); }
};

static inline bool Eq(int a, int b) { return a == b; }
static inline cGOBJ* Get(const cSafePtr* r)
{
    unsigned char v = !r->obj || Eq(r->obj->serial, r->serial);
    return v ? r->obj : 0;
}

extern "C" void cGameSound_PlaySound(cGameSound* self, const cSndFx& sndFx)
{
    unsigned char vagFlag;
    unsigned char lipsFlag;
    int bank;
    u_long128 sndID;
    cGOBJ* gobj;
    cSndFx* plSndFx;
    int vol;
    int pan;
    int checkPriFlag;
    int i;
    bank = sndFx.mBankID;
    sndID = sndFx.mSndID;
    {
        unsigned char v = !sndFx.mRefGobj.obj || Eq(sndFx.mRefGobj.obj->serial, sndFx.mRefGobj.serial);
        gobj = v ? sndFx.mRefGobj.obj : 0;
    }
    vol = 0x400;
    pan = -1;
    if (bank < 0 || bank >= 6)
        return;
    if (bank == 5) {
        plSndFx = cGameSound_AddToPlaylist(self, &sndFx, 1);
        if (plSndFx)
            cGameSound_StopVAG(self, 5, plSndFx, 0);
    } else if (bank == 4) {
        if (!self->mHogA && !self->mHogB)
            return;
        checkPriFlag = 1;
        for (i = 0; i < 50; i++) {
            cSndFx* fx = &self->slots[i].fx;
            if (fx->mBankID == 4 && fx->mHandle) {
                if (sndFx.mPriority < fx->mPriority)
                    checkPriFlag = 0;
                else if (fx->mPriority == sndFx.mPriority)
                    checkPriFlag = -1;
                break;
            }
        }
        if (checkPriFlag == 0)
            return;
        if (checkPriFlag < 0) {
            if (func_003C9C10() >= 4 && MsgQueue_CountPending(D_004F53C8) >= 4)
                MsgQueue_EraseFirstPending(D_004F53C8);
            {
                cPlaySoundMsg msg(sndFx);
                msg.immediate = 1;
                QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
            }
        } else {
            char vagName[64];
            char lipName[64];
            vagFlag = 0;
            lipsFlag = 0;
            cFileManL lipFile;
            sprintf(vagName, D_0049F520, &sndFx.mSndID);
            sprintf(lipName, D_0049F528, &sndFx.mSndID);
            {
                cFileManL vagFile;
                cFileMan_EncodeFilename_charP_cHogFileR_bool(&vagFile, vagName, self->mHogA, 1);
                if (!(self->mHogA && (!self->mHogA || cHogFile_GetBlockIndex(vagFile.mHogFile, vagName, 1) != -1))) {
                    if (self->mHogB) {
                        cFileMan_EncodeFilename_charP_cHogFileR_bool(&vagFile, vagName, self->mHogB, 1);
                        if (cHogFile_GetBlockIndex(vagFile.mHogFile, vagName, 1) != -1)
                            vagFlag = 1;
                    }
                } else {
                    vagFlag = 1;
                }
                if (vagFlag) {
                    cGameSound_StopVAG(self, 4, 0, 0);
                    plSndFx = cGameSound_AddToPlaylist(self, &sndFx, 1);
                    if (plSndFx) {
                        plSndFx->mSndFile = vagFile;
                        plSndFx->mLipFile = lipFile;
                        if (gobj && gobj->type == 2) {
                            if (cHogFile_GetBlockIndex(GH(vagFile), lipName, 1) != -1) {
                                cFileMan_EncodeFilename_charP_cHogFileR_bool(&lipFile, lipName, GH(vagFile), 1);
                                plSndFx->mLipFile = lipFile;
                                lipsFlag = 1;
                            }
                        }
                        if (lipsFlag) {
                            cFileStreamMan_StreamRequest(GetFileStreamMan(), &plSndFx->mLipFile, (void*)SoundMgr_OnLpdLoaded, plSndFx, 0, 0, 1);
                            plSndFx->mHandle = 3;
                        } else {
                            plSndFx->mHandle = 2;
                        }
                    }
                }
            }
        }
    } else if (g_GameState == 0xF || bank == 3 || g_GameState == 2) {
        plSndFx = cGameSound_AddToPlaylist(self, &sndFx, 1);
        if (plSndFx) {
            unsigned long long user = (unsigned int)plSndFx;
            int* handle = &self->mBankHandles[bank];
            snd_GetSoundUserData_CB(*handle, 0, -1, sndID, &self->slots[plSndFx->mPlayListIndex], (void*)triggerSndCB, user);
            cGameSound_CalcVolPan(self, plSndFx, &vol, &pan);
            snd_PlaySoundByNameVolPanPMPB_CB(*handle, 0, sndID, vol, pan, 0, 0, (void*)SoundMgr_OnStreamReply, user);
        }
    } else {
        cEffectMsg msg(sndFx);
        msg.immediate = 1;
        QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
    }
}
