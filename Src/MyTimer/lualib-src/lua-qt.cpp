#include "lua-qt.h"
#include <QDebug>
#include <QtMath>

#define PI 3.1415926535898

class LuaQt
{
public:
    static int debug(lua_State* L)
    {
        QString str(lua_tostring(L, 1));
        qDebug() << "lua print=" << str;
        return 0;
    }

    static int timeSpan2Datetime(lua_State* L)
    {
        int timeSpan = lua_tointeger(L, 1);
        int hour = timeSpan / 3600;
        int minute = (timeSpan - hour * 3600) / 60;
        int sec = (timeSpan - hour * 3600) % 60;
        QString str = QString("%0:%01:%02")
                .arg(hour, 2, 10, QLatin1Char('0'))
                .arg(minute, 2, 10, QLatin1Char('0'))
                .arg(sec, 2, 10, QLatin1Char('0'));
        lua_pushstring(L, str.toUtf8().constData());

        return 1;
    }

    static int getTargetPostion(lua_State* L)
    {
        int startX = lua_tointeger(L, 1);
        int startY = lua_tointeger(L, 2);
        int ang = lua_tointeger(L, 3);
        int r = lua_tointeger(L, 4);

        double sinValue = sin(ang * degree());
        double disY = sinValue * r;

        double cosValue = cos(ang * degree());
        double disX = cosValue * r;

        lua_newtable(L);
        lua_pushstring(L, "x");
        lua_pushinteger(L, startX + disX);
        lua_settable(L, -3);

        lua_pushstring(L, "y");
        lua_pushinteger(L, startY + disY);
        lua_settable(L, -3);

        return 1;
    }

    static double degree()
    {
        return PI / 180;
    }

};


//把需要用到的函数都放到注册表中, 统一进行注册
const luaL_Reg qtLib[] = {
    {"debug", LuaQt::debug},
    {"getTargetPostion", LuaQt::getTargetPostion},
    {"timeSpan2Datetime", LuaQt::timeSpan2Datetime},
    {NULL, NULL}
};


int luaopenQt(lua_State * L)
{
    luaL_newlib(L, qtLib);
    return 1;
}
