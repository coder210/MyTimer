#include "lua-button.h"
#include <QPushButton>
#include <QString>
#include <QPoint>
#include <QDebug>


class LuaButton
{
public:
    static int newButton(lua_State* L)
    {
        QPushButton* button = new QPushButton;
        lua_pushinteger(L, (int)button);
        return 1;
    }

    static int setText(lua_State* L)
    {
        QPushButton* button = (QPushButton*)lua_tointeger(L, 1);
        QString str(lua_tostring(L, 2));
        button->setText(str);
        return 0;
    }


    static int getText(lua_State* L)
    {
        QPushButton* button = (QPushButton*)lua_tointeger(L, 1);
        QString txt = button->text();
        lua_pushstring(L, txt.toUtf8().constData());
        return 1;
    }

    static int setClickEvent(lua_State* L)
    {
        QPushButton* button = (QPushButton*)lua_tointeger(L, 1);
        QString funcName(lua_tostring(L, 2));
        QObject::connect(button, &QPushButton::clicked, [=](){
            lua_getglobal(L, funcName.toUtf8().constData());
            lua_pcall(L, 0, 0, 0);
            if (lua_tointeger(L, -1) != 1)
            {
                qDebug() << funcName << " func call error";
            }
        });

        return 0;
    }


};

//把需要用到的函数都放到注册表中, 统一进行注册
const luaL_Reg buttonLib[] = {
    {"newButton", LuaButton::newButton},
    {"setText", LuaButton::setText},
    {"getText", LuaButton::getText},
    {"setClickEvent", LuaButton::setClickEvent},
    {NULL, NULL}
};


int luaopenButton(lua_State * L)
{
    luaL_newlib(L, buttonLib);
    return 1;
}








