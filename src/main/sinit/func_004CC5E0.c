extern char* D_004A0318;
extern float D_004A0320;
extern float D_004A0328;
extern float D_004A0330;
extern float D_004A0338;
extern float D_004A0340;
extern float D_004A0348;
extern float D_004A0350;
extern float D_004A0358;
extern float D_004A0368;
extern float D_004A0370;
extern float D_004A03B0;
extern float D_004A03B8;
extern char D_004A03C8[];
extern char D_004A03D0[];
extern char D_004A03D8[];
extern float D_004A03E0;
extern float D_004A03F0[4];
extern float D_004A0400;
extern float D_004A0408;
extern float D_004A0410;
extern float D_004A0418;
extern float D_004A0420;
extern float D_004A0428;
extern float D_004A0430;
extern char D_004A0500[];
extern char D_004A0510[];
extern char D_004A0518[];
extern char D_004A0520[];
extern char D_004DAD58[];
extern char* D_004F4FE0;

static inline void Tag4Copy(char* d, const char* s) {
    unsigned char end = 0;
    unsigned int i;
    for (i = 0; i < 4; i++) {
        char c = s[i];
        if (!c) end = 1;
        d[i] = end ? (char)0 : c;
    }
}

void func_004CC5E0(void) {
    D_004A0318 = D_004A0500;
    D_004A0320 = 1.74f;
    D_004A0328 = 0.0025000002f;
    D_004A0330 = 0.5f;
    D_004A0370 = 0.5f;
    D_004A0338 = 1.55f;
    D_004A0340 = 0.75f;
    D_004A0348 = 15.0f;
    D_004A0350 = 0.35f;
    D_004A0358 = 5.0f;
    D_004F4FE0 = D_004DAD58;
    D_004A0368 = 0.25f;
    D_004A03B0 = 2.5f;
    D_004A03B8 = 4.5f;
    Tag4Copy(D_004A03C8, D_004A0510);
    Tag4Copy(D_004A03D0, D_004A0518);
    Tag4Copy(D_004A03D8, D_004A0520);
    D_004A03F0[0] = 0.0f;
    D_004A03F0[1] = 0.0f;
    D_004A03E0 = 1.74f;
    D_004A03F0[2] = 0.5f;
    D_004A0400 = 12.0f;
    D_004A0408 = 22.0f;
    D_004A0410 = 7.0f;
    D_004A0420 = 0.5f;
    D_004A03F0[3] = 0.0f;
    D_004A0418 = 1.0f;
    D_004A0428 = 0.75f;
    D_004A0430 = 1.0f;
}

