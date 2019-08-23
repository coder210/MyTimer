#ifndef LUA_QT_H
#define LUA_QT_H

extern "C"
{
   #include "lua.h"
   #include "lualib.h"
   #include "lauxlib.h"
}

int luaopenQt(lua_State * L);

#endif // LUA_QT_H
