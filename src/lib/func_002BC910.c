typedef struct { int state; int x4; int x8; int pad[5]; int x20; int x24; } CtxC910;
extern CtxC910 D_0051ECC0;
extern int sceMc2DeleteSocket(int);
extern void initialize_mc2_socket(void);
int delete_mc2_socket(void)
{
    D_0051ECC0.x24--;
    if (D_0051ECC0.x24 <= 0) {
        if (D_0051ECC0.x4 != -1) {
            sceMc2DeleteSocket(D_0051ECC0.x20);
        }
        initialize_mc2_socket();
    }
    return 0;
}
