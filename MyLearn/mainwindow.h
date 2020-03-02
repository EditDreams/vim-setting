#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QComboBox>
#include <QWidget>
#include <QDebug>
#include <QCheckBox>
#include <QDate>
#include <QDateEdit>
#include <QLabel>
#include <QTime>
#include <QTimeEdit>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QDial>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QFocusFrame>
#include <QFontComboBox>
#include <QLCDNumber>
#include <QLineEdit>
#include <QMenu>
#include <QMenuBar>
#include <QProgressBar>
#include <QRadioButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QSlider>
#include <QToolBar>
#include <QAction>
#include <QTabBar>
#include <QToolBox>
#include <QHBoxLayout>
#include <QToolButton>

#define QCHECKSIZE 3 //size of check number

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QComboBox *combtn;
    QCheckBox *exclusive[QCHECKSIZE];    //3
    QCheckBox *unexclusive[QCHECKSIZE];
    QButtonGroup *chk_group[2];
    QDateEdit *date_edit[3];
    QLabel *lb1[6];
    QTimeEdit *time_edit[3];
    QDial *dial[3];
    QSpinBox *spin[3];
    QDoubleSpinBox *doublespin[3];
    QFontComboBox *fontcombo[5];
    QLabel *lb_font;
    QLabel *lb2[2];
private:
    QLineEdit *edit;
    QLabel *lb_le;
    QLabel *lb_edit;
    QLineEdit *edit_em[5];
    QMenu *menu[3];
    QAction *act[2];
    QMenuBar *menubar;
    QLabel *lb_menu;
    QProgressBar *progress[2];
    QRadioButton *radio[3];
    QRadioButton *radio1[3];
    QLabel *lb_sa;
    QScrollArea *area;
    QScrollBar *vscrollbar[3];
    QScrollBar *hscrollbar[3];
    QLabel *lb_sb[3];
    QSlider *slider[4];
    QLabel *lb_sl;
    QTabBar *tabbar;
    QToolBox *toolbox;
    QHBoxLayout *lay;
    QPushButton *push_btn[3];
private slots:
    void valueChanged();
    void chkChanged();
    void changedData();

    void btnClick();
    void btnPressed();
    void btnReleased();

    void changedIndex(int idx);
    void changedFont(const QFont &f);

    void textChanged(QString str);
    void trigerMenu(QAction*act);
    void valueChangedSB(int value);
    void valueChangedSlider(int value);
    void triggerToolbar();
    void currentTab(int value);
    void changedTabBox(int value);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
