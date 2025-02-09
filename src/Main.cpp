#include "Core/Ls6502Server.h"

int main()
{
    ls6052::Ls6502Server ls6502Server;

    ls6502Server.init();
    ls6502Server.run();
    ls6502Server.shutdown();
}
