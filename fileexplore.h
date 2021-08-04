#ifndef FILEEXPLORE_H
#define FILEEXPLORE_H

#include <QObject>
#include<QThread>
#include<QFileInfo>

//读取指定文件夹下的所有音乐文件，返回一个list
class FileExplore : public QThread
{
    Q_OBJECT
public:
    explicit FileExplore(QObject *parent = nullptr);//应该用单例模式，
    ~FileExplore();

    void run();
signals:
    void getFileListDone(QFileInfoList* _fileList);
public slots:

private:
    void GetFileList(const QString &path,QFileInfoList* file_list);
    void GetFileList(const QList<QString> paths);
    QFileInfoList* _fileList;
    QStringList m_filters;
    QStringList m_paths;
};

#endif // FILEEXPLORE_H
