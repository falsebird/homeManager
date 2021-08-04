#include "fileexplore.h"
#include<QDir>
#include<QDebug>
FileExplore::FileExplore(QObject *parent) : QThread(parent)
{
    m_filters.append("*.mp3");
}

FileExplore::~FileExplore()
{
    delete _fileList;
}

void FileExplore::run()
{
    GetFileList(m_paths);
    emit getFileListDone(_fileList);
}

void FileExplore::GetFileList(const QString &path, QFileInfoList *fileList)
{
    QDir dir(path);
    dir.setNameFilters(m_filters);
   // _fileWatcher->addPath(path);
    QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    fileList->append(file_list);
    QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    fileList->append(folder_list);
    for (int i = 0; i != folder_list.size(); i++) {
        QString name = folder_list.at(i).absoluteFilePath();
        GetFileList(name,fileList);
    }

}

void FileExplore::GetFileList(const QList<QString> paths)
{
    auto iter = paths.begin();
    _fileList->clear();
//    m_fileSet.clear();
//    m_fileList->clear();
    while(iter!= paths.constEnd()){
        GetFileList(*iter,_fileList);
        iter++;
    }
    //GetFileList(_path,_fileList);
    int fileNum =  _fileList->size();
    qDebug()<<fileNum;
//    for(int i = 0 ; i < fileNum ; i++){
//       qDebug()<< _fileList->at(i).absoluteFilePath();
//       qDebug()<<i<<endl;
//       m_fileList->append(myFileInfo(_fileList->at(i)));
//    }
//    emit getFileListDone(_fileList);
    /*m_fileSet = m_fileList->toSet();
    assert(m_fileSet.size()==m_fileList->size());*///两者的长度应该是相等的
}
