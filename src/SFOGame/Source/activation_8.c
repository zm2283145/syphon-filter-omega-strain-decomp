/*
 * SFOGame/Source/activation: 2 files, 00224180-00224330
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00224180 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
/* eClassID is a one-byte enum; comparing through an eClassID local gives retail's
   register choice (byte in a0, pointer kept in v1). */
#pragma enumsalwaysint off
enum eClassID { CID_0, CID_GROUP = 0x10, CID_MAX = 0x7F };
#include "vslot_pad.h"

struct FileMan_4180 { int flags; char name[0x90]; unsigned char b94; };
struct Model_4180 { char p0[0x28]; int refs; };
struct GOBJ_4180 {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Activate(int);
    virtual void Deactivate(int);
    unsigned int mMagic;
    char p8[0x2D - 8];
    unsigned char mActiveFlag;
    unsigned char mStreamingFlag;
    char p2F[0x49 - 0x2F];
    eClassID mClassID;
    char p4A[0x4C - 0x4A];
    int mSubclassId;
    char p50[0x64 - 0x50];
    char mParentName[48];
};
struct VUM_4180 { char p0[0x64]; VUM_4180* mRefGroupGobj; Model_4180* mModel; char p6C[0x1E0 - 0x6C]; FileMan_4180* mVUMFile; };
struct Man_4180 { int list[3]; };
struct EqualTo_4180 { };
struct Binder_4180 {
    EqualTo_4180 op;
    GOBJ_4180* const* value;
    Binder_4180(const EqualTo_4180& x, GOBJ_4180* const& y) : op(x), value(&y) {}
};
static inline Binder_4180 Bind2nd_4180(const EqualTo_4180& op, GOBJ_4180* const& x) { return Binder_4180(op, x); }

extern "C" {
void std_list_imp_voidPtr_remove_if(Man_4180* l, Binder_4180 pred);
VUM_4180* IsVUM(GOBJ_4180* g);
extern char g_Game[];
extern int D_004F56B0;
unsigned char cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(void* game, const char* name, VUM_4180** out);
void* GetFileStreamMan(void);
void cFileStreamMan_StreamRequestFlush_cFileManR_voidPcFSHandlePvoidPbool_voidP_eStreamMode(void* fsm, FileMan_4180* f, void* cb, void* data, int mode);
void cGOBJActivationMan_StreamCB(void);
void cGenerator_DeactivateImmediate(GOBJ_4180* g);
}


extern "C" void cGOBJActivationMan_Deactivate(Man_4180* self, GOBJ_4180* gobj, unsigned char actMode) {
    unsigned char deactivateFlag = 1;
    VUM_4180* vum;
    VUM_4180* loadedVUM;
    unsigned char foundFlag;
    EqualTo_4180 eq;
    std_list_imp_voidPtr_remove_if(self, Bind2nd_4180(eq, gobj));
    vum = IsVUM(gobj);
    if (vum && (vum->mVUMFile->flags & 4)) {
        FileMan_4180* file = vum->mVUMFile;
        loadedVUM = 0;
        eClassID c = gobj->mClassID;
        if (c == CID_GROUP) {
            foundFlag = cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(g_Game, gobj->mParentName, &loadedVUM);
        } else {
            foundFlag = cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(g_Game, file->name, &loadedVUM);
        }
        deactivateFlag = 0;
        if (foundFlag) {
            int& refs = vum->mModel->refs;
            if (refs > 0) {
                refs--;
            }
        }
        if (vum->mModel->refs == 0) {
            if (vum->mRefGroupGobj == 0) {
                cFileStreamMan_StreamRequestFlush_cFileManR_voidPcFSHandlePvoidPbool_voidP_eStreamMode(GetFileStreamMan(), file, (void*)cGOBJActivationMan_StreamCB, gobj, 0);
            }
        } else {
            deactivateFlag = 1;
        }
    }
    if (actMode == 1 && gobj->mSubclassId == D_004F56B0) {
        cGenerator_DeactivateImmediate(gobj);
    }
    if (gobj->mMagic == 0xBEBAAFDE && deactivateFlag) {
        gobj->Deactivate(0);
    }
    gobj->mActiveFlag = 0;
}
static inline void merge_flush_func_00224180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00224180 */

/* merge_units: begin func_00224330 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma enumsalwaysint off

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
#if 0 /* merge_units */
VUM_4330* IsVUM(GOBJ_4330* g);
#endif /* merge_units */
#define IsVUM(a0) ((VUM_4330 *)IsVUM((GOBJ_4180 *)(a0))) /* merge_units */

#if 0 /* merge_units */
unsigned char cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(void* game, const char* name, VUM_4330** out);
#endif /* merge_units */
#define cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(a0, a1, a2) (cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP((a0), (a1), (VUM_4180 * *)(a2))) /* merge_units */

unsigned char cNIEventBase_AreVUMsActive(GOBJ_4330* self, int n);
void cFileStreamMan_StreamRequest(void* fsm, FileMan_4330* f, void* cb, void* data, int mode, unsigned char a, unsigned char b);
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
#undef IsVUM /* merge_units */
#undef cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP /* merge_units */
static inline void merge_flush_func_00224330(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00224330 */
