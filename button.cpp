#include <Wt/WBrush>
#include <Wt/WColor>
//#include <Wt/WFont>
//#include <Wt/WLineF>
//#include <Wt/WPen>
#include <Wt/WContainerWidget>
#include <Wt/WPaintedWidget>
#include <Wt/WPaintDevice>
#include <Wt/WSpinBox>
#include <Wt/WPainter>
#include <Wt/WApplication>
#include <Wt/WText>
using namespace std;
using namespace Wt;
class MyPaint :public Wt::WPaintedWidget
{
public : MyPaint(Wt::WContainerWidget *parent =0)
         :Wt::WPaintedWidget(parent),end_(200) 
{
resize(500,40);
}
void setEnd(int end)
{
end_=end;
update();
}
void paintEvent(Wt::WPaintDevice *paintDevice)
{   
Wt::WPainter painter(paintDevice);
painter.setBrush(Wt::WBrush(Wt::WBrush(Wt::red)));
painter.drawRect(0,0,end_,300);
Wt::WContainerWidget *container =new Wt::WContainerWidget();
// MyPaint *paint = new MyPaint(container);
    
}
int end_; 
void setSize(double);
};

void MyPaint::setSize(double size )
{
//Wt::WContainerWidget *container =new Wt::WContainerWidget();
MyPaint *paint = new MyPaint(container);
Wt::WSpinBox *sb= new WSpinBox(container);
sb->setRange(50,500);
sb->setValue(250);
sb->changed().connect(std::bind([=] ()
{
    paint->setEnd(sb->value());
}));
}
class MyApplication : public WApplication
{
        public: MyPaint *shapes_;

               MyApplication(const WEnvironment &env): WApplication(env) {
                setTitle("Paint example");
                new MyPaint(root());
                }
};

WApplication *createApplication(const WEnvironment& env)
{
  return new MyApplication(env);
}

int main(int argc, char **argv)
{
  return WRun(argc, argv, &createApplication);
}
