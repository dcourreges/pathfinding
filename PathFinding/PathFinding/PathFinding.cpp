#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include <ctime>
#include "conio.h"

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