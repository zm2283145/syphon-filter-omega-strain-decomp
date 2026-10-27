#pragma cplusplus on
#include "types.h"

struct TeamRel {
    unsigned char hostile : 1;
};

extern "C" void cTeam_InitTeamData(TeamRel (*r)[16])
{
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            r[i][j].hostile = 0;
        for (j = 4; j < 16; j++)
            r[i][j].hostile = 1;
    }
    for (i = 4; i < 16; i++) {
        for (j = 0; j < 4; j++)
            r[i][j].hostile = 1;
        for (j = 4; j < 16; j++)
            r[i][j].hostile = 0;
    }
}
