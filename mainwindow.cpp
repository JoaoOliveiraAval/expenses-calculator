#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  setFieldsVisible(false);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_calculateButton_clicked() {
  auto daysQuantitySpinBox = ui->daysQuantitySpinBox->value();
  auto transportDailyCostSpinBox = ui->transportCostSpinBox->value();
  auto foodDailyCostSpinBox = ui->foodCostSpinBox->value();

  if (daysQuantitySpinBox == 0 || transportDailyCostSpinBox == 0 ||
      foodDailyCostSpinBox == 0)
    return;

  double totalFoodCost = daysQuantitySpinBox * foodDailyCostSpinBox;
  double totalTransportCost = daysQuantitySpinBox * transportDailyCostSpinBox;

  double totalCost =
      daysQuantitySpinBox * (foodDailyCostSpinBox + transportDailyCostSpinBox);

  ui->foodTotalCostLabel->setText("R$ " +
                                  QString::number(totalFoodCost, 'f', 2));
  ui->transportTotalCostLabel->setText(
      "R$ " + QString::number(totalTransportCost, 'f', 2));
  ui->totalCostLabel->setText("R$ " + QString::number(totalCost, 'f', 2));

  setFieldsVisible(true);
}

void MainWindow::setFieldsVisible(bool value) {
  ui->totalCostLabel->setVisible(value);
  ui->foodTotalCostLabel->setVisible(value);
  ui->transportTotalCostLabel->setVisible(value);
  ui->label_5->setVisible(value);
  ui->label_7->setVisible(value);
  ui->label_9->setVisible(value);
}

void MainWindow::clearAllFields() {
  ui->daysQuantitySpinBox->setValue(0);
  ui->foodCostSpinBox->setValue(0);
  ui->transportCostSpinBox->setValue(0);
  ui->totalCostLabel->clear();
  ui->foodTotalCostLabel->clear();
  ui->transportTotalCostLabel->clear();
}

void MainWindow::on_clearButton_clicked() {
  clearAllFields();
  setFieldsVisible(false);
}
