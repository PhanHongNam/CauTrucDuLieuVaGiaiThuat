#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<iostream>

using namespace std;

struct ThiSinh
{
    char sBD[10];
    char ten[25];
    char gioiTinh[4];
    double tongDiem;
};

struct Node
{
    ThiSinh ts;
    Node *next;
};

void nhap(Node *&l, int n)
{
    l = new Node;
    Node *q;
    q = l;
    int i = 1, gt;

    cout << "\nThi sinh thu " << i << endl;
    cout << "So bao danh: ";
    fflush(stdin); gets(l->ts.sBD);
    cout << "Ho va ten: ";
    fflush(stdin); gets(l->ts.ten);
    do
    {
        cout << "Gioi tinh:";
        cout << "\n\t1 Nam" << "\n\t2 Nu";
        cout << "\n\t";
        cin >> gt;
    } while (gt < 1 || gt > 2);
    if (gt == 1)
        strcpy(l->ts.gioiTinh,"Nam");
    else
        strcpy(l->ts.gioiTinh,"Nu");
    cout << "Tong diem: ";
    cin >> l->ts.tongDiem;
    i++;
    while (i <= n)
    {
        q->next = new Node;
        q = q->next;
        cout << "\nThi sinh thu " << i << endl;
        cout << "So bao danh: ";
        fflush(stdin); gets(q->ts.sBD);
        cout << "Ho va ten: ";
        fflush(stdin); gets(q->ts.ten);
        do
        {
            cout << "Gioi tinh:";
            cout << "\n\t1 Nam" << "\n\t2 Nu";
            cout << "\n\t";
            cin >> gt;
        }while (gt < 1 || gt > 2);
        if (gt == 1)
            strcpy(q->ts.gioiTinh,"Nam");
        else
            strcpy(q->ts.gioiTinh,"Nu");
        cout << "Tong diem: ";
        cin >> q->ts.tongDiem;
        i++;
    }
    q->next = NULL;
}

void xuat(ThiSinh ts)
{
    cout << setw(10) << ts.sBD << setw(25) << ts.ten;
    cout << setw(10) << ts.gioiTinh << setw(11) << ts.tongDiem  << endl;
}

void xuatDS(Node *l)
{
    Node *q;
    q = l;
    cout << setw(10) << "So Bao Danh" << setw(25) << "Ho Va Ten";
    cout << setw(10) << "Gioi Tinh" << setw(11) << "Tong Diem" << endl;
    while (q != NULL)
    {
        xuat(q->ts);
        q = q->next;
    }
}

void hienThiSinhTongDiemTren20(Node *l)
{
    Node *q;
    q = l;
    cout << setw(10) << "So Bao Danh" << setw(25) << "Ho Va Ten";
    cout << setw(10) << "Gioi Tinh" << setw(11) << "Tong Diem" << endl;
    while (q != NULL)
    {

        if (q->ts.tongDiem > 20)
        {
            xuat(q->ts);
            q = q->next;
        }
        else
            q = q->next;
    }
}

void xoaThiSinhViTriThu3(Node *l)
{
    int i = 1;
    Node *q, *p;
    q = l;
    while (i != 2)
    {
        q = q->next;
        i++;
    }
    p = q->next;
    q->next = p->next;
    delete p;
    q = l;
    cout << setw(10) << "So Bao Danh" << setw(25) << "Ho Va Ten";
    cout << setw(10) << "Gioi Tinh" << setw(11) << "Tong Diem" << endl;
    while (q != NULL)
    {
        xuat(q->ts);
        q = q->next;
    }
}

int main()
{
    Node *l;
    int n;
    do
    {
        cout << "\nNhap so thi sinh(>=5): ";
        cin >> n;
    }while (n < 5);
    cout << "\nNhap thong tin cac thi sinh:" << endl;
    nhap(l,n);
    cout << "\nDanh sach vua nhap: " << endl;
    xuatDS(l);
    cout << "\nCac thi sinh co tong diem tren 20" << endl;
    hienThiSinhTongDiemTren20(l);
    cout << "\nDanh sach sau khi xoa thi sinh thu 3" << endl;
    xoaThiSinhViTriThu3(l);

    return 0;
}
