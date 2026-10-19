#ifndef NPC_AUTH_H
#define NPC_AUTH_H
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
static inline int NpcAuth_IsLocal(void)
{
    return g_IsMultiplayer ? D_005721C0 : 1;
}
extern void NetEvent_Send(void* ent, int id, int size, int a, int b, int c, int d);
#endif