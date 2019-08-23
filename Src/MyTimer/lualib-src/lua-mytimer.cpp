#include "lua-mytimer.h"
#include "../lualib-src/lua-animation.h"
#include "../lualib-src/lua-button.h"
#include "../lualib-src/lua-label.h"
#include "../lualib-src/lua-widget.h"
#include "../lualib-src/lua-qt.h"
#include <QDebug>


extern "C"
{
   #include "lua.h"
   #include "lualib.h"
   #include "lauxlib.h"
}





QList<WidgetData>* luaMain(QWidget* parent)
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    luaL_requiref(L, "animation", luaopenAnimation, 1);
    luaL_requiref(L, "button", luaopenButton, 1);
    luaL_requiref(L, "label", luaopenLabel, 1);
    luaL_requiref(L, "widget", luaopenWidget, 1);
    luaL_requiref(L, "qt", luaopenQt, 1);

    if (luaL_dofile(L, "mytimer.lua") != 0)
    {
        qDebug() << lua_tostring(L, -1);
        return NULL;
    }

    lua_getglobal(L, "start");
    lua_pushinteger(L, (int)parent);
    lua_pcall(L, 1, 1, 0);
    if (lua_tointeger(L, -1) == 1)
    {
        qDebug() << "call start func ok";
    }
    else
    {
        qDebug() << "call start func error";
    }

    QList<WidgetData>* widgetDataList = new QList<WidgetData>;
    return widgetDataList;
}



