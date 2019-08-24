#include "lua-db.h"
#include <QSqlDatabase>
#include <QString>
#include <QDebug>

// 数据库操作
class LuaDB
{
public:
    static int open(lua_State* L)
    {
        QSqlDatabase::database();
        const char* dbType = lua_tostring(L, 1);
        QString connectString(lua_tostring(L, 2));
        QSqlDatabase db = QSqlDatabase::addDatabase(dbType);
        db.setDatabaseName(connectString);
        if (db.open())
        {
            lua_pushinteger(L, (int)&db);

        }
        else
        {
            lua_pushinteger(L, 0);
        }

        return 1;
    }



};


//把需要用到的函数都放到注册表中, 统一进行注册
const luaL_Reg dbLib[] = {
    {"open", LuaDB::open},
    {NULL, NULL}
};




int luaopenDB(lua_State * L)
{
    luaL_newlib(L, dbLib);
    return 1;
}
