#include <stdio.h>

#define WIDTH 40
#define HEIGHT 20

char picture[HEIGHT][WIDTH];

// Fill the canvas with '_'
void initializePicture()
{
    int i, j;

    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            picture[i][j] = '_';
        }
    }
}
void drawRectangle(int x, int y, int width, int height)
{
    int i, j;

    for(i = y; i < y + height; i++)
    {
        for(j = x; j < x + width; j++)
        {
            picture[i][j] = '*';
        }
    }
}
void drawLine(int x1, int y1, int x2, int y2)
{
    int i;

    if(y1 == y2)
    {
        for(i = x1; i <= x2; i++)
        {
            picture[y1][i] = '*';
        }
    }
    else if(x1 == x2)
    {
        for(i = y1; i <= y2; i++)
        {
            picture[i][x1] = '*';
        }
    }
}
void drawTriangle(int x, int y, int height)
{
    int i, j;

    for(i = 0; i < height; i++)
    {
        for(j = x - i; j <= x + i; j++)
        {
            picture[y + i][j] = '*';
        }
    }
}
void drawCircle(int centerX, int centerY, int radius)
{
    int x, y;

    for(y = 0; y < HEIGHT; y++)
    {
        for(x = 0; x < WIDTH; x++)
        {
            int dx = x - centerX;
            int dy = y - centerY;

            if(dx * dx + dy * dy <= radius * radius)
            {
                picture[y][x] = '*';
            }
        }
    }
}
void deleteRectangle(int x, int y, int width, int height)
{
    int i, j;

    for(i = y; i < y + height; i++)
    {
        for(j = x; j < x + width; j++)
        {
            picture[i][j] = '_';
        }
    }
}

// Display the canvas
void displayPicture()
{
    int i, j;

    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            printf("%c ", picture[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("2D Graphics Editor Started!\n\n");

    initializePicture();
    drawRectangle(5, 3, 10, 5);
    drawLine(0, 0, 20, 0);
    drawLine(25, 2, 25, 12);
    drawTriangle(15, 5, 5);

    drawCircle(30, 10, 4);

    deleteRectangle(7, 4, 3, 2);
    displayPicture();

    return 0;
}