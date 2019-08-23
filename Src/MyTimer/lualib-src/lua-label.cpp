#include "lua-label.h"
#include "mytimer-src/MyLabel.h"
#include <QString>
#include <QPoint>
#include <QDebug>


class LuaLabel
{
public:
    static int newLabel(lua_State* L)
    {
        MyLabel* label = new MyLabel;
        lua_pushinteger(L, (int)label);
        return 1;
    }


    static int setText(lua_State* L)
    {
        MyLabel* label = (MyLabel*)lua_tointeger(L, 1);
        QString str(lua_tostring(L, 2));
        label->setText(str);
        return 0;
    }

    static int setTextCenter(lua_State* L)
    {
         MyLabel* label = (MyLabel*)lua_tointeger(L, 1);
         label->setAlignment(Qt::AlignCenter);
         return 0;
    }

    static int setDbClicked(lua_State* L)
    {
         MyLabel* label = (MyLabel*)lua_tointeger(L, 1);
         QString funcName(lua_tostring(L, 2));
         QObject::connect(label, &MyLabel::dbClicked, [=](){
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
const luaL_Reg labelLib[] = {
    {"newLabel", LuaLabel::newLabel},
    {"setText", LuaLabel::setText},
    {"setTextCenter", LuaLabel::setTextCenter},
    {"setDbClicked", LuaLabel::setDbClicked},
    {NULL, NULL}
};


int luaopenLabel(lua_State * L)
{
    //首先创建一个 table, 然后把成员函数名做 key, 成员函数作为 value 放入该 table 中
    luaL_newlib(L, labelLib);
    return 1;
}






