#include <stdio.h>

#define ROWS 20
#define COLS 50

void initializeCanvas(char canvas[ROWS][COLS]);
void displayCanvas(char canvas[ROWS][COLS]);
void drawRectangle(char canvas[ROWS][COLS], int row, int col, int height, int width);
void drawLine(char canvas[ROWS][COLS], int row, int startCol, int endCol);
void drawVerticalLine(char canvas[ROWS][COLS], int col, int startRow, int endRow);

int main()
{
    char canvas[ROWS][COLS];
    int choice;

    initializeCanvas(canvas);
    do
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Vertical Line\n");
        printf("3. Display Canvas\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                drawRectangle(canvas, 2, 5, 6, 12);
                printf("Rectangle Drawn Successfully!\n");
                break;

            case 2:
                drawLine(canvas, 12, 5, 25);
                printf("Line Drawn Successfully!\n");
                break;
            case 3:
                drawVerticalLine(canvas, 15, 2, 15);
                printf("Vertical Line Drawn Successfully!\n");
                break;

            case 4:
                displayCanvas(canvas);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}

void initializeCanvas(char canvas[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '.';
        }
    }
}

void displayCanvas(char canvas[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(char canvas[ROWS][COLS], int row, int col, int height, int width)
{
    for(int i = row; i < row + height; i++)
    {
        for(int j = col; j < col + width; j++)
        {
            if(i == row || i == row + height - 1 ||
               j == col || j == col + width - 1)
            {
                canvas[i][j] = '*';
            }
        }
    }
}

void drawLine(char canvas[ROWS][COLS], int row, int startCol, int endCol)
{
    for(int j = startCol; j <= endCol; j++)
    {
        canvas[row][j] = '*';
    }
}
void drawVerticalLine(char canvas[ROWS][COLS], int col, int startRow, int endRow)
{
    for(int i = startRow; i <= endRow; i++)
    {
        canvas[i][col] = '*';
    }
}