#include<stdio.h>
int main(){
    int thang;
    scanf("%d",&thang);
    if(thang ==1||thang==3||thang==5||thang==7||thang==8||thang==10||thang==12){
        printf("thang %d co 31 ngay\n",thang);
    }
    else if(thang==2){
            int nam;scanf("%d",&nam);
        if((nam%4==0 && nam % 100 !=0)||(nam % 400==0))
        {
            printf("nam %d la nam nhuan va thang %d co 29 ngay\n",nam,thang);
        }
        else 
        {
            printf("nam %d ko la nam nhuan va thang %d co 28 ngay\n",nam,thang);
        }
    
}
    else if(thang==4||thang==6||thang==9||thang==11){
         printf("thang %d co 30 ngay\n",thang);
    }
    else{
        printf("%d ko hop le, vui long nhap lai thang tu 1->12 \n",thang);scanf("%d",&thang );
        return thang;
    }
   return 0;
}