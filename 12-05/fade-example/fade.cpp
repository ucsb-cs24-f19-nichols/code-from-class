#include <QApplication>
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QDesktopWidget>

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void pause(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

class ImageUpdateThread : public QThread
{
    Q_OBJECT
public:
    void run();
    ImageUpdateThread(QGraphicsPixmapItem &item) : item(item) {}
    void doRequestRedraw(QImage *i) {
        emit requestRedraw(i);
    }
signals:
    void requestRedraw(QImage *i);
private:
    QGraphicsPixmapItem &item;
};

/***********************************************
 * 
 * Begin code that you should read
 *
 * *********************************************/

void pause(int milliseconds); // stop the program for a certain number of ms

struct Color {
    Color(int r, int g, int b) : r(r), g(g), b(b) {}
    int r;
    int g;
    int b;
};

class Image {
public:
    Image(QGraphicsPixmapItem &item, ImageUpdateThread &thread); // don't worry about the constructor
    void changePixels();
    void commitChanges() const;
private:
    vector<vector<Color>> pixels; // 2d array pixels[5][7]

    // don't worry about these last two things
    QGraphicsPixmapItem &item;
    ImageUpdateThread &thread;
};

// comparison class that prioritizes (Color *)s, lighter ones first
// operator() (a, b) returns true when b is of higher priority than a
class LighterPixelsFirst {
public:
    bool operator() (const Color *a, const Color *b) {
        double brightnessA = (a->r + a->g + a->b) / 3.0 / 255;
        double brightnessB = (b->r + b->g + b->b) / 3.0 / 255;

        // brighter means closer to 1.0
        // 1.0 is the highest value 
        // so greater values means lighter colors

        return brightnessB > brightnessA;
    }
};

void Image::changePixels() {
    // add all the pixels to a priority_queue, prioritized how we choose

    // repeatedly:
    //   - change some pixels (we don't want to change all of them at once
    //                         because we want this to be animated!)
    //   - commit those changes (update the screen)
    //   - wait a little bit to process more pixels (frame rate)

    // our heap holds pointers to pixels, because we want to update
    // the actual pixel in the pixels vector
    priority_queue<Color*, vector<Color*>, LighterPixelsFirst> pq;

    // iterate through every pixel in the image and add 
    // a pointer to it to the pq heap
    for (unsigned int i = 0; i < pixels.size(); i++) {
        for (unsigned int j = 0; j < pixels[i].size(); j++) {
            pq.push(&pixels[i][j]);
        }
    }

    // now I'll pop all the pixels off the heap and put them into a queue (later a stack)
    // they'll then be in the queue in lightest to darkest order (or in the stack ...)
    
    // put everything in order
    // queue<Color*> order;
    stack<Color*> order;
    while (!pq.empty()) {
        order.push(pq.top());
        pq.pop();
    }

    // take a few pixels out of our order data structure and change them to white

    // get a few out at a time and update
    while (!order.empty()) {
        const int num_entries_to_pop_per_frame = 10000; // change 10000 pixels to white at once (per frame)
        const int num_milliseconds_to_wait = 25; // wait 25 milliseconds in between frames

        for (int i = 0; i < num_entries_to_pop_per_frame && !order.empty(); i++) {
            // pop from the order data structure and change the Color
            // Color *c = order.front(); // queue
            Color *c = order.top(); // stack
            order.pop();
            c->r = c->g = c->b = 255; // fade to white
            // c->r = c->g = c->b = 0; // fade to black
            // c->r = c->g = c->b = (c->r + c->g + c->b) / 3; // fade to grayscale
        }

        // commit the changes
        commitChanges();
        
        // wait a short amount of time
        pause(num_milliseconds_to_wait);
    }
}

/***********************************************
 * 
 * End code that you should read
 *
 * *********************************************/

void Image::commitChanges() const {
    QImage *img = new QImage(item.pixmap().toImage());
    for (int i = 0; i < img->width(); i++) {
        for (int j = 0; j < img->height(); j++) {
            Color currentValue = pixels[i][j];
            int r = currentValue.r;
            int g = currentValue.g;
            int b = currentValue.b;
            img->setPixel(i, j, qRgb(r, g, b));
        }
    }
    thread.doRequestRedraw(img);
    // QPixmap img_to_pixmap = QPixmap::fromImage(img);
    // item.setPixmap(img_to_pixmap.scaled(1500,1500,Qt::KeepAspectRatio));
}

Image::Image(QGraphicsPixmapItem &item, ImageUpdateThread &thread) : item(item), thread(thread) {
    QImage img = item.pixmap().toImage();
    for (int i = 0; i < img.width(); i++) {
        vector<Color> column;
        for (int j = 0; j < img.height(); j++) {
            QColor currentValue = img.pixelColor(i, j);
            int r = currentValue.red();
            int g = currentValue.green();
            int b = currentValue.blue();
            column.push_back(Color(r, g, b));
        }
        pixels.push_back(column);
    }
}

void ImageUpdateThread::run()
{
    pause(500);
    Image i(item, *this);
    i.changePixels();

    // QImage img = item.pixmap().toImage();
    // doRequestRedraw(&img);

    // exec();
    exit(0);
}

class MyApplication : public QApplication {
    Q_OBJECT
public:
    MyApplication(int &argc, char **argv) : QApplication(argc, argv) {}
public slots:
    void redraw(QImage *i) {
        QPixmap img_to_pixmap = QPixmap::fromImage(*i);
        delete i;
        item->setPixmap(img_to_pixmap.scaled(1500,1500,Qt::KeepAspectRatio));
    }
public:
    QGraphicsPixmapItem *item;
};

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    MyApplication a(argc, argv);

    QGraphicsScene scene;
    QGraphicsView view(&scene);
    // YOU'LL HAVE TO CHANGE THE PATH BELOW IF YOU
    // WANT THIS TO WORK ON YOUR MACHINE
    const char *image_file = "/Users/lawtonnichols/Desktop/cs24/code-from-class/12-05/fade-example/sunset.jpg";
    QPixmap pixmap = QPixmap(image_file);
    pixmap.setDevicePixelRatio(2.0);

    QGraphicsPixmapItem item(pixmap);
    a.item = &item;

    scene.addItem(&item);

    // int w = scene.width();
    // int h = scene.height();

    // pixmap = pixmap.scaled(w,h,Qt::KeepAspectRatio);

    item.setPixmap(pixmap.scaled(1500,1500,Qt::KeepAspectRatio));

    // QImage img = item.pixmap().toImage();
    // for (int i = 0; i < img.width(); i++) {
    //     for (int j = 0; j < img.height(); j++) {
    //         QColor currentValue = img.pixelColor(i, j);
    //         int r = currentValue.red();
    //         int g = currentValue.green();
    //         int b = currentValue.blue();
    //         int avg = (r + g + b) / 3;
    //         img.setPixel(i, j, qRgb(avg, avg, avg));
    //     }
    // }
    // QPixmap img_to_pixmap = QPixmap::fromImage(img);
    // item.setPixmap(img_to_pixmap.scaled(1500,1500,Qt::KeepAspectRatio));

    view.show();

    // QTimer t;
    // QObject::connect(&t, &QTimer::timeout, [&](){
    //     Image i(item);
    //     i.changePixels();
    // });
    // t.setSingleShot(true);
    // t.start(2000);

    ImageUpdateThread iut(item);
    QObject::connect(&iut, SIGNAL(requestRedraw(QImage*)), &a, SLOT(redraw(QImage*)));
    iut.start();

    return a.exec();
}

#include "fade.moc"