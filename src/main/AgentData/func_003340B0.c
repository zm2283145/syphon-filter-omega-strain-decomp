typedef struct { char p0[0x8AC]; char name[0xB73 - 0x8AC]; unsigned char flag; } T340B0;
extern int D_0052FE80;
extern void String_Copy(char* dst, const char* src);
void AgentData_SetName(T340B0* self, const char* s)
{
    String_Copy(self->name, s);
    if (D_0052FE80) {
        self->flag = 1;
        D_0052FE80 = 0;
    }
}