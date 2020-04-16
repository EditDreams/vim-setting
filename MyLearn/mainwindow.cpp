#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setGeometry(20,20,500,600);

    /*combtn=new QComboBox(this);
    //combtn->setGeometry(10,10,100,100);
    combtn->addItem("0.hello");
    combtn->addItem("1.world");
    combtn->addItem(QIcon("/home/abner/Desktop/0101.png"),"2.png");

    bool ret=connect(combtn,SIGNAL(currentIndexChanged(int)),this,SLOT(valueChanged()));
    if(true==ret)
        qDebug()<<"successful\n";
    else {
        qDebug()<<"failed\n";
    }*/

    //QCheckBox make two group for examples
    /*chk_group[0]=new QButtonGroup(this);
    chk_group[1]=new QButtonGroup(this);
    int xpos=20;
    int ypos=20;
    QString str_chk_1[3]={"red","green","yellow"};
    QString str_chk_2[4]={"up","down","left"};

    for(int i=0;i<QCHECKSIZE;++i){
        exclusive[i]=new QCheckBox(str_chk_1[i],this);
        exclusive[i]->setGeometry(xpos,ypos,100,30);
        chk_group[0]->addButton(exclusive[i]);  //first group setExclusive(flase)

        unexclusive[i]=new QCheckBox(str_chk_2[i],this);
        unexclusive[i]->setGeometry(xpos+120,ypos,100,30);
        chk_group[1]->addButton(unexclusive[i]);//true

        connect(exclusive[i],SIGNAL(clicked()),this,
                SLOT(chkChanged()));
        //unexclusive is not connect.
        ypos+=40;
    }
    chk_group[0]->setExclusive(false); //more than one choose
    chk_group[1]->setExclusive(true);  //one choose*/

    //QDate  QDateEdit
    /*QDate dt1=QDate(2020,02,28);
    QDate dt2=QDate::currentDate();
    date_edit[0]=new QDateEdit(dt1.addYears(2),this);
    date_edit[0]->setGeometry(10,10,140,40);
    date_edit[1]=new QDateEdit(dt1.addYears(-2),this);
    date_edit[1]->setGeometry(160,10,140,40);
    date_edit[2]=new QDateEdit(dt2,this);
    date_edit[2]->setGeometry(10,60,140,40);

    switch(dt2.dayOfWeek())
    {
    case 1:
        qDebug()<<"Monday";
        break;
    case 2:
        qDebug()<<"Tuesday";
        break;
    case 3:
        qDebug()<<"Wednesday";
        break;
    case 4:
        qDebug()<<"Thursday";
        break;
    case 5:
        qDebug()<<"Friday";
        break;
    case 6:
        qDebug()<<"Saturday";
        break;
    case 7:
        qDebug()<<"Sunday";
        break;
    }
    qDebug("Day of year:%d\n",dt1.dayOfYear());
    qDebug("End Day:%d\n",dt1.daysInMonth());
    qDebug("End Day:%d",dt1.daysInYear());

    QDate dt3=QDate::fromString("2020.02.29","yyyy.MM.dd");
    QDate dt4=QDate::fromString("06.26","MM.dd");

    lb1[0]=new QLabel(dt3.toString(),this);
    lb1[0]->setGeometry(10,110,150,30);
    lb1[1]=new QLabel(dt4.toString(),this);
    lb1[1]->setGeometry(10,150,150,30);

    if(QDate::isValid(3333,3,3)){
        qDebug("3333,3,3 true");
    }
    else {
        qDebug("3333,3,3  false");
    }
    QDate dt5=QDate(2020,2,29);

    QString long_week=dt5.longDayName(dt5.dayOfWeek());
    QString long_month=dt5.longMonthName(dt5.month());
    QString str_date_long=QString("%1 %2").arg(long_week).arg(long_month);

    QString short_week=dt5.shortDayName(dt5.dayOfWeek());
    QString short_month=dt5.shortMonthName(dt5.month());
    QString str_date_short=QString("%1 %2").arg(short_week).arg(short_month);

    lb1[2]=new QLabel(QString("long:%1 short:%2").arg(str_date_long).arg(str_date_short),this);
    lb1[2]->setGeometry(10,190,250,30);

    QDate dt6=QDate(2020,2,29);
    lb1[3]=new QLabel(dt6.toString(Qt::TextDate),this);  //default style
    lb1[3]->setGeometry(10,240,250,30);

    lb1[4]=new QLabel(dt6.toString(Qt::ISODate),this);  //ISO8601 style
    lb1[4]->setGeometry(10,270,250,30);

    lb1[5]=new QLabel(dt6.toString(Qt::SystemLocaleDate),this);  //international style
    lb1[5]->setGeometry(10,300,250,30);*/


    //QTime QTimeEdit
    /*QTime ti1=QTime(12,12,55,432);//hour min sec millisecond
    QTimeEdit *qte;
    qte =new QTimeEdit(ti1,this);
    //delete qte;
    qte->setGeometry(10,30,150,30);
    QLabel *lbl_tostring=new QLabel(ti1.toString("AP hh:mm:ss:zzz"),this);
    lbl_tostring->setGeometry(200,30,150,30);

    time_edit[0]=new QTimeEdit(ti1.addMSecs(200),this);//add 200 milliseconds
    time_edit[0]->setGeometry(10,60,150,30);

    QTime ti2=QTime::currentTime();
    time_edit[1]=new QTimeEdit(ti2,this);
    time_edit[1]->setGeometry(10,90,150,30);

    QTime ti3;
    ti3.start();
    for (int i=0;i<10000;++i) {
        for(int j=0;j<10000;++j)
        {
            ;
        }
    }
    qDebug("time is:%d",ti3.elapsed());

    QTime ti4=QTime::fromString("03:32","hh:mm");
    QLabel *lbl_fromstring=new QLabel(ti4.toString(),this);
    lbl_fromstring->setGeometry(10,120,150,30);
    qDebug()<<"hour:"<<ti2.hour()<<"min:"<<ti2.minute()<<"sec:"<<ti2.second()<<"msec"<<ti2.msec();
    */

    //QDateTime  QDateTimeEdit
    /*QDateTimeEdit *qdte1;
    qdte1=new QDateTimeEdit(QDateTime::currentDateTime(),this);
    qdte1->setDisplayFormat("yyyy-MM-dd hh:mm:ss:zzz");
    qdte1->setGeometry(10,30,250,50);

    //little modify the time
    QDateTimeEdit *qde[3];
    qde[0]=new QDateTimeEdit(QDate::currentDate(),this);
    qde[0]->setMinimumDate(QDate::currentDate().addYears(-3));
    qde[0]->setMaximumDate(QDate::currentDate().addYears(3));
    qde[0]->setDisplayFormat("yyyy");
    qde[0]->setGeometry(10,90,100,50);

    qde[1]=new QDateTimeEdit(QDate::currentDate(),this);
    qde[1]->setMinimumDate(QDate::currentDate().addMonths(-2));
    qde[1]->setMaximumDate(QDate::currentDate().addMonths(2));
    qde[1]->setDisplayFormat("MM");
    qde[1]->setGeometry(110,90,100,50);

    qde[2]=new QDateTimeEdit(QDate::currentDate(),this);
    qde[2]->setMinimumDate(QDate::currentDate().addDays(-20));
    qde[2]->setMaximumDate(QDate::currentDate().addDays(20));
    qde[2]->setDisplayFormat("dd");
    qde[2]->setGeometry(210,90,100,50);
    */

    //QDial
    /*int xpos=30;
    for (int i=0;i<3;++i,xpos+=110) {
        dial[i]=new QDial(this);
        dial[i]->setRange(0,100);
        dial[i]->setGeometry(xpos,30,100,100);
    }
    dial[0]->setNotchesVisible(true);
    connect(dial[0],SIGNAL(valueChanged(int)),this,SLOT(changedData()));
    */

    //QSpinBox QDoubleSpinBox
    /*int xpos=10;
    int ypos=30;
    int val[3]={50,100,200};
    double double_val[3]={50.5,127.32,171.342};
    for (int i=0;i<3;++i) {
        spin[i]=new QSpinBox(this);
        spin[i]->setMinimum(10);
        spin[i]->setMaximum(300);
        spin[i]->setValue(val[i]);
        spin[i]->setGeometry(xpos,ypos,100,30);

        doublespin[i]=new QDoubleSpinBox(this);
        doublespin[i]->setMinimum(10.0);
        doublespin[i]->setMaximum(300.0);
        doublespin[i]->setValue(double_val[i]);
        doublespin[i]->setGeometry(xpos+110,ypos,100,30);

        ypos+=40;
    }
    */


    //QPushButton QFocusFrame
    /*QPushButton *btn[3];
    int ypos=30;
    for (int i=0;i<3;++i) {
        btn[i]=new QPushButton(QString("Frame's button %1").arg(i),this);
        btn[i]->setGeometry(10,ypos,300,40);

        ypos+=50;
    }
    connect(btn[0],SIGNAL(clicked()),this,SLOT(btnClick()));
    connect(btn[0],SIGNAL(pressed()),this,SLOT(btnPressed()));
    connect(btn[0],SIGNAL(released()),this,SLOT(btnReleased()));

    QFocusFrame *btn_frame=new QFocusFrame(this);
    btn_frame->setWidget(btn[0]);
    btn_frame->setAutoFillBackground(true);
    */

    //QFontComboBox
    /*for (int i=0;i<5;++i) {
        fontcombo[i]=new QFontComboBox(this);
    }

    fontcombo[0]->setFontFilters(QFontComboBox::AllFonts);
    fontcombo[1]->setFontFilters(QFontComboBox::ScalableFonts);
    fontcombo[2]->setFontFilters(QFontComboBox::NonScalableFonts);
    fontcombo[3]->setFontFilters(QFontComboBox::MonospacedFonts);
    fontcombo[4]->setFontFilters(QFontComboBox::ProportionalFonts);

    int ypos=30;
    for (int i=0;i<5;++i) {
        fontcombo[i]->setGeometry(10,ypos,300,30);
        ypos+=40;
    }
    lb_font=new QLabel("hello world",this);
    lb_font->setGeometry(10,ypos,200,30);

    connect(fontcombo[0],SIGNAL(currentIndexChanged(int)),this,
                         SLOT(changedIndex(int)));
    connect(fontcombo[0],SIGNAL(currentFontChanged(QFont)),this,
                         SLOT(changedFont(const QFont &)));
                         */

    //QLabel QLCDNumber
    /*lb2[0]=new QLabel("hello world",this);
    lb2[0]->setGeometry(10,30,200,40);

    QPixmap pix=QPixmap("/home/abner/Desktop/0101.png");

    lb2[1]=new QLabel(this);
    lb2[1]->setPixmap(pix);
    lb2[1]->setGeometry(10,70,100,100);

    QLCDNumber *lcd[2];
    lcd[0]=new QLCDNumber(2,this);
    lcd[0]->display(24);
    lcd[0]->setGeometry(150,30,200,100);

    lcd[1]=new QLCDNumber(5,this);
    lcd[1]->display("10:06");
    lcd[1]->setGeometry(150,140,200,100);

    lcd[1]->setSegmentStyle(QLCDNumber::Outline);
    */


    //QLineEdit
    /*edit=new QLineEdit(" ",this);
    edit->setGeometry(10,30,100,50);
    lb_edit=new QLabel(this);
    lb_le=new QLabel("QLineEdit Text:",this);
    lb_le->setGeometry(10,100,100,50);

    connect(edit,SIGNAL(textChanged(QString)),this,
                 SLOT(textChanged(QString)));

    int ypos=150;
    for(int i=0;i<5;++i)
    {
        edit_em[i]=new QLineEdit("good morning!",this);
        edit_em[i]->setGeometry(10,ypos,200,40);
        ypos+=50;
    }
    edit_em[0]->setEchoMode(QLineEdit::Normal);
    edit_em[1]->setEchoMode(QLineEdit::NoEcho);
    edit_em[2]->setEchoMode(QLineEdit::Password);
    edit_em[3]->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    */

    //QMenu QMenuBar
    /*menu[0]=new QMenu("File");
    menu[0]->addAction("Edit");
    menu[0]->addAction("View");
    menu[0]->addAction("Tools");

    act[0]=new QAction("New",this);
    act[0]->setShortcut(Qt::CTRL|Qt::Key_A);
    act[0]->setStatusTip("this is a new menu");

    act[1]=new QAction("open",this);
    act[1]->setCheckable(true);

    menu[1]=new QMenu("save");
    menu[1]->addAction(act[0]);
    menu[1]->addAction(act[1]);

    menu[2]=new QMenu("print");
    menu[2]->addAction("page setup");
    menu[2]->addMenu(menu[1]);

    menubar=new QMenuBar(this);
    menubar->addMenu(menu[0]);
    menubar->addMenu(menu[2]);

    lb_menu=new QLabel(this);
    lb_menu->setGeometry(200,200,150,30);
    connect(menubar,SIGNAL(triggered(QAction*)),this,
                    SLOT(trigerMenu(QAction*)));
    */


    //QProgressBar
    /*progress[0] =new QProgressBar(this);
    progress[0]->setGeometry(0,0,100,30);
    progress[0]->setMinimum(0);
    progress[0]->setMaximum(100);
    progress[0]->setValue(50);
    progress[0]->setOrientation(Qt::Horizontal);

    progress[1] =new QProgressBar(this);
    progress[1]->setGeometry(0,60,100,30);
    progress[1]->setMinimum(0);
    progress[1]->setMaximum(100);
    progress[1]->setValue(75);
    progress[1]->setOrientation(Qt::Horizontal);
    progress[1]->setInvertedAppearance(true);//direction
    */


    //QRadioButton
    /*QString str_rb_1[3]={"apple","orange","book"};
    int ypos=30;
    for (int i=0;i<3;++i) {
        radio[i]=new QRadioButton(str_rb_1[i],this);
        radio[i]->setGeometry(10,ypos,150,30);

        ypos+=40;
    }
    QString str_rb_2[3]={"In-Vehicle","Smart TV","Media Phone"};
    ypos=30;
    for (int i=0;i<3;++i) {
        radio1[i]=new QRadioButton(str_rb_2[i],this);
        if(i==2)
            radio1[i]->setChecked(true);
        radio1[i]->setGeometry(180,ypos,150,30);
        ypos+=40;
    }
    */


    //QScrollArea
    /*QImage image("/home/abner/Desktop/test.jpg");
    lb_sa=new QLabel(this);
    lb_sa->setPixmap(QPixmap::fromImage(image));
    area=new QScrollArea(this);
    area->setWidget(lb_sa);
    area->setBackgroundRole(QPalette::Dark);
    area->setGeometry(0,0,image.width(),image.height()-60);
    */

    //QScrollBar
    /*int xpos=10;
    int ypos=50;
    for (int i=0;i<3;++i) {
        vscrollbar[i]=new QScrollBar(Qt::Vertical,this);
        vscrollbar[i]->setRange(0,100);
        vscrollbar[i]->setGeometry(xpos,30,20,200);

        lb_sb[i]=new QLabel(QString("%1").arg(vscrollbar[i]->value()),this);
        lb_sb[i]->setGeometry(xpos+2,220,30,30);
        xpos+=50;

        hscrollbar[i]=new QScrollBar(Qt::Horizontal,this);
        hscrollbar[i]->setRange(0,100);
        hscrollbar[i]->setGeometry(150,ypos,200,20);
        ypos+=30;
    }

    connect(vscrollbar[0],SIGNAL(valueChanged(int)),this,
            SLOT(valueChangedSB(int)));
    */


    //QSlider
    /*int xpos=0;
    int ypos=0;
    for (int i=0;i<4;++i) {
        if(i<=2){
            slider[i]=new QSlider(Qt::Vertical,this);
            slider[i]->setGeometry(xpos,20,30,80);
            xpos+=30;
        }
        else if (i>=3) {
           slider[i]=new QSlider(Qt::Horizontal,this);
           slider[i]->setGeometry(130,ypos,80,30);
           ypos+=30;
        }
        slider[i]->setRange(0,100);
        slider[i]->setValue(50);
    }
    lb_sl=new QLabel(this);

    connect(slider[0],SIGNAL(valueChanged(int)),this,
            SLOT(valueChangedSlider(int)));
            */


    //QTabWidget
    /*QTabWidget *tab=new QTabWidget(this);
    tab->setGeometry(50,50,200,200);
    QWidget *browser_tab=new QWidget;
    QWidget *user_tab=new QWidget;

    tab->addTab(browser_tab,QIcon("/home/abner/givemefive/QT/browser.png"),"Browser");
    tab->addTab(user_tab,QIcon("/home/abner/givemefive/QT/user.png"),"User");

    QString btn_str[3]={"button1","button2","button3"};
    QPushButton *btn[3];

    int ypos=30;
    for (int i=0;i<3;++i) {
        btn[i]=new QPushButton(btn_str[i],browser_tab);
        btn[i]->setGeometry(10,ypos,100,40);
        ypos+=50;
    }

    //connect(tab,SIGNAL(currentchanged(int)),
    */


    //QToolBar  QAction
    /*QToolBar *toolbar=new QToolBar(this);
    toolbar->setFixedSize(500,30);
    QAction *act[2];

    act[0]=new QAction(QIcon("/home/abner/givemefive/QT/browser.png"),"Browser",this);
    act[1]=new QAction(QIcon("/home/abner/givemefive/QT/user.png"),"User",this);

    act[0]->setShortcut(Qt::Key_Control|Qt::Key_E);
    act[0]->setToolTip("this is a tooltip");

    for (int i=0;i<2;++i) {
        toolbar->addAction((act[i]));
    }

    toolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    connect(act[0],SIGNAL(triggered()),this,
            SLOT(triggerToolbar()));
            */

    //QTabBar
    /*tabbar=new QTabBar(this);
    tabbar->setFixedSize(300,200);
    tabbar->setGeometry(0,50,400,400);
    tabbar->addTab("Browser");
    tabbar->addTab("User");
    tabbar->addTab("Application");

    connect(tabbar,SIGNAL(currentChanged(int)),this,
            SLOT(currentTab(int)));
            */


    //QToolBox
    /*toolbox=new QToolBox(this);
    toolbox->setFixedSize(200,200);
    lay=new QHBoxLayout(this);

    push_btn[0]=new QPushButton("database - 1",this);
    push_btn[1]=new QPushButton("network - 2",this);
    push_btn[2]=new QPushButton("graphlics - 3",this);
    toolbox->addItem(push_btn[0],"database");
    toolbox->addItem(push_btn[1],"network");
    toolbox->addItem(push_btn[2],"graphlics");

    lay->addWidget(toolbox);
    setLayout(lay);


    connect(toolbox,SIGNAL(currentChanged(int)),this,
            SLOT(changedTabBox(int)));

    */


    //QToolButton
    QToolBar *tool=new QToolBar(this);

    QToolButton *button=new QToolButton;
    button->setIcon(QIcon("/home/abner/givemefive/QT/browser.png"));

    QToolButton *button_1=new QToolButton;
    button_1->setIcon(QIcon("/home/abner/givemefive/QT/user.png"));

    tool->addWidget(button);
    tool->addWidget(button_1);
    tool->addSeparator();

}
void MainWindow::changedTabBox(int value)
{
    qDebug()<<value;
}
void MainWindow::currentTab(int value)
{
    qDebug()<<"current value is:"<<value;
}
void MainWindow::triggerToolbar()
{
    qDebug()<<"tool button 1 click";
}
void MainWindow::valueChangedSlider(int value)
{
    lb_sl->setText(QString("%1").arg(value));
    slider[3]->setValue(slider[0]->value());
}
void MainWindow::valueChangedSB(int value)
{
    lb_sb[0]->setText(QString("%1").arg(value));
    hscrollbar[0]->setValue(vscrollbar[0]->value());
}
void MainWindow::trigerMenu(QAction*act)
{
    QString str=QString("selected menu:%1").arg(act->text());
    lb_menu->setText(str);
}
void MainWindow::textChanged(QString str)
{
    lb_edit->setText(str);
    lb_edit->setGeometry(110,100,100,50);
}
void MainWindow::changedIndex(int idx)
{
    int current_index=idx;
    qDebug()<<"current index is:"<<current_index;
}
void MainWindow::changedFont(const QFont &f)
{
    QFont font=f;
    lb_font->setFont(font);
    qDebug()<<"font is :"<<font;
}
void MainWindow::btnClick()
{
    qDebug()<<"btnClick()";
}
void MainWindow::btnPressed()
{
    qDebug()<<"btnPressed()";
}
void MainWindow::btnReleased()
{
    qDebug()<<"btnRelease()";
}
void MainWindow::changedData()
{
    qDebug()<<"QDial 1 value :"<<dial[0]->value();
}
void MainWindow::chkChanged()
{
    qDebug()<<"function chkChanged is called\n";
}
void MainWindow::valueChanged()
{
    int currentIndex=combtn->currentIndex();
    QString currentText=combtn->currentText();
    qDebug()<<"now index is:"<<currentIndex<<'\t'<<currentText;
}

MainWindow::~MainWindow()
{
    delete combtn;
    for(int i=0;i<2;++i){
        if(chk_group!=nullptr)
            delete chk_group[i];
    }
    for(int i=0;i<3;++i){
        if(exclusive!=nullptr||unexclusive!=nullptr||date_edit!=nullptr){
            delete exclusive[i];
            delete unexclusive[i];
            delete date_edit[i];
        }
    }
    for (int i=0;i<6;++i) {
        if(lb1[i]!=nullptr)
            delete lb1[i];
    }
    //......
    delete ui;
}
