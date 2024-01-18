#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include "tableview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
private:
    TableView *table;

    void createMenus();

    QMenu *fileMenu;
    QMenu *toolsMenu;
    QMenu *infoMenu;
    QMenu *wipeMenu;

    QAction *loadAct;
    QAction *saveAct;
    QAction *exit;
    QAction *addAct;
    QAction *modAct;
    QAction *delAct;
    QAction *infoAct;
    QAction *wipeAct;

private slots:
    void loadFile();
    void saveFile();
};

#endif
