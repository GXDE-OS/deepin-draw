#include "adjustsizewidget.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>

#include "widgets/toolbutton.h"
#include "utils/configsettings.h"

AdjustsizeWidget::AdjustsizeWidget(QWidget *parent)
    : QWidget(parent)
{
    QLabel* casWidthLabel = new QLabel(this);
    casWidthLabel->setObjectName("CasWidthLabel");
    casWidthLabel->setText(tr("Canvas width"));

    m_widthLEdit = new QLineEdit(this);
    m_widthLEdit->setObjectName("WidthLineEdit");
    m_widthLEdit->setFixedWidth(80);

    connect(m_widthLEdit, &QLineEdit::textChanged, this, [=](const QString &text){
        qDebug() << "m_widthLEdit:" << text;
    });

    m_widthLEdit->setStyleSheet("background-color: red;");
    QLabel* unitWLabel = new QLabel(this);
    unitWLabel->setText("px");

    QLabel* casHeightLabel = new QLabel(this);
    casHeightLabel->setObjectName("CasHeightLabel");
    casHeightLabel->setText(tr("Canvas height"));

    m_heightLEdit = new QLineEdit(this);
    m_heightLEdit->setObjectName("HeightLineEdit");
    m_heightLEdit->setFixedWidth(80);


    int canvasWidth = ConfigSettings::instance()->value("artboard", "width").toInt();
    int canvasHeight = ConfigSettings::instance()->value("artboard", "height").toInt();

    if (canvasWidth == 0|| canvasHeight == 0)
    {
        QSize desktopSize = qApp->desktop()->size();
        canvasWidth = desktopSize.width();
        canvasHeight = desktopSize.height();
    }
    setCanvasSize(QSize(canvasWidth, canvasHeight));

    connect(m_heightLEdit, &QLineEdit::textChanged, this, [=](const QString &text){
        qDebug() << "m_heightLEdit:" << text;
    });

    QLabel* unitHLabel = new QLabel(this);
    unitHLabel->setText("px");

    ToolButton* cutTransAreaBtn = new ToolButton(this);
    cutTransAreaBtn->setFixedWidth(100);
    cutTransAreaBtn->setObjectName("CutAreaLineEdit");
    cutTransAreaBtn->setText(tr("Autocrop"));

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(casWidthLabel);
    layout->addWidget(m_widthLEdit);
    layout->addWidget(unitWLabel);
    layout->addSpacing(6);
    layout->addWidget(casHeightLabel);
    layout->addWidget(m_heightLEdit);
    layout->addWidget(unitHLabel);
    layout->addWidget(cutTransAreaBtn);
    setLayout(layout);
}

void AdjustsizeWidget::setCanvasSize(QSize size)
{
    m_widthLEdit->setText(QString("%1").arg(size.width()));
    m_heightLEdit->setText(QString("%1").arg(size.height()));
}

void AdjustsizeWidget::updateCanvasSize(QSize size)
{
    setCanvasSize(size);
}

AdjustsizeWidget::~AdjustsizeWidget()
{
}
