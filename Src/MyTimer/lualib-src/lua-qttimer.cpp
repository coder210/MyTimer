#include "lua-qttimer.h"
#include <QDebug>
#include <QTimer>
#include <QObject>
#include <QString>
#include <QLatin1Char>

class LuaTimer
{
public:
    static int newTimer(lua_State* L)
    {
        QTimer* timer = new QTimer;
        lua_pushinteger(L, (int)timer);
        return 1;
    }

    static int setTimeoutEvent(lua_State* L)
    {
        QTimer* timer = (QTimer*)lua_tointeger(L, 1);
        QString funcName(lua_tostring(L, 2));
        QObject::connect(timer, &QTimer::timeout, [=](){
            lua_getglobal(L, funcName.toUtf8().constData());
            lua_pcall(L, 0, 0, 0);
            if (lua_tointeger(L, -1) != 1)
            {
                qDebug() << funcName << " func call error";
            }
        });

        return 0;
    }



    static int start(lua_State* L)
    {
        QTimer* timer = (QTimer*)lua_tointeger(L, 1);
        int msec = lua_tointeger(L, 2);
        timer->start(msec);
        return 0;
    }


    static int stop(lua_State* L)
    {
        QTimer* timer = (QTimer*)lua_tointeger(L, 1);
        timer->stop();
        return 0;
    }

    static int setParent(lua_State* L)
    {
        QTimer* timer = (QTimer*)lua_tointeger(L, 1);
        QObject* parent = (QObject*)lua_tointeger(L, 2);
        timer->setParent(parent);
        return 0;
    }
};


//把需要用到的函数都放到注册表中, 统一进行注册
const luaL_Reg qtTimerLib[] = {
    {"newTimer", LuaTimer::newTimer},
    {"setTimeoutEvent", LuaTimer::setTimeoutEvent},
    {"start", LuaTimer::start},
    {"stop", LuaTimer::stop},
    {"setParent", LuaTimer::setParent},
    {NULL, NULL}
};


int luaopenQtTimer(lua_State * L)
{
    luaL_newlib(L, qtTimerLib);
    return 1;
}
