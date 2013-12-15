#ifndef QREADER_H
#define QREADER_H

#include <QThread>

class QReader : public QThread
{
    Q_OBJECT
public:
    explicit QReader(QObject* parent);
    
signals:
    
public slots:
    
};

#endif // QREADER_H
