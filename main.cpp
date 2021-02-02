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

    // 좌측 상단에 프로그램이 출력되도록 설정
    QRect geometry = QApplication::desktop()->geometry();   
    geometry.setY(0);

    QGraphicsScene scene;
    scene.setSceneRect(geometry);

    // 배경화면 이미지 설정
    QPixmap bg("E:\\Visual Studio Projects\\MatchThreePuzzleGame\\Images\\PNG\\bg.png");
    scene.setBackgroundBrush(bg);

    // 점수판 추가
    Values values;

    Board board(&scene, &values);
    Score score(&scene, &values);

    QGraphicsView view(&scene);
    // view.show();                                           //작은 화면으로 출력
    view.showFullScreen();                              // 전체 화면으로 출력

    return a.exec();
}