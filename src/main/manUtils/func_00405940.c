typedef struct { __int128 a; __int128 b; } HM_Pair;
typedef struct { __int128 slot0; __int128 slot1; __int128 q20; __int128 q30; HM_Pair pairs[32]; } HM_Pack;
extern char D_004BE910[];
extern char D_004BE920[];
extern char D_0055DDA0[];
extern char D_0057124C[];
extern int String_CompareN(char* a, char* b, int n);
extern void String_Copy(void* d, char* s);
extern int Appearance_GetBodyKind(HM_Pack* p);
extern int MeshCache_Load(void* cache, __int128 name, void* ctx, void* arg);
/* Requests the hard mesh (slot 2) when asked, then every pair's part mesh; returns the part count. */
int Appearance_RequestHardMesh(HM_Pack* p, int hard, void* arg)
{
    int i;
    if (hard) {
        if (String_CompareN((char*)&p->q20 + 1, D_004BE910, 4) == 0) {
            MeshCache_Load(D_0055DDA0, p->q20, D_0057124C, arg);
        } else {
            String_Copy(&p->q20, D_004BE920);
            if (Appearance_GetBodyKind(p) == 0)
                *(char*)&p->q20 = '2';
            else
                *(char*)&p->q20 = '1';
            MeshCache_Load(D_0055DDA0, p->q20, D_0057124C, arg);
        }
    }
    for (i = 0; p->pairs[i].a; i++)
        MeshCache_Load(D_0055DDA0, p->pairs[i].a, D_0057124C, arg);
    return i;
}
