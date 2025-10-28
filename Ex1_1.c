#include <stdio.h>
#include <locale.h>
#include <math.h>

// Площадь
float area_parallelogram(float h, float a) {
    return a * h;  // площадь = основание * высота
}

// Определение
void definition_parallelogram() {
    printf("Параллелограмм - это четырёхугольник, у которого противоположные стороны попарно параллельны и равны\n");

}

// Рисование
void draw_parallelogram(int width, int height, char symbol) {
    printf("\n");
    for (int i = 0; i < height; i++) {
        // Сдвиг
        for (int space = 0; space < i; space++) {
            printf(" ");
        }
        for (int j = 0; j < width; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
}

// Название
void name_figure(int sides) {
    printf("\nНазвание фигуры: ");
    switch (sides) {
    case 3: printf("Треугольник\n"); break;
    case 4: printf("Параллелограмм\n"); break;
    case 0: printf("Круг\n"); break;
    default: printf("Многоугольник с %d сторонами\n", sides);
    }
}

// Главное меню
void print_menu() {
    printf("Выберите операцию: \n");
    printf("1 - Рассчитать площадь\n");
    printf("2 - Вывести определение фигуры\n");
    printf("3 - Нарисовать фигуру\n");
    printf("4 - Вывести название фигуры\n");
    printf("0 - Выход\n");
}

int main() {
    setlocale(LC_ALL, "");

    float height, base, angle;
    int choice;
    char draw_symbol = '*';
    int sides = 4;  // стороны паралллелограмма

    printf("Введите основание параллелограмма (a): ");
    scanf("%f", &base);
    printf("Введите высоту параллелограмма (h): ");
    scanf("%f", &height);
    printf("Введите угол при основании (α в градусах): ");
    scanf("%f", &angle);



    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            float area = area_parallelogram(height, base);
            printf("\nПлощадь параллелограмма:\n");
            printf("Основание: %.2f\n", base);
            printf("Высота: %.2f\n", height);
            printf("Угол: %.2f°\n", angle);
            printf("Площадь = основание × высота = %.2f\n", area);
            break;
        }

        case 2:
            definition_parallelogram();
            break;

        case 3:
            printf("\nРисунок параллелограмма:\n");
            draw_parallelogram((int)base, (int)height, draw_symbol);
            break;

        case 4:
            name_figure(sides);
            break;

        case 0:
            printf("Выход из программы.\n");
            break;

        default:
            printf("Неверный выбор! Попробуйте снова.\n");
        }

    } while (choice != 0);

    return 0;
}