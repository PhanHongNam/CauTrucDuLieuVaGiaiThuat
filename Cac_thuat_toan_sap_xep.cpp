#include<stdio.h>
#include<iostream>

using namespace std;

void selectSort(int X[], int n)
{
    for(int i = 0; i < n - 1; i++)//Duyệt từ phần tử đầu của mảng đến phần từ gần cuối của mảng để so sánh với các p.tử sau nó
    {
        int m = i; /*Ta luôn giả sử p.tử có chỉ số i đang xét có giá trị nhỏ nhất(lớn nhất)
        ở đây ta tạo biến m để lưu chỉ số của p.tử có giá trị nhỏ nhất
        */
        for(int j = i + 1; j < n; j++) // Duyệt lần lượt các phần tử sau i để so sánh
        {
            if(X[j] < X[m]) /* Nếu p.tử có chỉ số j có giá trị nhỏ hơn p.tử  có giá trị nhỏ nhất(lớn nhất)(có chỉ số m)
                                (Sắp xếp giảm dần thì đổi X[j] < X[m] thành X[j] > X[m])*/

                m = j; // thì ta lưu chỉ số của phần tử nhỏ nhất(lớn nhất) đó lại vào m
        }

        //Sau khi làm hết vòng for j trên ta sẽ tìm được p.tử có chỉ số m(hay là p.tử X[m]) là p.tử có giá trị nhỏ nhất(lớn nhất)

        if(m != i) // Nếu chỉ số của p.tử nhỏ nhất(lớn nhất) có chỉ số # với chỉ số i đang xét thì thực hiển đổi giá trị của X[i] đang xét và X[m]
        {
            int temp = X[i];
            X[i] = X[m];
            X[m] = temp;
        }
    }
}

void insertSort(int X[], int n)
{
    /*
    * Trong thuật toán này, ta chia mảng thành 2 dãy là dãy đích và dãy nguồn
    * Dãy đích là dãy mà sau khi sắp xếp ta thu được là 1 dãy tăng dần(giảm dần), dãy đích ban đầu là phần tử đầu tiên của mảng
    * Dãy nguồn là dãy còn lại của mảng
    * Ta lấy lần lượt các p.tử trong dãy nguồn đem so sánh với các p.tử trong dãy đích để bỏ vào vị trí thích hợp
    * Ý tưởng thuật toán dựa trên việc chơi bài
    * Giả sử hiện tại dãy đích là con 2, dãy nguồn là con 5, 3, 4, 1, ở đây xếp tăng dần( Mảng ban đầu là 2 5 3 4 1)
    * Trước tiên ta rút con 5 từ dãy nguồn, đem so sánh thấy 5 lớn hơn 3 nên để nguyên, có dãy đích 3 5
    * Tiếp theo lấy 3 ở dãy nguồn so sánh với 5 thấy nhỏ hơn nên đẩy 5 lên, chưa vội bỏ 3 vào, tiếp tục so sánh với 2,
    * thấy không nhỏ hơn nên bỏ 3 vào sau 2, ta có dãy đích 2 3 5
    * Lấy 4 từ dãy nguồn so sánh với 5 thấy nhỏ hơn, đẩy 5 lên, chưa vội bỏ vào, so sánh với 3 thấy k nhỏ hơn
    * nên bỏ 4 vào sau 3, ta có dãy đích 2 3 4 5
    * Cuối cùng lấy 1 từ dãy nguồn đem so sánh với 5, thấy nhỏ hơn nên đẩy 5 lên, chưa vội bỏ vào lại so sánh với 4,
    * thấy vẫn nhỏ hơn nên đẩy 4 lên, cứ như vậy so sánh với 3, 2 và đẩy 3 với 2 lên
    * sau đó ta thấy k còn p.tử nào trong dãy nguồn để so sánh với 1 nên bỏ 1 vào đầu tiên, ta có dãy đích 1 2 3 4 5
    */
    for(int i = 1; i < n; i++) //Duyệt các p.tử thứ 2 đến hết mảng để so sánh rồi bỏ vào vị trí thích hợp trong dãy đích
    {
        int k = X[i]; // Lấy biến k để lưu giá trị của p.tử mình rút ra từ dãy nguồn để bỏ vào dãy đích
        int j = i - 1; // Dùng j để lưu chỉ số của p.tử đứng trước ngay p.tử mình vừa rút ra ở dãy nguồn
        while(j >= 0 && k < X[j])
        /*
        * Trong khi p.tử bạn đang so sánh(với cái rút ra ở dãy nguồn) thuộc dãy đích vẫn đang trong phạm vi của mảng
        * (nếu < 0 tức là ngoài mảng) và p.tử bạn rút ra ở dãy nguồn vẫn đang lớn hơn(nhỏ hơn) p.tử ở dãy đích thì làm các
        * việc sau(ở đây tăng dần nên k < X[j] còn giảm dần thì đổi thành k > X[j]
        */
        {
            X[j+1] = X[j]; // Gán p.tử đứng sau bằng p.tử đang xét ở dãy đích
            j--; // Sau đó giảm j để tiếp tục so sánh cái mình rút ở dãy đích với phần từ đứng trước p.tử đang xét
        }
        X[j+1] = k;
        /*
        * Vòng while dừng khi j = - 1 hoặc p.tử bạn rút ra ở dãy nguồn không nhỏ hơn(lớn hơn) với phần tử X[j]
        * đang xét ở dãy đích, nên ta thực hiên bỏ phần tử rút ra ban đầu ở dãy nguồn vào đầu(j = -1) hoặc
        * đứng trước p.tử không nhỏ hơn(lớn hơn) trong dãy đích nên ta gán p.tử đứng sau p.tử đang xét trong
        * dãy đích bằng phần tử rút ra ban đầu ở dãy nguồn
        */
    }
}

void bubleSort(int X[], int n)
{
    /*
    * Hai phần tử liên tiếp nhau nhỏ hơn(lớn hơn) thì đổi chỗ
    */
    for(int i = 0; i < n - 1; i++) // Duyệt mảng từ p.tử đầu đến p.tử gần cuối
    {
        for(int j = n - 1; j > i; j--) // Duyệt từ cuối đến cái kế tiếp i
        {
            if(X[j] < X[j-1])
            /*
            * Nếu 2 p.tử liên tiếp nhỏ hơn(lớn hơn thì đổi chỗ), ở đây tăng dần nên cái sau nhỏ hơn cái trước thì đổi chỗ
            * Đối với giảm dần thì đổi thành X[j] > X[j-1], tức là cái sau lớn hơn thì đổi chỗ
            */
            {
                int temp = X[j];
                X[j] = X[j-1];
                X[j-1] = temp;
            }
        }
    }
}

void xuat(int X[], int n)
{
    for(int i = 0; i < n; i++)
        cout << X[i] << " ";
}

int main()
{
    int X[] = {12, 42, 54, 4, 78, 100, 55, 88, 1, 99}, n = 10;
    cout << "\nMang truoc khi sap xep" << endl;
    xuat(X,n);
    cout << "\nMang sau khi sap xep" << endl;
    //selectSort(X,n);
    //insertSort(X,n);
    bubleSort(X,n);
    xuat(X,n);

    return 0;
}
