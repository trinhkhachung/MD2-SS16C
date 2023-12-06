#include <stdio.h>
int main() {
    FILE *file = fopen("D:Documents\\bt01.txt", "w");
    if (file == NULL) {
        printf("Không thể mở file.\n");
        return 1; 
    }
    char inputString[100];
    printf("Nhập chuỗi: ");
    fgets(inputString, sizeof(inputString), stdin);
    fprintf(file, "%s", inputString);
    fclose(file);
    printf("Chuỗi đã được ghi vào file bt01.txt.\n");
    return 0; 
}