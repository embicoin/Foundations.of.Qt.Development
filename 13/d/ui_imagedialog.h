/********************************************************************************
** Form generated from reading UI file 'imagedialog.ui'
**
** Created: Sat Sep 13 15:46:59 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEDIALOG_H
#define UI_IMAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ImageDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *imageLabel;
    QListWidget *tagList;
    QHBoxLayout *horizontalLayout;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *addTagButton;
    QPushButton *addImageButton;
    QLabel *label;
    QLabel *imagesLabel;

    void setupUi(QDialog *ImageDialog)
    {
        if (ImageDialog->objectName().isEmpty())
            ImageDialog->setObjectName(QString::fromUtf8("ImageDialog"));
        ImageDialog->resize(739, 522);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageDialog->sizePolicy().hasHeightForWidth());
        ImageDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(ImageDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        imageLabel = new QLabel(ImageDialog);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy1);
        imageLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(imageLabel, 0, 0, 1, 1);

        tagList = new QListWidget(ImageDialog);
        tagList->setObjectName(QString::fromUtf8("tagList"));
        tagList->setSelectionMode(QAbstractItemView::MultiSelection);

        gridLayout->addWidget(tagList, 0, 1, 2, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        previousButton = new QPushButton(ImageDialog);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(previousButton->sizePolicy().hasHeightForWidth());
        previousButton->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(previousButton);

        nextButton = new QPushButton(ImageDialog);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        sizePolicy2.setHeightForWidth(nextButton->sizePolicy().hasHeightForWidth());
        nextButton->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(nextButton);

        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addTagButton = new QPushButton(ImageDialog);
        addTagButton->setObjectName(QString::fromUtf8("addTagButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(addTagButton->sizePolicy().hasHeightForWidth());
        addTagButton->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(addTagButton);

        addImageButton = new QPushButton(ImageDialog);
        addImageButton->setObjectName(QString::fromUtf8("addImageButton"));
        sizePolicy3.setHeightForWidth(addImageButton->sizePolicy().hasHeightForWidth());
        addImageButton->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(addImageButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 2, 1);

        label = new QLabel(ImageDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 1, 1, 1);

        imagesLabel = new QLabel(ImageDialog);
        imagesLabel->setObjectName(QString::fromUtf8("imagesLabel"));
        imagesLabel->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(imagesLabel, 2, 2, 1, 1);


        retranslateUi(ImageDialog);

        QMetaObject::connectSlotsByName(ImageDialog);
    } // setupUi

    void retranslateUi(QDialog *ImageDialog)
    {
        ImageDialog->setWindowTitle(QApplication::translate("ImageDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        imageLabel->setText(QApplication::translate("ImageDialog", "No Image", 0, QApplication::UnicodeUTF8));
        previousButton->setText(QApplication::translate("ImageDialog", "Previous", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("ImageDialog", "Next", 0, QApplication::UnicodeUTF8));
        addTagButton->setText(QApplication::translate("ImageDialog", "AddTag", 0, QApplication::UnicodeUTF8));
        addImageButton->setText(QApplication::translate("ImageDialog", "AddImage", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ImageDialog", "Images      ", 0, QApplication::UnicodeUTF8));
        imagesLabel->setText(QApplication::translate("ImageDialog", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImageDialog: public Ui_ImageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEDIALOG_H
