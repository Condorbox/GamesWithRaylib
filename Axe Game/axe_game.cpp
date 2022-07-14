#include "raylib.h"

int main()
{
    int with{800};
    int height{450};
    InitWindow(with, height, "hello");

    // circle parameters
    int circle_x = with / 4;
    int circle_y = height / 2;
    int circle_radius = 25;
    // circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    // axe parameters
    int axe_x = with / 2;
    int axe_y = 0;
    int axe_length = 50;
    // axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    int direction = 10;

    bool collision_with_axe = (b_axe_y >= u_circle_y) && (u_axe_y <= b_circle_y) && (l_axe_x <= r_circle_x) && (r_axe_x >= l_circle_x);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (!collision_with_axe)
        {
            if (axe_y > height || axe_y < 0)
            {
                direction *= -1;
            }

            axe_y += direction;

            if (IsKeyDown(KEY_D) && circle_x < (with - circle_radius))
            {
                circle_x += 10;
            }
            else if (IsKeyDown(KEY_A) && circle_x > (0 + circle_radius))
            {
                circle_x -= 10;
            }

            // Update Circle Position
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            // Update Axe Position
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;
            // Update Collision
            collision_with_axe = (b_axe_y >= u_circle_y) && (u_axe_y <= b_circle_y) && (l_axe_x <= r_circle_x) && (r_axe_x >= l_circle_x);

            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);
        }
        else
        {
            DrawText("GameOver!", 400, 200, 20, BLACK);
        }

        EndDrawing();
    }
}