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
int coloane = 12, lini = 10;
int minesweeper[30][30];
int copie[30][30];
int bombe = (lini + coloane) * 2-coloane;
int sepoate = 0;
int sumabombe;
int gasite;
int quest[30][30];
Sprite joc[30][30];
Texture nothing;

void reset()
{
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			minesweeper[i][j] = 0;
}
void fill(int x, int y)
{
	if (minesweeper[x][y] == 0)
		if(x>=0&&x<lini&&y>=0&&y<coloane)
		{
			gasite++;
			joc[y][x].setTexture(nothing);
			minesweeper[x][y] = 12;
		fill(x, y + 1);
		fill(x, y - 1);
		fill(x + 1, y);
		fill(x - 1, y);
		fill(x + 1, y + 1);
		fill(x + 1, y - 1);
		fill(x - 1, y - 1);
		fill(x - 1, y + 1);
	}
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
	Texture one;
	one.loadFromFile("1.png");
	Texture two;
	two.loadFromFile("2.png");
	Texture three;
	three.loadFromFile("3.png");
	Texture four;
	four.loadFromFile("4.png");
	Texture five;
	five.loadFromFile("5.png");
	Texture six;
	six.loadFromFile("6.png");
	Texture seven;
	seven.loadFromFile("7.png");
	Texture eight;
	eight.loadFromFile("8.png");
	Texture bomba;
	bomba.loadFromFile("bomba.png");
	nothing.loadFromFile("0.png");
	Texture question;
	question.loadFromFile("10.png");
	
	
	
	
	
	
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
	Texture patrat;
	patrat.loadFromFile("patrat.png");
	patrat.setSmooth(true);
	
	

	int Okpentrustart = 0;
	
	
	
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
					if (Mouse::isButtonPressed(Mouse::Left))
					{
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
							if (eveniment.mouseButton.x >= (rezx * 2 + rezx / 2) / coloane&&eveniment.mouseButton.y >= (rezy * 2) / lini)
								if (eveniment.mouseButton.x <= (rezx * 2 + rezx) / coloane + 30 * coloane&& eveniment.mouseButton.y <= (rezy * 2) / lini + 30 * lini)
								{
									int y = (eveniment.mouseButton.x - ((rezx * 2 + rezx) / coloane)) / 30;
									int x = (eveniment.mouseButton.y - ((rezy * 2) / lini)) / 30;

									cout << x << " " << y << " " << minesweeper[x][y] << endl;
									if (minesweeper[x][y] == 1&&quest[x][y]==0)
									{
										joc[y][x].setTexture(one); gasite++; minesweeper[x][y] = 12;
									}
									else
										if (minesweeper[x][y] == 2)
										{
											joc[y][x].setTexture(two); gasite++; minesweeper[x][y] = 12;
										}
										else
											if (minesweeper[x][y] == 3)
											{
												joc[y][x].setTexture(three); gasite++; minesweeper[x][y] = 12;
											}
											else
												if (minesweeper[x][y] == 4)
												{
													joc[y][x].setTexture(four); gasite++; minesweeper[x][y] = 12;
												}
												else
													if (minesweeper[x][y] == 5)
													{
														joc[y][x].setTexture(five); gasite++; minesweeper[x][y] = 12;
													}
													else
														if (minesweeper[x][y] == 6)
														{
															joc[y][x].setTexture(six); gasite++; minesweeper[x][y] = 12;
														}
														else
															if (minesweeper[x][y] == 7)
															{
																joc[y][x].setTexture(seven); gasite++; minesweeper[x][y] = 12;
															}
															else
																if (minesweeper[x][y] == 8)
																{
																	joc[y][x].setTexture(eight); gasite++; minesweeper[x][y] = 12;
																}
																else
																	if (minesweeper[x][y] == 0)
																		fill(x, y);
									cout << gasite + sumabombe << " " << lini*coloane << endl;
									if (gasite + sumabombe == lini*coloane)
									{
										coloane = coloane + 2;
										if (coloane % 2 == 0)
											lini = lini + 2;
										sepoate = 0;
									}
								}
						
					}
					else
						if(Mouse::isButtonPressed(Mouse::Right))
					{
							if (eveniment.mouseButton.x >= (rezx * 2 + rezx / 2) / coloane&&eveniment.mouseButton.y >= (rezy * 2) / lini)
								if (eveniment.mouseButton.x <= (rezx * 2 + rezx) / coloane + 30 * coloane&& eveniment.mouseButton.y <= (rezy * 2) / lini + 30 * lini)
								{
									int y = (eveniment.mouseButton.x - ((rezx * 2 + rezx) / coloane)) / 30;
									int x = (eveniment.mouseButton.y - ((rezy * 2) / lini)) / 30;
									joc[y][x].setTexture(question);
									quest[x][y] = 1;
								}
					}
				break;
			}

			
			
			renderWindow.draw(Background);
			renderWindow.draw(Start);
			if (Okpentrustart == 1)
			{
				
				if (sepoate == 0)
				{
					cout << endl;
					for (int i = 0; i < coloane; i++)
						for (int j = 0; j < lini; j++)
						{
							joc[i][j].setTexture(patrat);
							joc[i][j].setPosition(Vector2f((rezx * 2 + rezx) / coloane + 30 * i, (rezy * 2) / lini + 30 * j));
						}
					sumabombe = 0;
					reset();
					creare();
					sepoate = 1;
					for (int k1 = 0; k1 < lini; k1++)
					{
						for (int k2 = 0; k2 < coloane; k2++)
							if (minesweeper[k1][k2] != BOMBA)
								cout << minesweeper[k1][k2] << " ";
							else
							{
								cout << "B "; sumabombe++;
							}
						cout << endl;
					}
					gasite = 0;
				}
				for (int i = 0; i < coloane; i++)
					for (int j = 0; j < lini; j++)
					{
						renderWindow.draw(joc[i][j]);
					}
			}
			
			renderWindow.display();
			



		}
	}
	
	
}

