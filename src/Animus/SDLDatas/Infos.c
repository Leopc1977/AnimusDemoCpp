#include "animus/SDLDatas/SDLInfos.hpp"
#include "animus/SDLDatas/windowInfos.hpp"
#include "animus/SDLDatas/rendererInfos.hpp"
#include "animus/SDLDatas/animusInfos.hpp"

#include <stdbool.h>

#include "animus/SDLDatas/Infos.hpp"

void InitParameters(){
    Init_AnimusInfos();
    Init_SDLInfos();
    Init_WindowInfos();
    Init_RendererInfos();
}