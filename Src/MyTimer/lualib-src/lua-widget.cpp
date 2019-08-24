#include "lua-widget.h"
#include <QWidget>
#include <QString>
#include <QPoint>
#include <QDebug>


class LuaWidget
{
public:

    static int getWidth(lua_State* L)
    {
        QWidget* widget = (QWidget*)lua_tointeger(L, 1);
        int w = widget->width();
        lua_pushinteger(L, w);
        return 1;
    }


    static int getHeight(lua_State* L)
    {
        QWidget* widget = (QWidget*)lua_tointeger(L, 1);
        int h = widget->height();
        lua_pushinteger(L, h);
        return 1;
    }

    static int setFixedSize(lua_State* L)
    {
        QWidget* widget = (QWidget*)lua_tointeger(L, 1);
        int w = lua_tointeger(L, 2);
        int h = lua_tointeger(L, 3);
        widget->setFixedSize(w, h);
        return 0;
    }

    static int setStyleSheet(lua_State* L)
    {
        QWidget* widget = (QWidget*)lua_tointeger(L, 1);
        QString str(lua_tostring(L, 2));
        widget->setStyleSheet(str);
        return 0;
    }

    static int move(lua_State* L)
    {
        QWidget* widget = (QWidget*)lua_tointeger(L, 1);
        int x = lua_tointeger(L, 2);
        int y = lua_tointeger(L, 3);
        widget->move(QPoint(x, y));
        return 0;
    }

    static int close(lua_State* L)
    {
        QWidget* widget = (QWidget*)lua_tointeger(L, 1);
        widget->close();
        return 0;
    }

    static int setParent(lua_State* L)
    {
        QWidget* widget = (QWidget*)lua_tointeger(L, 1);
        QWidget* parent = (QWidget*)lua_tointeger(L, 2);
        widget->setParent(parent);
        return 0;
    }
};


//把需要用到的函数都放到注册表中, 统一进行注册
const luaL_Reg widgetLib[] = {
    {"getWidth", LuaWidget::getWidth},
    {"getHeight", LuaWidget::getHeight},
    {"setFixedSize", LuaWidget::setFixedSize},
    {"setStyleSheet", LuaWidget::setStyleSheet},
    {"move", LuaWidget::move},
    {"close", LuaWidget::close},
    {"setParent", LuaWidget::setParent},
    {NULL, NULL}
};


int luaopenWidget(lua_State * L)
{
    //首先创建一个 table, 然后把成员函数名做 key, 成员函数作为 value 放入该 table 中
    luaL_newlib(L, widgetLib);
    return 1;
}





