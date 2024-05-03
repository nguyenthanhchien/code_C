#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

// Kích thước cửa sổ
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Struct để lưu trữ một điểm trong không gian 2D
typedef struct {
    double x;
    double y;
} Point;

// Hàm để tính toán spline cubic cho một đoạn nội suy
void computeCubicSpline(Point p1, Point p2, double* a, double* b, double* c, double* d) {
    *a = (p2.y - p1.y) / (p2.x - p1.x);
    *b = 0; // Đối với spline cubic, b luôn bằng 0
    *c = *a;
    *d = p1.y;
}

// Hàm để vẽ ba điểm và spline cubic tương ứng
void draw(SDL_Renderer* renderer, Point points[], int n) {
    // Vẽ ba điểm
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Đỏ
    for (int i = 0; i < n; i++) {
        SDL_RenderDrawPoint(renderer, (int)points[i].x, (int)points[i].y);
    }

    // Vẽ spline cubic
    double a1, b1, c1, d1; // Hệ số của đoạn 1
    double a2, b2, c2, d2; // Hệ số của đoạn 2

    computeCubicSpline(points[0], points[1], &a1, &b1, &c1, &d1);
    computeCubicSpline(points[1], points[2], &a2, &b2, &c2, &d2);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Xanh dương
    for (double x = points[0].x; x < points[2].x; x += 0.1) {
        double y1 = a1 * (x - points[0].x) * (x - points[0].x) + d1;
        double y2 = a2 * (x - points[1].x) * (x - points[1].x) + d2;
        SDL_RenderDrawLine(renderer, (int)x, (int)y1, (int)x, (int)y2);
    }
}

int main() {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    // Khởi tạo SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Tạo cửa sổ và renderer
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);

    // Thiết lập màu nền là màu trắng
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Khởi tạo ba điểm bất kỳ
    Point points[3] = { {100, 200}, {300, 400}, {500, 300} };

    // Vẽ ba điểm và spline cubic tương ứng
    draw(renderer, points, 3);

    // Hiển thị cửa sổ
    SDL_RenderPresent(renderer);

    // Chờ một lát trước khi đóng cửa sổ
    SDL_Delay(5000);

    // Đóng cửa sổ và giải phóng bộ nhớ
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
