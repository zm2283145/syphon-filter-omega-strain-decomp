#include "types.h"
extern unsigned char* D_005061D0;
static inline void W16_0027C070(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_0027C070(int v) { W16_0027C070((unsigned short)v); W16_0027C070(v >> 16); }
static inline void WF_0027C070(float f) { W32_0027C070(*(int*)&f); }
static inline short R16_0027C070(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_0027C070(void) { unsigned short lo = R16_0027C070(); return lo + ((unsigned short)R16_0027C070() << 16); }
static inline float RF_0027C070(void) { int i = R32_0027C070(); return *(float*)&i; }
typedef struct { char pad[0x4C]; int kind; } T_0027C070;
typedef struct { char pad[0x24]; int id; char p28[8]; float pos[4]; float f; } M_0027C070;
extern int g_HumanActorClassKey;
extern void Script_ReadU32(int* p);
extern float Script_ReadFloat(void);
extern void Actor_StartGrenadeThrow(float f, T_0027C070* t, int* id, float* pos);
void func_0027C070(M_0027C070* m, T_0027C070* t) {
    Script_ReadU32(&m->id);
    m->pos[0] = Script_ReadFloat();
    m->pos[1] = Script_ReadFloat();
    m->pos[2] = Script_ReadFloat();
    m->pos[3] = 1.0f;
    m->f = RF_0027C070();
    if (t && t->kind == g_HumanActorClassKey) Actor_StartGrenadeThrow(m->f, t, &m->id, m->pos);
}