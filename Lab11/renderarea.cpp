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

#include "renderarea.h"

#include <QPainter>
#include <QPainterPath>


RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    setMouseTracking(true);
    antialiased = false;
    transformed = false;
    pixmap.load(":/images/qt-logo.png");

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(300, 300);
}


QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}

void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
}


void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();

}


void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}


void RenderArea::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}



void RenderArea::paintEvent(QPaintEvent * /* event */)
{   
    QPainterPath path;
    path.moveTo(20, 80);
    path.lineTo(20, 30);
    path.cubicTo(80, 0, 50, 50, 80, 80);

    //const QRect form = QRect(250, 150, 300, 200);

    QPainter painter(this);
    painter.setBrush(brush);
    if (antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);

            painter.save();


        for(auto fig = Figs.begin(); fig != Figs.end(); fig++) {
            painter.setPen(fig->get()->pen);
            switch (fig->get()->getShape()) {

                case Figures::Trig :
                {
                    Trig* curFig = (Trig*)fig->get();
                    QPointF points[3] = {
                        curFig->upPoint,
                        curFig->leftPoint,
                        curFig->rightPoint,
                    };
                    painter.drawPolygon(points,3);
                    break;
                }

                case Figures::Square:
                {
                    Square* curFig = (Square*)fig->get();
                    painter.drawRect(curFig->leftUpPoint.x(),curFig->leftUpPoint.y(),curFig->wigth,curFig->height);
                    break;
                }

                case Figures::Circle:
                {
                    Circle* curFig = (Circle*)fig->get();
                    painter.drawEllipse(curFig->circlePoint,curFig->radius,curFig->radius);
                    break;
                }
            }

            painter.restore();
        }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}

void RenderArea::mouseMoveEvent(QMouseEvent *event) {
    QPointF position = event->position();
    bool flag = false;

    for(auto fig = Figs.rbegin(); fig != Figs.rend(); fig++) {
        if (flag) {
            switch (fig->get()->getShape()) {

                case Figures::Trig :
                {
                    Trig* curFig = (Trig*)fig->get();
                    curFig->pen = curFig->getOldPen();
                    break;
                }

                case Figures::Square:
                {
                    Square* curFig = (Square*)fig->get();
                    curFig->pen = curFig->getOldPen();
                    break;
                }

                case Figures::Circle:
                {
                    Circle* curFig = (Circle*)fig->get();
                    curFig->pen = curFig->getOldPen();
                    break;
                }
            }
            if (figureIsMoving) break;
        } else {
            switch (fig->get()->getShape()) {

                case Figures::Trig :
                {
                    Trig* curFig = (Trig*)fig->get();

                    if (curFig->inTheFigure(position)) {
                        curFig->pen = QPen(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
                        update();
                        flag = true;
                    } else {
                        curFig->pen = curFig->getOldPen();
                        update();
                    }
                    break;
                }

                case Figures::Square:
                {
                    Square* curFig = (Square*)fig->get();

                    if (curFig->inTheFigure(position)) {
                        curFig->pen = QPen(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
                        update();
                        flag = true;
                    } else {
                        curFig->pen = curFig->getOldPen();
                        update();
                    }
                    break;
                }

                case Figures::Circle:
                {
                Circle* curFig = (Circle*)fig->get();

                if (curFig->inTheFigure(position)) {
                    curFig->pen = QPen(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
                    update();
                    flag = true;
                } else {
                    curFig->pen = curFig->getOldPen();
                    update();
                }
                break;
                }
            }
        }
        if (figureIsMoving) break;
    }

    if ((event->buttons() & Qt::LeftButton) && figureIsMoving) {
        QPointF difference = position - startPos;

        switch (movingFigure->getShape()) {

            case Figures::Trig :
            {
                Trig* curFig = (Trig*)movingFigure;

                curFig->takeNewPos(difference);

                break;
            }

            case Figures::Square:
            {
                Square* curFig = (Square*)movingFigure;

                curFig->takeNewPos(difference);

                break;
            }

            case Figures::Circle:
            {
                Circle* curFig = (Circle*)movingFigure;

                curFig->takeNewPos(difference);

                break;
            }
        }

        startPos = position;
    } else if (!(event->buttons() & Qt::LeftButton) && figureIsMoving) {
        figureIsMoving = false;
        //movingFigure = NULL;

    }
}


void RenderArea::mousePressEvent(QMouseEvent *event) {
    QPointF position = event->position();
    bool flagForMenu = false;

    for(auto fig = Figs.rbegin(); fig != Figs.rend(); fig++) {
            if (figureIsMoving) break;
            switch (fig->get()->getShape()) {

                case Figures::Trig :
                {
                    Trig* curFig = (Trig*)fig->get();

                    if (curFig->inTheFigure(position)) {
                        movingFigure = fig->get();
                        if (event->buttons() & Qt::LeftButton) figureIsMoving = true;
                        else if (event->buttons() & Qt::RightButton) flagForMenu = true;
                        startPos = position;
                    }
                    break;
                }

                case Figures::Square:
                {
                    Square* curFig = (Square*)fig->get();

                    if (curFig->inTheFigure(position)) {
                        movingFigure = fig->get();
                        if (event->buttons() & Qt::LeftButton) figureIsMoving = true;
                        else if (event->buttons() & Qt::RightButton) flagForMenu = true;
                        startPos = position;
                    }
                    break;
                }

                case Figures::Circle:
                {
                    Circle* curFig = (Circle*)fig->get();

                    if (curFig->inTheFigure(position)) {
                        movingFigure = fig->get();
                        if (event->buttons() & Qt::LeftButton) figureIsMoving = true;
                        else if (event->buttons() & Qt::RightButton) flagForMenu = true;
                        startPos = position;
                    }
                break;
                }
            }
    }


    if (flagForMenu) {
        createMenu();
    }


}

void RenderArea::createMenu() {
    myMenu = new QMenu();

    QAction * editDevice = new QAction("Удалить", this);

    connect(editDevice, &QAction::triggered, this, &RenderArea::deleteFigure);

    myMenu->addAction(editDevice);

    myMenu->popup(RenderArea::cursor().pos());

}

void RenderArea::deleteFigure() {
    std::_List_iterator<std::unique_ptr<Figures>> thisOne;
    for(auto fig = Figs.begin(); fig != Figs.end(); fig++) {
        if (movingFigure == fig->get()) {
            thisOne = fig;
        }
    }
    Figs.erase(thisOne);
    update();
}
