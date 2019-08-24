#ifndef LUA_QTTIMER_H
#define LUA_QTTIMER_H

extern "C"
{
   #include "lua.h"
   #include "lualib.h"
   #include "lauxlib.h"
}

int luaopenQtTimer(lua_State * L);

#endif // LUA_QTTIMER_H
