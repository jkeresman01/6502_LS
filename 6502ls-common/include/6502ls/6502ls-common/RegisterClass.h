#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "ClassRegistry.h"


////////////////////////////////////////////////////////////
#define REGISTER_CLASS(INTERFACE, CLASSNAME)                                                           \
    namespace                                                                                          \
    {                                                                                                  \
    struct CLASSNAME##AutoRegister                                                                     \
    {                                                                                                  \
        CLASSNAME##AutoRegister()                                                                      \
        {                                                                                              \
            ls6502::ClassRegistry::getInstance()                                                       \
                .registerClass<INTERFACE>(#CLASSNAME, []() { return std::make_shared<CLASSNAME>(); }); \
        }                                                                                              \
    };                                                                                                 \
    static CLASSNAME##AutoRegister autoRegister_##CLASSNAME;                                           \
    }
