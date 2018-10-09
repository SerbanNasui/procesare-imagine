/********************************************************************************
** Form generated from reading UI file 'plotter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTTER_H
#define UI_PLOTTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Plotter
{
public:
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *customPlot;

    void setupUi(QDialog *Plotter)
    {
        if (Plotter->objectName().isEmpty())
            Plotter->setObjectName(QStringLiteral("Plotter"));
        Plotter->setEnabled(true);
        Plotter->resize(642, 305);
        verticalLayout_3 = new QVBoxLayout(Plotter);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        customPlot = new QCustomPlot(Plotter);
        customPlot->setObjectName(QStringLiteral("customPlot"));

        verticalLayout_3->addWidget(customPlot);


        retranslateUi(Plotter);

        QMetaObject::connectSlotsByName(Plotter);
    } // setupUi

    void retranslateUi(QDialog *Plotter)
    {
        Plotter->setWindowTitle(QApplication::translate("Plotter", "Grey Plotter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Plotter: public Ui_Plotter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTTER_H
