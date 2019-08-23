#ifndef LUA_LABEL_H
#define LUA_LABEL_H


extern "C"
{
   #include "lua.h"
   #include "lualib.h"
   #include "lauxlib.h"
}

int luaopenLabel(lua_State * L);



#endif // LUA_LABEL_H
