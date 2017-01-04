// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#define BOMBA 11
using namespace sf;
using namespace std;
int coloane = 7, lini = 5;
int minesweeper[30][30];
int bombe = (lini + coloane) * 2-coloane;
void reset()
{
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			minesweeper[i][j] = 0;
}
void creare()
{
	srand(time(0));
	int s = 0;
	while (s<bombe)
	{
		int number = rand() % coloane+1;
		int number2 = rand() % lini+1;
		if (minesweeper[number][number2] != BOMBA)
		{
			s++;
			minesweeper[number][number2] = BOMBA;
		}
	}
	for (int k = 0; k<lini; k++)
		for (int k2 = 0; k2<coloane; k2++)
			if (minesweeper[k][k2] == BOMBA)
			{
				if (minesweeper[k][k2 + 1] != BOMBA)
					minesweeper[k][k2 + 1]++;
				if (minesweeper[k][k2 - 1] != BOMBA)
					minesweeper[k][k2 - 1] ++;
				if (minesweeper[k + 1][k2] != BOMBA)
					minesweeper[k + 1][k2]++;
				if (minesweeper[k - 1][k2] != BOMBA)
					minesweeper[k - 1][k2] ++;
				if (minesweeper[k + 1][k2 + 1] != BOMBA)
					minesweeper[k + 1][k2 + 1]++;
				if (minesweeper[k + 1][k2 - 1] != BOMBA)
					minesweeper[k + 1][k2 - 1] ++;
				if (minesweeper[k - 1][k2 + 1] != BOMBA)
					minesweeper[k - 1][k2 + 1] ++;
				if (minesweeper[k - 1][k2 - 1] != BOMBA)
					minesweeper[k - 1][k2 - 1] ++;
			}
}
int rezx, rezy;
int main()
{
	
	
	
	creare();
	
	for (int k1 = 0; k1 < lini; k1++)
	{
		for (int k2 = 0; k2 < coloane; k2++)
			cout << minesweeper[k1][k2] << " ";
		cout << endl;
	}
	
	cout << endl;
	for (int k1 = 0; k1 < lini; k1++)
	{
		for (int k2 = 0; k2 < coloane; k2++)
			if(minesweeper[k1][k2]!=BOMBA)
			cout << minesweeper[k1][k2] << " ";
		else
			cout << "B ";
		cout << endl;
	}
	rezx = 1024;
	rezy = 860;
	RenderWindow renderWindow(VideoMode(rezx, rezy), "MineSweeper");
	Sprite Start;
	Texture ButonulStart;
	ButonulStart.loadFromFile("Start_button_red.png");
	ButonulStart.setSmooth(true);
	Start.setTexture(ButonulStart);
	Start.setScale(1, 1);
	Start.setPosition(Vector2f(420, 660));
	Sprite Background;
	Texture Backgroundtext;
	Backgroundtext.loadFromFile("Background.png");
	Backgroundtext.setSmooth(true);
	Background.setTexture(Backgroundtext);
	Sprite joc[30][30];
	Texture patrat;
	patrat.loadFromFile("patrat.png");
	patrat.setSmooth(true);
	
	

	int Okpentrustart = 0;
	for (int i = 0; i < coloane; i++)
		for (int j = 0; j < lini; j++)
		{
			joc[i][j].setTexture(patrat);
			joc[i][j].setPosition(Vector2f((rezx*2+rezx/2)/coloane+30 * i,(rezy*2)/lini+30 * j));
	     }
	while (renderWindow.isOpen())
	{
		Event eveniment;
		while (renderWindow.pollEvent(eveniment))
		{

			switch (eveniment.type)
			{
			case Event::Closed:
				renderWindow.close();
				break;
			case Event::MouseButtonPressed:
				if (eveniment.mouseButton.x >= Start.getPosition().x&&eveniment.mouseButton.y >= Start.getPosition().y)
				{
					if (eveniment.mouseButton.x <= Start.getPosition().x + 80 && eveniment.mouseButton.y <= Start.getPosition().y + 80)
					{
						cout << eveniment.mouseButton.x << " " << eveniment.mouseButton.y;
						cout << endl << Start.getPosition().x << " " << Start.getPosition().y;
						cout << "Da" << endl;
						Okpentrustart = 1;
					}
				}
				else
					if (eveniment.mouseButton.x >= (rezx*2+rezx/2) / coloane&&eveniment.mouseButton.y >= (rezy * 2) / lini)
						if (eveniment.mouseButton.x <= (rezx * 2 + rezx / 2) / coloane + 30 * coloane&& eveniment.mouseButton.y <= (rezy * 2) / lini + 30 * lini)
						{
							cout << (eveniment.mouseButton.y - ((rezy * 2) / lini)) / 30 << " " << (eveniment.mouseButton.x - ((rezx * 2 + rezx / 2) / coloane)) / 30 << endl;
							int x = eveniment.mouseButton.y - ((rezy * 2) / lini)) / 30;
							int y = eveniment.mouseButton.x - ((rezx * 2 + rezx / 2) / coloane)) / 30;
						}
				
				break;
			}

			
			
			renderWindow.draw(Background);
			renderWindow.draw(Start);
			if (Okpentrustart == 1)
				for (int i = 0; i < coloane; i++)
					for (int j = 0; j < lini; j++)
					{
						renderWindow.draw(joc[i][j]);
						reset();
						creare();
						
					}
			renderWindow.display();
		
			



		}
	}
	
	
}

