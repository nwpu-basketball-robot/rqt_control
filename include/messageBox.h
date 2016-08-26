#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H
#include <QMessageBox>
#include <QDialog>

class MessageBox : public QDialog
{
    Q_OBJECT

public:
    MessageBox(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~MessageBox();

private:
    void init();
    QString MESSAGE;

    public slots:
        void criticalMessage();
        void informationMessage();
        void questionMessage();
        void warningMessage();
};

#endif // MESSAGEBOX_H


