#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

// Will be sent to the movement void and be analyzed
char input_key;
void start();

// 37 represents y and 48 represents x
// 0 represents the blank spaces in maze
// 1 represents the walls of the maze
// 2 represents the exit for the maze



int maze_map [37][48] =
{
// 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 5 5 5
// 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,1,1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,1,1},
{1,1,6,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,1,6,1,1,6,1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,6,1,1},
{1,1,6,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,1,6,1,1,6,1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,6,1,1},
{1,1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,1,1},
{1,1,6,1,1,1,1,1,1,1,1,6,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1,1,6,1,1,1,1,1,1,1,1,6,1,1},
{1,1,6,6,6,6,6,6,6,6,6,6,1,1,6,6,6,6,6,6,6,6,6,1,1,6,6,6,6,6,6,6,6,6,1,1,6,6,6,6,6,6,6,6,6,6,1,1},
{1,1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,1,6,1,1,6,1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,1,1},
{1,1,0,0,0,0,0,0,0,1,1,6,1,1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,1,1,6,1,1,0,0,0,0,0,0,0,1,1},
{1,1,0,0,0,0,0,0,0,1,1,6,1,1,6,1,1,1,1,1,1,1,4,4,4,4,1,1,1,1,1,1,1,6,1,1,6,1,1,0,0,0,0,0,0,0,1,1},
{1,1,0,0,0,0,0,0,0,1,1,6,1,1,6,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,6,1,1,6,1,1,0,0,0,0,0,0,0,1,1},
{1,1,1,1,1,1,1,1,1,1,1,6,1,1,6,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,6,1,1,6,1,1,1,1,1,1,1,1,1,1,1},
{2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,3},
{1,1,1,1,1,1,1,1,1,1,1,6,1,1,6,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,6,1,1,6,1,1,1,1,1,1,1,1,1,1,1},
{1,1,0,0,0,0,0,0,0,1,1,6,1,1,6,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,6,1,1,6,1,1,0,0,0,0,0,0,0,1,1},
{1,1,0,0,0,0,0,0,0,1,1,6,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1,1,6,1,1,0,0,0,0,0,0,0,1,1},
{1,1,0,0,0,0,0,0,0,1,1,6,1,1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,1,1,6,1,1,0,0,0,0,0,0,0,1,1},
{1,1,1,1,1,1,1,1,1,1,1,6,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1,1,6,1,1,1,1,1,1,1,1,1,1,1},
{1,1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,1,1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,1,1},
{1,1,6,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,1,6,1,1,6,1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,6,1,1},
{1,1,6,6,6,6,6,6,6,1,1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,1,1,6,6,6,6,6,6,6,1,1},
{1,1,1,1,1,1,1,1,6,1,1,6,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1,1,6,1,1,6,1,1,1,1,1,1,1,1},
{1,1,6,6,6,6,6,6,6,6,6,6,1,1,6,6,6,6,6,6,6,6,6,1,1,6,6,6,6,6,6,6,6,6,1,1,6,6,6,6,6,6,6,6,6,6,1,1},
{1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1,1},
{1,1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}



};

// Function Prototype
void draw_maze();
void pacman_movement();

int main()
{
//    start();
    draw_maze();
    pacman_movement();
    return 0;
}
void draw_maze()
{
//    cout << "Score: \n";
      // This loop will increment until it reaches thirty-seven because it is the vertical line
  for (int v = 0; v < 37; v++)
  {
    // This loop will increment until it reaches forty-eight because it is the horizontal line
    for (int h = 0; h < 48; h++)
    {
      switch (maze_map[v][h])
      {
        // These cases are defining what the numbers mean
        // The break breaks the switch
        case 0:
             cout << " ";
             break;
        case 1:
             // Char 219 is simply a block, but 216 also works nicely,
             cout << char(216);
             break;
        case 2:
             cout << " ";
             break;
        case 3:
             cout << " ";
             break;
        case 4:
             cout << "_";
             break;
        case 5:
             cout << " ";
             break;
        case 6:
             cout << ".";
             break;

      }
    }
   cout << endl;
  }
}


// This void will place the character on the map
void gotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// This void will move the character 1
void pacman_movement()
{
    int x = 2;
    int y = 3;
    int x_before = 2;
    int y_before = 1;

    while (true)
    {
        gotoXY(x_before, y_before);
        cout << " ";

        gotoXY(x,y);
        cout << char(4);

        input_key = getch();
        x_before = x;
        y_before = y;

        // Analyzes the key variable
        // Also makes a controller for the game
        if(input_key == 'w')
        {
            y -= 1;
        }

        else if(input_key == 's')
        {
            y += 1;
        }

        else if(input_key == 'a')
        {
            x -= 1;
        }

        else if(input_key == 'd')
        {
            x += 1;
        }

        while(maze_map[y][x] == 1)
        {
            x = x_before;
            y = y_before;
        }

    }
}

void score();

void score(int x)
{
    int score = 0;

    if (x++)
    {
        score++;
    }
    cout << "Score: " << score;
}

void start()
{
    int letter;
    cout << "Welcome to Pac Man. Enter any key and press enter to start.          ";
    cin >> letter;
}
