/*
 * SFOGame/Source/GuiOnlineConnect: 1 file, 0029D020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiOnlineConnect_29D020 */
#pragma push /* merge_units */
typedef struct Self { char pad[0x120]; int handle; } Self;
extern void* D_004FFC04;
extern char D_004AABF0[];
extern void* cDME_GetLobby(Self*);
extern void GuiOnlineConnect_Back(Self*, int);
extern int GuiLobbyScreen_GetLobbyString(Self*, int, int, int, int, int);
extern int cGameFrontEnd_PushMessageBox(void*, int, char*, int, int, int);
extern void cGameFrontEnd_PopMessageBox(void*, int);
extern void cGameFrontEnd_LobbyStartAccountScreen(void*);
extern void SFOLobby_GetAnnouncements(void*);
extern int SFOLobby_GetUsagePolicy(void*);
extern void SFOLobby_GetPrivacyPolicy(void*);
int GuiOnlineConnect_RetrieveServerNotices(Self* self)
{
    void* r = cDME_GetLobby(self);
    void* g;
    int h;
    if (r == 0) {
        GuiOnlineConnect_Back(self, 1);
        return 0;
    }
    g = D_004FFC04;
    h = cGameFrontEnd_PushMessageBox(g, 0, D_004AABF0, GuiLobbyScreen_GetLobbyString(self, 0xD, 0, 0, 0, 0), 0, 0);
    if (self->handle != -1) cGameFrontEnd_PopMessageBox(D_004FFC04, self->handle);
    cGameFrontEnd_LobbyStartAccountScreen(D_004FFC04);
    SFOLobby_GetAnnouncements(r);
    if (SFOLobby_GetUsagePolicy(r)) SFOLobby_GetPrivacyPolicy(r);
    cGameFrontEnd_PopMessageBox(D_004FFC04, h);
    return 1;
}
static inline void merge_flush_GuiOnlineConnect_29D020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiOnlineConnect_29D020 */
