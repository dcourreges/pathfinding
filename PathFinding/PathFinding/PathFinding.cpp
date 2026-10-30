#include <iostream>
#include <vector>
<<<<<<< HEAD

#define NOMINMAX
#include <windows.h>

#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define DEFAULT "\033[0m"

#define ENTER 13

constexpr int ROWS = 10;
constexpr int COLS = 10;

void gotoxy(short x, short y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hConsole, position);
}

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void Refresh()
{
	gotoxy(0, 0);
}

class Grid
{

	struct Tile
	{
		int row, col;

		bool obstacle = false;

		bool added = false;

		Tile* camefrom = nullptr;
	};

	std::vector<std::vector<Tile*>> TILES ;

	std::vector<std::vector<char>> map =
	{
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ','#',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
	};

	

	int playerRow = 0;
	int playerCol = 0;

	int cursorRow = 0;
	int cursorCol = 0;

	bool isInPath[ROWS][COLS];

public:
	void Run()
	{
		ResetPath();
		CreateGrid();
		
		while (true)
		{
			Display();
			Input();
			Path();

			FindPath(TILES[playerRow][playerCol], TILES[cursorRow][cursorCol]);

			Refresh();
		}
	}

	void ResetPath()
	{
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				isInPath[row][col] = false;
			}
		}
	}

	void Path()
	{
		ResetPath();

		int diffRow = cursorRow - playerRow;
		int lenghtRow = std::abs(diffRow);
		if (lenghtRow != 0)
		{
			int dirRow = diffRow / lenghtRow;
			for (int row = 0; row < lenghtRow; row++)
			{
				isInPath[playerRow + dirRow * row][playerCol] = true;
			}
		}

		int diffCol = cursorCol - playerCol;
		int lenghtCol = std::abs(diffCol);
		if (lenghtCol != 0)
		{
			int dirCol = diffCol / lenghtCol;
			for (int col = 0; col < lenghtCol; col++)
			{
				isInPath[playerRow + diffRow][playerCol + dirCol * col] = true;
			}
		}
	}


	void CreateGrid()
	{
		for (int row = 0; row < ROWS; row++)
		{
			std::vector<Tile*> tiles;
			for (int col = 0; col < COLS; col++)
			{
				Tile* tile = new Tile();
				tile->col = col;
				tile->row = row;
				tiles.push_back(tile);
			}
			TILES.push_back(tiles);
		}


	}

	void Display()
	{
		//Display
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				std::cout << "[";

				if (cursorRow == row && cursorCol == col)
				{
					std::cout << BG_GREEN;
				}
				else if (isInPath[row][col])
				{
					std::cout << BG_RED;
				}

				if (row == 1 && col == 2)
				{
					std::cout << "#";
					TILES[row][col]->obstacle = true;
				}

				if (playerRow == row && playerCol == col)
				{
					std::cout << "O";
				}

				else
				{
					std::cout << " ";
				}

				std::cout << DEFAULT;

				std::cout << "]";
			}

			std::cout << std::endl;
		}
	}

	void Input()
	{
		while (true)
		{
			int input = _getch();
			switch (input)
			{
			case 'z':
				cursorRow = std::max(0, cursorRow - 1);
				return;

			case 's':
				cursorRow = std::min(ROWS - 1, cursorRow + 1);
				return;

			case 'q':
				cursorCol = std::max(0, cursorCol - 1);
				return;

			case 'd':
				cursorCol = std::min(COLS - 1, cursorCol + 1);
				return;

			case '\r':
				playerCol = cursorCol;
				playerRow = cursorRow;
				return;
			}

		}


		system("cls");
	}

	Tile* GetTile(int row, int col)
	{

	}

	bool FindPath(Tile* start, Tile* end)
	{
		
		std::vector<Tile*> remains;
		remains.push_back(start);

		while (remains.size() > 0)
		{
			Tile* current = remains[0];
			remains.erase(remains.begin());

			if (current == end)
			{
				Tile* currenTile = current;
				while (currenTile != nullptr)
				{
					currenTile = currenTile->camefrom;
				}
				return true;
			}

			constexpr int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

			for (int i = 0; i < 4; i++)
			{
				int neighborRow = current->row + directions[i][1];

				int neighborCol = current->col + directions[i][0];

				if (neighborRow > ROWS || neighborRow < 0  || neighborCol > COLS || neighborCol < 0)
					continue;

				if (TILES[neighborRow][neighborCol]->obstacle == true)
					continue;


				if (TILES[neighborRow][neighborCol]->added == true)
						continue;
				
				remains.push_back(TILES[neighborRow][neighborCol]);

				TILES[neighborRow][neighborCol]->added = true;

			}

		}

		return false;
	}
};


=======
#include <string>
#include <cstdlib> 
#include <ctime>
#include "conio.h"
>>>>>>> parent of fee42d2 (path)

int main()
{

    std::string CharBOLD = "\033[22m";

    std::string CharGREEN = "\033[32m";

    std::string CharBLUE = "\033[34m";

    std::string CharYELLOW = "\033[33m";

    std::string CharRESET = "\033[39m";

    std::string BackRESET = "\033[49m";

    std::string BackYELLOW = "\033[43m";

    std::string BackGREEN = "\033[42m";

    std::string BackBLUE = "\033[44m";

    const int dirs[4][2] = {
    {  0, -1 },   // up
    {  0,  1 },   // down
    { -1,  0 },   // left
    {  1,  0 }    // right
    };

    int LINE = 10;

    int ROW = 10;

    int GETCHAR = -1;

    int playerPosX = 2;               
    int playerPosY = 3;

    int cursorPosX = 2;
    int cursorPosY = 3;

    srand(time(0));

    int obstaclePosX = playerPosX;//rand()%LINE;
    int obstaclePosY = playerPosY + 3;//rand()%ROW;

    bool playing = true;


    while (playing == true)
    {

        GETCHAR = _getch();
        std::system("cls");


       

        if ((GETCHAR == 75 || GETCHAR ==  113) && (cursorPosX - 1 != obstaclePosX && cursorPosY != obstaclePosY) )
        {
            cursorPosX -= 1;


            if (cursorPosX < 0)
                cursorPosX = 0;
        }

        if ((GETCHAR == 77 || GETCHAR == 100 )) //&& (cursorPosX + 1 != obstaclePosX))
        {
            cursorPosX += 1;


            if (cursorPosX > ROW - 1)
                cursorPosX = ROW - 1;

        }

        if ((GETCHAR == 72 || GETCHAR == 122)) //&& (cursorPosY - 1 != obstaclePosY))
        {
            cursorPosY -= 1;

            if (cursorPosY < 0)
                cursorPosY = 0;
        }

        if ((GETCHAR == 80 || GETCHAR == 115))// && (cursorPosY + 1 != obstaclePosY))
        {
            cursorPosY += 1;

            if (cursorPosY > LINE - 1)
                cursorPosY = LINE - 1;

        }

        if (GETCHAR == 27)
        { 
            playing = false;
        }

        if (GETCHAR == 13)
        {
            playerPosX = cursorPosX;
            playerPosY = cursorPosY;
        }

       int returnY = cursorPosY - 1;

       if (returnY < 0)
       {
           returnY = cursorPosY + 1;
       }

       int returnX = cursorPosX - 1;

       if (returnX < 0)
       {
           returnX = cursorPosX + 1;
       }

       bool obstacleOnPathX = (obstaclePosY == cursorPosY) && ((obstaclePosX >= playerPosX && obstaclePosX <= cursorPosX) || (obstaclePosX <= playerPosX && obstaclePosX >= cursorPosX));

       bool obstacleOnPathY = (obstaclePosX == cursorPosX) && ((obstaclePosY >= playerPosY && obstaclePosY <= cursorPosY) || (obstaclePosY <= playerPosY && obstaclePosY >= cursorPosY));

        for (int row = 0; row < ROW; row++)
        {
            for (int line = 0; line < LINE; line++)
            {
                if (row == cursorPosY && line == cursorPosX)
                {
                    std::cout << "[" << CharBOLD << CharBLUE << "X" << CharRESET << "] ";
                    continue;
                }

                if (row == playerPosY && line == playerPosX)
                {
                    std::cout << "[" << CharBOLD << CharYELLOW << "O" << CharRESET << "] ";
                    continue;
                }

                if (row == obstaclePosY && line == obstaclePosX)
                {
                    std::cout << "[" << CharBOLD << CharGREEN << "#" << CharRESET << "] ";
                    continue;
                }


                if ((line <= cursorPosX && line >= playerPosX || line >= cursorPosX && line <= playerPosX) && row == cursorPosY)
                {
                    std::cout << "[" << BackYELLOW << " " << BackRESET << "] ";
                    continue;
                }

                if ((row <= cursorPosY && row >= playerPosY || row >= cursorPosY && row <= playerPosY) && line == playerPosX)
                {
                    std::cout  << "[" << BackGREEN << " " << BackRESET << "] " ;
                    continue;
                }

                if (obstacleOnPathX && row == returnY && line >= obstaclePosX - 1 && line <= obstaclePosX + 1)
                {
                    std::cout << "[" << BackBLUE << " " << BackRESET << "] ";
                    continue;
                }

                if (obstacleOnPathY && line == returnX && row >= obstaclePosY - 1 && row <= obstaclePosY + 1)
                {
                    std::cout << "[" << BackBLUE << " " << BackRESET << "] ";
                    continue;
                }


                std::cout << "[ ] ";
            }

            std::cout << std::endl;

        }

        //std::cout << GETCHAR;
    }

    
    
    
}