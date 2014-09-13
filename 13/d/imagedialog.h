#ifndef IMAGEDIALOG_H
#define IMAGEDIALOG_H

#include <QDialog>
#include "ui_imagedialog.h"
#include "imagecollection.h"

class ImageDialog : public QDialog
{
    Q_OBJECT    

    public:
        ImageDialog();

    private slots:
        void nextClicked();
        void previousClicked();
        void tagsChanged();

        void addImageClicked();
        void addTagClicked();

    private:
        QStringList selectedTags();

        void updateImages();
        void updateTags();
        void updateCurrentImage();

        Ui::ImageDialog ui;

        QList<int> imageIds;
        int currentImage;

        ImageCollection images;
};

#endif
