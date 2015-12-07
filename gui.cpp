#include "gui.moc"
#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "SimpleGraphics.h"
#include <QGraphicsItemGroup>
using namespace std;
gui::gui()
{
//    ctor
    CreateView();
    CreateActions();
    CreateMenus();
    CreateToolbar();
    SetActionConnection();
    QString title = "Sample";
    setWindowTitle(title);
    setMinimumSize(800, 600);
    //Display();
    //FileSaveDialog();
    //drawGraphics();

}

gui::~gui()
{
    delete widget;
    delete scene;
    //dtor
}

void gui::CreateView(){
    widget = new QWidget();//繪製painter item的物件
    setCentralWidget(widget);
    graphicsView = new QGraphicsView(widget);//要調整生成的位置
    QString gView = "graphicView";
    graphicsView->setObjectName(gView);

    scene = new QGraphicsScene();//管理painter item的物件
    graphicsView->setScene(scene);
    QVBoxLayout *layout = new QVBoxLayout;//呈現畫面
    layout->setMargin(0);
    layout->addWidget(graphicsView);
    widget->setLayout(layout);
}

void gui::SetActionConnection() {
    connect(aboutDeveloper, SIGNAL(triggered()), this, SLOT(MessageDialog()));
    connect(openFile, SIGNAL(triggered()), this, SLOT(FileOpenDialog()));
    connect(saveFile, SIGNAL(triggered()), this, SLOT(FileSaveDialog()));

    connect(createCircle, SIGNAL(triggered()), this, SLOT(createCircleItem()));
    connect(createRectangle, SIGNAL(triggered()), this, SLOT(createRectangleItem()));
    connect(createSquare, SIGNAL(triggered()), this, SLOT(createSquareItem()));

}

void gui::CreateActions() {
    aboutDeveloper = new QAction("aboutDeveloper", widget);
    openFile = new QAction("openFile", widget);
    saveFile = new QAction("saveFile", widget);

    createCircle = new QAction("createCircle", widget);
    createRectangle = new QAction("createRectangle", widget);
    createSquare = new QAction("createSquare", widget);

    QIcon openFileicon;
    openFileicon.addFile(QStringLiteral("./img/openFile.png"), QSize(), QIcon::Normal, QIcon::Off);
    openFile->setIcon(openFileicon);

    QIcon saveFileicon;
    saveFileicon.addFile(QStringLiteral("./img/saveFile.png"), QSize(), QIcon::Normal, QIcon::Off);
    saveFile->setIcon(saveFileicon);

    QIcon createCircleicon;
    createCircleicon.addFile(QStringLiteral("./img/circle.ico"), QSize(), QIcon::Normal, QIcon::Off);
    createCircle->setIcon(createCircleicon);

    QIcon createRectangleicon;
    createRectangleicon.addFile(QStringLiteral("./img/rectangle.ico"), QSize(), QIcon::Normal, QIcon::Off);
    createRectangle->setIcon(createRectangleicon);

    QIcon createSquareicon;
    createSquareicon.addFile(QStringLiteral("./img/square.png"), QSize(), QIcon::Normal, QIcon::Off);
    createSquare->setIcon(createSquareicon);
}

void gui::CreateMenus() {

     file = menuBar()->addMenu("File");
     file->addAction(openFile);
     file->addAction(saveFile);

     about = menuBar()->addMenu("About");
     about->addAction(aboutDeveloper);
}

void gui::CreateToolbar(){

    toolbar = addToolBar("toolbar");
    toolbar->addAction(openFile);
    toolbar->addAction(saveFile);
    toolbar->addAction(createCircle);
    toolbar->addAction(createRectangle);
    toolbar->addAction(createSquare);
}
void gui::Display() {

    SimpleGraphics g1(new Circle(100,100,50));
    SimpleGraphics g2(new Circle(100,100,100));
    Painter *item1 = new Painter((g1.getBoundingBox()).llx(),(g1.getBoundingBox()).lly(), (g1.getBoundingBox()).getL(), (g1.getBoundingBox()).getW(), g1.shape()->describe(), QPen(Qt::blue));
    Painter *item2 = new Painter((g2.getBoundingBox()).llx(),(g2.getBoundingBox()).lly(), (g2.getBoundingBox()).getL(), (g2.getBoundingBox()).getW(), g1.shape()->describe(), QPen(Qt::blue));

    // Group all selected items together
    QGraphicsItemGroup *group = scene->createItemGroup(scene->selectedItems());
    group->setFlag(QGraphicsItem::ItemIsMovable);
    group->addToGroup(item1);
    group->addToGroup(item2);
    scene->addItem(group);
    scene->update();//¨ê·sµe­±



}

void gui::MessageDialog() {
    QMessageBox msgbox;
    std::string message("102318120\n");
    message += std::string("author:Chang Ting-Jhih\n");
    QString qstr = QString::fromStdString(message);
    msgbox.setText(qstr);
    msgbox.exec();
}


void gui::FileOpenDialog(){
   QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                QDir::currentPath(),
                                                tr("Text files (*.txt);;All files (*.*)"));

    string filePath = fileName.toStdString();


    if(fileName.length()>4){
        std::replace( filePath.begin(), filePath.end(), '/', '\\');
        int found=filePath.find_first_of("\\");
        filePath.insert(found,"\\");

        scene->clear();//清除原有的場景

        GraphicsFactory graphicsFactory;
        Graphics *graphics=graphicsFactory.buildGraphicsFromFile(filePath.c_str());

        graphics->accept(descriptionVisitor);
        fileContent = descriptionVisitor.getDescription();
        drawGraphics(graphics);
    }
}

void gui::FileSaveDialog(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                           QDir::currentPath(),
                           tr("Text files (*.txt);;All files (*.*)"));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << fileContent.c_str();
}

void gui::drawGraphics(Graphics *graphics){
    //graphics->accept(descriptionVisitor);
    drawVisitor.setScene(scene);
    graphics->accept(drawVisitor);

    //delete graphicsFactory;
}

void gui::createCircleItem(){
    SimpleGraphics g1(new Circle(100,100,50));
    Painter *item = new Painter((g1.getBoundingBox()).llx(),(g1.getBoundingBox()).lly(), (g1.getBoundingBox()).getL(), (g1.getBoundingBox()).getW(),  g1.shape()->describe(), QPen(Qt::blue));
    scene->addItem(item);
}

void gui::createRectangleItem(){
    SimpleGraphics g1(new Rectangle(0,0,100,50));
    Painter *item = new Painter((g1.getBoundingBox()).llx(),(g1.getBoundingBox()).lly(), (g1.getBoundingBox()).getL(), (g1.getBoundingBox()).getW(),  g1.shape()->describe(), QPen(Qt::blue));
    scene->addItem(item);
}

void gui::createSquareItem(){
    SimpleGraphics g1(new Square(0,0,50));
    Painter *item = new Painter((g1.getBoundingBox()).llx(),(g1.getBoundingBox()).lly(), (g1.getBoundingBox()).getL(), (g1.getBoundingBox()).getW(),  g1.shape()->describe(), QPen(Qt::blue));
    scene->addItem(item);
}
