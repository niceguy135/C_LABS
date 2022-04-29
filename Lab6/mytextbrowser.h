#ifndef MYTEXTBROWSER_H
#define MYTEXTBROWSER_H

#include <QTextBrowser>
#include <QColor>
#include <QString>
#include <iostream>

class MyTextBrowser : public QTextBrowser
{
    Q_OBJECT
public:
    MyTextBrowser(QWidget* parent);

    void writeRed(QString text);
    void writeGreen(QString text);
};

#endif // MYTEXTBROWSER_H
