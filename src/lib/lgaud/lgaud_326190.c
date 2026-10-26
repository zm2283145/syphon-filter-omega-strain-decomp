typedef struct { unsigned char b[8]; } ScfBytes8;
extern ScfBytes8 D_004914A0;
void sceScfSetT10kConfig(ScfBytes8 *p)
{
    D_004914A0 = *p;
}