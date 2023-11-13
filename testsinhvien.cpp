#include<iostream>
#include<cstring>
using namespace std;
struct diachi{
    char tenduong[100];
    string tinhthanh;
    int sonha;
};
struct sinhvien{
char hoten[100];
int masv;
float gpa;
string gioiitinh;
diachi diachinha;
};
struct book{
    string tensach;
    char tacgia[100];
    sinhvien tieude;
};
void nhapmang(sinhvien arr[],int size){
    for(int i=0; i<size; i++){
    cout<<"sinh vien thu "<< i+1 <<endl;
    cout<<"moi nhap ho ten: "; cin.getline(arr[i].hoten , sizeof(arr[i].hoten));
    cout<<"moi nhap vao masv: "; cin>>arr[i].masv ; cin.ignore();
    cout<<"moi nhap vao gpa: "; cin>>arr[i].gpa ; cin.ignore();
    cout<<"moi nhap vao gioi tinh: ";getline(cin , arr[i].gioiitinh) ; cin.ignore();
    cout<<"moi nhap vao dia chi duong: "; cin.getline(arr[i].diachinha.tenduong , sizeof(arr[i].diachinha.tenduong));cin.ignore();
    cout<<"moi nhap vao tinh thanh: "; getline(cin ,arr[i].diachinha.tinhthanh);cin.ignore();
    cout<<"moi nhap vao so nha: "; cin>>arr[i].diachinha.sonha;cin.ignore();
    }
    
}

int main(){
    int size;
    cin>>size;cin.ignore();
    sinhvien *arr=new sinhvien[size];
    nhapmang( arr,size);
    delete[] arr;
}