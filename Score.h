#pragma once

#include <QtWidgets/QGraphicsTextItem>
#include <QtWidgets/QGraphicsScene>

#include "Value.h"

class Score : public QGraphicsSimpleTextItem
{
public:
	Score(QGraphicsScene* scene, Values* values);
};