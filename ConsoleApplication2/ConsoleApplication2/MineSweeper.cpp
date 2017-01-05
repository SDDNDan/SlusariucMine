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
#include <string.h>
#define BOMBA 11
using namespace sf;
using namespace std;
int coloane = 8, lini = 6;
int minesweeper[30][30];
int minesweeperhelp[30][30];
int copie[30][30];
int bombe = (lini + coloane) * 2-coloane;
int sepoate = 0;
int sumabombe;
int gasite;
int quest[40][40];
int hero = 25;
int onlyonestart;
int cati = 0;
int ScorulJucatorului = 0;
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
struct poziti {
	int x, y;
}pozitiile[8];
Top10 lista[10];
void citestedoar()
{
	cati = 0;
	int ok = 0;
	char numetop[30];
	int scor;
	ifstream fin("Top10.txt");
	while (fin >> numetop >> scor)
	{	
			strcpy(lista[cati].numele, numetop);
			lista[cati].scor = scor;
			cati++;	
	}
	fin.close();
}
void citire(char nou[30],int scorul)
{
	
	cati = 0;
	int ok = 0;
	char numetop[30];
	int scor;
	ifstream fin("Top10.txt");
	while (fin >> numetop >> scor)

	{
		if (scorul > scor&&ok==0&&nou[0]!=' ')
		{
			strcpy(lista[cati].numele, nou);
			lista[cati].scor = scorul;
			cati++;
			if (cati < 10)
			{
				strcpy(lista[cati].numele, numetop);
				lista[cati].scor = scor;
				cati++;
			}
			ok = 1;
	    }
		else
		{
			strcpy(lista[cati].numele, numetop);
			lista[cati].scor = scor;
			cati++;
		}
	}
	if (ok == 0 && cati < 10 && nou[0] != ' ')
	{
		strcpy(lista[cati].numele, nou);
		lista[cati].scor = scorul;
		cati++;
	}
	fin.close();
	ofstream fout("Top10.txt");
	for (int i = 0; i < cati; i++)
		fout << lista[i].numele << ' ' << lista[i].scor << endl;
	fout.close();
}
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
			int poate = rand() % 100+1;
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
	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);
	pozitiile[0].x = 0;
	pozitiile[1].x = 0;
	pozitiile[2].x = 1;
	pozitiile[3].x = -1;
	pozitiile[4].x = 1;
	pozitiile[5].x = 1;
	pozitiile[6].x = -1;
	pozitiile[7].x = -1;
	pozitiile[0].y = 1;
	pozitiile[1].y = -1;
	pozitiile[2].y = 0;
	pozitiile[3].y = 0;
	pozitiile[4].y = 1;
	pozitiile[5].y = -1;
	pozitiile[6].y = 1;
	pozitiile[7].y = -1;
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
	String words2 ="Scorul: 0";
	Text text2(words2, font, 40);
	
	
	
	
	
	rezx = 1024;
	rezy = 860;
	text2.setPosition(Vector2f(rezx / 2-100, 0));
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
	Sprite Background2;
	Texture Backgroundtext2;
	Backgroundtext2.loadFromFile("Background2.png");
	Backgroundtext2.setSmooth(true);
	Background2.setTexture(Backgroundtext2);
	
	

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
						if (eveniment.mouseButton.x >= 840 && eveniment.mouseButton.y > 780)
						{
							citestedoar();
							
							renderWindow.draw(Background2);
							string afisare="Top 10";
							Text afisaretext(afisare,font,40);
							afisaretext.setPosition(Vector2f(400, 0));
							afisaretext.setString(afisare);
							renderWindow.draw(afisaretext);

							
							for (int i = 0; i < cati; i++)
							{   
								afisaretext.setPosition(Vector2f(50, (60*i)+100));
								string aux(lista[i].numele);
								afisaretext.setString(aux);
								renderWindow.draw(afisaretext);
								afisaretext.setPosition(Vector2f(50+200, (60 * i) + 100));
								char scoruasta[30];
								if (lista[i].scor > 100)
								{
									scoruasta[0] = char(lista[i].scor / 100 % 10 + 48);
									scoruasta[1] = char(lista[i].scor / 10 % 10 + 48);
									scoruasta[2] = char(lista[i].scor  % 10 + 48);
									scoruasta[3] = NULL;
								}
								else
									if (lista[i].scor > 10)
									{
										
										scoruasta[0] = char(lista[i].scor / 10 % 10 + 48);
										scoruasta[1] = char(lista[i].scor % 10 + 48);
										scoruasta[2] = NULL;
									}
									else
										if (lista[i].scor >=0)
										{
											
											scoruasta[0] = char(lista[i].scor % 10 + 48);
											scoruasta[1] = NULL;
										}
								string aux2(scoruasta);
								afisaretext.setString(aux2);
								renderWindow.draw(afisaretext);
							}
							renderWindow.display();
							wait(5);
						}
						else
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
																			
																			loss.setPosition(Vector2f(250, 150));
																			renderWindow.draw(loss);
																			renderWindow.display();
																			sepoate = 0;
																			coloane = 8;
																			lini = 6;
																			
																			
																			char numenou[30];
																			string numelecolegului = words;
																			strncpy(numenou, numelecolegului.c_str(), sizeof(numenou));
																			citire(numenou, ScorulJucatorului);
																			ScorulJucatorului = 0;
																			words2 = "Scorul: ";
																			words2 += (char)(ScorulJucatorului + 48);
																			for (int i = 0; i < cati; i++)
																				cout << lista[i].numele << " " << lista[i].scor << endl;
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
										ScorulJucatorului++;
										words2 = "Scorul: ";
										
										if (ScorulJucatorului > 9)
										{
											words2 += (char)(ScorulJucatorului / 10 + 48);
											words2 += (char)(ScorulJucatorului + 48);
										}
										else
											words2 += (char)(ScorulJucatorului + 48);
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
											if(hero<80)
											hero++;
										}
										else
											if(hero<80)
											hero++;
										
									}
								}
						
					}
					else
						if (Mouse::isButtonPressed(Mouse::Right))
						{
							if (onlyonestart == 1)
							{
								if (eveniment.mouseButton.x >= (rezx * 2 + rezx / 2) / coloane&&eveniment.mouseButton.y >= (rezy * 2) / lini)
									if (eveniment.mouseButton.x <= (rezx * 2 + rezx + 100) / coloane + 30 * coloane&& eveniment.mouseButton.y <= (rezy * 2) / lini + 30 * lini)

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
						}
						else
							if (Mouse::isButtonPressed(Mouse::Middle))
							{
								int y = (eveniment.mouseButton.x - ((rezx * 2 + rezx + 100) / coloane)) / 30;
								int x = (eveniment.mouseButton.y - ((rezy * 2) / lini)) / 30;
								int curaj = 0;
								int curaj2 = 0;
								
								if (quest[x][y + 1] == 1 && minesweeper[x][y + 1] == 11&&x>=0&&x<lini&&y+1>=0&&y+1<coloane)
									curaj++;
								if (quest[x][y - 1] == 1 && minesweeper[x][y - 1] == 11 && x >= 0 && x<lini&&y -1 >= 0 && y-1<coloane)
									curaj++;
								if (quest[x + 1][y] == 1 && minesweeper[x + 1][y] == 11 && x+1 >= 0 && x+1<lini&&y >= 0 && y<coloane)
									curaj++;
								if (quest[x - 1][y] == 1 && minesweeper[x - 1][y] == 11 && x-1 >= 0 && x-1 <lini&&y>= 0 && y<coloane)
									curaj++;
								if (quest[x + 1][y + 1] == 1 && minesweeper[x + 1][y + 1] == 11 && x+1 >= 0 && x+1<lini&&y + 1 >= 0 && y+1<coloane)
									curaj++;
								if (quest[x + 1][y - 1] == 1 && minesweeper[x + 1][y - 1] == 11 && x+1 >= 0 && x+1<lini&&y-1 >= 0 && y-1<coloane)
									curaj++;
								if (quest[x - 1][y + 1] == 1 && minesweeper[x - 1][y + 1] == 11 && x-1 >= 0 && x-1<lini&&y + 1 >= 0 && y+1<coloane)
									curaj++;
								if (quest[x - 1][y - 1] == 1 && minesweeper[x - 1][y - 1] == 11 && x-1 >= 0 && x-1<lini&&y - 1 >= 0 && y-1<coloane)
									curaj++;
								if (quest[x][y + 1] == 1 && x >= 0 && x<lini&&y + 1 >= 0 && y + 1<coloane)
									curaj2++;
								if (quest[x][y - 1] == 1 && x >= 0 && x<lini&&y - 1 >= 0 && y - 1<coloane)
									curaj2++;
								if (quest[x - 1][y] == 1 && x - 1 >= 0 && x - 1 <lini&&y >= 0 && y<coloane)
									curaj2++;
								if (quest[x + 1][y] == 1 && x + 1 >= 0 && x + 1<lini&&y >= 0 && y<coloane)
									curaj2++;
								if (quest[x + 1][y + 1] == 1 && x + 1 >= 0 && x + 1<lini&&y + 1 >= 0 && y + 1<coloane)
									curaj2++;
								if (quest[x + 1][y - 1] == 1 && x + 1 >= 0 && x + 1<lini&&y - 1 >= 0 && y - 1<coloane)
									curaj2++;
								if (quest[x - 1][y + 1] == 1 && x - 1 >= 0 && x - 1<lini&&y + 1 >= 0 && y + 1<coloane)
									curaj2++;
								if (quest[x - 1][y - 1] == 1 && x - 1 >= 0 && x - 1<lini&&y - 1 >= 0 && y - 1<coloane)
									curaj2++;

								if (curaj2 != 0)
								{
									if (curaj == minesweeperhelp[x][y] && curaj == curaj2)
									{
										
										
										for (int contor = 0; contor < 8; contor++)
										{
											int auxx = x + pozitiile[contor].x;
											int auxy = y + pozitiile[contor].y;
											if (minesweeper[auxx][auxy] == 1)
											{
												joc[auxy][auxx].setTexture(one); gasite++; minesweeper[auxx][auxy] = 12;
											}
											else
												if (minesweeper[auxx][auxy] == 2)
												{
													joc[auxy][auxx].setTexture(two); gasite++; minesweeper[auxx][auxy] = 12;
												}
												else
													if (minesweeper[auxx][auxy] == 3)
													{
														joc[auxy][auxx].setTexture(three); gasite++; minesweeper[auxx][auxy] = 12;
													}
													else
														if (minesweeper[auxx][auxy] == 4)
														{
															joc[auxy][auxx].setTexture(four); gasite++; minesweeper[auxx][auxy] = 12;
														}
														else
															if (minesweeper[auxx][auxy] == 5)
															{
																joc[auxy][auxx].setTexture(five); gasite++; minesweeper[auxx][auxy] = 12;
															}
															else
																if (minesweeper[auxx][auxy] == 6)
																{
																	joc[auxy][auxx].setTexture(six); gasite++; minesweeper[auxx][auxy] = 12;
																}
																else
																	if (minesweeper[auxx][auxy] == 7)
																	{
																		joc[auxy][auxx].setTexture(seven); gasite++; minesweeper[auxx][auxy] = 12;
																	}
																	else
																		if (minesweeper[auxx][auxy] == 8)
																		{
																			joc[auxy][auxx].setTexture(eight); gasite++; minesweeper[auxx][auxy] = 12;
																		}
																		else
																			if (minesweeper[auxx][auxy] == 11)
																			{
																				joc[auxy][auxx].setTexture(bomba); minesweeper[auxx][auxy] = 12;
																			}
																		else
																			if (minesweeper[auxx][auxy] == 0)
																				fill(auxx, auxy);
										}
										
									}
									else
										if(curaj!=curaj2)
									{
										loss.setPosition(Vector2f(250, 150));
										renderWindow.draw(loss);
										renderWindow.display();
										sepoate = 0;
										coloane = 8;
										lini = 6;


										char numenou[30];
										string numelecolegului = words;
										strncpy(numenou, numelecolegului.c_str(), sizeof(numenou));
										citire(numenou, ScorulJucatorului);
										ScorulJucatorului = 0;
										words2 = "Scorul: ";
										words2 += (char)(ScorulJucatorului + 48);
										for (int i = 0; i < cati; i++)
											cout << lista[i].numele << " " << lista[i].scor << endl;
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

			
			text2.setString(words2);
			renderWindow.draw(Background);
			renderWindow.draw(Start);
			renderWindow.draw(text);
			renderWindow.draw(text2);
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
					cout << "Nr Bombe: "<<sumabombe<<endl;
					gasite = 0;
					for (int k1 = 0; k1 < lini; k1++)
						for (int k2 = 0; k2 < coloane; k2++)
							minesweeperhelp[k1][k2] = minesweeper[k1][k2];
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

