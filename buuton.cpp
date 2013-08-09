#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WPainter>
#include <Wt/WPaintedWidget>
#include <Wt/WPaintDevice>
#include <Wt/WBreak>
#include <Wt/WPushButton>
using namespace Wt;
using namespace std;
      
class PaintApplication : public WPaintedWidget
{
        int angle_,size_; 
        public: PaintApplication(WContainerWidget *parent)
                : WPaintedWidget(parent),
                        angle_(0),size_(1) 
                {
                 WContainerWidget *container=new Wt::WContainerWidget(root());
                 WPushButton *b=new WPushButton(container);
                    container->addWidget(new WBreak());
                  b->clicked.connect(this,&PaintApplication::setRelativeSize);
 resize(710, 400);
                }


void paintEvent(WPaintDevice *paintDevice) //function to draw rectangle
{

            WPainter painter(paintDevice);
            painter.setBrush(Wt::WBrush(Wt::WBrush(Wt::red)));
            painter.drawRect(10,10,180,180);
           // WContainerWidget *container=new Wt::WContainerWidget(root());
           // WPushButton *b=new WPushButton(container);  
            //container->addWidget(new WBreak());
            //b->clicked().connect(this, PaintApplication::setRelativeSize);

}

void setRelativeSize(double);

};

void PaintApplication::setRelativeSize(double size) //function to define size of rectangle
 {
   size = std::max(0.1, std::min(1.0, size));
   if (size_ != size) {
     size_ = size;
 update();
   }
 }

class MyApplication : public WApplication
{
        PaintApplication *shapes_;
        public: MyApplication(const WEnvironment &env): WApplication(env) {
                setTitle("Paint example");
                new PaintApplication(root());
                }
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

