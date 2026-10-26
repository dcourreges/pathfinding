#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
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



    int LINE = 10;

    int ROW = 10;

    int GETCHAR = -1;

    int playerPosX = 2;               
    int playerPosY = 3;

    int cursorPosX = 2;
    int cursorPosY = 3;

    bool playing = true;


    while (playing == true)
    {

        GETCHAR = _getch();
        std::system("cls");


       

        if (GETCHAR == 75 || GETCHAR ==  113)
        {
            cursorPosX -= 1;


            if (cursorPosX < 0)
                cursorPosX = 0;
        }

        if (GETCHAR == 77 || GETCHAR == 100)
        {
            cursorPosX += 1;


            if (cursorPosX > ROW - 1)
                cursorPosX = ROW - 1;

        }

        if (GETCHAR == 72 || GETCHAR == 122)
        {
            cursorPosY -= 1;

            if (cursorPosY < 0)
                cursorPosY = 0;
        }

        if (GETCHAR == 80 || GETCHAR == 115)
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
                /*if (isPath)
                {
                    std::cout << BackGREEN << "[" << " "  << "] " << BackRESET;
                    continue;
                }*/



                std::cout << "[ ] ";
            }

            std::cout << std::endl;

        }

        //std::cout << GETCHAR;
    }

    
    
    
}