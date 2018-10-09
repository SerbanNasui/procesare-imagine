/********************************************************************************
** Form generated from reading UI file 'magnifier.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAGNIFIER_H
#define UI_MAGNIFIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Magnifier
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *verticalWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Magnifier)
    {
        if (Magnifier->objectName().isEmpty())
            Magnifier->setObjectName(QStringLiteral("Magnifier"));
        Magnifier->resize(261, 202);
        Magnifier->setAutoFillBackground(false);
        Magnifier->setSizeGripEnabled(false);
        horizontalLayout = new QHBoxLayout(Magnifier);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalWidget = new QWidget(Magnifier);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        gridLayout = new QGridLayout(verticalWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        label = new QLabel(verticalWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1, Qt::AlignHCenter);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);


        horizontalLayout->addWidget(verticalWidget);


        retranslateUi(Magnifier);

        QMetaObject::connectSlotsByName(Magnifier);
    } // setupUi

    void retranslateUi(QDialog *Magnifier)
    {
        Magnifier->setWindowTitle(QApplication::translate("Magnifier", "ZOOM IN", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Magnifier: public Ui_Magnifier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGNIFIER_H
