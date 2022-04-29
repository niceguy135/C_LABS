#include "mytextbrowser.h"

MyTextBrowser::MyTextBrowser(QWidget* parent)
    :QTextBrowser(parent)
{

}

void MyTextBrowser::writeRed(QString text) {
    auto preColor = this->textColor();
    this->setTextColor(Qt::red);
    this->append(text);
    this->setTextColor(preColor);
}

void MyTextBrowser::writeGreen(QString text) {
    auto preColor = this->textColor();
    this->setTextColor(Qt::green);
    this->append(text);
    this->setTextColor(preColor);
}
