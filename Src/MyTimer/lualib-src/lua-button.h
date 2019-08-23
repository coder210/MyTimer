#ifndef LUA_BUTTON_H
#define LUA_BUTTON_H


extern "C"
{
   #include "lua.h"
   #include "lualib.h"
   #include "lauxlib.h"
}

int luaopenButton(lua_State * L);

#endif // LUA_BUTTON_H
