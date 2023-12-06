#include<stdio.h>
struct Book {
    int maSach;
    char tenSach[100];
    char tacGia[100];
    float giaTien;
    char Theloai[50];
};

void inputSach(struct Book books[], int *soLuongSach) {
    int num;
    printf("Nhập số lượng sách: ");
    scanf("%d", &num);
    if ((*soLuongSach) + num > 100) {
        printf("Số lượng sách vượt quá giới hạn.\n");
        return;
    }
    for (int i = *soLuongSach; i < *soLuongSach + num; i++) {
        printf("\nNhập thông tin cho sách thứ %d:\n", i + 1);
        books[i].maSach = i + 1;
        printf("Mã sách: %d\n", books[i].maSach);
        printf("Tên sách: ");
        scanf(" %[^\n]s", books[i].tenSach);
        printf("Tác giả: ");
        scanf(" %[^\n]s", books[i].tacGia);
        printf("Giá tiền: ");
        scanf("%f", &books[i].giaTien);
        printf("Thể loại: ");
        scanf(" %[^\n]s", books[i].Theloai);
    }
    *soLuongSach += num;
}

void luuThongTinSach(struct Book books[], int soLuongSach) {
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("Không thể mở file để ghi.\n");
        return;
    }
    for (int i = 0; i < soLuongSach; i++) {
        fprintf(file, "%d;%s;%s;%.2f;%s\n", books[i].maSach, books[i].tenSach, books[i].tacGia, books[i].giaTien, books[i].Theloai);
    }
    fclose(file);
    printf("Thông tin sách đã được lưu vào file books.txt.\n");
}

void hienThiThongTinSachTuFile() {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Không thể mở file để đọc.\n");
        return;
    }
    printf("\nThông tin sách từ file:\n");
    printf("%-8s%-20s%-20s%-15s%-15s\n", "Ma Sach|", "Ten sach|", "Tac gia|", "gia tien|", "the loai|");
    struct Book book;
    while (fscanf(file, "%d;%[^;];%[^;];%f;%[^\n]\n", &book.maSach, book.tenSach, book.tacGia, &book.giaTien, book.Theloai) != EOF) {
        printf("%-8d%-21s%-20s%-15.3f%-s\n", book.maSach, book.tenSach, book.tacGia, book.giaTien, book.Theloai);
    }
    fclose(file);
}

int main() {
    struct Book books[100];
    int choice, soLuongSach = 0;
    do {
        printf("\nMENU\n");
        printf("1. Nhập số lượng và thông tin sách\n");
        printf("2. Lưu thông tin sách vào file\n");
        printf("3. Hiển thị thông tin sách từ file\n");
        printf("4. Thoát\n");
        printf("Chọn chức năng: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputSach(books, &soLuongSach);
                break;
            case 2:
                luuThongTinSach(books, soLuongSach);
                break;
            case 3:
                hienThiThongTinSachTuFile();
                break;
            case 4:
                printf("Thoát khỏi chương trình.\n");
                break;
            default:
                printf("Chức năng không hợp lệ. Vui lòng chọn lại.\n");
        }
    } while (choice != 4);
    return 0;
}