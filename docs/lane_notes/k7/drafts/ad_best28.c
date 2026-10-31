#pragma cplusplus on
#pragma opt_lifetimes off
#include "types.h"
#include "alloc_guard.h"

struct Rel3 { int a, b, c; };
struct ReqArr { Rel3 rel; unsigned char flag; char pad[3]; };   /* 0x10 */
void* cArray_eRequirementState_ctor_(void*);
struct Ach;
extern "C" { void* cArray_eRequirementState_ctor(void*); void cArray_eRequirementState_ResizeActual(void*, int, void*); void cAgentData_tAchievement_Reset(void*); void* cArray_eRequirementState_dtor(void*, int); extern int D_004926C8; }
#pragma define_section AGENT_LOCAL_DTORS ".dtors_drop" far_absolute RX
struct RA2 { Rel3 rel; unsigned char flag; char pad[3]; RA2(int n) { cArray_eRequirementState_ctor(this); cArray_eRequirementState_ResizeActual(this, n, &D_004926C8); } ~RA2() {} /* Inline actual cArray destruction; duplicate wrapper is discarded like AllocGuard. */
 };
struct Ach { unsigned char state; char pad[3]; RA2 reqs;
  Ach(int n) : reqs(n) { cAgentData_tAchievement_Reset(this); }
 /* Member destructor mirrors real tAchievement ownership. */
 ~Ach() { cArray_eRequirementState_dtor(&reqs, -1); }
 };
extern "C" void std_vector_imp_tAchievement_insert(void*, Ach*, int, const Ach*);
struct AchArr { int a; int size; Ach* data; unsigned char flag; char pad[3];
  void push_back(const Ach& x) { std_vector_imp_tAchievement_insert(this, data + size, 1, &x); } }; /* 0x10 */
struct RowDef { int a, b, c, n; int e, f; };                     /* 0x18 */
struct Tbl { int a; int count; RowDef* data; int d; RowDef& operator[](int n) { return data[n]; } int Size() const { return count; } };          /* 0x10 */

struct cAgentData {
    int mVersion;               /* 000 */
    int mSlot;                  /* 004 */
    int mStats[31];             /* 008 */
    unsigned int mObj[8];       /* 084 */
    unsigned int mObjLvl[8];    /* 0A4 */
    ReqArr mMissionStats;       /* 0C4 */
    char padD4[0x8AC - 0xD4];
    char mName[16];             /* 8AC */
    char mCellName[16];         /* 8BC */
    char mPassword[16];         /* 8CC */
    char sv0[0x40];             /* 8DC */
    char sv1[0x40];             /* 91C */
    char sv2[0x40];             /* 95C */
    int sv99C;                  /* 99C */
    int sv9A0;                  /* 9A0 */
    void* mSkl;                 /* 9A4 */
    char mCompressedSkl[256];   /* 9A8 */
    AchArr mAch[5];             /* AA8 */
    ReqArr mRatings;            /* AF8 */
    unsigned int mBonuses[9];   /* B08 */
    unsigned int mBonusesLvl[9];/* B2C */
    int mRank;                  /* B50 */
    int mRankLvl;               /* B54 */
    ReqArr mUnlocked;           /* B58 */
    void AddAch(int i, int n) { mAch[i].push_back(Ach(n)); }
    AchArr& Ach_(int i) { return mAch[i]; }
};

extern "C" {
extern Tbl D_00532A70[5];
extern int D_00532AD4;
extern int D_004926C8;
extern int D_004926D8;
void* std_vector_tMissionStats_ctor(void*);
void* cArray_tAchievement_ctor(void*);
void* cArray_tAchievement_dtor(void*, int);
void __construct_array(void*, void*, void*, int, int);
void* std_vector_eAchievementState_ctor(void*);
void* std_vector_charPtr_ctor_void_2(void*);
int cArrayCapacity_Int(int*);
void std_vector_charPtr_reserve(void*, int);
void* cArray_eRequirementState_ctor(void*);
void cArray_eRequirementState_ResizeActual(void*, int, void*);
void cAgentData_tAchievement_Reset(void*);
void* cArray_eRequirementState_dtor(void*, int);
void std_vector_eAchievementState_push_back(void*, void*);
void cAgentData_Reset(cAgentData*);
void* cMemMan_Allocate(int, int, const char*, int);
void* memset(void*, int, unsigned int);
cAgentData* cAgentData_ctor(cAgentData* self);
}

static inline void AddAch(cAgentData* s, int i, int n) { s->mAch[i].push_back(Ach(n)); }
cAgentData* cAgentData_ctor(cAgentData* self)
{
    for (int i = 0; i < 8; i++) self->mObj[i] = 0;
    for (int i = 0; i < 8; i++) self->mObjLvl[i] = 0;
    { ReqArr* p = &self->mMissionStats; std_vector_tMissionStats_ctor(p); p->flag = 1; }
    self->sv0[0] = 0;
    self->sv1[0] = 0;
    self->sv99C = -1;
    self->sv2[0] = 0;
    self->sv9A0 = -1;
    __construct_array(self->mAch, (void*)cArray_tAchievement_ctor, (void*)cArray_tAchievement_dtor, 0x10, 5);
    { ReqArr* p = &self->mRatings; std_vector_eAchievementState_ctor(p); p->flag = 1; }
    for (int i = 0; i < 9; i++) self->mBonuses[i] = 0;
    for (int i = 0; i < 9; i++) self->mBonusesLvl[i] = 0;
    {
        int cap = 128;
        ReqArr* p = &self->mUnlocked;
        std_vector_charPtr_ctor_void_2(p);
        std_vector_charPtr_reserve(p, cArrayCapacity_Int(&cap));
        p->flag = 0;
    }
    int off = 0;
    for (int i = 0; i < 5; i++, off += 16) {
        if (0 < D_00532A70[i].count) { int j = 0; do { { char* s = (char*)self; __asm__("" : "+r"(s)); ((AchArr*)(s + off + 0xAA8))->push_back(Ach(D_00532A70[i][j].n)); } j++; } while (j < D_00532A70[i].count); }
    }
    for (int i = 0; i < D_00532AD4; i++) {
        std_vector_eAchievementState_push_back(&self->mRatings, &D_004926D8);
    }
    cAgentData_Reset(self);
    self->mName[0] = 0;
    self->mCellName[0] = 0;
    self->mPassword[0] = 0;
    self->mVersion = -1;
    self->mSlot = 0;
    {
        void* m;
        {
            AllocGuard g;
            m = cMemMan_Allocate(0, 0x440, "AgentData.cc", 0xD5);
        }
        self->mSkl = m;
    }
    memset(self->mCompressedSkl, 0, 0x100);
    return self;
}
