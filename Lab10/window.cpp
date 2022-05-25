#include "renderarea.h"
#include "window.h"

#include <QtWidgets>


const int IdRole = Qt::UserRole;



Window::Window()
{
    setMouseTracking(true);
    renderArea = new RenderArea;



    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(0, 20);
    penWidthSpinBox->setSpecialValueText(tr("0 (cosmetic pen)"));

    penWidthLabel = new QLabel(tr("Pen &Width:"));
    penWidthLabel->setBuddy(penWidthSpinBox);



    penStyleComboBox = new QComboBox;
    penStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidLine));
    penStyleComboBox->addItem(tr("Dash"), static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem(tr("Dot"), static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem(tr("Dash Dot"), static_cast<int>(Qt::DashDotLine));
    penStyleComboBox->addItem(tr("Dash Dot Dot"), static_cast<int>(Qt::DashDotDotLine));
    penStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoPen));

    penStyleLabel = new QLabel(tr("&Pen Style:"));
    penStyleLabel->setBuddy(penStyleComboBox);

    penCapComboBox = new QComboBox;
    penCapComboBox->addItem(tr("Flat"), Qt::FlatCap);
    penCapComboBox->addItem(tr("Square"), Qt::SquareCap);
    penCapComboBox->addItem(tr("Round"), Qt::RoundCap);

    penCapLabel = new QLabel(tr("Pen &Cap:"));
    penCapLabel->setBuddy(penCapComboBox);

    penJoinComboBox = new QComboBox;
    penJoinComboBox->addItem(tr("Miter"), Qt::MiterJoin);
    penJoinComboBox->addItem(tr("Bevel"), Qt::BevelJoin);
    penJoinComboBox->addItem(tr("Round"), Qt::RoundJoin);

    penJoinLabel = new QLabel(tr("Pen &Join:"));
    penJoinLabel->setBuddy(penJoinComboBox);



    brushStyleComboBox = new QComboBox;
    brushStyleComboBox->addItem(tr("Linear Gradient"),
            static_cast<int>(Qt::LinearGradientPattern));
    brushStyleComboBox->addItem(tr("Radial Gradient"),
            static_cast<int>(Qt::RadialGradientPattern));
    brushStyleComboBox->addItem(tr("Conical Gradient"),
            static_cast<int>(Qt::ConicalGradientPattern));
    brushStyleComboBox->addItem(tr("Texture"), static_cast<int>(Qt::TexturePattern));
    brushStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidPattern));
    brushStyleComboBox->addItem(tr("Horizontal"), static_cast<int>(Qt::HorPattern));
    brushStyleComboBox->addItem(tr("Vertical"), static_cast<int>(Qt::VerPattern));
    brushStyleComboBox->addItem(tr("Cross"), static_cast<int>(Qt::CrossPattern));
    brushStyleComboBox->addItem(tr("Backward Diagonal"), static_cast<int>(Qt::BDiagPattern));
    brushStyleComboBox->addItem(tr("Forward Diagonal"), static_cast<int>(Qt::FDiagPattern));
    brushStyleComboBox->addItem(tr("Diagonal Cross"), static_cast<int>(Qt::DiagCrossPattern));
    brushStyleComboBox->addItem(tr("Dense 1"), static_cast<int>(Qt::Dense1Pattern));
    brushStyleComboBox->addItem(tr("Dense 2"), static_cast<int>(Qt::Dense2Pattern));
    brushStyleComboBox->addItem(tr("Dense 3"), static_cast<int>(Qt::Dense3Pattern));
    brushStyleComboBox->addItem(tr("Dense 4"), static_cast<int>(Qt::Dense4Pattern));
    brushStyleComboBox->addItem(tr("Dense 5"), static_cast<int>(Qt::Dense5Pattern));
    brushStyleComboBox->addItem(tr("Dense 6"), static_cast<int>(Qt::Dense6Pattern));
    brushStyleComboBox->addItem(tr("Dense 7"), static_cast<int>(Qt::Dense7Pattern));
    brushStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoBrush));

    brushStyleLabel = new QLabel(tr("&Brush:"));
    brushStyleLabel->setBuddy(brushStyleComboBox);




    antialiasingCheckBox = new QCheckBox(tr("&Antialiasing"));

    transformationsCheckBox = new QCheckBox(tr("&Transformations"));


    //*Начинаю добавлять окна для прмоугольника *//
    leftUpPointX = new QSpinBox();
    leftUpPointY = new QSpinBox();
    leftUpPointX->setMaximum(10000);
    leftUpPointY->setMaximum(10000);
    weights = new QSpinBox();
    heights = new QSpinBox();
    weights->setMaximum(10000);
    heights->setMaximum(10000);
    leftUpPointXLabel = new QLabel(tr("&Коорд. Х лев. верх. точки:"));
    leftUpPointYLabel = new QLabel(tr("&Коорд. Y лев. верх. точки:"));
    weightLabel = new QLabel(tr("&Ширина прямоугольника:"));
    heightLabel = new QLabel(tr("&Высота прямоугольника:"));
    leftUpPointXLabel->setBuddy(leftUpPointX);
    leftUpPointYLabel->setBuddy(leftUpPointY);
    weightLabel->setBuddy(weights);
    heightLabel->setBuddy(heights);
    rectLabel = new QLabel(tr("Постройка прмоуголнька"));
    plotRect = new QPushButton("Построить прямоугольник");


    //*Начинаю добавлять окна для круга *//
    circleCenterX = new QSpinBox();
    circleCenterY = new QSpinBox();
    circleRadius = new QSpinBox();
    circleCenterX->setMaximum(10000);
    circleCenterY->setMaximum(10000);
    circleRadius->setMaximum(10000);
    circleCenterXLabel = new QLabel(tr("&Коорд. Х центра окруж.:"));
    circleCenterYLabel = new QLabel(tr("&Коорд. Y центра окруж.:"));
    circleRadiusLabel = new QLabel(tr("&Радиус окружности:"));
    circleCenterXLabel->setBuddy(circleCenterX);
    circleCenterYLabel->setBuddy(circleCenterY);
    circleRadiusLabel->setBuddy(circleRadius);
    circleLabel = new QLabel(tr("Постройка круга"));
    plotCircle = new QPushButton("Построить круг");

    //*Начинаю добавлять окна для треугольника *//
    upPointX = new QSpinBox();
    upPointY = new QSpinBox();
    leftPointX = new QSpinBox();
    leftPointY = new QSpinBox();
    rightPointX = new QSpinBox();
    rightPointY = new QSpinBox();
    upPointX->setMaximum(10000);
    upPointY->setMaximum(10000);
    leftPointX->setMaximum(10000);
    leftPointY->setMaximum(10000);
    rightPointX->setMaximum(10000);
    rightPointY->setMaximum(10000);
    upPointXLabel = new QLabel(tr("&Коорд. Х точки 1:"));
    upPointYLabel = new QLabel(tr("&Коорд. Y точки 1:"));
    leftPointXLabel = new QLabel(tr("&Коорд. Х точки 2:"));
    leftPointYLabel = new QLabel(tr("&Коорд. Y точки 2:"));
    rightPointXLabel = new QLabel(tr("&Коорд. Х точки 3:"));
    rightPointYLabel = new QLabel(tr("&Коорд. Y точки 3:"));
    upPointXLabel->setBuddy(upPointX);
    upPointYLabel->setBuddy(upPointY);
    leftPointXLabel->setBuddy(leftPointX);
    leftPointYLabel->setBuddy(leftPointY);
    rightPointXLabel->setBuddy(rightPointX);
    rightPointYLabel->setBuddy(rightPointY);
    trigLabel = new QLabel(tr("Постройка треугольника"));
    plotTrig = new QPushButton("Построить треугольник");

    clear = new QPushButton("Отчистить все!!!");



    connect(penWidthSpinBox, &QSpinBox::valueChanged,
            this, &Window::penChanged);
    connect(penStyleComboBox, &QComboBox::activated,
            this, &Window::penChanged);
    connect(penCapComboBox, &QComboBox::activated,
            this, &Window::penChanged);
    connect(penJoinComboBox, &QComboBox::activated,
            this, &Window::penChanged);
    connect(brushStyleComboBox, &QComboBox::activated,
            this, &Window::brushChanged);
    connect(antialiasingCheckBox, &QAbstractButton::toggled,
            renderArea, &RenderArea::setAntialiased);
    connect(transformationsCheckBox, &QAbstractButton::toggled,
            renderArea, &RenderArea::setTransformed);


    //соединяю кнопки построения со своими методами построения в renderarea.h/cpp
    connect(plotRect, &QAbstractButton::pressed,
            this, &Window::plotRectFun);
    connect(plotCircle, &QAbstractButton::pressed,
            this, &Window::plotCircleFun);
    connect(plotTrig, &QAbstractButton::pressed,
            this, &Window::plotTrigFun);
    connect(clear, &QAbstractButton::pressed,
            renderArea, &RenderArea::clearFigure);




    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(renderArea, 0, 0, 1, 4);

    mainLayout->addWidget(penWidthLabel, 3, 0, Qt::AlignRight);
    mainLayout->addWidget(penWidthSpinBox, 3, 1);
    mainLayout->addWidget(penStyleLabel, 4, 0, Qt::AlignRight);
    mainLayout->addWidget(penStyleComboBox, 4, 1);
    mainLayout->addWidget(penCapLabel, 3, 2, Qt::AlignRight);
    mainLayout->addWidget(penCapComboBox, 3, 3);
    mainLayout->addWidget(penJoinLabel, 2, 2, Qt::AlignRight);
    mainLayout->addWidget(penJoinComboBox, 2, 3);
    mainLayout->addWidget(brushStyleLabel, 4, 2, Qt::AlignRight);
    mainLayout->addWidget(brushStyleComboBox, 4, 3);

    //пошла моя фигня
    //прямоугольник
    mainLayout->addWidget(rectLabel, 5, 0, Qt::AlignRight);

    mainLayout->addWidget(leftUpPointXLabel,6,0);
    mainLayout->addWidget(leftUpPointX,6,1);
    mainLayout->addWidget(leftUpPointYLabel,6,2);
    mainLayout->addWidget(leftUpPointY,6,3);
    mainLayout->addWidget(weightLabel,7,0);
    mainLayout->addWidget(weights,7,1);
    mainLayout->addWidget(heightLabel,7,2);
    mainLayout->addWidget(heights,7,3);
    mainLayout->addWidget(plotRect,8,0,Qt::AlignLeft);

    //круг
    mainLayout->addWidget(circleLabel, 9, 0, Qt::AlignRight);
    mainLayout->addWidget(circleCenterXLabel,10,0);
    mainLayout->addWidget(circleCenterX,10,1);
    mainLayout->addWidget(circleCenterYLabel,10,2);
    mainLayout->addWidget(circleCenterY,10,3);
    mainLayout->addWidget(circleRadiusLabel,11,0);
    mainLayout->addWidget(circleRadius,11,1);
    mainLayout->addWidget(plotCircle,12,0,Qt::AlignRight);

    //трекгольник
    mainLayout->addWidget(trigLabel, 13, 0, Qt::AlignRight);
    mainLayout->addWidget(upPointXLabel,14,0);
    mainLayout->addWidget(upPointX,14,1);
    mainLayout->addWidget(upPointYLabel,14,2);
    mainLayout->addWidget(upPointY,14,3);
    mainLayout->addWidget(leftPointXLabel,15,0);
    mainLayout->addWidget(leftPointX,15,1);
    mainLayout->addWidget(leftPointYLabel,15,2);
    mainLayout->addWidget(leftPointY,15,3);
    mainLayout->addWidget(rightPointXLabel,16,0);
    mainLayout->addWidget(rightPointX,16,1);
    mainLayout->addWidget(rightPointYLabel,16,2);
    mainLayout->addWidget(rightPointY,16,3);
    mainLayout->addWidget(plotTrig,17,0,Qt::AlignRight);

    mainLayout->addWidget(clear,17,2,Qt::AlignRight);

    setLayout(mainLayout);

    penChanged();
    brushChanged();
    antialiasingCheckBox->setChecked(true);

    setWindowTitle(tr("Построй свою фигуру!"));

    setMaximumSize(500,500);
}


void Window::penChanged()
{
    int width = penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(
            penStyleComboBox->currentIndex(), IdRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(
            penCapComboBox->currentIndex(), IdRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(
            penJoinComboBox->currentIndex(), IdRole).toInt());

    //renderArea->setPen(QPen(Qt::blue, width, style, cap, join));
    curPen = QPen(Qt::blue, width, style, cap, join);
}



void Window::brushChanged()
{
    Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->itemData(

            brushStyleComboBox->currentIndex(), IdRole).toInt());


    if (style == Qt::LinearGradientPattern) {
        QLinearGradient linearGradient(0, 0, 100, 100);
        linearGradient.setColorAt(0.0, Qt::white);
        linearGradient.setColorAt(0.2, Qt::green);
        linearGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(linearGradient);

    } else if (style == Qt::RadialGradientPattern) {
        QRadialGradient radialGradient(50, 50, 50, 70, 70);
        radialGradient.setColorAt(0.0, Qt::white);
        radialGradient.setColorAt(0.2, Qt::green);
        radialGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(radialGradient);
    } else if (style == Qt::ConicalGradientPattern) {
        QConicalGradient conicalGradient(50, 50, 150);
        conicalGradient.setColorAt(0.0, Qt::white);
        conicalGradient.setColorAt(0.2, Qt::green);
        conicalGradient.setColorAt(1.0, Qt::black);
        renderArea->setBrush(conicalGradient);

    } else if (style == Qt::TexturePattern) {
        renderArea->setBrush(QBrush(QPixmap(":/images/brick.png")));

    } else {
        renderArea->setBrush(QBrush(Qt::green, style));
    }
}


//реализация моих методов
void Window::plotRectFun() {
    QPointF point = QPointF(leftUpPointX->value(),leftUpPointY->value());
    auto wid = weights->value();
    auto hei = heights->value();

    auto rectangl = std::make_unique<Square>(point, wid, hei, curPen);

    renderArea->addFigure(std::move(rectangl));
    renderArea->update();
}

void Window::plotCircleFun() {
    QPointF point = QPointF(circleCenterX->value(),circleCenterY->value());
    auto radius = circleRadius->value();

    auto circle = std::make_unique<Circle>(point, radius,curPen);

    renderArea->addFigure(std::move(circle));
    renderArea->update();
}

void Window::plotTrigFun() {
    QPointF point1 = QPointF(upPointX->value(),upPointY->value());
    QPointF point2 = QPointF(leftPointX->value(),leftPointY->value());
    QPointF point3 = QPointF(rightPointX->value(),rightPointY->value());

    auto trig = std::make_unique<Trig>(point1, point2, point3, curPen);

    renderArea->addFigure(std::move(trig));
    renderArea->update();
}
