#ifndef MYTIMERWIDGET_H
#define MYTIMERWIDGET_H

#include <QWidget>
#include <QPoint>

class MyTimerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyTimerWidget(QWidget *parent = 0);
    ~MyTimerWidget();

private:
    bool eventFilter(QObject * sender, QEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    bool _pressed = false;
    QPoint _point;

signals:

public slots:
};

#endif // MYTIMERWIDEGET_H
