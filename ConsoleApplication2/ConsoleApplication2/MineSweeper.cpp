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
#include "SFML\Audio.hpp"
#define BOMBA 11
using namespace sf;
using namespace std;
int rezx = 1024;
int rezy = 860;
Image icon;
Texture one;
Texture two;
Texture three;
Texture four;
Texture five;
Texture six;
Texture seven;
Texture eight;
Texture nine;
Texture bomba;
Texture zero;
Texture aduna;
Texture question;
Texture create;
Texture scadere;
RenderWindow renderWindow(VideoMode(rezx, rezy), "MineSweeper", Style::Titlebar | Style::Close);
int customcoloane, customlini;
int coloane = 8, lini = 6;
int minesweeper[30][30];
int minesweeperhelp[30][30];
int copie[30][30];
int bombe = (lini + coloane) * 2-coloane;
int sepoate = 0;
int sumabombe;
int gasite;
int minesweeperfrecventa[30][30];
int quest[40][40];
int hero = 20;
int onlyonestart;
int cati = 0;
int ScorulJucatorului = 0;
int StartCustom=1;
int PrimulClick=0;
Sprite joc[30][30];
Texture nothing;
Sprite loss;
Texture ptloss;
Sprite win;
Texture ptwin;
Sound sunetjoc;
SoundBuffer sunetjocbuff;
Sound sunetwin;
SoundBuffer sunetwinbuff;
Sound sunetloss;
SoundBuffer sunetlossbuff;
Sprite custom[10];
struct Top10 {
	char numele[30];
	int nul;
	int scor;
};
struct poziti {
	int x, y;
}pozitiile[8];
Top10 lista[10];
void verificaremax()
{
	if (coloane > 28)
		coloane = 8;
	if (lini > 17)
		lini = 6;
	if (hero > 90)
		hero = 0;
	if (hero < 0)
		hero = 90;

}
void verificarelc()
{
	int x = lini;
	int y = coloane;
	int z = hero;
	if (x % 10 == 0)
		custom[3].setTexture(zero);
	else
		if (x % 10 == 1)
			custom[3].setTexture(one);
		else
			if (x % 10 == 2)
				custom[3].setTexture(two);
			else
				if (x % 10 == 3)
					custom[3].setTexture(three);
				else
					if (x % 10 == 4)
						custom[3].setTexture(four);
					else
						if (x % 10 == 5)
							custom[3].setTexture(five);
						else
							if (x % 10 == 6)
								custom[3].setTexture(six);
							else
								if (x % 10 == 7)
									custom[3].setTexture(seven);
								else
									if (x % 10 == 8)
										custom[3].setTexture(eight);
									else
										if (x % 10 == 9)
											custom[3].setTexture(nine);
	if (x / 10 == 0)
		custom[1].setTexture(zero);
	else
		if (x / 10 == 1)
			custom[1].setTexture(one);
		else
			if (x / 10 == 2)
				custom[1].setTexture(two);
			else
				if (x / 10 == 3)
					custom[1].setTexture(three);
				else
					if (x / 10 == 4)
						custom[1].setTexture(four);
					else
						if (x / 10 == 5)
							custom[1].setTexture(five);
						else
							if (x/ 10 == 6)
								custom[1].setTexture(six);
							else
								if (x / 10 == 7)
									custom[1].setTexture(seven);
								else
									if (x / 10 == 8)
										custom[1].setTexture(eight);
									else
										if (x / 10 == 9)
											custom[1].setTexture(nine);
	if (y % 10 == 0)
		custom[2].setTexture(zero);
	else
		if (y % 10 == 1)
			custom[2].setTexture(one);
		else
			if (y % 10 == 2)
				custom[2].setTexture(two);
			else
				if (y % 10 == 3)
					custom[2].setTexture(three);
				else
					if (y % 10 == 4)
						custom[2].setTexture(four);
					else
						if (y % 10 == 5)
							custom[2].setTexture(five);
						else
							if (y % 10 == 6)
								custom[2].setTexture(six);
							else
								if (y % 10 == 7)
									custom[2].setTexture(seven);
								else
									if (y % 10 == 8)
										custom[2].setTexture(eight);
									else
										if (y % 10 == 9)
											custom[2].setTexture(nine);
	if (y / 10 == 0)
		custom[0].setTexture(zero);
	else
		if (y / 10 == 1)
			custom[0].setTexture(one);
		else
			if (y / 10 == 2)
				custom[0].setTexture(two);
			else
				if (y / 10 == 3)
					custom[0].setTexture(three);
				else
					if (y / 10 == 4)
						custom[0].setTexture(four);
					else
						if (y / 10 == 5)
							custom[0].setTexture(five);
						else
							if (y / 10 == 6)
								custom[0].setTexture(six);
							else
								if (y / 10 == 7)
									custom[0].setTexture(seven);
								else
									if (y / 10 == 8)
										custom[0].setTexture(eight);
									else
										if (y / 10 == 9)
											custom[0].setTexture(nine);
	if (z % 10 == 0)
		custom[5].setTexture(zero);
	else
		if (z % 10 == 1)
			custom[5].setTexture(one);
		else
			if (z % 10 == 2)
				custom[5].setTexture(two);
			else
				if (z % 10 == 3)
					custom[5].setTexture(three);
				else
					if (z % 10 == 4)
						custom[5].setTexture(four);
					else
						if (z % 10 == 5)
							custom[5].setTexture(five);
						else
							if (z % 10 == 6)
								custom[5].setTexture(six);
							else
								if (z % 10 == 7)
									custom[5].setTexture(seven);
								else
									if (z % 10 == 8)
										custom[5].setTexture(eight);
									else
										if (z % 10 == 9)
											custom[5].setTexture(nine);
	if (z / 10 == 0)
		custom[4].setTexture(zero);
	else
		if (z / 10 == 1)
			custom[4].setTexture(one);
		else
			if (z / 10 == 2)
				custom[4].setTexture(two);
			else
				if (z / 10 == 3)
					custom[4].setTexture(three);
				else
					if (z / 10 == 4)
						custom[4].setTexture(four);
					else
						if (z / 10 == 5)
							custom[4].setTexture(five);
						else
							if (z / 10 == 6)
								custom[4].setTexture(six);
							else
								if (z / 10 == 7)
									custom[4].setTexture(seven);
								else
									if (z / 10 == 8)
										custom[4].setTexture(eight);
									else
										if (z / 10 == 9)
											custom[4].setTexture(nine);

}
/*void castigatorsauloss()
{
	for (int x = 0; x < coloane; x++)
		for (int y = 0; y < lini; y++)
		{
			if (minesweeperhelp[x][y] == 1)
			{
				joc[y][x].setTexture(one);
			}
			else
				if (minesweeperhelp[x][y] == 2)
				{
					joc[y][x].setTexture(two);
				}
				else
					if (minesweeperhelp[x][y] == 3)
					{
						joc[y][x].setTexture(three);
					}
					else
						if (minesweeperhelp[x][y] == 4)
						{
							joc[y][x].setTexture(four);
						}
						else
							if (minesweeperhelp[x][y] == 5)
							{
								joc[y][x].setTexture(five);
							}
							else
								if (minesweeperhelp[x][y] == 6)
								{
									joc[y][x].setTexture(six);
								}
								else
									if (minesweeperhelp[x][y] == 7)
									{
										joc[y][x].setTexture(seven);
									}
									else
										if (minesweeperhelp[x][y] == 8)
										{
											joc[y][x].setTexture(eight);
										}
										else
											if (minesweeperhelp[x][y] == 0)
												joc[y][x].setTexture(nothing);
											else
												if (minesweeperhelp[x][y] == 11)
													joc[y][x].setTexture(bomba);
												else
													if (minesweeperhelp[x][y] == 12)
														joc[y][x].setTexture(bomba);


			renderWindow.draw(joc[y][x]);
			renderWindow.display();
		}
	
}*/
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
	if (minesweeper[x][y] == 0 && x >= 0 && x<lini&&y >= 0 && y<coloane)
		if (x >= 0 && x < lini&&y >= 0 && y < coloane)
		{
			minesweeperfrecventa[x][y] = 1;
			gasite++;
			joc[y][x].setTexture(nothing);
			renderWindow.draw(joc[y][x]);
			minesweeper[x][y] = 12;
			fill(x, y + 1);
			fill(x, y - 1);
			fill(x + 1, y);
			fill(x - 1, y);
			fill(x + 1, y + 1);
			fill(x + 1, y - 1);
			fill(x - 1, y - 1);
			fill(x - 1, y + 1);
			for (int contor = 0; contor < 8; contor++)
			{
				int auxx = x + pozitiile[contor].x;
				int auxy = y + pozitiile[contor].y;
				if (minesweeper[auxx][auxy] == 1)
				{
					joc[auxy][auxx].setTexture(one); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
				}
				else
					if (minesweeper[auxx][auxy] == 2)
					{
						joc[auxy][auxx].setTexture(two); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
					}
					else
						if (minesweeper[auxx][auxy] == 3)
						{
							joc[auxy][auxx].setTexture(three); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
						}
						else
							if (minesweeper[auxx][auxy] == 4)
							{
								joc[auxy][auxx].setTexture(four); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
							}
							else
								if (minesweeper[auxx][auxy] == 5)
								{
									joc[auxy][auxx].setTexture(five); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
								}
								else
									if (minesweeper[auxx][auxy] == 6)
									{
										joc[auxy][auxx].setTexture(six); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
									}
									else
										if (minesweeper[auxx][auxy] == 7)
										{
											joc[auxy][auxx].setTexture(seven); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
										}
										else
											if (minesweeper[auxx][auxy] == 8)
											{
												joc[auxy][auxx].setTexture(eight); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
											}
			}
		}
}

void creare()
{
	srand(time(0));
	int s = 0;
	for (int k = 0; k<lini; k++)
		for (int k2 = 0; k2 < coloane; k2++)
		{
			int poate = rand() % 100;
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

int main()
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	sunetjocbuff.loadFromFile("Click.wav");
	sunetjoc.setBuffer(sunetjocbuff);
	sunetwinbuff.loadFromFile("Muzica.wav");
	sunetwin.setBuffer(sunetwinbuff);
	sunetlossbuff.loadFromFile("Lost.wav");
	sunetloss.setBuffer(sunetlossbuff);
	
	icon.loadFromFile("Icon.png");
	renderWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
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
	custom[0].setPosition(Vector2f(30, 680));
	custom[1].setPosition(Vector2f(30, 710));
	custom[2].setPosition(Vector2f(70, 680));
	custom[3].setPosition(Vector2f(70, 710));
	custom[4].setPosition(Vector2f(30, 780));
	custom[5].setPosition(Vector2f(70, 780));
	custom[6].setPosition(Vector2f(110, 780));
	custom[7].setPosition(Vector2f(150, 780));
	custom[8].setPosition(Vector2f(110, 680));
	custom[9].setPosition(Vector2f(110, 720));
	one.loadFromFile("1.png");
	two.loadFromFile("2.png");
	three.loadFromFile("3.png");
	four.loadFromFile("4.png");
	five.loadFromFile("5.png");
	six.loadFromFile("6.png");
	seven.loadFromFile("7.png");
	eight.loadFromFile("8.png");
	bomba.loadFromFile("bomba.png");
	nothing.loadFromFile("0.png");
	question.loadFromFile("10.png");
	ptloss.loadFromFile("loss.png");
	loss.setTexture(ptloss);
	ptwin.loadFromFile("win.png");
	zero.loadFromFile("zero.png");
	aduna.loadFromFile("+.png");
	create.loadFromFile("create.png");
	scadere.loadFromFile("minus.png");
	nine.loadFromFile("noua.png");
	win.setTexture(ptwin);
	char nume[30];
	int pozchar = 0;
	String words;
	Font font;
	font.loadFromFile("Candarai.ttf");
	Text text(words,font,40);
	String words2 ="Scorul: 0";
	Text text2(words2, font, 40);
	
	custom[0].setTexture(five);
	custom[1].setTexture(five);
	custom[2].setTexture(aduna);
	custom[3].setTexture(aduna);
	custom[4].setTexture(two);
	custom[5].setTexture(zero);
	custom[6].setTexture(aduna);
	custom[7].setTexture(scadere);
	custom[8].setTexture(aduna);
	custom[9].setTexture(aduna);
	text2.setPosition(Vector2f(rezx / 2-100, 0));
	
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
						string afisare = "Top 10";
						Text afisaretext(afisare, font, 40);
						afisaretext.setPosition(Vector2f(400, 0));
						afisaretext.setString(afisare);
						renderWindow.draw(afisaretext);


						for (int i = 0; i < cati; i++)
						{
							afisaretext.setPosition(Vector2f(50, (60 * i) + 100));
							string aux(lista[i].numele);
							afisaretext.setString(aux);
							renderWindow.draw(afisaretext);
							afisaretext.setPosition(Vector2f(50 + 200, (60 * i) + 100));
							char scoruasta[30];
							if (lista[i].scor >= 100)
							{
								scoruasta[0] = char(lista[i].scor / 100 % 10 + 48);
								scoruasta[1] = char(lista[i].scor / 10 % 10 + 48);
								scoruasta[2] = char(lista[i].scor % 10 + 48);
								scoruasta[3] = NULL;
							}
							else
								if (lista[i].scor >= 10)
								{

									scoruasta[0] = char(lista[i].scor / 10 % 10 + 48);
									scoruasta[1] = char(lista[i].scor % 10 + 48);
									scoruasta[2] = NULL;
								}
								else
									if (lista[i].scor >= 0)
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
								sunetjoc.play();
								onlyonestart = 1;
								Okpentrustart = 1;
								ScorulJucatorului = 0;
								hero = 20;
								coloane = 8;
								lini = 6;
								sepoate = 0;
								StartCustom = 0;
							}
						}
						else



							if (eveniment.mouseButton.x >= 110 && eveniment.mouseButton.x < 140 && eveniment.mouseButton.y >= 680 && eveniment.mouseButton.y < 710)
							{
								coloane++; StartCustom = 1; sepoate = 0; verificaremax();
							}
							else
								if (eveniment.mouseButton.x >= 110 && eveniment.mouseButton.x < 140 && eveniment.mouseButton.y >= 720 && eveniment.mouseButton.y < 750)
								{
									lini++; StartCustom = 1; sepoate = 0; verificaremax();
								}
								else
									if (eveniment.mouseButton.x >= 110 && eveniment.mouseButton.x < 140 && eveniment.mouseButton.y >= 780 && eveniment.mouseButton.y < 810)
									{
										hero++; StartCustom = 1; sepoate = 0; verificaremax();
									}
									else
										if (eveniment.mouseButton.x >= 150 && eveniment.mouseButton.x < 180 && eveniment.mouseButton.y >= 780 && eveniment.mouseButton.y < 810)
										{
											hero--; StartCustom = 1; sepoate = 0; verificaremax();
										}
					/*custom[0].setPosition(Vector2f(30, 680));
					custom[1].setPosition(Vector2f(30, 710));
					custom[2].setPosition(Vector2f(70, 680));
					custom[3].setPosition(Vector2f(70, 710));
					custom[4].setPosition(Vector2f(30, 780));
					custom[5].setPosition(Vector2f(70, 780));
					custom[6].setPosition(Vector2f(100, 780));
					custom[7].setPosition(Vector2f(150, 730));
					custom[8].setPosition(Vector2f(110, 680));
					custom[9].setPosition(Vector2f(110, 720));*/
										else
											if (onlyonestart == 1)
												if (eveniment.mouseButton.x >= (rezx * 2 + rezx + 100) / coloane&&eveniment.mouseButton.y >= (rezy * 2) / lini)
													if (eveniment.mouseButton.x <= (rezx * 2 + rezx + 100) / coloane + 30 * coloane&& eveniment.mouseButton.y <= (rezy * 2) / lini + 30 * lini)
													{
														sunetjoc.play();
														int y = (eveniment.mouseButton.x - ((rezx * 2 + rezx + 100) / coloane)) / 30;
														int x = (eveniment.mouseButton.y - ((rezy * 2) / lini)) / 30;


														if (minesweeper[x][y] == 1 && quest[x][y] == 0)
														{
															joc[y][x].setTexture(one); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
														}
														else
															if (minesweeper[x][y] == 2 && quest[x][y] == 0)
															{
																joc[y][x].setTexture(two); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
															}
															else
																if (minesweeper[x][y] == 3 && quest[x][y] == 0)
																{
																	joc[y][x].setTexture(three); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
																}
																else
																	if (minesweeper[x][y] == 4 && quest[x][y] == 0)
																	{
																		joc[y][x].setTexture(four); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
																	}
																	else
																		if (minesweeper[x][y] == 5 && quest[x][y] == 0)
																		{
																			joc[y][x].setTexture(five); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
																		}
																		else
																			if (minesweeper[x][y] == 6 && quest[x][y] == 0)
																			{
																				joc[y][x].setTexture(six); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
																			}
																			else
																				if (minesweeper[x][y] == 7 && quest[x][y] == 0)
																				{
																					joc[y][x].setTexture(seven); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
																				}
																				else
																					if (minesweeper[x][y] == 8 && quest[x][y] == 0)
																					{
																						joc[y][x].setTexture(eight); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
																					}
																					else
																						if (minesweeper[x][y] == 0 && quest[x][y] == 0)
																							fill(x, y);
																						else
																							if (minesweeper[x][y] == 11 && quest[x][y] == 0)
																							{

																								if (PrimulClick == 0)
																								{
																									int curaj4 = 0;
																									if (minesweeper[x][y + 1] == 11 && x >= 0 && x < lini&&y + 1 >= 0 && y + 1 < coloane)
																										curaj4++;
																									if (minesweeper[x][y - 1] == 11 && x >= 0 && x < lini&&y - 1 >= 0 && y - 1 < coloane)
																										curaj4++;
																									if (minesweeper[x + 1][y] == 11 && x + 1 >= 0 && x + 1 < lini&&y >= 0 && y < coloane)
																										curaj4++;
																									if (minesweeper[x - 1][y] == 11 && x - 1 >= 0 && x - 1 < lini&&y >= 0 && y < coloane)
																										curaj4++;
																									if (minesweeper[x + 1][y + 1] == 11 && x + 1 >= 0 && x + 1 < lini&&y + 1 >= 0 && y + 1 < coloane)
																										curaj4++;
																									if (minesweeper[x + 1][y - 1] == 11 && x + 1 >= 0 && x + 1 < lini&&y - 1 >= 0 && y - 1 < coloane)
																										curaj4++;
																									if (minesweeper[x - 1][y + 1] == 11 && x - 1 >= 0 && x - 1 < lini&&y + 1 >= 0 && y + 1 < coloane)
																										curaj4++;
																									if (minesweeper[x - 1][y - 1] == 11 && x - 1 >= 0 && x - 1 < lini&&y - 1 >= 0 && y - 1 < coloane)
																										curaj4++;
																									minesweeper[x][y] = curaj4;
																									if (minesweeper[x][y] == 1 && quest[x][y] == 0)
																									{
																										joc[y][x].setTexture(one); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
																									}
																									else
																										if (minesweeper[x][y] == 2 && quest[x][y] == 0)
																										{
																											joc[y][x].setTexture(two); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
																										}
																										else
																											if (minesweeper[x][y] == 3 && quest[x][y] == 0)
																											{
																												joc[y][x].setTexture(three); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
																											}
																											else
																												if (minesweeper[x][y] == 4 && quest[x][y] == 0)
																												{
																													joc[y][x].setTexture(four); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
																												}
																												else
																													if (minesweeper[x][y] == 5 && quest[x][y] == 0)
																													{
																														joc[y][x].setTexture(five); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
																													}
																													else
																														if (minesweeper[x][y] == 6 && quest[x][y] == 0)
																														{
																															joc[y][x].setTexture(six); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
																														}
																														else
																															if (minesweeper[x][y] == 7 && quest[x][y] == 0)
																															{
																																joc[y][x].setTexture(seven); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
																															}
																															else
																																if (minesweeper[x][y] == 8 && quest[x][y] == 0)
																																{
																																	joc[y][x].setTexture(eight); gasite++; minesweeper[x][y] = 12; minesweeperfrecventa[x][y] = 1;
																																}
																																else
																																	if (minesweeper[x][y] == 0 && quest[x][y] == 0)
																																		fill(x, y);
																									renderWindow.draw(joc[y][x]);
																									renderWindow.display();
																									PrimulClick = 1;
																								}
																								else

																								{
																									loss.setPosition(Vector2f(250, 150));

																									renderWindow.draw(loss);
																									renderWindow.display();
																									sepoate = 0;
																									coloane = 8;
																									lini = 6;

																									if (StartCustom == 0) {
																										char numenou[30];
																										string numelecolegului = words;
																										strncpy(numenou, numelecolegului.c_str(), sizeof(numenou));
																										citire(numenou, ScorulJucatorului);
																										ScorulJucatorului = 0;
																										words2 = "Scorul: ";
																										words2 += (char)(ScorulJucatorului + 48);
																									}



																									sunetloss.play();
																									wait(4);


																								}

																							}
														int SUMAC = 0;
														for (int i = 0; i < lini; i++)
														{
															for (int j = 0; j < coloane; j++)
																if (minesweeper[i][j] == 12)
																	SUMAC++;

														}
														//cout <<SUMAC<< endl;
														if (SUMAC + sumabombe == lini*coloane)
														{
															if (StartCustom == 0)
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
															}
															win.setPosition(Vector2f(250, 150));

															renderWindow.draw(win);

															renderWindow.display();
															sunetwin.play();
															wait(7);

															sepoate = 0;

															if (StartCustom == 0)
															{
																if (coloane < 28)
																{
																	coloane = coloane + 2;
																	if (lini < 20)
																		lini = coloane - 2;
																	if (hero < 80)
																		hero++;
																}
																else
																	if (hero < 80)
																		hero++;

															}
														}
														PrimulClick = 1;
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
									sunetjoc.play();
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
							
								sunetjoc.play();
								int y = (eveniment.mouseButton.x - ((rezx * 2 + rezx + 100) / coloane)) / 30;
								int x = (eveniment.mouseButton.y - ((rezy * 2) / lini)) / 30;
								int curaj = 0;
								int curaj2 = 0;
								int curaj3 = 0;
								if (minesweeperfrecventa[x][y]== 1)
								{
								if (minesweeper[x][y + 1] == 11 && x >= 0 && x < lini&&y + 1 >= 0 && y + 1 < coloane)
									curaj3++;
								if (minesweeper[x][y - 1] == 11 && x >= 0 && x < lini&&y - 1 >= 0 && y - 1 < coloane)
									curaj3++;
								if (minesweeper[x + 1][y] == 11 && x + 1 >= 0 && x + 1 < lini&&y >= 0 && y < coloane)
									curaj3++;
								if (minesweeper[x - 1][y] == 11 && x - 1 >= 0 && x - 1 < lini&&y >= 0 && y < coloane)
									curaj3++;
								if (minesweeper[x + 1][y + 1] == 11 && x + 1 >= 0 && x + 1 < lini&&y + 1 >= 0 && y + 1 < coloane)
									curaj3++;
								if (minesweeper[x + 1][y - 1] == 11 && x + 1 >= 0 && x + 1 < lini&&y - 1 >= 0 && y - 1 < coloane)
									curaj3++;
								if (minesweeper[x - 1][y + 1] == 11 && x - 1 >= 0 && x - 1 < lini&&y + 1 >= 0 && y + 1 < coloane)
									curaj3++;
								if (minesweeper[x - 1][y - 1] == 11 && x - 1 >= 0 && x - 1 < lini&&y - 1 >= 0 && y - 1 < coloane)
									curaj3++;

								if (quest[x][y + 1] == 1 && minesweeper[x][y + 1] == 11 && x >= 0 && x < lini&&y + 1 >= 0 && y + 1 < coloane)
									curaj++;
								if (quest[x][y - 1] == 1 && minesweeper[x][y - 1] == 11 && x >= 0 && x < lini&&y - 1 >= 0 && y - 1 < coloane)
									curaj++;
								if (quest[x + 1][y] == 1 && minesweeper[x + 1][y] == 11 && x + 1 >= 0 && x + 1 < lini&&y >= 0 && y < coloane)
									curaj++;
								if (quest[x - 1][y] == 1 && minesweeper[x - 1][y] == 11 && x - 1 >= 0 && x - 1 < lini&&y >= 0 && y < coloane)
									curaj++;
								if (quest[x + 1][y + 1] == 1 && minesweeper[x + 1][y + 1] == 11 && x + 1 >= 0 && x + 1 < lini&&y + 1 >= 0 && y + 1 < coloane)
									curaj++;
								if (quest[x + 1][y - 1] == 1 && minesweeper[x + 1][y - 1] == 11 && x + 1 >= 0 && x + 1 < lini&&y - 1 >= 0 && y - 1 < coloane)
									curaj++;
								if (quest[x - 1][y + 1] == 1 && minesweeper[x - 1][y + 1] == 11 && x - 1 >= 0 && x - 1 < lini&&y + 1 >= 0 && y + 1 < coloane)
									curaj++;
								if (quest[x - 1][y - 1] == 1 && minesweeper[x - 1][y - 1] == 11 && x - 1 >= 0 && x - 1 < lini&&y - 1 >= 0 && y - 1 < coloane)
									curaj++;
								if (quest[x][y + 1] == 1 && x >= 0 && x < lini&&y + 1 >= 0 && y + 1 < coloane)
									curaj2++;
								if (quest[x][y - 1] == 1 && x >= 0 && x < lini&&y - 1 >= 0 && y - 1 < coloane)
									curaj2++;
								if (quest[x - 1][y] == 1 && x - 1 >= 0 && x - 1 < lini&&y >= 0 && y < coloane)
									curaj2++;
								if (quest[x + 1][y] == 1 && x + 1 >= 0 && x + 1 < lini&&y >= 0 && y < coloane)
									curaj2++;
								if (quest[x + 1][y + 1] == 1 && x + 1 >= 0 && x + 1 < lini&&y + 1 >= 0 && y + 1 < coloane)
									curaj2++;
								if (quest[x + 1][y - 1] == 1 && x + 1 >= 0 && x + 1 < lini&&y - 1 >= 0 && y - 1 < coloane)
									curaj2++;
								if (quest[x - 1][y + 1] == 1 && x - 1 >= 0 && x - 1 < lini&&y + 1 >= 0 && y + 1 < coloane)
									curaj2++;
								if (quest[x - 1][y - 1] == 1 && x - 1 >= 0 && x - 1 < lini&&y - 1 >= 0 && y - 1 < coloane)
									curaj2++;
								cout << curaj << " " << curaj2 << " " << curaj3 << endl;
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
												joc[auxy][auxx].setTexture(one); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
											}
											else
												if (minesweeper[auxx][auxy] == 2)
												{
													joc[auxy][auxx].setTexture(two); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
												}
												else
													if (minesweeper[auxx][auxy] == 3)
													{
														joc[auxy][auxx].setTexture(three); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
													}
													else
														if (minesweeper[auxx][auxy] == 4)
														{
															joc[auxy][auxx].setTexture(four); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
														}
														else
															if (minesweeper[auxx][auxy] == 5)
															{
																joc[auxy][auxx].setTexture(five); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
															}
															else
																if (minesweeper[auxx][auxy] == 6)
																{
																	joc[auxy][auxx].setTexture(six); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
																}
																else
																	if (minesweeper[auxx][auxy] == 7)
																	{
																		joc[auxy][auxx].setTexture(seven); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
																	}
																	else
																		if (minesweeper[auxx][auxy] == 8)
																		{
																			joc[auxy][auxx].setTexture(eight); gasite++; minesweeper[auxx][auxy] = 12; minesweeperfrecventa[auxx][auxy] = 1;
																		}

																		else
																			if (minesweeper[auxx][auxy] == 0)
																				fill(auxx, auxy);
										}

									}
									else
										if (curaj != curaj2&&curaj3 == curaj2)
										{

											loss.setPosition(Vector2f(250, 150));
											renderWindow.draw(loss);
											renderWindow.display();
											sepoate = 0;
											coloane = 8;
											lini = 6;

											if (StartCustom == 1)
											{
												char numenou[30];
												string numelecolegului = words;
												strncpy(numenou, numelecolegului.c_str(), sizeof(numenou));
												citire(numenou, ScorulJucatorului);
												ScorulJucatorului = 0;
												words2 = "Scorul: ";
												words2 += (char)(ScorulJucatorului + 48);
											}
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
											sunetloss.play();
											wait(4);
										}
								}

								renderWindow.display();
								int SUMAC = 0;
								for (int i = 0; i < lini; i++)
								{
									for (int j = 0; j < coloane; j++)
										if (minesweeper[i][j] == 12)
											SUMAC++;

								}
								//cout <<SUMAC<< endl;
								if (SUMAC + sumabombe == lini*coloane)
								{

									ScorulJucatorului++;
									words2 = "Scorul: ";
									if (StartCustom == 0)
									{
										if (ScorulJucatorului > 9)
										{
											words2 += (char)(ScorulJucatorului / 10 + 48);
											words2 += (char)(ScorulJucatorului + 48);
										}
										else
											words2 += (char)(ScorulJucatorului + 48);
									}
									win.setPosition(Vector2f(250, 150));

									renderWindow.draw(win);
									renderWindow.display();
									sunetwin.play();
									wait(7);

									sepoate = 0;
									if (StartCustom == 0)
									{
										if (coloane < 28)
										{
											coloane = coloane + 2;
											if (lini < 20)
												lini = coloane - 2;
											if (hero < 80)
												hero++;
										}
										else
											if (hero < 80)
												hero++;

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
							//joc[i][j].setPosition(Vector2f((rezx * 2 + rezx+100) / coloane + 30 * i, (rezy * 2) / lini + 30 * j));
							joc[i][j].setPosition(Vector2f((rezx * 2 + rezx + 100) / coloane + 30 * i, (rezy * 2) / lini + 30 * j));
						}
					sumabombe = 0;
					reset();
					resetquest();
					creare();
					sepoate = 1;
					PrimulClick = 0;
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
				verificarelc();
				for (int i = 0; i < 10; i++)
					renderWindow.draw(custom[i]);
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

