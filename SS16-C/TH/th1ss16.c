#include<stdio.h>
//int main(){
//	FILE*taptin = NULL;
//	taptin = fopen("test.txt","w");
//	if(taptin!=NULL){
//		fputc('A',taptin);//ghi them vao tap tin ki tu a
//		fclose(taptin);
//	}
//	return 0;
//}
//int main(){
//	FILE*taptin = NULL;
//	taptin = fopen("test.txt","w");
//	if(taptin!=NULL){
//		fputs("xin chao cac ban",taptin);//ghi vao tap chuoi bat ki
//		fclose(taptin);
//	}
//	return 0;
//}
int main(){
	FILE*taptin = NULL;
	int tuoi = 0;
	taptin = fopen("test.txt","w");
	if(taptin!=NULL){
		//hoi tuoi
		printf("ban bao nhieu tuoi");
		scanf("%d",&tuoi);
		//ghi du lieu vao tap tin
		fprintf(taptin,"nguoi dung dang %d tuoi",tuoi);
		fclose(taptin);
	}
	return 0;
}
