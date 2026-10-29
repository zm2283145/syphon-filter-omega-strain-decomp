#pragma cplusplus on
#include "types.h"
#pragma enumsalwaysint off
/* eClassID is a one-byte enum; comparing through an eClassID local gives retail's
   register choice (byte in a0, pointer kept in v1). */
enum eClassID { CID_0, CID_GROUP = 0x10, CID_MAX = 0x7F };
#include "vslot_pad.h"

struct FileMan_4330 { int flags; char name[0x90]; unsigned char b94; };
struct Model_4330 { char p0[0x28]; int refs; };
struct GOBJ_4330 {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Activate(int);
    char p4[0x2D - 4];
    unsigned char mActiveFlag;
    unsigned char mStreamingFlag;
    char p2F[0x49 - 0x2F];
    eClassID mClassID;
    char p4A[0x64 - 0x4A];
    char mParentName[48];
};
struct VUM_4330 { char p0[0x68]; Model_4330* mModel; char p6C[0x1E0 - 0x6C]; FileMan_4330* mVUMFile; };
struct Man_4330 { int list[3]; };

extern "C" {
void std_list_cGOBJPtr_push_back(Man_4330* l, GOBJ_4330** p);
VUM_4330* IsVUM(GOBJ_4330* g);
extern char g_Game[];
unsigned char cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(void* game, const char* name, VUM_4330** out);
unsigned char cNIEventBase_AreVUMsActive(GOBJ_4330* self, int n);
void* GetFileStreamMan(void);
void cFileStreamMan_StreamRequest(void* fsm, FileMan_4330* f, void* cb, void* data, int mode, unsigned char a, unsigned char b);
void cGOBJActivationMan_StreamCB(void);
}


extern "C" void cGOBJActivationMan_Activate(Man_4330* self, GOBJ_4330* gobj, int mode) {
    unsigned char activateFlag = 1;
    unsigned char groupVUMFlag = 0;
    VUM_4330* vum;
    gobj->mStreamingFlag = 0;
    std_list_cGOBJPtr_push_back(self, &gobj);
    vum = IsVUM(gobj);
    if (vum && (vum->mVUMFile->flags & 4)) {
        FileMan_4330* file = vum->mVUMFile;
        VUM_4330* loadedVUM = 0;
        unsigned char foundFlag;
        eClassID c = gobj->mClassID;
        if (c == CID_GROUP) {
            foundFlag = cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(g_Game, gobj->mParentName, &loadedVUM);
        } else {
            foundFlag = cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(g_Game, file->name, &loadedVUM);
        }
        activateFlag = 0;
        if (foundFlag) {
            if (vum->mModel->refs == 0) {
                if (gobj->mClassID == 0x10) {
                    activateFlag = cNIEventBase_AreVUMsActive(gobj, 0);
                    groupVUMFlag = 1;
                    if (activateFlag && !file->b94) {
                        activateFlag = 0;
                    }
                }
            } else if (file->b94) {
                activateFlag = 1;
            }
            vum->mModel->refs++;
        }
        if (!activateFlag) {
            gobj->mStreamingFlag = 1;
            cFileStreamMan_StreamRequest(GetFileStreamMan(), file, (void*)cGOBJActivationMan_StreamCB, gobj, 0, 0, !groupVUMFlag);
        }
    }
    if (activateFlag) {
        gobj->Activate(0);
    }
    gobj->mActiveFlag = 1;

}
