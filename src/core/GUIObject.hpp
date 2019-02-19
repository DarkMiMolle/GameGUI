#pragma once

#include <string_view>
#include "coreGlobal.hpp"

#define DECLARE_GUIOBJECT(name)                                 \
    public:                                                     \
    static constexpr std::string_view className()               \
    {                                                           \
        return std::string_view(#name);                         \
    }


OPEN_CORE_NAMESPACES

class GUIObject
{
    DECLARE_GUIOBJECT(GUIObject)
public:
    GUIObject();
    virtual ~GUIObject() = default;


};

CLOSE_CORE_NAMESPACES
