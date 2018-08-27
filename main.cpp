#include "menu.h"
#include "singleton.h"
#include "downloader.h"
#include <QApplication>


Singleton* Singleton::_instance = NULL;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    w.show();
    Downloader z;
    z.getHtml("https://businessinsider.com.pl/finanse/kursy-walut");
    z.readTxt();
    return a.exec();
}
