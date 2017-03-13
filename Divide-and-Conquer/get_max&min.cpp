#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int *a, n, count=0, Max = -1, Min = 1000000;

//分治法寻找最大最小元素
void find(int *a, int l, int r, int mid, int &max, int &min){
    if(l==r){       //只有一个元素
        max = min = a[l];
        return;
    }

    if(r==l+1){     //只有两个元素
        if(a[r]>a[l]) {min = a[l]; max = a[r];}
        else {min = a[r]; max = a[l];}
        count++;
        return;
    }

    int max1 = -1, max2 = -1, min1 = 1000000, min2 = 1000000;

    find(a,l,mid,(l+mid)/2,max1,min1);      //在左半部分分治
    find(a,mid+1,r,(mid+1+r)/2,max2,min2);  //在右半部分分治

    if(max1>max2) {max = max1; count++;}    //选出左右部分的最大值
    else {max = max2; count++;}

    if(min1>min2) {min = min2; count++;}    //选出左右部分的最小值
    else {min = min1; count++;}
}

//线性扫描寻找最大最小元素
void search(int *a, int &max, int &min){
    for(int i=0;i<n;++i){
        if(a[i]>max) {max = a[i]; count++;} //优化搜索次数
        else if(a[i]<min) {min = a[i]; count += 2;}
        else count += 2;
    }
}

int main()
{
    srand(time(NULL));

    cout << "输入数组规模: ";
    cin >> n;
    a = new int[n];

    for(int i=0;i<n;++i){       //生成随机数组
        a[i] = rand() % 1000000;
    }

    find(a,0,n-1,(n-1)/2,Max,Min);
    cout << "分治法结果：\n Max = " << Max << "\n Min = " << Min << "\n 比较次数 = " << count;

    count = 0;
    Max = -1;
    Min = 1000000;
    search(a,Max,Min);
    cout << "\n搜索法结果：\n Max = " << Max << "\n Min = " << Min << "\n 比较次数 = " << count;

    delete []a;

    return 0;
}
