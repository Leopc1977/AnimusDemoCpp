#ifndef RENDERERINFOS
#define RENDERERINFOS

int Index;
int32_t rendererInitFlags;

void Init_RendererInfos();

struct RendererInfos
{
    int Index;
    int32_t rendererInitFlags;   
};
typedef struct RendererInfos RendererInfos;

extern RendererInfos _RendererInfos;

#endif