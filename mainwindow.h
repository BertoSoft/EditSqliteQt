#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    //
    // Funciones de MainWindow
    //
    void    initUi();
    void    initReloj();
    void    refrescaReloj();
    void    salir();
    void    centrarApp();

protected:

    bool    eventFilter(QObject *obj, QEvent *ev);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
