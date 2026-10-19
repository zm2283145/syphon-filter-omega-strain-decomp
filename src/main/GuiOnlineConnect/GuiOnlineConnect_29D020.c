typedef struct Self { char pad[0x120]; int handle; } Self;
extern void* D_004FFC04;
extern char D_004AABF0[];
extern void* DME_GetLobby(Self*);
extern void GuiOnlineConnect_Back(Self*, int);
extern int GuiScreen_GetLobbyString(Self*, int, int, int, int, int);
extern int FrontEnd_OpenPopup(void*, int, char*, int, int, int);
extern void FrontEnd_ClosePopup(void*, int);
extern void FrontEnd_DownloadPolicies(void*);
extern void SFOLobby_RequestSettings(void*);
extern int SFOLobby_GetUsagePolicy(void*);
extern void SFOLobby_GetPrivacyPolicy(void*);
int GuiOnlineConnect_Retry(Self* self)
{
    void* r = DME_GetLobby(self);
    void* g;
    int h;
    if (r == 0) {
        GuiOnlineConnect_Back(self, 1);
        return 0;
    }
    g = D_004FFC04;
    h = FrontEnd_OpenPopup(g, 0, D_004AABF0, GuiScreen_GetLobbyString(self, 0xD, 0, 0, 0, 0), 0, 0);
    if (self->handle != -1) FrontEnd_ClosePopup(D_004FFC04, self->handle);
    FrontEnd_DownloadPolicies(D_004FFC04);
    SFOLobby_RequestSettings(r);
    if (SFOLobby_GetUsagePolicy(r)) SFOLobby_GetPrivacyPolicy(r);
    FrontEnd_ClosePopup(D_004FFC04, h);
    return 1;
}
