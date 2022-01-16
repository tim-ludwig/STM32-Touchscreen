//*******************************************************************
/*!
 \file   main.cpp
 \author Thomas Breuer, Tim Ludwig
 \date   18.09.2019
 \brief  Template
 */

//*******************************************************************
#include <lib.h>
#include <config.h>
#include <Color.h>

#include <tictactoe/TicTacToe.h>
#include <touchlib/components/TicTacToeComponent.h>

#include <touchlib/components/Container.h>
#include <touchlib/components/Slider.h>
#include <touchlib/events/action/SliderEvent.h>
#include <touchlib/components/ToggleSwitch.h>
#include <touchlib/events/action/ToggleSwitchEvent.h>
#include <touchlib/components/RadioButton.h>
#include <touchlib/events/action/RadioButtonEvent.h>
#include <touchlib/logic/RadioButtonGroup.h>

//*******************************************************************

using namespace touchlib;

void tictactoe(void) {
	TicTacToeGame game;
	TicTacToeComponent g(game, true, lcd.getWidth(), lcd.getHeight());

	touchScreen.getRootContainer()->addComponent(&g);

	while (!game.hasEnded()) {
		if (game.getCurrentPlayer() == 'o')
			game.doMove(game.bestMove());

		lcd.clear();
		g.show(lcd);
		lcd.refresh();
	}

	char winner = game.winner();
	if (winner == ' ') {
		lcd.printf(1, 1, 5, "Draw!");
	} else {
		lcd.printf(1, 1, 6, "%c won!", winner);
	}

	cSystem::delayMilliSec(10);
	lcd.refresh();
}

void redraw(ActionEvent& event) {
	lcd.clear();
	touchScreen.getRootContainer()->show(lcd);
	lcd.refresh();
}

void uiDemo() {
	lcd.setZoom(2);

	Slider slider { 85, 20, 300, indigo };
	touchScreen.getRootContainer()->addComponent(&slider);

	slider.addEventListener(redraw);

	ToggleSwitch tSwitch1 {  85, 100, indigo};
	ToggleSwitch tSwitch2 { 185, 100, indigo};
	ToggleSwitch tSwitch3 { 285, 100, indigo};

	touchScreen.getRootContainer()->addComponent(&tSwitch1);
	touchScreen.getRootContainer()->addComponent(&tSwitch2);
	touchScreen.getRootContainer()->addComponent(&tSwitch3);

	tSwitch1.addEventListener(redraw);
	tSwitch2.addEventListener(redraw);
	tSwitch3.addEventListener(redraw);

	RadioButton rBtn1 { 85, 150, indigo };
	RadioButton rBtn2 { 135, 150, indigo };
	RadioButton rBtn3 { 185, 150, indigo };

	RadioButtonGroup grp;
	grp.addButton(&rBtn1);
	grp.addButton(&rBtn2);
	grp.addButton(&rBtn3);

	touchScreen.getRootContainer()->addComponent(&rBtn1);
	touchScreen.getRootContainer()->addComponent(&rBtn2);
	touchScreen.getRootContainer()->addComponent(&rBtn3);

	rBtn1.addEventListener(redraw);
	rBtn2.addEventListener(redraw);
	rBtn3.addEventListener(redraw);

	touchScreen.getRootContainer()->show(lcd);
	lcd.refresh();

	while (true) {
	}
}

int main(void) {
	lcd.setBackColor(Color::White);
	lcd.setTextColor(Color::Black);
	lcd.drawRectangle(0, 0, lcd.getWidth(), lcd.getHeight(), Color::White);

	Container root;
	touchScreen.setRootContainer(&root);

	//*
	uiDemo();
	/*/
	tictactoe();
	//*/
}

