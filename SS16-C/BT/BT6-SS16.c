#include <stdio.h>
struct Student{
    char name[100];
    int age;
    char phone[15];
    char email[100];
};

int main() {
    int numStudents;
    printf("Nhập số lượng sinh viên: ");
    scanf("%d", &numStudents);
    struct Student students[numStudents];
    for (int i = 0; i < numStudents; i++) {
        printf("\nNhập thông tin cho sinh viên thứ %d:\n", i + 1);
        printf("Họ và tên: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Tuổi: ");
        scanf("%d", &students[i].age);
        printf("Số điện thoại: ");
        scanf("%s", students[i].phone);
        printf("Email: ");
        scanf("%s", students[i].email);
    }
    FILE *file = fopen("D:\\Documents\\students.txt", "w");
    if (file == NULL) {
        printf("Không thể mở file để ghi.\n");
        return 1;
    }
    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%s %d %s %s\n", students[i].name, students[i].age, students[i].phone, students[i].email);
    }
    fclose(file);
    file = fopen("D:\\Documents\\students.txt", "r");
    if (file == NULL) {
        printf("Không thể mở file để đọc.\n");
        return 1;
    }
    printf("Danh sách sinh viên là:\n");
    for (int i = 0; i < numStudents; i++) {
        fscanf(file, "%s %d %s %s", students[i].name, &students[i].age, students[i].phone, students[i].email);
        printf("%s %d %s %s\n", students[i].name, students[i].age, students[i].phone, students[i].email);
    }
    fclose(file);
    printf("Thông tin sinh viên đã được lưu vào file students.txt và được đọc lại từ file.\n");
    return 0;
}