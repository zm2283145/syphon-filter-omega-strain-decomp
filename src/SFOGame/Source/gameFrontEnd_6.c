/*
 * SFOGame/Source/gameFrontEnd: 3 files, 002C97A0-002C9860
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C97A0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cLoadMsg_dtor, D_004DE200, cMessage_dtor)
static inline void merge_flush_func_002C97A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C97A0 */

/* merge_units: begin func_002C9800 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cInitMsg_dtor, D_004DE220, cMessage_dtor)
static inline void merge_flush_func_002C9800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C9800 */

/* merge_units: begin func_002C9860 */
#pragma push /* merge_units */
extern void* cSystemContainer_GetSystem(void* a, void* b);
extern void cWeaponDB_CloseWeaponsHog(int);
extern char* GetMachine(void);
extern void cGameSound_Unload(void*);
extern void cGameFrontEnd_CloseCharacter(void*, int);
extern void cGameFrontEnd_CloseZeusHog(void*);
extern void cUSBKeybd_SetAsciiMode(void*);
extern unsigned char* cDME_GetLobby(void);
extern char* strncpy(char*, const char*, int);
extern char D_004ACF48[];
extern char D_004F2CC0[];
extern char g_Game[];
extern char g_LevelDirName[];
extern int g_WeaponDatabase;
extern unsigned char D_0051EF68;
extern char D_0055A700[];

typedef struct {
    char pad0[0x28];
    unsigned char f28;
    char pad29[0xE];
    unsigned char f37;
    unsigned char f38;
} Obj9860;

typedef struct {
    signed char len;
    char text[0x80];
} PStr;

static inline void Copy(PStr* buf, const char* s)
{
    char* d;
    const char* p;
    int n;
    n = 0;
    d = buf->text;
    p = s;
    while ((*d++ = *p++) != 0) {
        if (++n >= 0x7E) {
            n++;
            d[0] = '\n';
            d[1] = 0;
            break;
        }
    }
    buf->len = n;
}

void cGameFrontEnd_Suspend(Obj9860* self, unsigned char mode)
{
    if (self->f37 == 0) {
        { char* q = GetMachine(); q[0x278] = 1; }
        cUSBKeybd_SetAsciiMode(D_0055A700);
        switch (mode) {
        case 0: {
            void* svc;
            D_0051EF68 = 0;
            svc = cSystemContainer_GetSystem(g_Game, D_004F2CC0);
            if (svc) {
                PStr save;
                unsigned char* g;
                Copy(&save, g_LevelDirName);
                strncpy(g_LevelDirName, D_004ACF48, 0x80);
                cGameSound_Unload(svc);
                strncpy(g_LevelDirName, save.text, 0x80);
                g = cDME_GetLobby();
                if (g && g[0x2409] == 0) {
                    D_0051EF68 = 1;
                    g[0x2409] = 1;
                }
            }
            break;
        }
        case 1:
            break;
        }

        cGameFrontEnd_CloseZeusHog(self);
        cWeaponDB_CloseWeaponsHog(g_WeaponDatabase);
        cGameFrontEnd_CloseCharacter(self, 1);
        self->f37 = 1;
        self->f28 = 0;
        self->f38 = mode;
    }
}
static inline void merge_flush_func_002C9860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C9860 */
