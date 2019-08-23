#ifndef MYLABEL_H
#define MYLABEL_H
#include <QLabel>
#include <QEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget *parent=0);
    MyLabel(const QString &text,QWidget *parent=0);
    ~MyLabel(){}

    bool event(QEvent *event);


signals:
    void dbClicked();

public slots:
};



#endif // MYLABEL_H
