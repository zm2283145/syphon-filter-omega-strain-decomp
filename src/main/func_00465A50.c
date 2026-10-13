extern char D_00586610[], D_005867B0[], D_005862D0[], D_00586470[], D_00586950[];
extern int func_00465C50(void*, void*);
extern int func_00465B50(void*, void*);
extern int func_00414A80(void*, void*, unsigned short, int, int);
int func_00465A50(void* self, void* b, unsigned short type, int idx, int e)
{
    if (type == 0x10 || type == 0x11) {
        void* t = 0;
        switch (idx) {
        case 0: t = D_00586610; break;
        case 1: t = D_005867B0; break;
        case 2: t = D_005862D0; break;
        case 3: t = D_00586470; break;
        case 4: t = D_00586950; break;
        }
        if (t) {
            int r;
            if (type == 0x10) r = func_00465C50(b, t);
            else r = func_00465B50(b, t);
            return r;
        }
    }
    return func_00414A80(self, b, type, idx, e);
}
