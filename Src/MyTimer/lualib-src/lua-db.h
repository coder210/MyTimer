#ifndef LUA_DB_H
#define LUA_DB_H

extern "C"
{
   #include "lua.h"
   #include "lualib.h"
   #include "lauxlib.h"
}

int luaopenDB(lua_State * L);


#endif // LUA_DB_H
