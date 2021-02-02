#include "Score.h"
#include "Consts.h"

void observe(Score* score, const int& value)
{
	score->setText(("Score :" + std::to_string(value)).c_str());
}

Score::Score(QGraphicsScene* scene, Values* values)
{
	scene->addItem(this);
	setX(scene->sceneRect().width() / 2 - Consts::BOARD_ITEM_SIZE * Consts::BOARD_LENGTH / 2);
	setY(scene->sceneRect().height() / 2 + Consts::BOARD_ITEM_SIZE * Consts::BOARD_LENGTH / 2);
	setScale(2.5);

	values->score.observe([this](const int& value) {
		observe(this, value);
	});
}