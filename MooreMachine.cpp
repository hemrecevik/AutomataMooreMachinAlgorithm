#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

main(){
	FILE *fp1,*fp2,*fp3;
	char eleman[79],sembol,alfabe[20],alfabe2[10],cikti_sembol[20],cikti_sembol2[10];
	int elemansayisi=0,i=0,alfabe_sayisi=0,cikti_sayisi=0;
	if ((fp1 = fopen ("INPUT.txt", "r")) == NULL) {
      printf("Dosya açma hatasý!");
      exit(1);
  }
	fgets(eleman, 79, fp1);
	sembol=eleman[3];
	while(eleman[i]!='}'){
		if(eleman[i]==sembol){
			elemansayisi++;
		}
		i++;
	}
	i=0;
	
	fgets(alfabe, 20, fp1);
	while(1){
	if(alfabe[i]=='{'){
		i++;
		while(alfabe[i]!='}'){
			if(alfabe[i]!=',')
			{
				alfabe2[alfabe_sayisi]=alfabe[i];
				alfabe_sayisi++;
			}
			i++;
		}
		break;
	}
	i++;
}

	i=0;
	fgets(cikti_sembol, 20, fp1);
	while(1){
	if(cikti_sembol[i]=='{'){
		i++;
		while(cikti_sembol[i]!='}'){
			if(cikti_sembol[i]!=',')
			{
				cikti_sembol2[cikti_sayisi]=cikti_sembol[i];
				cikti_sayisi++;
			}
			i++;
		}
		break;
	}
	i++;
	}
	cikti_sayisi++;
	if ((fp2 = fopen ("GECISTABLOSU.txt", "r")) == NULL) {
      printf("Dosya açma hatasý!");
      exit(1);
  }
	int satir=0,sutun=0;
	char gecis_tablosu[elemansayisi][alfabe_sayisi+1][2];
	while(!feof(fp2)){	
	fscanf(fp2,"%s",gecis_tablosu[sutun][satir]);
	satir++;
	if(satir==alfabe_sayisi+1)
	{	
		satir=0;
		sutun++;
	}
	if(satir==alfabe_sayisi+1 && sutun==elemansayisi)break;
}
if ((fp3 = fopen ("OUTPUT.txt", "r")) == NULL) {
      printf("Dosya açma hatasý!");
      exit(1);
  }
  int cikis_tablosu[elemansayisi],sayac=0;
  while(!feof(fp3)){
  	fscanf(fp3,"%d",&cikis_tablosu[sayac]);
  	sayac++;
  }
  char ifade[15];
  int sayac2=0,deger=0,k1=0,sayac3=0,k2=0,q=0;
	printf("String ifadeyi giriniz : ");
	scanf("%s",ifade);
	printf("Input String");
	printf("	");
	while(ifade[q]!='\0'){
		printf("%c	",ifade[q]);
		q++;
	}
	printf("\n");
	printf("State       ");
	printf("%c%c	",gecis_tablosu[k1][k2][0],gecis_tablosu[k1][k2][1]);
	while(ifade[sayac2]!='\0'){
		while(ifade[sayac2]!=alfabe2[sayac3]){
			sayac3++;
		}
		k2=sayac3+1;
		printf("%c%c	",gecis_tablosu[k1][k2][0],gecis_tablosu[k1][k2][1]);
		
		k1=gecis_tablosu[k1][k2][1]-'0';
		sayac3=0;
		sayac2++;
	}
	sayac2=0,k1=0,k2=0;
	printf("\nOutput      ");
	printf("%d	",cikis_tablosu[0]);
	while(ifade[sayac2]!='\0'){
		while(ifade[sayac2]!=alfabe2[sayac3]){
			sayac3++;
		}
		k2=sayac3+1;
		printf("%d	",cikis_tablosu[gecis_tablosu[k1][k2][1]-'0']);
		
		k1=gecis_tablosu[k1][k2][1]-'0';
		sayac3=0;
		sayac2++;
	}
	
	
}
