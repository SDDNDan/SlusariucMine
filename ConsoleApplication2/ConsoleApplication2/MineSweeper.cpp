// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define BOMBA 11
using namespace sf;
using namespace std;
int coloane = 8, lini = 6;
int minesweeper[30][30];
int copie[30][30];
int bombe = (lini + coloane) * 2-coloane;
int sepoate = 0;
int sumabombe;
int gasite;
int quest[30][30];
int hero = 3;
int onlyonestart;
Sprite joc[30][30];
Texture nothing;
Sprite loss;
Texture ptloss;
Sprite win;
Texture ptwin;
struct Top10 {
	char numele[30];
	int nul;
	int scor;
};
void wait(int seconds)
{
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}
void reset()
{
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			minesweeper[i][j] = 0;
}
void resetquest()
{
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			quest[i][j] = 0;
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
	for (int k = 0; k<lini; k++)
		for (int k2 = 0; k2 < coloane; k2++)
		{
			int poate = rand() % 10+1;
			if(poate<hero)
				if (minesweeper[k][k2] != BOMBA)
				{
					s++;
					minesweeper[k][k2] = BOMBA;
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
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
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
	ptloss.loadFromFile("loss.png");
	loss.setTexture(ptloss);
	ptwin.loadFromFile("win.png");
	win.setTexture(ptwin);
	char nume[30];
	int pozchar = 0;
	String words;
	Font font;
	font.loadFromFile("Candarai.ttf");
	Text text(words,font,40);
	

	
	
	
	
	rezx = 1024;
	rezy = 860;
	RenderWindow renderWindow(VideoMode(rezx, rezy), "MineSweeper",Style::Titlebar|Style::Close);
	Sprite Start;
	Texture ButonulStart;
	ButonulStart.loadFromFile("Start_button_red.png");
	ButonulStart.setSmooth(true);
	Start.setTexture(ButonulStart);
	Start.setScale(1, 1);
	Start.setPosition(Vector2f(470, 700));
	Sprite Background;
	Texture Backgroundtext;
	Backgroundtext.loadFromFile("Background.png");
	Backgroundtext.setSmooth(true);
	Background.setTexture(Backgroundtext);
	Texture patrat;
	patrat.loadFromFile("patrat.png");
	patrat.setSmooth(true);
	
	

	int Okpentrustart = 0;
	
	
	/*Top10 Toti[10];
	cin >> Toti[0].numele;
	cout << Toti[0].numele;
	Toti[0].scor = 5;
	Toti[0].nul = 6;
	for (int i = 0; i < Toti[0].nul; i++)
		words += (char)Toti[0].numele[i];
	if (Toti[0].scor / 10 == 0)
		words += char(Toti[0].scor + 48);
	else
	{
		words += char(Toti[0].scor/10 + 48);
		words += char(Toti[0].scor + 48);
	}*/
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

							if (eveniment.mouseButton.x <= Start.getPosition().x + 100 && eveniment.mouseButton.y <= Start.getPosition().y + 100)
							{
								onlyonestart = 1;
								cout << eveniment.mouseButton.x << " " << eveniment.mouseButton.y;
								cout << endl << Start.getPosition().x << " " << Start.getPosition().y;
								cout << "Da" << endl;
								Okpentrustart = 1;

							}
						}
						else
							if(onlyonestart==1)
							if (eveniment.mouseButton.x >= (rezx * 2 + rezx+100) / coloane&&eveniment.mouseButton.y >= (rezy * 2) / lini)
								if (eveniment.mouseButton.x <= (rezx * 2 + rezx+100) / coloane + 30 * coloane&& eveniment.mouseButton.y <= (rezy * 2) / lini + 30 * lini)
								{
									int y = (eveniment.mouseButton.x - ((rezx * 2 + rezx+100) / coloane)) / 30;
									int x = (eveniment.mouseButton.y - ((rezy * 2) / lini)) / 30;
									
									cout << x << " " << y << " " << minesweeper[x][y] << endl;
									if (minesweeper[x][y] == 1&&quest[x][y]==0)
									{
										joc[y][x].setTexture(one); gasite++; minesweeper[x][y] = 12;
									}
									else
										if (minesweeper[x][y] == 2 && quest[x][y] == 0)
										{
											joc[y][x].setTexture(two); gasite++; minesweeper[x][y] = 12;
										}
										else
											if (minesweeper[x][y] == 3 && quest[x][y] == 0)
											{
												joc[y][x].setTexture(three); gasite++; minesweeper[x][y] = 12;
											}
											else
												if (minesweeper[x][y] == 4 && quest[x][y] == 0)
												{
													joc[y][x].setTexture(four); gasite++; minesweeper[x][y] = 12;
												}
												else
													if (minesweeper[x][y] == 5 && quest[x][y] == 0)
													{
														joc[y][x].setTexture(five); gasite++; minesweeper[x][y] = 12;
													}
													else
														if (minesweeper[x][y] == 6 && quest[x][y] == 0)
														{
															joc[y][x].setTexture(six); gasite++; minesweeper[x][y] = 12;
														}
														else
															if (minesweeper[x][y] == 7 && quest[x][y] == 0)
															{
																joc[y][x].setTexture(seven); gasite++; minesweeper[x][y] = 12;
															}
															else
																if (minesweeper[x][y] == 8 && quest[x][y] == 0)
																{
																	joc[y][x].setTexture(eight); gasite++; minesweeper[x][y] = 12;
																}
																else
																	if (minesweeper[x][y] == 0 && quest[x][y] == 0)
																		fill(x, y);
																	else
																		if (minesweeper[x][y] == 11 && quest[x][y] == 0)
																		{
																			cout << "Da";
																			loss.setPosition(Vector2f(250, 150));
																			renderWindow.draw(loss);
																			renderWindow.display();
																			sepoate = 0;
																			coloane = 8;
																			lini = 6;
																			/*
																			//PENTRU AJUTOR PREZENTARE
																			if (coloane < 28)
																			{
																				coloane++;
																				if (lini<20)
																					lini = coloane - 2;
																			}
																			else
																			hero++;
																			*/
																			wait(3);
																			
																		}
									cout << gasite + sumabombe << " " << lini*coloane << endl;
									if (gasite + sumabombe == lini*coloane)
									{
										win.setPosition(Vector2f(250, 150));
										renderWindow.draw(win);
										renderWindow.display();										
										wait(3);
										
										sepoate = 0;
										if (coloane < 28)
										{
											coloane++;
											if (lini < 20)
												lini = coloane - 2;
										}
										else
											hero++;
										
									}
								}
						
					}
					else
						if(Mouse::isButtonPressed(Mouse::Right))
							if (onlyonestart == 1)
					{
							if (eveniment.mouseButton.x >= (rezx * 2 + rezx / 2) / coloane&&eveniment.mouseButton.y >= (rezy * 2) / lini)
								if (eveniment.mouseButton.x <= (rezx * 2 + rezx+100) / coloane + 30 * coloane&& eveniment.mouseButton.y <= (rezy * 2) / lini + 30 * lini)
								
								{
									int y = (eveniment.mouseButton.x - ((rezx * 2 + rezx + 100) / coloane)) / 30;
									int x = (eveniment.mouseButton.y - ((rezy * 2) / lini)) / 30;
									if (minesweeper[x][y] != 12)
									{
										if (quest[x][y] == 0)
										{
											joc[y][x].setTexture(question);
											quest[x][y] = 1;
										}
										else
										{
											quest[x][y] = 0;
											joc[y][x].setTexture(patrat);
										}
									}
								}
					}
				break;
				case Event::TextEntered:
					if (eveniment.text.unicode >= 32 && eveniment.text.unicode <= 126)
					{
						words += (char)eveniment.text.unicode;
						nume[pozchar] = (char)eveniment.text.unicode;
						pozchar++;
					}
					else
						if (eveniment.text.unicode == 8 && words.getSize() > 0)
						{
							words.erase(words.getSize() - 1, words.getSize());
							pozchar--;
							
						}
					
					text.setPosition(Vector2f(700, 0));
					text.setString(words);
					break;
			}

			
			
			renderWindow.draw(Background);
			renderWindow.draw(Start);
			renderWindow.draw(text);
			if (Okpentrustart == 1)
			{
				
				if (sepoate == 0)
				{
					cout << endl;
					for (int i = 0; i < coloane; i++)
						for (int j = 0; j < lini; j++)
						{
							joc[i][j].setTexture(patrat);
							joc[i][j].setPosition(Vector2f((rezx * 2 + rezx+100) / coloane + 30 * i, (rezy * 2) / lini + 30 * j));
						}
					sumabombe = 0;
					reset();
					resetquest();
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
					cout << sumabombe;
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

