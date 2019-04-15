#ifndef OEAMPLIFIER_H
#define OEAMPLIFIER_H
#include <memory>
#include <QWidget>

class OEAmplifier : public QWidget
{
    Q_OBJECT
public:
    explicit OEAmplifier(std::shared_ptr<QPixmap> originPainting, QWidget *parent = 0);

signals:

public slots:

    void onSizeChange(int w, int h);

    void onPostionChange(int x, int y);

protected:

    virtual void paintEvent(QPaintEvent *);

private:
    /// 外部组件的大小信息
    QSize screenSize_;
    /// 鼠标的位置
    QPoint cursorPoint_;
    /// 取色放大器的边长
    int sideLength_;
    /// 放大区的高度
    int imageHeight_;
    /// 屏幕原画
    std::shared_ptr<QPixmap> originPainting_;

};

#endif /// OEAMPLIFIER_H
