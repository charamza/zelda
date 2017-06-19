#include "resource.h"

Resource::Resource()
{

}

void Resource::load()
{
    spritesheet.load("../Zelda/res/spritesheet.png");
    player.load("../Zelda/res/player.png");
    objects.load("../Zelda/res/objects.png");
    font.load("../Zelda/res/font.png");
    entityLog.load("../Zelda/res/log.png");
    entityNPC.load("../Zelda/res/npc.png");
    skeleton.load("../Zelda/res/skeleton.png");
}
