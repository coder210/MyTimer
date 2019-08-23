#ifndef LUA_ANIMATION_H
#define LUA_ANIMATION_H

extern "C"
{
   #include "lua.h"
   #include "lualib.h"
   #include "lauxlib.h"
}

int luaopenAnimation(lua_State * L);

#endif
