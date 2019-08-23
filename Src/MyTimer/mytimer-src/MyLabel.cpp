#include "MyLabel.h"
#include <QDebug>

MyLabel::MyLabel(QWidget* parent)
    :QLabel(parent)
{

}

MyLabel::MyLabel(const QString& text,QWidget* parent)
    :QLabel(text, parent)
{
}


bool MyLabel::event(QEvent *e)
{
    if (e->type() == QEvent::MouseButtonDblClick)
    {
        emit this->dbClicked();
    }

    return QLabel::event(e);
}



