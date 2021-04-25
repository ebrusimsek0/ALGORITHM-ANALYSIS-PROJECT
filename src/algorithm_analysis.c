/* SIRALI, TERSDEN SIRALI VE RANDOM DÝZÝLER ÝLE INSERTION SORT VE MERGE SORT ÝÇÝN KARMAÞIKLIÐIN HESAPLANMASI VE KARÞILAÞTIRILMASI */
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>  //rand fonksiyonu için kütüphane
#include <math.h>  //log2 için kütüphane

double t,t1;
clock_t start,end,end2;


//insertion sort sýralama algoritmasý
void insertionSort(int A[], int n) 
{ 
	int i, key, j; 
	for (i = 1; i < n; i++) 
	{ 
		key = A[i]; 
		j = i - 1; 
		while (j >= 0 && A[j] > key) 
		{ 
			A[j + 1] = A[j]; 
			j = j - 1; 
		} 
		A[j + 1] = key; 
	} 
} 
//merge sort için geri birleþtirme algoritmasý
void merge(int A[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 
	int L[n1], R[n2]; 
	for (i = 0; i < n1; i++) 
		L[i] = A[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = A[m + 1+ j]; 
	i = 0; 
	j = 0;  
	k = l;  
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			A[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			A[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 
	while (i < n1) 
	{ 
		A[k] = L[i]; 
		i++; 
		k++; 
	} 
	while (j < n2) 
	{ 
		A[k] = R[j]; 
		j++; 
		k++; 
	} 
} 
//merge sort sýralama algoritmasý
void mergeSort(int A[], int l, int r) 
{ 
	if (l < r) 
	{ 
		int m = l+(r-l)/2; 
		mergeSort(A, l, m); 
		mergeSort(A, m+1, r); 
		merge(A, l, m, r); 
	} 
} 
//dizi elemanlarýný yazdýrma fonksiyonu
void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 

void bestcomplexity(int n){
	float	i_complexity=n;
   	float	m_complexity=n*log2(n);
   	printf("\nInsertion sort karmasikligi %f \n", i_complexity); 
	printf("\nMerge sort karmasikligi %f \n", m_complexity);
}
void worstcomplexity(int n){
	float	i_complexity=n*n;
   	float	m_complexity=n*log2(n);
   	printf("\nInsertion sort karmasikligi %f \n", i_complexity); 
	printf("\nMerge sort karmasikligi %f \n", m_complexity);
}
void averagecomplexity(int n){
	float	i_complexity=n*n;
   	float	m_complexity=n*log2(n);
   	printf("\nInsertion sort karmasikligi %f \n", i_complexity); 
	printf("\nMerge sort karmasikligi %f \n", m_complexity);
}
void bi_complexity(int n){
	float	i_complexity=n;
   	printf("\nInsertion sort karmasikligi %f \n", i_complexity); 
}
void i_complexity(int n){
	float	i_complexity=n*n;
   	printf("\nInsertion sort karmasikligi %f \n", i_complexity); 
}
void m_complexity(int n){
	float	m_complexity=n*log2(n);
   	printf("\nMerge sort karmasikligi %f \n", m_complexity);
}

//ayný diziye iki sýralama algoritmasýný uygulamak için fonksiyon
void Sort(int A[], int n){
	printf("\nOrjinal dizi \n");
	printArray(A, n);
	start = clock(); 
	insertionSort(A, n); 
	end = clock();
	mergeSort(A, 0, n- 1);
	end2 = clock(); 
	printf("\nSiralanmis dizi \n"); 
	printArray(A, n);
}
char menu(){
	char sec;
    printf("\nMENU\n");
    printf("\nA-DIZI SECME\n");
    printf("\nB-CIKIS\n");
    printf("\nBir secim yapiniz\n");
   	scanf("%c",&sec);
	return sec;
}
char menu2(){
	char sec;
	system("cls");
printf("\nSiralamak istediginiz diziyi secin\n");
	printf("\nA-SIRALI\n");
	printf("\nB-TERSTEN SIRALI\n");	
	printf("\nC-RANDOM 100 ELEMANLI\n");
	printf("\nD-RANDOM 500 ELEMANLI\n");
	printf("\nE-RANDOM 1000 ELEMANLI\n");					
	printf("\nF-GERI DON\n");
	 printf("\nBir secim yapiniz\n");
   	scanf("%c",&sec);
	return sec;
}
char menu3(){
	char sec;
	system("cls");
	printf("\nLUTFEN BIR SIRALAMA YONTEMI SECINIZ\n");
	printf("\nA-INSERTION SORT\n");
	printf("\nB-MERGE SORT\n");
	printf("\nC-KARMASIKLIK KARSILASTIR\n");
	printf("\nD-GERI DON\n");
	printf("\nBir secim yapiniz\n");
   	scanf("%c",&sec); 
	return sec;
}
 
int main() 
{ 
	int i,j;
	int A[1000], B[1000],C[100],D[500],E[1000],temp;
	

 clock_t start,end,end2,start2;

	char secim='a';
	char secim2='a';															
	char secim3='a';
	srand (time(NULL));  //random üretilen sayýnýn zamana baðlý deðiþmesi için
	//sýralý dizi oluþturma
	for (i=0; i < 1000; i++) {
        A[i]=i+1;
    }
    //tersden sýralý dizi oluþturma
    for(i=0; i<1000; i++)
	{
		B[i]=i+1;
	}
	j=i-1;  
	i=0;  
	while(i<j)
	{
		temp=B[i];
		B[i]=B[j];
		B[j]=temp;
		i++;
		j--;
	}
    //100 elemanlý random dizi
	for (i=0;i<100;i++)
	{
		C[i]=rand() %999+1;
	}
	 //500 elemanlý random dizi
	for (i=0;i<500;i++)
	{
		D[i]=rand() %999+1;
	}
	 //1000 elemanlý random dizi
	for (i=0;i<1000;i++)
	{
		E[i]=rand() %999+1;
	}
	

	secim=menu();
		do{
			switch(secim){ //MENU1
			case 'a':
			case 'A': secim2=menu2();
				do{
					switch(secim2){ //MENU2
						case 'a': 
						case 'A': secim3=menu3();  //SIRALI DÝZÝ SEÇÝLÝRSE
							do{
								switch(secim3){ //MENU3
								case 'a':
								case 'A':  //sýralý dizi için insertion sort
									system("cls");
									printf("\nOrjinal dizi \n");
									printArray(A, 1000);
									start=clock(); 
									insertionSort(A, 1000);
									printArray(A, 1000);  
									end = clock(); 
									t=(double)(end - start);
									printf("\nRunning Time=%f \n",t/CLOCKS_PER_SEC);
									bi_complexity(1000);
									return 0;
									break;
								case 'b':
								case 'B': //sýralý dizi için merge sort
									system("cls");
									printf("\nOrjinal dizi \n");
									printArray(A, 1000);
									start=clock(); 
									mergeSort(A, 0, 999);
									printArray(A, 1000);    
									end = clock(); 
									t=(double)(end - start);
									printf("\nRunning Time=%f \n",t/CLOCKS_PER_SEC);
									m_complexity(1000);
									return 0; 
									break;
								case 'c':
								case 'C': //sýralý dizi için hem insertion hem mergesort
									system("cls");
									Sort(A,1000); 
									t=(double)(end - start);
									t1=(double)(end2 - end);
									printf("\nRunning Time \nInsertion sort=%f\nMerge sort=%f\n",t/CLOCKS_PER_SEC,-t1/CLOCKS_PER_SEC);
									bestcomplexity(1000);
									return 0;
									break;
								case 'd':
								case 'D': system("cls"); break;		//geri sön											
								default : printf("\nA-D arasinda secim giriniz\n "); secim3=menu3(); break;
							}
							}while(secim3!='d' && secim3!='D'); secim2=menu2(); system("cls");break;
						case 'b':
						case 'B': secim3=menu3(); 
							do{
								switch(secim3){
								case 'a':
								case 'A': //ters sýralý dizi için insertionsort
									system("cls");
									printf("\nOrjinal dizi \n");
									printArray(B, 1000);
									start = clock();
									insertionSort(B, 1000);
									printArray(B, 1000);  
									end = clock();
									t=(double)(end - start);
									printf("\nRunning Time=%f \n",t/CLOCKS_PER_SEC);
									i_complexity(1000);
									return 0;
									break;
								case 'b':
								case 'B': //ters sýralý dizi için mergesort
									system("cls");
									printf("\nOrjinal dizi \n");
									printArray(B, 1000);
									start = clock(); 
									mergeSort(B, 0, 999); 
									printArray(B, 1000);  
									end = clock(); 
									t=(double)(end - start);
									printf("\nRunning Time=%f \n",t/CLOCKS_PER_SEC);
									m_complexity(1000); 
									return 0;
									break;
								case 'c':
								case 'C': //ters sýralý dizi için hem insertion hem merge
									system("cls");
									Sort(B, 1000); 
									t=(double)(end - start);
									t1=(double)(end2 - end);
									printf("\nRunning Time \nInsertion sort=%f\nMerge sort=%f\n",t/CLOCKS_PER_SEC,t1/CLOCKS_PER_SEC);
									worstcomplexity(1000); 
									return 0;
									break;
								case 'd':
								case 'D': system("cls"); break;				 //dizi seçme menüsüne geri dön									
								default : printf("\nA-D arasinda secim giriniz\n "); secim3=menu3(); break;
							}
							}while(secim3!='d' && secim3!='D'); secim2=menu2(); system("cls"); break;
						case 'c':
						case 'C': secim3=menu3(); 
							do{
								switch(secim3){
								case 'a':
								case 'A': //100 random sýralý dizi için insertion sort
									system("cls");
									printf("\nOrjinal dizi \n");
									printArray(C, 100);
									start = clock(); 
									insertionSort(C, 100);
									printArray(C, 100);  
									end = clock(); 
									t=(double)(end - start);
									printf("\nRunning Time=%f \n",t/CLOCKS_PER_SEC);
									i_complexity(100); 
									return 0;
									break;
								case 'b':
								case 'B': //100 random sýralý dizi için merge sort
									system("cls");
									printf("\nOrjinal dizi \n");
									printArray(C, 100);
									start = clock(); 
									mergeSort(C, 0, 99);
									printArray(C, 100);  
									end = clock();
									t=(double)(end - start);
									printf("\nRunning Time=%f \n",t/CLOCKS_PER_SEC);
									m_complexity(100); 
									return 0; 
									break;
								case 'c':
								case 'C': //100 random sýralý dizi için hem insertion sort hem mergesort
									system("cls");
									Sort(C, 100); 
									t=(double)(end - start);
									t1=(double)(end2 - end);
									printf("\nRunning Time \nInsertion sort=%f\nMerge sort=%f\n",t/CLOCKS_PER_SEC,t1/CLOCKS_PER_SEC);
									averagecomplexity(100); 
									return 0; 
									break;
								case 'd':
								case 'D': system("cls"); break;	 //dizi seçme menüsüne geri dön												
								default : printf("\nA-D arasinda secim giriniz\n "); secim3=menu3(); break;
							}
							}while(secim3!='d' && secim3!='D'); secim2=menu2(); system("cls"); break;
						case 'd':
						case 'D':secim3=menu3(); 
							do{
								switch(secim3){
								case 'a':
								case 'A': //500 random sýralý dizi için insertion sort 
									system("cls");
									printf("\nOrjinal dizi \n");
									printArray(D, 500);
									start = clock(); 
									insertionSort(D, 500);
									printArray(D, 500);  
									end = clock(); 
									t=(double)(end - start);
									printf("\nRunning Time=%f \n",t/CLOCKS_PER_SEC);
									i_complexity(500); 
									return 0;
									break;
								case 'b':
								case 'B':  //500 random sýralý dizi için  mergesort
									system("cls");
									printf("\nOrjinal dizi \n");
									printArray(D, 500);
									start = clock(); 
									mergeSort(D, 0, 499);
									printArray(D, 500);  
									end = clock(); 
									t=(double)(end - start);
									printf("\nRunning Time=%f \n",t/CLOCKS_PER_SEC);
									m_complexity(500);
									return 0; 
									break;
								case 'c':
								case 'C': //500 random sýralý dizi için hem insertion sort hem mergesort
									system("cls");
									Sort(D, 500); 
									t=(double)(end - start);
									t1=(double)(end2 - end);
									printf("\nRunning Time \nInsertion sort=%f\nMerge sort=%f\n",t/CLOCKS_PER_SEC,t1/CLOCKS_PER_SEC);
									averagecomplexity(500); 
									return 0;
									break;
								case 'd':
								case 'D': system("cls"); break;	 //dizi seçme menüsüne geri dön												
								default : printf("\nA-D arasinda secim giriniz \n"); secim3=menu3(); break;
							}
							}while(secim3!='d' && secim3!='D'); secim2=menu2(); system("cls"); break;
						case 'e':
						case 'E':secim3=menu3(); 
							do{
								switch(secim3){
								case 'a':
								case 'A': //1000 random sýralý dizi için  insertion sort 
									system("cls");
									printf("\nOrjinal dizi \n");
									printArray(E, 1000);
									start = clock(); 
									insertionSort(E, 1000); 
									printArray(E, 1000);  
									end = clock(); 
									t=(double)(end - start);
									printf("\nRunning Time=%f \n",t/CLOCKS_PER_SEC);
									i_complexity(1000);
									return 0; 
									break;
								case 'b':
								case 'B':  //1000 random sýralý dizi için  mergesort
									system("cls");
									printf("\nOrjinal dizi \n");
									printArray(E, 1000);
									start = clock(); 
									mergeSort(E, 0, 999);
									printArray(E, 1000);  
									end = clock(); 
									t=(double)(end - start);
									printf("\nRunning Time=%f \n",t/CLOCKS_PER_SEC);
									m_complexity(1000);
									return 0;
									break;
								case 'c':
								case 'C': //1000 random sýralý dizi için hem insertion sort hem mergesort
									system("cls");
									Sort(E, 1000);
									t=(double)(end - start);
									t1=(double)(end2 - end);
									printf("\nRunning Time \nInsertion sort=%f\nMerge sort=%f\n",t/CLOCKS_PER_SEC,t1/CLOCKS_PER_SEC);
									averagecomplexity(1000); 
									return 0;
									break;
								case 'd':
								case 'D': system("cls"); break;	 //dizi seçme menüsüne geri dön												
								default : printf("\nA-D arasinda secim giriniz\n "); secim3=menu3(); break;
							}
							}while(secim3!='d' && secim3!='D'); secim2=menu2(); system("cls"); break;
						case 'f':
						case 'F': system("cls"); break;		//ilk menüye geri dön										   
						default : printf("A-F arasinda secim giriniz "); secim2=menu2(); break;
					}
					}while(secim2!='f' && secim2!='F');  secim=menu(); system("cls"); break;
			case 'b':
			case 'B': printf("\nProgram Sonlaniyor...\n"); //çýkýþ
					  return 0; break;
			default : printf("\nA-B arasinda secim giriniz \n"); secim=menu(); break;
		}
		}while(secim!='b' && secim!='B');
} 
