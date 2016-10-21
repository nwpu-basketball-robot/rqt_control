#include <QThread>
#include <QProcess>

class thread_:public QThread{
    Q_OBJECT
public:
    thread_(QProcess* process, QString commod);
private:
    QProcess* qprocess;
    QString cmd;
    void run();
};
