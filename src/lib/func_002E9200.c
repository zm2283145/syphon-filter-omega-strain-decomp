typedef struct {
    int state;
    int pad[7];
    unsigned int time;
    int a;
    int b;
} Ent_2E9200;
extern Ent_2E9200 D_005227F0[];
extern int func_00306018(unsigned int *);
extern void func_002DD328(int *);
int func_002E9200(void)
{
    unsigned int now;
    unsigned int i;
    func_00306018(&now);
    for (i = 0; i < 0x100; i++) {
        if (D_005227F0[i].state == 2 && now - D_005227F0[i].time > 30000) {
            if (D_005227F0[i].b) {
                func_002DD328(&D_005227F0[i].b);
                D_005227F0[i].b = 0;
            }
            if (D_005227F0[i].a) {
                func_002DD328(&D_005227F0[i].a);
                D_005227F0[i].a = 0;
            }
            D_005227F0[i].state = 0;
        }
    }
    return 0;
}

