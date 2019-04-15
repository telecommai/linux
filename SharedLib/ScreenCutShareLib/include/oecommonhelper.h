#ifndef COMMONHELPER_H
#define COMMONHELPER_H
#include <QString>
#include <QRect>

class QWidget;

class OECommonHelper
{
public:

    static void setStyle(const QString &style);

    static void setLanguagePack(const QString& language);

    static void moveCenter(QWidget* widget, QRect parentRect = {});

    static const float& getWindowWidthMultiplyingPower(void);

    static const float& getWindowHeightMultiplyingPower(void);

    static bool getSmallestWindowFromCursor(QRect &out_rect);

    static bool getCurrentWindowFromCursor(QRect &out_rect);

protected:

    static void upWindowSizeMultiplyingPower(void);


private:
    /// 窗口横向倍率
    static float widthMultiplyingPower_;
    /// 窗口纵向倍率
    static float heightMultiplyingPower_;
};

#endif /// COMMONHELPER_H
