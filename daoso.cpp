#include<iostream>
#include<random>
using namespace std;
void nhap(int M[],int size){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis(0,99);
    for(int i=0;i<size;i++){
        M[i]=dis(gen);
    }
}

void xuat(int M[],int size){
        for(int i=0; i<size ; i++){
            cout<<M[i]<<" ";
        }
    }

    void daomang(int& a,int& b){
        int temp=a;
        a=b;
        b=temp;
    }
    void sapxep(int M[], int size){
        for(int i=0; i< size ; i++){
            int min_index=i;
        for(int j=i+1; j<size; j++){
            if(M[j]<M[min_index]){
                min_index=j;
            }
        
        }
        if(i != min_index){
                daomang(M[i],M[min_index]);
            }
    }

}
int main(){ 
    int size;
    cin>>size;
    int M[size];
    nhap(M,size);
    cout<<"mang ngau nhien la:"<<endl;
    xuat(M,size);
    sapxep(M,size);
    cout<<endl;
    cout<<"mang sau khi sx la:";
    xuat(M,size);
}