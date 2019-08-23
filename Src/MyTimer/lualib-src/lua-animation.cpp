#include "lua-animation.h"
#include <QPropertyAnimation>
#include <QString>
#include <QPoint>

class LuaPropertyAnimation
{
public:
    static int newPropertyAnimation(lua_State* L)
    {
        QPropertyAnimation* animation = new QPropertyAnimation;
        lua_pushinteger(L, (int)animation);
        return 1;
    }


    static int setTargetObject(lua_State* L)
    {
        QPropertyAnimation* animation = (QPropertyAnimation*)lua_tointeger(L, 1);
        QObject* object = (QObject*)lua_tointeger(L, 2);
        animation->setTargetObject(object);
        return 0;
    }


    static int setPropertyName(lua_State* L)
    {
        QPropertyAnimation* animation = (QPropertyAnimation*)lua_tointeger(L, 1);
        animation->setPropertyName(lua_tostring(L, 2));
        return 0;
    }


    static int setDuration(lua_State* L)
    {
        QPropertyAnimation* animation = (QPropertyAnimation*)lua_tointeger(L, 1);
        int duration = lua_tointeger(L, 2);
        animation->setDuration(duration);
        return 0;
    }


    static int setStartValue(lua_State* L)
    {
        QPropertyAnimation* animation = (QPropertyAnimation*)lua_tointeger(L, 1);
        int x = lua_tointeger(L, 2);
        int y = lua_tointeger(L, 3);
        animation->setStartValue(QPoint(x, y));
        return 0;
    }


    static int setEndValue(lua_State* L)
    {
        QPropertyAnimation* animation = (QPropertyAnimation*)lua_tointeger(L, 1);
        int x = lua_tointeger(L, 2);
        int y = lua_tointeger(L, 3);
        animation->setEndValue(QPoint(x, y));
        return 0;
    }

    static int start(lua_State* L)
    {
        QPropertyAnimation* animation = (QPropertyAnimation*)lua_tointeger(L, 1);
        animation->start();
        return 0;
    }
};



//把需要用到的函数都放到注册表中, 统一进行注册
const luaL_Reg animationLib[] = {
    {"newPropertyAnimation", LuaPropertyAnimation::newPropertyAnimation},
    {"setTargetObject", LuaPropertyAnimation::setTargetObject},
    {"setPropertyName", LuaPropertyAnimation::setPropertyName},
    {"setDuration", LuaPropertyAnimation::setDuration},
    {"setStartValue", LuaPropertyAnimation::setStartValue},
    {"setEndValue", LuaPropertyAnimation::setEndValue},
    {"start", LuaPropertyAnimation::start},
    {NULL, NULL}
};


int luaopenAnimation(lua_State * L)
{
    //首先创建一个 table, 然后把成员函数名做 key, 成员函数作为 value 放入该 table 中
    luaL_newlib(L, animationLib);
    return 1;
}



