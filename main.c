#include <stdio.h>
#include <math.h>

#define ROWS 30
#define COLS 60

char canvas[ROWS][COLS];

/* Initialize Canvas */
void initializeCanvas() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            canvas[i][j] = '_';
        }
    }
}

/* Display Canvas */
void displayCanvas() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

/* Draw Rectangle */
void drawRectangle(int x, int y, int width, int height) {
    for(int i = y; i < y + height; i++) {
        for(int j = x; j < x + width; j++) {
            if(i < ROWS && j < COLS)
                canvas[i][j] = '*';
        }
    }
}

/* Draw Horizontal/Vertical Line */
void drawLine(int x1, int y1, int x2, int y2) {
    if(y1 == y2) {
        for(int x = x1; x <= x2; x++)
            canvas[y1][x] = '*';
    }
    else if(x1 == x2) {
        for(int y = y1; y <= y2; y++)
            canvas[y][x1] = '*';
    }
}

/* Draw Triangle */
void drawTriangle(int x, int y, int height) {
    for(int i = 0; i < height; i++) {
        for(int j = -i; j <= i; j++) {
            if(y + i < ROWS && x + j >= 0 && x + j < COLS)
                canvas[y + i][x + j] = '*';
        }
    }
}

/* Draw Circle */
void drawCircle(int cx, int cy, int r) {
    for(int y = 0; y < ROWS; y++) {
        for(int x = 0; x < COLS; x++) {
            int dx = x - cx;
            int dy = y - cy;

            if(dx * dx + dy * dy <= r * r)
                canvas[y][x] = '*';
        }
    }
}

/* Delete Object Area */
void deleteObject(int x, int y, int width, int height) {
    for(int i = y; i < y + height; i++) {
        for(int j = x; j < x + width; j++) {
            if(i < ROWS && j < COLS)
                canvas[i][j] = '_';
        }
    }
}

int main() {
    int choice;

    initializeCanvas();

    do {
        printf("\n--- 2D Graphics Editor ---\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Object\n");
        printf("6. Display Picture\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int x,y,w,h;
                printf("Enter x y width height: ");
                scanf("%d%d%d%d",&x,&y,&w,&h);
                drawRectangle(x,y,w,h);
                break;
            }

            case 2: {
                int x1,y1,x2,y2;
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                drawLine(x1,y1,x2,y2);
                break;
            }

            case 3: {
                int x,y,h;
                printf("Enter x y height: ");
                scanf("%d%d%d",&x,&y,&h);
                drawTriangle(x,y,h);
                break;
            }

            case 4: {
                int cx,cy,r;
                printf("Enter centerX centerY radius: ");
                scanf("%d%d%d",&cx,&cy,&r);
                drawCircle(cx,cy,r);
                break;
            }

            case 5: {
                int x,y,w,h;
                printf("Enter x y width height to delete: ");
                scanf("%d%d%d%d",&x,&y,&w,&h);
                deleteObject(x,y,w,h);
                break;
            }

            case 6:
                displayCanvas();
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 7);

    return 0;
}