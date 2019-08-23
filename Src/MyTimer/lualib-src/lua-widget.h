#ifndef LUA_WIDGET_H
#define LUA_WIDGET_H

extern "C"
{
   #include "lua.h"
   #include "lualib.h"
   #include "lauxlib.h"
}


int luaopenWidget(lua_State * L);

#endif // LUA_WIDGET_H
