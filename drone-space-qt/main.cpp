#include <iostream>

//#include <QApplication>

#include <QPushButton>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    QPushButton *button = new QPushButton("&Download", this);

    return 0;

}
