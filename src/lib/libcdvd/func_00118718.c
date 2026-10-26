typedef struct { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; } SemaParam8718;
extern int CreateSema(SemaParam8718 *);
extern int D_004878A8;
int D_004878AC = -1;
int D_004878B0 = -1;
extern volatile int D_004878A0;
extern volatile int D_004878B4;

static inline SemaParam8718 *publish(SemaParam8718 *p,int *where,int value){/* Prepare next semaphore argument before publishing its predecessor. */ __asm__ volatile("" : "+r"(p));*where=value;return p;}
void cmd_sem_init(void)
{
    SemaParam8718 p; int value;
    if (D_004878A8 == -1 || D_004878AC == -1 || D_004878B0 == -1) {
        p.option = 0;
        p.initCount = 1;
        p.maxCount = 1;
        value = CreateSema(&p);
        value = CreateSema(publish(&p,&D_004878A8,value));
        D_004878B0 = CreateSema(publish(&p,&D_004878AC,value));
        p.initCount = 0;
        D_004878A0 = CreateSema(&p);
        D_004878B4 = 0;
    }
}


