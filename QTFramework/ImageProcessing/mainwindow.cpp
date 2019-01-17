#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    qApp->installEventFilter(this);
    initialImage = nullptr;
    modifiedImage = nullptr;
    transientData= new QMap<QString,double>();
    magnifierDialog=nullptr;
    greyPlotterDialog=nullptr;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    if(initialImage!=nullptr)
    {
        delete initialImage;
        initialImage = nullptr;
    }
    if(modifiedImage != nullptr)
    {
        delete modifiedImage;
        modifiedImage = nullptr;
    }
    if(transientData!= nullptr)
    {
        delete transientData;
        transientData = nullptr;
    }
    if(magnifierDialog!=nullptr)
    {
        delete magnifierDialog;
        magnifierDialog=nullptr;
    }
    if(greyPlotterDialog!=nullptr)
    {
        delete greyPlotterDialog;
        greyPlotterDialog=nullptr;
    }
    delete ui;
}

/*
    Loads an image from disk without modifying its coloration.
*/
void MainWindow::on_actionColor_triggered()
{
    loadImages();
    updateImages(true);
}

/*
    Loads an image from disk and transforms it into a greyscaleimage.
*/
void MainWindow::on_actionGreyscale_triggered()
{
    loadImages();
    toGreyScale(initialImage);
    updateImages(true);
}

/*
    The SaveAs button saves the modifiedImage on disk on a given path.
*/
void MainWindow::on_actionSave_as_triggered()
{
    QString imagePath = QFileDialog::getSaveFileName(this, tr("Open file"),"",tr("IMAGE (*.jpg *.jpeg *.png *.bmp)"));
    if(imagePath.length()<2)
    {
        return;
    }
    if(modifiedImage != nullptr)
    {
        modifiedImage->save(imagePath);
    }
}

/*
    The method transforms the given image into a greyscale image.
 */
void MainWindow::toGreyScale(QImage* image)
{
    if(image== nullptr)
    {
        return;
    }
    for (int i = 0;  i < image->width();  i++)
    {
        for (int j = 0; j < image->height(); j++)
        {
            int gray = qGray(image->pixel(i,j));
            image->setPixel(i,j, QColor(gray, gray, gray).rgb());
        }
    }
}


/*
    At loading, initialImage and modifiedImage are both initialized with the image taken from the given path.
    But only the initialImage is shown in the UI.
*/
void MainWindow::loadImages()
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open file"),"",tr("IMAGE (*.jpg *.jpeg *.png *.bmp)"));
    if(imagePath.length()<5)
    {
        qDebug("Path too short!");
        return;
    }
    if(initialImage != nullptr)
    {
        delete initialImage;
    }

    //initialImage = new QImage(imagePath);
    //initialImagePath=imagePath;

    QImage *image=new QImage(imagePath);
    int width=image->width();
    int height=image->height();
    int count=image->bitPlaneCount();

   // qDebug()<<count;
   if(count==8)
    {

        initialImage=new QImage(width,height,QImage::Format_RGB32);
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<height;j++)
            {
                byte cl=qGray(image->pixel(i,j));
               //QRgb cl=image->pixel(i,j);
               //initialImage->setPixelColor(i,j,cl);
               initialImage->setPixelColor(i,j,qRgb(cl,cl,cl));
            }
        }
    qDebug()<<count;
        delete image;
    }
    else
        initialImage=image;


    if(modifiedImage != nullptr)
    {
        delete modifiedImage;
    }
	modifiedImage = nullptr;
	
    //modifiedImage = new QImage(imagePath);
  //  modifiedImage = new QImage(width,height,QImage::Format_RGB32);


}

/*
    The method updates and shows the initialImage and the modifiedImage. It is supposed to be called after a modification.
    The modifiedImage is shown only if relevant.
 */
void MainWindow::updateImages(bool isOpen)
{
    if(initialImage != nullptr)
    {
        QPixmap pixMapInitial = QPixmap::fromImage(*initialImage);

        ui->label->setPixmap(pixMapInitial);
		if (modifiedImage != nullptr)
		{
			QPixmap pixMapModified = QPixmap::fromImage(*modifiedImage);

			if (!isOpen) {
				ui->label_2->setPixmap(pixMapModified);
			}
		}
		else
			ui->label_2->setPixmap(QPixmap());
    }
}

/*
 * The SaveAsInitialImage button replaces the initialImage with the modifiedImage on disk and also on the UI.
 */
void MainWindow::on_btnSaveAsInitialImage_clicked()
{
    if(modifiedImage!= nullptr)
    {
        initialImage= new QImage(*modifiedImage);
      //  initialImage->save(initialImagePath);
        updateImages(true);
    }
}

/*
    The lamba property launches a dialog that permits saving into the transientData a needed double value.
*/
void MainWindow::on_actionLamba_triggered()
{
    bool ok;
    SmartDialog lambda("Lambda", &ok);
    //transientData->insert("Lambda",lambda.getValue());
    //Example of usage CTRL+/ to uncomment
    //    if (ok)
    //    {
    //        ui->label->setText(QString::number(transientData->value("Lambda")));
    //    }

}

/*
 * The method manages the behavior when the mouse is pressed.
 * If the mouse is pressed over the initialImage or the modifiedImage, specific algorithms (like zoom in, grey plotter etc.) are triggered.
 */
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(initialImage != nullptr)// && modifiedImage !=nullptr)
    {
        if(isMousedPressedOnInitialImage(obj, event)||isMousedPressedOnModifiedImage(obj,event))
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            int mouseX = mouseEvent->pos().x();
            int mouseY = mouseEvent->pos().y();
            qDebug() << QString("Mouse move (%1,%2)").arg(mouseX).arg(mouseY);

            if(isMousedPressedOnInitialImage(obj, event))
            {
                launchMagnifierDialog(mouseX,mouseY,initialImage);
            }else
            {
                launchMagnifierDialog(mouseX,mouseY, modifiedImage);
            }
			if (initialImage!=nullptr)
				plotGreyPixels(mouseY, initialImage);
			if (modifiedImage!=nullptr)
				plotGreyPixels(mouseY,modifiedImage);
            return true;
        }
    }
    return false;
}

bool MainWindow::isMousedPressedOnInitialImage(QObject *obj, QEvent *event)
{
    return (qobject_cast<QLabel*>(obj) == ui->label) && event->type() == QEvent::MouseButtonPress;
}

bool MainWindow::isMousedPressedOnModifiedImage(QObject *obj, QEvent *event)
{
    return  qobject_cast<QLabel*>(obj) == ui->label_2 && event->type() == QEvent::MouseButtonPress;
}

/*
    The method zooms over a 9x9 area that surrounds the given coordinate (x,y).
 */
void MainWindow::launchMagnifierDialog(int x, int y, QImage* image)
{
    if(magnifierDialog == nullptr)
    {
        return;
    }
    magnifierDialog->drawMagnifiedImage(image,x,y);
}

/*
    The method creates a reverted image to the initialImage and puts it in the modifiedImage.
 */
void MainWindow::on_actionRevert_colors_triggered()
{
    if(initialImage == nullptr)
    {
        return;
    }
    if(modifiedImage != nullptr)
    {
        delete modifiedImage;
    }
    modifiedImage = new QImage(initialImage->width(),initialImage->height(),QImage::Format_RGB32);


    for (int i = 0;  i < initialImage->width();  i++)
    {
        for (int j = 0; j < initialImage->height(); j++)
        {
            QColor color = initialImage->pixelColor(i, j);
            modifiedImage->setPixel(i,j,qRgb(255-color.red(),255-color.green(),255-color.blue()));
        }
    }
    updateImages(false);
}

/*
    Sets to visible the greyPlotterDialog.
 */
void MainWindow::on_actionPlot_grey_level_triggered()
{
    if(greyPlotterDialog==nullptr)
    {
        greyPlotterDialog= new Plotter();
        greyPlotterDialog->activateWindow();
        greyPlotterDialog->setUpPlot();
    }
    greyPlotterDialog->show();
}

/*
   The method plots to the greyPlotDialog the grey level of a given level-y from a given image.
 */
void MainWindow::plotGreyPixels(int y, QImage* image) const
{

	if (greyPlotterDialog == nullptr)
	{
		return;
	}

	if (image != nullptr)
	{
		for (int j = 0; j < initialImage->width(); j++)
		{


			int gray = qGray(image->pixel(j, y));
			if (image == initialImage)
			{
				greyPlotterDialog->plotValuesToFirstGraph(j, gray);
			}
			else
			{
				greyPlotterDialog->plotValuesToSecondGraph(j, gray);
			}
			qDebug() << QString("qGray (%1)").arg(gray);
		}
	}
	else
	{
		if (initialImage == nullptr)
		{
			greyPlotterDialog->clearValuesToFirstGraph();
		}

		if (modifiedImage == nullptr)
		{
			greyPlotterDialog->clearValuesToFirstGraph();
		}
	}
    greyPlotterDialog->refresh();
}

/*
   Sets to visible the magnifier dialog.
 */
void MainWindow::on_actionLaunch_magnifier_triggered()
{
    if(magnifierDialog == nullptr)
    {
        magnifierDialog = new Magnifier();
        magnifierDialog->activateWindow();
    }
    magnifierDialog->show();
}

/*
    The gama property launches a dialog that permits saving into the transientData a needed double value.
*/
void MainWindow::on_actionGama_triggered()
{
    bool ok;
    SmartDialog smart("Gama",&ok,4);
    if(ok)
    {
        QMap<QString, double>intermidiateValues= smart.getValues();
        QMap<QString, double>::iterator i;
        QString key;
        for (i = intermidiateValues.begin(); i != intermidiateValues.end(); ++i)
        {
            key=i.key();
            (*transientData)[i.key()]= i.value();
        }
        //Example of usage CTRL+/ to uncomment
        //Make sure you enter a double value!
        //ui->label->setText(QString::number((*transientData)[key]));
    }
}

/*TEMA1/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 0,5*/
//oglindit
void MainWindow::on_actionMirroring_triggered()
{
    if(initialImage == nullptr)
    {
        return;
    }
    if(modifiedImage != nullptr)
    {
        delete modifiedImage;
    }
    modifiedImage = new QImage(initialImage->width(),initialImage->height(),QImage::Format_RGB32);


    for (int i = 0;  i < initialImage->width();  i++)
    {
        for (int j = 0; j < initialImage->height(); j++)
        {
            QColor color = initialImage->pixelColor(i, j);
            modifiedImage->setPixel(initialImage->width()-i,j,qRgb(color.red(),color.green(),color.blue()));
        }
    }
    updateImages(false);
}

//threshholding
void MainWindow::on_actionThresholding_triggered()
{
    bool val;
       SmartDialog tresholding("Val: ", &val);
       double t = tresholding.getFirstValue();
       if(initialImage== nullptr)
       {
           return;
       }
       modifiedImage = new QImage( initialImage->width(),initialImage->height(),QImage::Format_RGB32);
       for (int i = 0;  i < initialImage->width();  i++)
       {
           for (int j = 0; j < initialImage->height(); j++)
           {
               int gray = qGray(initialImage->pixel(i,j));
               gray = gray < t ? 0 : 255;
               modifiedImage->setPixel(i,j,QColor(gray, gray, gray).rgb());
           }
       }
       updateImages(false);

}

// histogama
int* MainWindow::histogram()
{
    int v[256];
    for (int i = 0;  i < initialImage->width();  i++)
        for (int j = 0; j < initialImage->height(); j++)
        {
            int gray = qGray(initialImage->pixel(i,j));
            v[gray]++;
        }
    return v;
}
void MainWindow::on_actionHistogram_triggered()
{

}

/*TEMA2//////////////////////////////////////////////////////////////////z///////////////////////////////////////////////////////////////////////////////////////// 1p*/
void MainWindow::on_actionBrightnessIncreasing_triggered()
{
    modifiedImage = new QImage( initialImage->width(),initialImage->height(),QImage::Format_RGB888);
    bool ok=false;
    SmartDialog dialog2("Modify Brightness and Contrast",&ok,1);
    if(ok)
    {
        int value=dialog2.getFirstValue();
        int lookUpTable[256];
        for(int i=0 ; i<256 ; i++)
        {
            int a;
            a=i;
            lookUpTable[i]=a+value;
            if(lookUpTable[i]>255)
            {
                lookUpTable[i]=255;
            }
            qDebug()<<"LookUpTable["<<i<<"]"<<lookUpTable[i]<<endl;}
        for(int i=0;i<initialImage->width();i++)
        {
            for(int j=0;j<initialImage->height();j++)
            {
                int color=initialImage->pixelColor(i,j).value();
                modifiedImage->setPixel(i,j,qRgb(lookUpTable[color],lookUpTable[color],lookUpTable[color]));
            }
        }
    }else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","You must to insert a value bigger than 0 and smaller than 256");
        messageBox.setFixedSize(500,200);
        on_actionBrightnessIncreasing_triggered();
    }
    updateImages(false);
}

void MainWindow::on_actionBrightnessDiminishing_triggered()
{
    modifiedImage = new QImage( initialImage->width(),initialImage->height(),QImage::Format_RGB888);
    bool ok=false;
    SmartDialog dialog2("Modify Brightness and Contrast",&ok,1);
    if(ok)
    {
        int val=dialog2.getFirstValue();
        if(val<=255&&val>=0){
            int value=val;
            int lookUpTable[256];
            for(int i=0 ; i<256 ; i++)
            {
                int a=i;
                lookUpTable[i]=a-value;
                if(lookUpTable[i]<0)
                {
                    lookUpTable[i]=0;
                }
                qDebug()<<"LookUpTable["<<i<<"]"<<lookUpTable[i]<<endl;
            }
            for(int i=0;i<initialImage->width();i++)
            {
                for(int j=0;j<initialImage->height();j++)
                {
                    int color=initialImage->pixelColor(i,j).value();
                    modifiedImage->setPixel(i,j,qRgb(lookUpTable[color],lookUpTable[color],lookUpTable[color]));
                }
            }
        }else
        {   QMessageBox messageBox;
            messageBox.critical(0,"Error","You must to insert a value bigger than 0 and smaller than 256!");
            messageBox.setFixedSize(500,200);
            on_actionBrightnessDiminishing_triggered();
        }
    }
    updateImages(false);
}

/*TEMA3/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 1p*/
void MainWindow::on_actionColorBinarization_triggered()
{
    bool ok;
    modifiedImage = new QImage( initialImage->width(),initialImage->height(),QImage::Format_RGB888);
        SmartDialog Point("Coordonate(X1,Y2)",&ok,2);
        SmartDialog Point2("Threshold",&ok,1);
        if(ok){
            int x =Point.getFirstValue();
            int y =Point.getsecondValue();
            double t = Point2.getFirstValue();
            QColor rgb=initialImage->pixel(QPoint(x,y));

            int r0,g0,b0;
            r0=rgb.red();
            g0=rgb.green();
            b0=rgb.blue();
            for(int i=0;i<initialImage->width();i++){
                for(int j=0;j<initialImage->height();j++){

                    QColor image=initialImage->pixel(i,j);
                    int imgRed,imgGreen,imgBlue;
                    imgRed=image.red();
                    imgGreen=image.green();
                    imgBlue=image.blue();

                    double def=sqrt(((imgRed-r0)*(imgRed-r0))+((imgGreen-g0)*(imgGreen-g0))+((imgBlue-b0)*(imgBlue-b0)));
                    QRgb white = qRgb(255,255,255);
                    QRgb black = qRgb(0, 0, 0);
                    if(def<=t){

                        modifiedImage->setPixel(i,j,white);
                    }else{

                        modifiedImage->setPixel(i,j,qRgb(0, 0, 0));
                    }
                }
            }
            updateImages(false);

        }
}

/*TEMA4/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 1p*/
void MainWindow::on_actionMeanFilter_triggered()
{
    modifiedImage = new QImage( initialImage->width(),initialImage->height(),QImage::Format_RGB888);
    bool ok;
    SmartDialog dialog3("Insert a value:",&ok,1);
    if(ok)
    {
        double value=dialog3.getFirstValue();
        int k = value/2;

        for(int i=k ; i<initialImage->width()-k-1;i++){
            for(int j=k;j<initialImage->height()-k-1;j++){
                double sum=0;

                for(int a=-k;a<=k;a++){
                    for(int b=-k;b<=k;b++){

                        sum+=qGray(initialImage->pixel(i+a,j+b));

                    }
                }
                auto average=sum/(value*value);
                modifiedImage->setPixel(i,j,qRgb(average,average,average));
            }
        }


    }
    updateImages(false);
}

/* TEMA5///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


/*TEMA6 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 2p*/
void MainWindow::on_actionClosing_triggered()
{
    modifiedImage = new QImage( initialImage->width(),initialImage->height(),QImage::Format_RGB888);
            on_actionThresholding_triggered();
                bool ok;

             SmartDialog dialog("Matrice",&ok,1);
                 if(ok)
                 {   int a= dialog.getFirstValue();

                     int k=a/2;

                 initialImage= new QImage(modifiedImage->width(),modifiedImage->height(),QImage::Format_RGB888);

        //Dilatare daca am centrul alb si cel putin un vecin negru il fac negru

                 for(int i=k;i<modifiedImage->width()-k;i++){
                     for(int j=k;j<modifiedImage->height()-k;j++){

                         if(qGray(modifiedImage->pixel(i,j))==0)
                         { bool ok=true;

                         for(int x=-k;x<=k ;x++){
                             for(int y=-k;y<=k ;y++)
                                 if(qGray(modifiedImage->pixel(i+x,j+y))==255) ok=false;


                             }

                         if(ok==false){
                             initialImage->setPixel(i,j,qRgb(255,255,255));


                         }else{
                             initialImage->setPixel(i,j,qRgb(0,0,0));

                              }

                         }
                     }
                 }
        //Erodare daca am centru negru si cel putin un vecin alb, colorez centrul alb
                     for(int i=k;i<initialImage->width()-k;i++){
                         for(int j=k;j<initialImage->height()-k;j++){

                             if(qGray(initialImage->pixel(i,j))==255)

                             {
                                 bool ok=true;

                             for(int x=-k;x<=k && ok ;x++){
                                 for(int y=-k;y<=k && ok ;y++)

                                     if(qGray(initialImage->pixel(i+x,j+y))==0) ok=false;

                             }
                             if(ok==false)
                             {
                                 modifiedImage->setPixel(i,j,qRgb(0,0,0));

                             }else{
                                 modifiedImage->setPixel(i,j,qRgb(255,255,255));

                                  }
                             }
                         }
                     }

        //


                 }

                 updateImages(false);
}

/* TEMA7/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 3p*/
void MainWindow::on_actionRotatiaCuInterpolare_triggered()
{
    modifiedImage = new QImage( initialImage->width(),initialImage->height(),QImage::Format_RGB888);
    bool ok=false;
    double xCent=initialImage->width()/2;
    double yCent=initialImage->height()/2;
    double xc;
    double yc;
    double theta;
    SmartDialog Grade("InsertGrade",&ok,1);
    if(ok){
        theta =Grade.getFirstValue();
    }
    qDebug()<<theta;
    double O =( theta * M_PI) / 180;
    for (int xP = 0;  xP < modifiedImage->width();  xP++)
    {
        for (int yP = 0; yP < modifiedImage->height(); yP++)
        {
            xc=(xP-xCent)*qCos(O)+(yP-yCent)*qSin(O)+xCent;
            yc=-(xP-xCent)*qSin(O)+(yP-yCent)*qCos(O)+yCent;
            if( xc < modifiedImage->width()-1 && xc>0 && yc>0 && yc<modifiedImage->height()-1 )
            {
                int Xintreg = (int)xc;
                int Yintreg = (int)yc;
                double val1 =(xc - Xintreg) * (qGray(initialImage->pixel(Xintreg +1, Yintreg))
                                               -qGray(initialImage->pixel(Xintreg, Yintreg)))
                        +qGray(initialImage->pixel(Xintreg, Yintreg)) ;

                double val2 =(xc - Xintreg) * (qGray(initialImage->pixel(Xintreg +1, Yintreg+1))
                                               -qGray(initialImage->pixel(Xintreg, Yintreg+1)))
                        +qGray(initialImage->pixel(Xintreg, Yintreg+1)) ;

                double val3 =(yc - Yintreg) * (val2-val1)+val1;

                modifiedImage->setPixel(xP,yP,qRgb(val3,val3,val3));

            }else{
                if(xc>=255||yc>=255){

                    modifiedImage->setPixel(xP,yP,qRgb(0,0,0));
                }
                if(xc<=0||yc<=0){
                    modifiedImage->setPixel(xP,yP,qRgb(0,0,0));
                }
            }
        }
    }
    updateImages(false);
}

/* TEMA8///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

