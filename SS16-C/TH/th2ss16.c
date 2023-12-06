#include<stdio.h>
int main(){
	FILE*taptin=NULL;
	int kytuhientai=0;
	taptin=fopen("test.txt","r");
	if(taptin!=NULL){
		do{
			kytuhientai=fgetc(taptin);//doc ky tu
			printf("%c",kytuhientai);//in ky tu do ra man hinh
		} while(kytuhientai!=EOF);
		fclose(taptin);
	}
	return 0;
}
