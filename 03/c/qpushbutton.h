#include <QApplication> 
#include <QWidget> 
#include <QPushButton> 
#include <QHBoxLayout> 
#include <QDialog> 
#include <QMessageBox> 

class ButtonDialog : public QDialog 
{
    Q_OBJECT
    public: 
        ButtonDialog(QWidget *parent = 0); 

    private slots: 
        void buttonClicked(); 
        void buttonToggled(); 

    private: 
        QPushButton *clickButton; 
        QPushButton *toggleButton; 
}; 
