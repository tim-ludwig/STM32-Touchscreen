/*
 * TicTacToeGame.cpp
 *
 *  Created on: 17 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/components/TicTacToeComponent.h>
#include "Color.h"

namespace touchlib {
	static WORD min(WORD a, WORD b) {
		return a < b ? a : b;
	}

	TicTacToeComponent::TicTacToeComponent(TicTacToeGame& _g, bool _ai, int _width, int _height) : g(_g), ai(_ai) {
		sideLength = min(_width, _height);

		cellSize = sideLength / 3;
		int x = sideLength < _width ? (_width - sideLength) / 2 : 0;
		int y = sideLength < _height ? (_height - sideLength) / 2 : 0;

		box = BoundingBox { x, y, sideLength, sideLength };
	}

	void TicTacToeComponent::onEvent(TouchEvent& event) {
		if(ai && g.getCurrentPlayer() == 'o') {
			return;
		}

		WORD col = (event.getX() - box.x()) / cellSize;
		WORD row = (event.getY() - box.y()) / cellSize;

		g.doMove(Move(row, col));
	}

	void TicTacToeComponent::onEvent(DragEvent& event) {}
	void TicTacToeComponent::onEvent(ReleaseEvent& event) {}

	void TicTacToeComponent::show(cDevDisplayGraphic& lcd) {
		lcd.drawRectangle(0, 0, lcd.getWidth(), lcd.getHeight(), Color::White);

		for (int i = 0; i <= 3; i++) {
			lcd.drawLine(box.x(), box.y() + i * cellSize, box.x() + sideLength, box.y() + i * cellSize, 1, Color::Black);
			lcd.drawLine(box.x() + i * cellSize, box.y(), box.x() + i * cellSize, box.y() + sideLength, 1, Color::Black);
		}

		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 3; col++) {
				WORD l = box.x() + col * cellSize;
				WORD u = box.y() + row * cellSize;
				WORD r = l + cellSize;
				WORD d = u + cellSize;

				switch (g.at(row, col)) {
				case 'x':
					lcd.drawLine(l + 10, u + 10, r - 10, d - 10, 2, Color::Blue);
					lcd.drawLine(r - 10, u + 10, l + 10, d - 10, 2, Color::Blue);
					break;
				case 'o':
					lcd.drawCircle(l + cellSize / 2, u + cellSize / 2, cellSize / 2 - 10, Color::Blue);
					lcd.drawCircle(l + cellSize / 2, u + cellSize / 2, cellSize / 2 - 12, Color::White);
					break;
				default:
					break;
				}
			}
		}

		lcd.refresh();
	}
}
