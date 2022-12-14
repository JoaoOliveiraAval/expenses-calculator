#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void setFieldsVisible(bool value);
  void clearAllFields();
private slots:
  void on_calculateButton_clicked();

  void on_clearButton_clicked();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
