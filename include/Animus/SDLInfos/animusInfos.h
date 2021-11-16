#ifndef ANIMUSINFOS
#define ANIMUSINFOS

void Init_AnimusInfos();

int MAX_SCENE;

struct AnimusInfos
{
    int MAX_SCENE;
};
typedef struct AnimusInfos AnimusInfos;

extern AnimusInfos _AnimusInfos;

#endif