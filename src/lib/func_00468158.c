typedef struct { char w[0xC4]; } SA;
typedef struct { char w[0xEC]; } SB;
extern int D_00497E24;
extern SA D_00587E08;
extern SB D_00587ED0;
void func_00468158(void* dst)
{
    switch (D_00497E24) {
    case 44:
        *(SA*)dst = D_00587E08;
        break;
    case 18:
        *(SB*)dst = D_00587ED0;
        break;
    }
}

