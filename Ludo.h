#pragma once

#include <QtWidgets/QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QRandomGenerator>
#include <QTimer>
#include "ui_Ludo.h"

#include "piece.h"
#include "constants.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LudoClass; };
QT_END_NAMESPACE

class Ludo : public QMainWindow
{
    Q_OBJECT

public:
    Ludo(QWidget *parent = nullptr);
    ~Ludo();

signals:
    void endRound();

public slots:
    void playerRound();
    // TESTING
    void reset();

private slots:
    void delayedEndRound();

private:
    Ui::LudoClass *ui;
    int numRound, numPlayer;
    std::vector<piece*> piecesBlue, piecesGreen, piecesRed, piecesYellow;

    QGraphicsScene* graphicsSceneBoard;
    QGraphicsProxyWidget* diceProxy;

};
