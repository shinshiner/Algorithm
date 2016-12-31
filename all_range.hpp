void swap(int &a, int &b) {int tmp = a; a = b; b = tmp;}

void all_range(int k, int n, int a[]){
    if(k==n-1){         //到达最后一个数位，输出当前排列
        for(int i=1;i<n;++i) cout << a[i] << ' ';
        cout << '\n';
    }
    else
        for(int i=k;i<n;++i){
            swap(a[k],a[i]);     //依次交换k位与k后的每一位上的数字
            all_range(k+1,n,a);
            swap(a[k],a[i]);
        }
}

void all_range(int n){      //包裹函数
    int *a = new int[n+1];

    for(int i=1;i<=n;++i) a[i] = i;
    all_range(1,n+1,a);
    delete []a;
}
