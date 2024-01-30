#include "Public/UnoGame.h"

int main(int argc, char* argv[])
{
    UnoGame Game{};
    Game.Start();

    while (Game.IsRunning())
    {
        Game.Update();
    }
    
    return 0;
}
