extern char D_004FFB50[];
extern unsigned char D_00572400;
extern char D_00587310[], D_005874B0[], D_00587650[], D_005877F0[], D_00587990[];
void Game_EndLevel(void*, int);
extern int func_00465C50(void*, void*);
extern int func_00465B50(void*, void*);
extern int func_00465A50(void*, void*, unsigned short, int, int);
int func_004653B0(void* self, void* b, unsigned short type, int idx, int e)
{
    if (type == 0x1A && idx == 0x667) {
        Game_EndLevel(D_004FFB50, D_00572400 ? 2 : 3);
        return 1;
    }
    if (type == 0x1A && idx == 0x668) {
        Game_EndLevel(D_004FFB50, 3);
        return 1;
    }
    if (type == 0x10 || type == 0x11) {
        void* t = 0;
        switch (idx) {
        case 5: t = D_00587310; break;
        case 2: case 3: case 6: t = D_005874B0; break;
        case 7: t = D_00587650; break;
        case 8: t = D_005877F0; break;
        case 9: t = D_00587990; break;
        }
        if (t) {
            int r;
            if (type == 0x10) r = func_00465C50(b, t);
            else r = func_00465B50(b, t);
            return r;
        }
    }
    return func_00465A50(self, b, type, idx, e);
}
