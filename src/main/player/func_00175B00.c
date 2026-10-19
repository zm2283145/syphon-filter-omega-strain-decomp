/* retail keeps the dead Loc_LookupText arm of (t ? Loc_LookupText(t) : 0) with a char* t propagated to $zero (beq $zero,$zero): opt_dead_code off */
#pragma opt_dead_code off
typedef struct { char pad[0x6AC]; char timer[0x30]; float baseTime; } SoundMgr175B;
typedef union { int i; float f; } ScriptArg175B;
extern SoundMgr175B* g_Hud;
extern int Loc_LookupText(int id);
extern void HudTimer_Start(void* timer, int obj, float time);

int Script_cPlayer_SetTimer(ScriptArg175B* args) { float timeArg[1]; float time; int id; *(int*)timeArg = args[1].i; time = *timeArg; { char* t = 0; id = t ? Loc_LookupText((int)t) : 0; } HudTimer_Start(g_Hud->timer, id, time + g_Hud->baseTime); return 0; }



