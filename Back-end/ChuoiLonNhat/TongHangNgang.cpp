#include<stdio.h>
#include<conio.h>
#define MAX 100


void nhap(int a[][MAX],int m,int n)
{ 
     for(int i=0;i<m;i++)
     for(int j=0;j<n;j++)
     {
        printf(" nhap a[%d][%d]:",i,j);
        scanf("%d",&a[i][j]);
     } 
}      
      
void inMatran(int a[][MAX],int m, int n)
{     
    printf(" ma tran vua nhap la:");
    for(int i=0;i<m;i++)
    {
        printf("\n");
        for(int j=0;j<n;j++)
        printf("%3d",a[i][j]);
    }
}

int TongHangNgang(int a[][MAX],int i,int m) //tinh tong cua hang i
{
    int S=0;
    for(int j=1;j<=m;j++)
    {
        S = S + a[i][j];
    }
    return S;
}

int HangLonNhat(int a[][MAX],int m,int n) //tim hang co tong lon nhat
{
    int max=TongHangNgang(a,0,m);//khoi tao max bang tong cua hang 1
    int h=0;
    for(int i=0;i<m;i++)
    {
        if(max < TongHangNgang(a,i,m))
           {
                max = TongHangNgang(a,i,m);
                h = i;
           }
    }
    return h; 
}
void xuatHanglonnhat(int a[][MAX],int m,int n){

    for(int i=0;i<n;i++)
    {
       printf("%3d", a[HangLonNhat(a,m,n)][i]);
    }
}

int  main()
 {
    int m,n;
    int a[100][100];
    printf("nhap so hang  m :");
    scanf("%d",&m);
    printf("nhap so cot n:");
    scanf("%d",&n);
    nhap(a,m,n);
    inMatran(a,m,n);
    printf("\nTong chuoi lon nhat theo hang ngang la:",HangLonNhat(a,m,n));
    xuatHanglonnhat(a,m,n);
    getch();
    return 0;
} 