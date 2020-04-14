#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

// Global Variables
const int MAX_MOVES = 56; 
const float width = 1366.f; //1024.0f;
const float height = 768.f; //575.719f;
const float Token = height*0.0571f;
int Dice; int player;
int RedCounter1 = 0, RedCounter2 = 0, RedCounter3 = 0, RedCounter4 = 0 ;
bool Red1 = false, Red2 = false, Red3 = false, Red4 = false;
int BlueCounter1 = 0, BlueCounter2 = 0, BlueCounter3 = 0, BlueCounter4 = 0;
bool Blue1 = false, Blue2 = false, Blue3 = false, Blue4 = false;
int GreenCounter1 = 0, GreenCounter2 = 0, GreenCounter3 = 0, GreenCounter4 = 0;
bool Green1 = false, Green2 = false, Green3 = false, Green4 = false;
int YellowCounter1 = 0, YellowCounter2 = 0, YellowCounter3 = 0, YellowCounter4 = 0;
bool Yellow1 = false, Yellow2 = false, Yellow3 = false, Yellow4 = false;
bool board[52];

//SFML Definitions
RenderWindow window(VideoMode(width, height), "Ludo Star", Style::Default );

Texture BoardTexture;

View mainView;
RectangleShape Board(Vector2f(height, height));
Vector2u WindowSize = window.getSize();

Texture RedTokenTexture;
Texture BlueTokenTexture;
Texture GreenTokenTexture;
Texture YellowTokenTexture;

RectangleShape RedToken1(Vector2f(Token, Token));
RectangleShape RedToken2(Vector2f(Token, Token));
RectangleShape RedToken3(Vector2f(Token, Token));
RectangleShape RedToken4(Vector2f(Token, Token));

RectangleShape BlueToken1(Vector2f(Token, Token));
RectangleShape BlueToken2(Vector2f(Token, Token));
RectangleShape BlueToken3(Vector2f(Token, Token));
RectangleShape BlueToken4(Vector2f(Token, Token));
		
RectangleShape GreenToken1(Vector2f(Token, Token));
RectangleShape GreenToken2(Vector2f(Token, Token));
RectangleShape GreenToken3(Vector2f(Token, Token));
RectangleShape GreenToken4(Vector2f(Token, Token));
		
RectangleShape YellowToken1(Vector2f(Token, Token));
RectangleShape YellowToken2(Vector2f(Token, Token));
RectangleShape YellowToken3(Vector2f(Token, Token));
RectangleShape YellowToken4(Vector2f(Token, Token));

//Board Coordinates
vector<Vector2f>RedCOORD{
	//red
	{width * 0.465f, height * 0.875f},		{width * 0.465f, height * 0.8125f},		{width * 0.465f, height * 0.75f},		{width * 0.465f, height * 0.6875f},		{width * 0.465f, height * 0.625f},
	{width * 0.43f, height * 0.5625f},		{width * 0.3947f, height * 0.5625f},	{width * 0.3596f, height * 0.5625f},	{width * 0.3244f, height * 0.5625f},	{width * 0.2893f, height * 0.5625f},
	{width * 0.2542f, height * 0.5625f},	{width * 0.2542f, height * 0.5f},		{width * 0.2542f, height * 0.4375f},

	//green
	{width * 0.2893f, height * 0.4375f},  	{width * 0.3244f, height * 0.4375f},	{width * 0.3596f, height * 0.4375f},	{width * 0.3947f, height * 0.4375f},	{width * 0.43f, height * 0.4375f},
	{width * 0.465f, height * 0.375f},		{width * 0.465f, height * 0.3125f},		{width * 0.465f, height * 0.25f},		{width * 0.465f, height * 0.1875f},		{width * 0.465f, height * 0.125f},
	{width * 0.465f, height * 0.0625f},		{width * 0.5f, height * 0.0625f},		{width * 0.5353f, height * 0.0625f},

	//yellow
	{width * 0.5353f, height * 0.125f},  	{width * 0.5353f, height * 0.1875f},	{width * 0.5353f, height * 0.25f},		{width * 0.5353f, height * 0.3125f},	{width * 0.5353f, height * 0.375f},
	{width * 0.5704f, height * 0.4375f},	{width * 0.6055f, height * 0.4375f},	{width * 0.6407f, height * 0.4375f},	{width * 0.6758f, height * 0.4375f},	{width * 0.711f, height * 0.4375f},
	{width * 0.7461f, height * 0.4375f},	{width * 0.7461f, height * 0.5f},		{width * 0.7461f, height * 0.5625f},

	//blue
	{width * 0.711f, height * 0.5625f}, 	{width * 0.6758f, height * 0.5625f},	{width * 0.6407f, height * 0.5625f},	{width * 0.6055f, height * 0.5625f},	{width * 0.5704f, height * 0.5625f},
	{width * 0.5353f, height * 0.625f},		{width * 0.5353f, height * 0.6875f},	{width * 0.5353f, height * 0.75f},		{width * 0.5353f, height * 0.8125f},	{width * 0.5353f, height * 0.875f},
	{width * 0.5353f, height * 0.9375f},	{width * 0.5f, height * 0.9375f},

	//red win
	{width * 0.5f, height * 0.875f},		{width * 0.5f, height * 0.8125f},		{width * 0.5f, height * 0.75f},			{width * 0.5f, height * 0.6875f},		{width * 0.5f, height * 0.625f},
	{width * 0.5f, height * 0.5625f}

};
vector<Vector2f>BlueCOORD{
	//blue
	{width * 0.711f, height * 0.5625f}, 	{width * 0.6758f, height * 0.5625f},	{width * 0.6407f, height * 0.5625f},	{width * 0.6055f, height * 0.5625f},	{width * 0.5704f, height * 0.5625f},
	{width * 0.5353f, height * 0.625f},		{width * 0.5353f, height * 0.6875f},	{width * 0.5353f, height * 0.75f},		{width * 0.5353f, height * 0.8125f},	{width * 0.5353f, height * 0.875f},
	{width * 0.5353f, height * 0.9375f},	{width * 0.5f, height * 0.9375f},		{width * 0.465f, height * 0.9375f},

	//red
	{width * 0.465f, height * 0.875f},		{width * 0.465f, height * 0.8125f},		{width * 0.465f, height * 0.75f},		{width * 0.465f, height * 0.6875f},		{width * 0.465f, height * 0.625f},
	{width * 0.43f, height * 0.5625f},		{width * 0.3947f, height * 0.5625f},	{width * 0.3596f, height * 0.5625f},	{width * 0.3244f, height * 0.5625f},	{width * 0.2893f, height * 0.5625f},
	{width * 0.2542f, height * 0.5625f},	{width * 0.2542f, height * 0.5f},		{width * 0.2542f, height * 0.4375f},

	//green
	{width * 0.2893f, height * 0.4375f},  	{width * 0.3244f, height * 0.4375f},	{width * 0.3596f, height * 0.4375f},	{width * 0.3947f, height * 0.4375f},	{width * 0.43f, height * 0.4375f},
	{width * 0.465f, height * 0.375f},		{width * 0.465f, height * 0.3125f},		{width * 0.465f, height * 0.25f},		{width * 0.465f, height * 0.1875f},		{width * 0.465f, height * 0.125f},
	{width * 0.465f, height * 0.0625f},		{width * 0.5f, height * 0.0625f},		{width * 0.5353f, height * 0.0625f},

	//yellow
	{width * 0.5353f, height * 0.125f},  	{width * 0.5353f, height * 0.1875f},	{width * 0.5353f, height * 0.25f},		{width * 0.5353f, height * 0.3125f},	{width * 0.5353f, height * 0.375f},
	{width * 0.5704f, height * 0.4375f},	{width * 0.6055f, height * 0.4375f},	{width * 0.6407f, height * 0.4375f},	{width * 0.6758f, height * 0.4375f},	{width * 0.711f, height * 0.4375f},
	{width * 0.7461f, height * 0.4375f},	{width * 0.7461f, height * 0.5f},		

	//blue win
	{width * 0.711f, height * 0.5f},		{width * 0.6758f, height * 0.5f},		{width * 0.6407f, height * 0.5f},		{width * 0.6055f, height * 0.5f},		{width * 0.5704f, height * 0.5f},
	{width * 0.5353f, height * 0.5f},
};
vector<Vector2f>GreenCOORD{
	//green
	{width * 0.2893f, height * 0.4375f},  	{width * 0.3244f, height * 0.4375f},	{width * 0.3596f, height * 0.4375f},	{width * 0.3947f, height * 0.4375f},	{width * 0.43f, height * 0.4375f},
	{width * 0.465f, height * 0.375f},		{width * 0.465f, height * 0.3125f},		{width * 0.465f, height * 0.25f},		{width * 0.465f, height * 0.1875f},		{width * 0.465f, height * 0.0625f},
	{width * 0.465f, height * 0.0625f},		{width * 0.5f, height * 0.0625f},		{width * 0.5353f, height * 0.0625f},

	//yellow
	{width * 0.5353f, height * 0.0625f},  	{width * 0.5353f, height * 0.1875f},	{width * 0.5353f, height * 0.25f},	{width * 0.5353f, height * 0.3125f},	{width * 0.5353f, height * 0.375f},
	{width * 0.5704f, height * 0.4375f},	{width * 0.6055f, height * 0.4375f},	{width * 0.6407f, height * 0.4375f},	{width * 0.6758f, height * 0.4375f},	{width * 0.711f, height * 0.4375f},
	{width * 0.7461f, height * 0.4375f},	{width * 0.7461f, height * 0.5f},		{width * 0.7461f, height * 0.5625f},

	//blue
	{width * 0.711f, height * 0.5625f}, 	{width * 0.6758f, height * 0.5625f},	{width * 0.6407f, height * 0.5625f},	{width * 0.6055f, height * 0.5625f},	{width * 0.5704f, height * 0.5625f},
	{width * 0.5353f, height * 0.625f},		{width * 0.5353f, height * 0.6875f},	{width * 0.5353f, height * 0.75f},	{width * 0.5353f, height * 0.8125f},	{width * 0.5353f, height * 0.875f},
	{width * 0.5353f, height * 0.9375f},	{width * 0.5f, height * 0.9375f},		{width * 0.465f, height * 0.9375f},
	
	//red
	{width * 0.465f, height * 0.875f},		{width * 0.465f, height * 0.8125f},		{width * 0.465f, height * 0.75f},	{width * 0.465f, height * 0.6875f},	{width * 0.465f, height * 0.625f},
	{width * 0.43f, height * 0.5625f},		{width * 0.3947f, height * 0.5625f},	{width * 0.3596f, height * 0.5625f},	{width * 0.3244f, height * 0.5625f},	{width * 0.2893f, height * 0.5625f},
	{width * 0.2542f, height * 0.5625f},	{width * 0.2542f, height * 0.5f},		

	//green win
	{width * 0.2893f, height * 0.5f},  	{width * 0.3244f, height * 0.5f},	{width * 0.3596f, height * 0.5f},	{width * 0.3947f, height * 0.5f},	{width * 0.43f, height * 0.5f},
	{width * 0.465f, height * 0.5f},

};
vector<Vector2f>YellowCOORD{
	//yellow
	{width * 0.5353f, height * 0.125f},  	{width * 0.5353f, height * 0.1875f},	{width * 0.5353f, height * 0.25f},		{width * 0.5353f, height * 0.3125f},	{width * 0.5353f, height * 0.375f},
	{width * 0.5704f, height * 0.4375f},	{width * 0.6055f, height * 0.4375f},	{width * 0.6407f, height * 0.4375f},	{width * 0.6758f, height * 0.4375f},	{width * 0.711f, height * 0.4375f},
	{width * 0.7461f, height * 0.4375f},	{width * 0.7461f, height * 0.5f},		{width * 0.7461f, height * 0.5625f},

	//blue
	{width * 0.711f, height * 0.5625f}, 	{width * 0.6758f, height * 0.5625f},	{width * 0.6407f, height * 0.5625f},	{width * 0.6055f, height * 0.5625f},	{width * 0.5704f, height * 0.5625f},
	{width * 0.5353f, height * 0.625f},		{width * 0.5353f, height * 0.6875f},	{width * 0.5353f, height * 0.75f},		{width * 0.5353f, height * 0.8125f},	{width * 0.5353f, height * 0.875f},
	{width * 0.5353f, height * 0.9375f},	{width * 0.5f, height * 0.9375f},		{width * 0.465f, height * 0.9375f},

	//red
	{width * 0.465f, height * 0.875f},		{width * 0.465f, height * 0.8125f},		{width * 0.465f, height * 0.75f},		{width * 0.465f, height * 0.6875f},		{width * 0.465f, height * 0.625f},
	{width * 0.43f, height * 0.5625f},		{width * 0.3947f, height * 0.5625f},	{width * 0.3596f, height * 0.5625f},	{width * 0.3244f, height * 0.5625f},	{width * 0.2893f, height * 0.5625f},
	{width * 0.2542f, height * 0.5625f},	{width * 0.2542f, height * 0.5f},		{width * 0.2542f, height * 0.4375f},

	//green
	{width * 0.2893f, height * 0.4375f},  	{width * 0.3244f, height * 0.4375f},	{width * 0.3596f, height * 0.4375f},	{width * 0.3947f, height * 0.4375f},	{width * 0.43f, height * 0.4375f},
	{width * 0.465f, height * 0.375f},		{width * 0.465f, height * 0.3125f},		{width * 0.465f, height * 0.25f},		{width * 0.465f, height * 0.1875f},		{width * 0.465f, height * 0.125f},
	{width * 0.465f, height * 0.0625f},		{width * 0.5f, height * 0.0625f},		

	//yellow win
	{width * 0.5f, height * 0.125f},  	{width * 0.5f, height * 0.1875f},	{width * 0.5f, height * 0.25f},		{width * 0.5f, height * 0.3125f},	{width * 0.5f, height * 0.375f},
	{width * 0.5f, height * 0.4375f},
};
vector<Vector2f>RedHomeCOORD{
	{width * 0.3768f, height * 0.78125f}, //right
	{width * 0.3414f, height * 0.844677f}, //bottom
	{width * 0.3414f, height * 0.718677f}, //top
	{width * 0.3054f, height * 0.78125f} //left
};
vector<Vector2f>BlueHomeCOORD{
	{width * 0.6591f, height * 0.718677f}, //top
	{width * 0.6945f, height * 0.78125f}, //right
	{width * 0.6231f, height * 0.78125f}, //left
	{width * 0.6591f, height * 0.844677f} //bottom
};
vector<Vector2f>GreenHomeCOORD{
	{width* 0.3414f, height* 0.280875f}, //bottom
	{width* 0.3054f, height* 0.216875f}, //left
	{width* 0.3768f, height* 0.216875f}, //right
	{width* 0.3414f, height* 0.154875f} //top
};
vector<Vector2f>YellowHomeCOORD{
	{width* 0.6231f, height* 0.216875f}, //left
	{width* 0.6591f, height* 0.154875f}, //top
	{width* 0.6591f, height* 0.280875f}, //bottom
	{width* 0.6945f, height* 0.216875f} //right
	
};

// Functions
void DrawRED()
{
	window.draw(RedToken1);
	window.draw(RedToken2);
	window.draw(RedToken3);
	window.draw(RedToken4);
}
void DrawBLUE()
{
	window.draw(BlueToken1);
	window.draw(BlueToken2);
	window.draw(BlueToken3);
	window.draw(BlueToken4);
}
void DrawGREEN()
{
	window.draw(GreenToken1);
	window.draw(GreenToken2);
	window.draw(GreenToken3);
	window.draw(GreenToken4);

}
void DrawYELLOW()
{
	window.draw(YellowToken1);
	window.draw(YellowToken2);
	window.draw(YellowToken3);
	window.draw(YellowToken4);

}
void Draw2Players()
{
	window.clear();
	window.setView(mainView);
	window.draw(Board);
	DrawRED();
	DrawYELLOW();
	window.display();
}
void Draw4Players()
{
	window.clear();
	window.setView(mainView);
	window.draw(Board);
	DrawRED();
	DrawBLUE();
	DrawYELLOW();
	DrawGREEN();
	window.display();
}
void MoveRED(int Dice) 
{
	cin >> Dice;
	if (!Red1 && Dice == 5) {
		RedToken1.setPosition(RedCOORD[0].x, RedCOORD[0].y);
		Red1 = true;
		RedCounter1++;
	}
	else if (Red1 && RedCounter1 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			RedToken1.setPosition(RedCOORD[RedCounter1].x, RedCOORD[RedCounter1].y);
			RedCounter1++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
	else if (!Red2 && Dice == 5) {
		RedToken2.setPosition(RedCOORD[0].x, RedCOORD[0].y);
		Red2 = true;
		RedCounter2++;
	}
	else if (Red2 && RedCounter2 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			RedToken2.setPosition(RedCOORD[RedCounter2].x, RedCOORD[RedCounter2].y);
			RedCounter2++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
	else if (!Red3 && Dice == 5) {
		RedToken3.setPosition(RedCOORD[0].x, RedCOORD[0].y);
		Red3 = true;
		RedCounter3++;
	}
	else if (Red3 && RedCounter3 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			RedToken3.setPosition(RedCOORD[RedCounter3].x, RedCOORD[RedCounter3].y);
			RedCounter3++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
	else if (!Red4 && Dice == 5) {
		RedToken4.setPosition(RedCOORD[0].x, RedCOORD[0].y);
		Red4 = true;
		RedCounter4++;
	}
	else if (Red4 && RedCounter4 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			RedToken4.setPosition(RedCOORD[RedCounter4].x, RedCOORD[RedCounter4].y);
			RedCounter4++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
}
void MoveBLUE(int Dice)
{
	cin >> Dice;
	if (!Blue1 && Dice == 5) {
		BlueToken1.setPosition(BlueCOORD[0].x, BlueCOORD[0].y);
		Blue1 = true;
		BlueCounter1++;
	}
	else if (Blue1 && BlueCounter1 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			BlueToken1.setPosition(BlueCOORD[BlueCounter1].x, BlueCOORD[BlueCounter1].y);
			BlueCounter1++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
	else if (!Blue2 && Dice == 5) {
		BlueToken2.setPosition(BlueCOORD[0].x, BlueCOORD[0].y);
		Blue2 = true;
		BlueCounter2++;
	}
	else if (Blue2 && BlueCounter2 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			BlueToken2.setPosition(BlueCOORD[BlueCounter2].x, BlueCOORD[BlueCounter2].y);
			BlueCounter2++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
	else if (!Blue3 && Dice == 5) {
		BlueToken3.setPosition(BlueCOORD[0].x, BlueCOORD[0].y);
		Blue3 = true;
		BlueCounter3++;
	}
	else if (Blue3 && BlueCounter3 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			BlueToken3.setPosition(BlueCOORD[BlueCounter3].x, BlueCOORD[BlueCounter3].y);
			BlueCounter3++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
	else if (!Blue4 && Dice == 5) {
		BlueToken4.setPosition(BlueCOORD[0].x, BlueCOORD[0].y);
		Blue4 = true;
		BlueCounter4++;
	}
	else if (Blue4 && BlueCounter4 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			BlueToken4.setPosition(BlueCOORD[BlueCounter4].x, BlueCOORD[BlueCounter4].y);
			BlueCounter4++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
}
void MoveGREEN(int Dice)
{
	cin >> Dice;
	if (!Green1 && Dice == 5) {
		GreenToken1.setPosition(GreenCOORD[0].x, GreenCOORD[0].y);
		Green1 = true;
		GreenCounter1++;
	}
	else if (Green1 && GreenCounter1 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			GreenToken1.setPosition(GreenCOORD[GreenCounter1].x, GreenCOORD[GreenCounter1].y);
			GreenCounter1++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
	else if (!Green2 && Dice == 5) {
		GreenToken2.setPosition(GreenCOORD[0].x, GreenCOORD[0].y);
		Green2 = true;
		GreenCounter2++;
	}
	else if (Green2 && GreenCounter2 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			GreenToken2.setPosition(GreenCOORD[GreenCounter2].x, GreenCOORD[GreenCounter2].y);
			GreenCounter2++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
	else if (!Green3 && Dice == 5) {
		GreenToken3.setPosition(GreenCOORD[0].x, GreenCOORD[0].y);
		Green3 = true;
		GreenCounter3++;
	}
	else if (Green3 && GreenCounter3 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			GreenToken3.setPosition(GreenCOORD[GreenCounter3].x, GreenCOORD[GreenCounter3].y);
			GreenCounter3++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
	else if (!Green4 && Dice == 5) {
		GreenToken4.setPosition(GreenCOORD[0].x, GreenCOORD[0].y);
		Green4 = true;
		GreenCounter4++;
	}
	else if (Green4 && GreenCounter4 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			GreenToken4.setPosition(GreenCOORD[GreenCounter4].x, GreenCOORD[GreenCounter4].y);
			GreenCounter4++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
}
void MoveYELLOW(int Dice)
{
	cin >> Dice;
	if (!Yellow1 && Dice == 5) {
		YellowToken1.setPosition(YellowCOORD[0].x, YellowCOORD[0].y);
		Yellow1 = true;
		YellowCounter1++;
	}
	else if (Yellow1 && YellowCounter1 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			YellowToken1.setPosition(YellowCOORD[YellowCounter1].x, YellowCOORD[YellowCounter1].y);
			YellowCounter1++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
	else if (!Yellow2 && Dice == 5) {
		YellowToken2.setPosition(YellowCOORD[0].x, YellowCOORD[0].y);
		Yellow2 = true;
		YellowCounter2++;
	}
	else if (Yellow2 && YellowCounter2 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			YellowToken2.setPosition(YellowCOORD[YellowCounter2].x, YellowCOORD[YellowCounter2].y);
			YellowCounter2++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
	else if (!Yellow3 && Dice == 5) {
		YellowToken3.setPosition(YellowCOORD[0].x, YellowCOORD[0].y);
		Yellow3 = true;
		YellowCounter3++;
	}
	else if (Yellow3 && YellowCounter3 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			YellowToken3.setPosition(YellowCOORD[YellowCounter3].x, YellowCOORD[YellowCounter3].y);
			YellowCounter3++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
	else if (!Yellow4 && Dice == 5) {
		YellowToken4.setPosition(YellowCOORD[0].x, YellowCOORD[0].y);
		Yellow4 = true;
		YellowCounter4++;
	}
	else if (Yellow4 && YellowCounter4 <= MAX_MOVES) {
		for (int i = 1; i <= Dice; i++) {
			YellowToken4.setPosition(YellowCOORD[YellowCounter4].x, YellowCOORD[YellowCounter4].y);
			YellowCounter4++;
			this_thread::sleep_for(std::chrono::milliseconds(300));
			if (player == 2) {
				Draw2Players();
			}
			else if (player == 4) {
				Draw4Players();
			}
		}
	}
}

int main()
{
	// Main
		mainView.setSize(width, height);
		mainView.setCenter(width / 2, height / 2);
		Vector2f ViewSize = mainView.getSize();
		Vector2f BoardSize = Board.getSize();

		BoardTexture.loadFromFile("texture/back.png");
		Board.setTexture(&BoardTexture);
		Board.setOrigin(height / 2, height / 2);
		Board.setPosition(width / 2, height / 2);
	
	//Red Tokens
			RedTokenTexture.loadFromFile("texture/Red.png");
			RedToken1.setTexture(&RedTokenTexture);
			RedToken1.setOrigin(Token/2, Token/2);
			RedToken1.setPosition(RedHomeCOORD[0].x, RedHomeCOORD[0].y);
			RedToken2.setTexture(&RedTokenTexture);
			RedToken2.setOrigin(Token/2, Token/2);
			RedToken2.setPosition(RedHomeCOORD[1].x, RedHomeCOORD[1].y);
			RedToken3.setTexture(&RedTokenTexture);
			RedToken3.setOrigin(Token/2, Token/2);
			RedToken3.setPosition(RedHomeCOORD[2].x, RedHomeCOORD[2].y);
			RedToken4.setTexture(&RedTokenTexture);
			RedToken4.setOrigin(Token/2, Token/2);
			RedToken4.setPosition(RedHomeCOORD[3].x, RedHomeCOORD[3].y);

	//Blue Tokens
			BlueTokenTexture.loadFromFile("texture/Blue.png");
			BlueToken1.setTexture(&BlueTokenTexture);
			BlueToken1.setOrigin(Token/2, Token/2);
			BlueToken1.setPosition(BlueHomeCOORD[0].x, BlueHomeCOORD[0].y);
			BlueToken2.setTexture(&BlueTokenTexture);
			BlueToken2.setOrigin(Token/2, Token/2);
			BlueToken2.setPosition(BlueHomeCOORD[1].x, BlueHomeCOORD[1].y);
			BlueToken3.setTexture(&BlueTokenTexture);
			BlueToken3.setOrigin(Token/2, Token/2);
			BlueToken3.setPosition(BlueHomeCOORD[2].x, BlueHomeCOORD[2].y);
			BlueToken4.setTexture(&BlueTokenTexture);
			BlueToken4.setOrigin(Token/2, Token/2);
			BlueToken4.setPosition(BlueHomeCOORD[3].x, BlueHomeCOORD[3].y);

	//Green Tokens
			GreenTokenTexture.loadFromFile("texture/Green.png");
			GreenToken1.setTexture(&GreenTokenTexture);
			GreenToken1.setOrigin(Token/2, Token/2);
			GreenToken1.setPosition(GreenHomeCOORD[0].x, GreenHomeCOORD[0].y);
			GreenToken2.setTexture(&GreenTokenTexture);
			GreenToken2.setOrigin(Token/2, Token/2);
			GreenToken2.setPosition(GreenHomeCOORD[1].x, GreenHomeCOORD[1].y);
			GreenToken3.setTexture(&GreenTokenTexture);
			GreenToken3.setOrigin(Token/2, Token/2);
			GreenToken3.setPosition(GreenHomeCOORD[2].x, GreenHomeCOORD[2].y);
			GreenToken4.setTexture(&GreenTokenTexture);
			GreenToken4.setOrigin(Token/2, Token/2);
			GreenToken4.setPosition(GreenHomeCOORD[3].x, GreenHomeCOORD[3].y);

	//Yellow Tokens
			YellowTokenTexture.loadFromFile("texture/Yellow.png");
			YellowToken1.setTexture(&YellowTokenTexture);
			YellowToken1.setOrigin(Token/2, Token/2);
			YellowToken1.setPosition(YellowHomeCOORD[0].x, YellowHomeCOORD[0].y);
			YellowToken2.setTexture(&YellowTokenTexture);
			YellowToken2.setOrigin(Token/2, Token/2);
			YellowToken2.setPosition(YellowHomeCOORD[1].x, YellowHomeCOORD[1].y);
			YellowToken3.setTexture(&YellowTokenTexture);
			YellowToken3.setOrigin(Token/2, Token/2);
			YellowToken3.setPosition(YellowHomeCOORD[2].x, YellowHomeCOORD[2].y);
			YellowToken4.setTexture(&YellowTokenTexture);
			YellowToken4.setOrigin(Token/2, Token/2);
			YellowToken4.setPosition(YellowHomeCOORD[3].x, YellowHomeCOORD[3].y);

			window.draw(Board);
			window.display();
	std::cin >> player;
	Event evnt;

	while (window.isOpen())
	{
		while (window.pollEvent(evnt))
		{
			if (evnt.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		}
		/*//move
		if (Keyboard::isKeyPressed(Keyboard::F11)) {
			//window.setSize(Vector2u(1366.f, 768.f));
			::ShowWindow(window.getSystemHandle(), SW_SHOWMAXIMIZED);

		}*/
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			RedToken1.move(0.0f, -48.0f);
			/*RedToken2.move(0.0f, -10.0f);
			RedToken3.move(0.0f, -10.0f);
			RedToken4.move(0.0f, -10.0f);*/
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			RedToken1.move(-48.0f, 0.0f);
			/*RedToken2.move(-10.0f, 0.0f);
			RedToken3.move(-10.0f, 0.0f);
			RedToken4.move(-10.0f, 0.0f);*/
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			RedToken1.move(0.0f, 48.0f);
			/*RedToken2.move(0.0f, 10.0f);
			RedToken3.move(0.0f, 10.0f);
			RedToken4.move(0.0f, 10.0f);*/
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			RedToken1.move(48.0f, 0.0f);
			/*RedToken2.move(10.0f, 0.0f);
			RedToken3.move(10.0f, 0.0f);
			RedToken4.move(10.0f, 0.0f);*/
		}
		if (Keyboard::isKeyPressed(Keyboard::Y)) {
			RedToken1.move(0.0f, -1.0f);
			/*RedToken2.move(0.0f, -1.0f);
			RedToken3.move(0.0f, -1.0f);
			RedToken4.move(0.0f, -1.0f);*/
		}
		if (Keyboard::isKeyPressed(Keyboard::G)) {
			RedToken1.move(-1.0f, 0.0f);
			/*RedToken2.move(-1.0f, 0.0f);
			RedToken3.move(-1.0f, 0.0f);
			RedToken4.move(-1.0f, 0.0f);*/
		}
		if (Keyboard::isKeyPressed(Keyboard::H)) {
			RedToken1.move(0.0f, 1.0f);
			/*RedToken2.move(0.0f, 1.0f);
			RedToken3.move(0.0f, 1.0f);
			RedToken4.move(0.0f, 1.0f);*/
		}
		if (Keyboard::isKeyPressed(Keyboard::J)) {
			RedToken1.move(1.0f, 0.0f);
			/*RedToken2.move(1.0f, 0.0f);
			RedToken3.move(1.0f, 0.0f);
			RedToken4.move(1.0f, 0.0f);*/
		}
		if (Keyboard::isKeyPressed(Keyboard::P)) {
			cout << "Left: " << RedToken1.getPosition().x << " " << RedToken1.getPosition().y << endl;
			/*cout << "Top: " << RedToken2.getPosition().x << " " << RedToken2.getPosition().y << endl;
			cout << "Right: " << RedToken3.getPosition().x << " " << RedToken3.getPosition().y << endl;
			cout << "Bottom: " << RedToken4.getPosition().x << " " << RedToken4.getPosition().y << endl << endl;*/
		}
		/*if (Mouse::isButtonPressed(Mouse::Left)) {
			Vector2i Mpos = Mouse::getPosition(window);
			objectg.setPosition((float)Mpos.x, (float)Mpos.y);
			
		}*/
		
		
		if (player == 2) {
			Draw2Players();
			MoveRED(Dice);
			Draw2Players();
			MoveYELLOW(Dice);
		}
			
		else if (player == 4) {
			Draw4Players();
			MoveRED(Dice);
			Draw4Players();
			MoveBLUE(Dice);
			Draw4Players();
			MoveYELLOW(Dice);
			Draw4Players();
			MoveGREEN(Dice);
		}
	}
	return 0;
}