#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTreeWidget>
#include <QDebug>
#include <QProcess>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QTreeWidgetItem* addTreeRoot(QString name, QString description);
    void addTreeChild(QTreeWidgetItem *parent, QString name, QString description);

public slots:
    void PlayTitle(QTreeWidgetItem *item, int column);
};

#endif // MAINWINDOW_H
