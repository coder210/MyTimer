#ifndef LUA_MYTIMER_H
#define LUA_MYTIMER_H

#include <QWidget>


#define BUTTON 0
#define LABEL 1

typedef void (*clickCallBack)();
typedef void (*dbClickCallBack)();

struct WidgetData
{
    QWidget* id;
    int type;
    clickCallBack ccb;
    dbClickCallBack dbccb;
};

QList<WidgetData>* luaMain(QWidget* parent);

#endif // LUA_MYTIMER_H



