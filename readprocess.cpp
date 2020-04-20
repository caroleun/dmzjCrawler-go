#include "readprocess.h"

ReadProcess::ReadProcess(QString cmd)
{
    QProcess proc;

    QTextCodec* utf8 = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(utf8);

    proc.start(cmd.toLocal8Bit());
    proc.waitForReadyRead();
    if (proc.isReadable())
    {
        QByteArray bytes = proc.readAllStandardOutput();
        this->result = utf8->toUnicode(bytes);
    }
    proc.waitForFinished();
}
