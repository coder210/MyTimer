#include <QMouseEvent>
#include <QPushButton>

#include "MyTimerWidget.h"
#include "lualib-src/lua-mytimer.h"
#include <QObject>
#include <QDebug>
#include "MyLabel.h"

MyTimerWidget::MyTimerWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint|windowFlags());
    this->setAttribute(Qt::WA_TranslucentBackground);

    luaMain(this);

}

MyTimerWidget::~MyTimerWidget()
{

}



bool MyTimerWidget::eventFilter(QObject * sender, QEvent * event)
{

    return QWidget::eventFilter(sender, event);
}


void MyTimerWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    _pressed = false;
}

void MyTimerWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        _pressed = true;
        _point = event->pos();
    }
}

void MyTimerWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (_pressed)
    {
        move(event->pos() - _point + pos());
    }
}
