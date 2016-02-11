#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <QGraphicsScene>
#include "observer.h"
#include "tile.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow, public Observer {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void applyUpdate() override;

private:
    std::unique_ptr<Ui::MainWindow> ui_;
    std::unique_ptr<QGraphicsScene> scene_;

    std::vector<std::pair<int, std::shared_ptr<Tile> > > tiles_;
};

#endif // MAINWINDOW_H
