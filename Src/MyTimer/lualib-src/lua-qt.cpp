#include "lua-qt.h"
#include <QDebug>

class LuaQt
{
public:
    static int debug(lua_State* L)
    {
        QString str(lua_tostring(L, 1));
        qDebug() << "lua print=" << str;
        return 0;
    }
};


//把需要用到的函数都放到注册表中, 统一进行注册
const luaL_Reg qtLib[] = {
    {"debug", LuaQt::debug},
    {NULL, NULL}
};


int luaopenQt(lua_State * L)
{
    luaL_newlib(L, qtLib);
    return 1;
}
