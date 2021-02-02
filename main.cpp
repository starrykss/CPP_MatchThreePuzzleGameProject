#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>      
#include <QtWidgets/QDesktopWidget>

#include "Board.h"
#include "Value.h"
#include "Score.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ���� ��ܿ� ���α׷��� ��µǵ��� ����
    QRect geometry = QApplication::desktop()->geometry();   
    geometry.setY(0);

    QGraphicsScene scene;
    scene.setSceneRect(geometry);

    // ���ȭ�� �̹��� ����
    QPixmap bg("E:\\Visual Studio Projects\\MatchThreePuzzleGame\\Images\\PNG\\bg.png");
    scene.setBackgroundBrush(bg);

    // ������ �߰�
    Values values;

    Board board(&scene, &values);
    Score score(&scene, &values);

    QGraphicsView view(&scene);
    // view.show();                                           //���� ȭ������ ���
    view.showFullScreen();                              // ��ü ȭ������ ���

    return a.exec();
}