#pragma once

#include <QGraphicsPixmapItem>
#include <map>

#include "constants.h"
#include "tile.h"

class piece : public QGraphicsPixmapItem {
	Q_OBJECT

	int indexCurr, indexNext, moveRolled;
	QPointF coordCurr, coordNext;
	ludoConstants::status status;

public:

	using QGraphicsPixmapItem::QGraphicsPixmapItem;
	static QGraphicsPixmapItem* promptDot;
	piece(const QPixmap& icon);

	void setIndexCurr(const int indexCurr);
	void setMoveRolled(const int moveRolled);
	void setStatus(const ludoConstants::status status);

	int getIndexCurr() const;
	int getMoveRolled() const;
	ludoConstants::status getStatus() const;

	// SET TO PURE VIRTUAL METHODS LATER
	
	// retrieve the color of the piece, pure virtual
	virtual char getColor() const = 0;
	// retrieve the coordinate of the takeoff tile, pure virtual
	virtual QPointF getTakeoffTileCoord() const = 0;
	// retrieve the index of the first tile the piece lands on upon taking off, pure virtual 
	virtual int getInitialTileIndex() const = 0;
	// retrieve the index of the last tile the piece must reach before entering final approach, pure virtual
	virtual int getLastPublicTileIndex() const = 0;
	// retrieve the coordinate of the corresponding final approach tile with the index given, pure virtual
	virtual QPointF getFinalApproachTileCoord(const int& indexFinal) const = 0;
	
	/*
	virtual void checkJump();
	virtual void setToSpawn(const std::vector<piece> pieces);
	*/

signals:
	void endRound();

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	// override mouse release and implement snapping into position logic
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

private:
	
};

// derived class fo
class pieceBlue : public piece {

public:
	pieceBlue(const QPixmap& icon);
	char getColor() const override;
	QPointF getTakeoffTileCoord() const override;
	int getInitialTileIndex() const override;
	int getLastPublicTileIndex() const override;
	QPointF getFinalApproachTileCoord(const int& indexFinal) const override;
};
