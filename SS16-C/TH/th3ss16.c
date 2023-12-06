#include<stdio.h>
int main(){
	FILE*taptin = NULL;
	const int SO_KY_TU_TOI_DA = 1000;
	char arr[SO_KY_TU_TOI_DA]="";//chuoi co kich thuoc bang ki tu toi da
	taptin=fopen("test.txt","r");
	if(taptin!=NULL){
		fgets(arr,SO_KY_TU_TOI_DA,taptin);
		printf("%s,arr");
		fclose(taptin);
	}
	return 0;
}
