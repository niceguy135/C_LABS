/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <memory.h>
#include <QMouseEvent>
#include <iostream>
#include <QPen>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QComboBox;
class QLabel;
class QSpinBox;
class QPushButton;
QT_END_NAMESPACE
class RenderArea;

//! [0]
class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

private slots:
    void penChanged();
    void brushChanged();

    //реализация моих методов
    void plotRectFun();

    void plotCircleFun();

    void plotTrigFun();

private:
    RenderArea *renderArea;
    QLabel *shapeLabel;
    QLabel *penWidthLabel;
    QLabel *penStyleLabel;
    QLabel *penCapLabel;
    QLabel *penJoinLabel;
    QLabel *brushStyleLabel;
    QComboBox *shapeComboBox;
    QSpinBox *penWidthSpinBox;
    QComboBox *penStyleComboBox;
    QComboBox *penCapComboBox;
    QComboBox *penJoinComboBox;
    QComboBox *brushStyleComboBox;
    QCheckBox *antialiasingCheckBox;
    QCheckBox *transformationsCheckBox;
    //мои свойства

    //прямоугольники
    QSpinBox *leftUpPointX;
    QSpinBox *leftUpPointY;
    QLabel *leftUpPointXLabel;
    QLabel *leftUpPointYLabel;
    QSpinBox *weights;
    QSpinBox *heights;
    QLabel *weightLabel;
    QLabel *heightLabel;
    QPoint leftUpPoint;
    float width;
    float height;
    QPushButton *plotRect;
    QLabel *rectLabel;

    //круги
    QSpinBox *circleCenterX;
    QSpinBox *circleCenterY;
    QLabel *circleCenterXLabel;
    QLabel *circleCenterYLabel;
    QSpinBox *circleRadius;
    QLabel *circleRadiusLabel;
    QPoint circleCenter;
    float radius;
    QPushButton *plotCircle;
    QLabel *circleLabel;

    //треугольники
    QSpinBox *upPointX;
    QSpinBox *upPointY;
    QSpinBox *leftPointX;
    QSpinBox *leftPointY;
    QSpinBox *rightPointX;
    QSpinBox *rightPointY;
    QLabel *upPointXLabel;
    QLabel *upPointYLabel;
    QLabel *leftPointXLabel;
    QLabel *leftPointYLabel;
    QLabel *rightPointXLabel;
    QLabel *rightPointYLabel;
    QPoint upPoint;
    QPoint leftPoint;
    QPoint rightPoint;
    QPushButton *plotTrig;
    QLabel *trigLabel;


    QPushButton *clear;
    QPen curPen;
};
//! [0]

#endif // WINDOW_H
