#include <iostream>
using namespace std;

#define MAXSIZE 50
typedef int KeyType;

typedef  struct                     
{ KeyType  key;                                             
} ElemType;  

typedef  struct
{ ElemType  *R; 
  int  length;
} SSTable;                      

void  Create(SSTable &T)
{ int i;
  T.R=new ElemType[MAXSIZE+1];
  cin>>T.length;
  for(i=1;i<=T.length;i++)
     cin>>T.R[i].key;   
}

int Search_Bin(SSTable T, KeyType k) {
    int low = 1; // 数组索引从1开始
    int high = T.length; // 数组的最后一个元素的索引
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2; // 防止溢出的写法
        if (T.R[mid].key == k) {
            return mid; // 找到目标值，返回索引
        } else if (T.R[mid].key < k) {
            low = mid + 1; // 在右半部分查找
        } else {
            high = mid - 1; // 在左半部分查找
        }
    }
    return 0; // 没有找到，返回0
}


int  Search_Bin(SSTable T, KeyType k);

int main () 
{  SSTable T;  KeyType k;
   Create(T);
   cin>>k;
   int pos=Search_Bin(T,k);
   if(pos==0) cout<<"NOT FOUND"<<endl;
   else cout<<pos<<endl;
   return 0;
}
