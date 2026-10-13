typedef struct { char pad[0x80]; char name[1]; } W352C0;
typedef struct { char pad[0xB08]; unsigned int bits[1]; } A352C0;
extern void* D_004FFD30;
extern W352C0* WeaponDb_Get(void* db, int id);
extern void cAgentData_UnlockWeapon(A352C0* self, const char* name);
void AgentData_UnlockById(A352C0* self, int id)
{
    if (id > -1) {
        if (id < 10000) {
            cAgentData_UnlockWeapon(self, WeaponDb_Get(D_004FFD30, id)->name);
        } else {
            int i = (unsigned char)(id - 10000);
            if (i > -1)
                self->bits[i / 32] |= 1 << (i & 31);
        }
    }
}