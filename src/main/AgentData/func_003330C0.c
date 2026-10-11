extern __int128 func_003FDA40(const char* s);
extern int func_003309C0(__int128 key);
typedef struct { char pad[0xB08]; unsigned int bits[1]; } AgentD30C0;
void cAgentData_UnlockLevel(AgentD30C0* self, const char* name)
{
    int i = func_003309C0(func_003FDA40(name));
    if (i > -1)
        self->bits[i / 32] |= 1 << (i & 31);
}