extern int DME_GetLobby(void);
extern int Iop_LoadNetModules(int a);
extern void func_00271280(int a);
extern void func_002EA4F0(void* a, void* b);
extern void DME_CreateLobby(void);
extern char* GameIni_GetString(int id);
extern int sprintf(char* buf, const char* fmt, ...);
extern char* Libc_Strcat(char* d, const char* s);
extern unsigned int strlen(const char* s);
extern char* Agent_GetSelected(void* a, int idx);
extern void String_Copy(char* d, const char* s);
extern void func_00453C70(char* o, int a, void* info, char* text, int len, int flag);
extern void func_00442670(char* o, int v);
extern unsigned char Loc_GetLanguage(void);
extern void func_00452F60(char* o, void* cb);
extern void func_002C7FC0(void* self);
extern int func_002CAA70();
extern int sfo_malloc_2CA9B0();
extern int func_002CC200();

typedef struct {
    int v[10];
} Ids;

typedef struct {
    int f0;
    char name[0x80];
    char name2[0x40];
} Info;

extern unsigned char D_0048C250;
extern int D_0048C160[];
extern Ids D_0048C260;
extern char D_004ACFA0[];
extern char D_004ACFA8[];
extern int D_004ACB30[];
extern char D_004FFB50[];
extern unsigned char D_0051EEA8;

int FrontEnd_StartOnline(void* self)
{
    Ids ids;
    char text[0x400];
    char line[0x80];
    Info info;
    char* o;
    unsigned int i;
    int* p;
    int j;
    int len;
    char* ag;

    if (DME_GetLobby()) {
        return 0;
    }
    if (D_0048C250) {
        if (Iop_LoadNetModules(0)) {
            D_0051EEA8 = 1;
            func_00271280(0);
            D_0048C250 = 0;
        } else {
            return 0;
        }
    }
    func_002EA4F0(func_002CAA70, sfo_malloc_2CA9B0);
    DME_CreateLobby();
    o = (char*)DME_GetLobby();
    p = ids.v;
    ids = D_0048C260;
    text[0] = 0;
    for (i = 0; i < 10; i++, p++) {
        char* s = GameIni_GetString(*p);
        if (s && *s) {
            sprintf(line, D_004ACFA0, *p, s);
            Libc_Strcat(text, line);
        }
    }
    len = strlen(text);
    ag = Agent_GetSelected(D_004FFB50, -1) + 0x8DC;
    __clear((char*)&info, 0xC4);

    {
        char* s = GameIni_GetString((int)D_004ACFA8);
        if (s) {
            String_Copy(info.name, s);
        }
    }
    String_Copy(info.name2, ag + 0x80);
    func_00453C70(o, 0, &info, text, len, 1);
    {
        int* q = D_004ACB30;
        for (j = 0; j < 9; j++, q++) {
            func_00442670(o, D_0048C160[*q]);
        }
    }
    {
        int lang;
        switch (Loc_GetLanguage()) {
        case 0: lang = 1; break;
        case 1: lang = 2; break;
        case 2: lang = 8; break;
        case 3: lang = 5; break;
        case 4: lang = 7; break;
        case 5: lang = 6; break;
        case 6: lang = 3; break;
        default: lang = 1; break;
        }
        *(int*)(o + 0x26A4) = lang;
    }
    func_00452F60(o, func_002CC200);
    func_002C7FC0(self);
    return 1;
}
