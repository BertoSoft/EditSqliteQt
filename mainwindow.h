#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTableWidgetItem>

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
    void    initSp();
    void    refrescaReloj();
    void    refrescaArbolTablas();
    void    refrescaTabla();
    void    salir();
    void    centrarApp();
    void    activaControles();
    void    desactivaControles();
    void    limpiaControles();
    void    modificarDatos();

protected:

    bool    eventFilter(QObject *obj, QEvent *ev) override;
    void    keyPressEvent(QKeyEvent *ev) override;
    void    resizeEvent(QResizeEvent *ev) override;

private slots:
    void on_actionAbrir_Archivo_triggered();

    void on_actionSAlir_triggered();

    void on_spTablas_activated(int index);

    void on_tabTabla_itemActivated(QTableWidgetItem *item);

    void on_tabTabla_cellClicked(int row, int column);

    void on_btnModificar_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
