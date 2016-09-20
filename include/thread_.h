#include <QThread>

class thread_:public QThread{
    Q_OBJECT
public:
    thread_();
    virtual void run();
};
