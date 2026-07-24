#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

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
    // Controles Globales
    //
    QLabel  *lblTexto       = new QLabel();
    QLabel  *lblHora        = new QLabel();
    QLabel  *lblFecha       = new QLabel();

    //
    // Funciones de MainWindow
    //
    void    abrirBaseDatos();
    void    initUi();
    void    initReloj();
    void    initBarraEstado();
    void    initArbolTablas();
    void    refrescaReloj();
    void    salir();
    void    centrarApp();

protected:

    bool    eventFilter(QObject *obj, QEvent *ev) override;
    void    keyPressEvent(QKeyEvent *ev) override;

private slots:
    void on_actionAbrir_Archivo_triggered();

    void on_actionSAlir_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
