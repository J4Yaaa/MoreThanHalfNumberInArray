#include <stdio.h>

enum Status
{
    invalid,
    valid
};

enum Status sta = valid;

int CheckMoreThanHelf(int arr[],int len,int key)
{
    int count = 0;
    int i = 0;
    for(; i < len; ++i)
    {
        if(arr[i] == key)
            ++count;
    }
    if(count * 2 <= len)
    {
        sta = invalid;
        return 0;
    }
    return 1;
}


//方法1,利用partion函数来求超过一半的数
//      当数组中有一个数字超过数组总共数字的一半时,offset的位置在数组中间的时候,所对应的数字就是这个数字
//int Partion(int arr[],int len, int start,int end)
//{
//    (void)len;
//    int key = arr[end];
//    int left = start;
//    int right = end;
//    while(left < right)
//    {
//        while(left < right && arr[left] <= key)
//        {
//            ++left;
//        }
//        while(left < right && arr[right] >= key)
//        {
//            --right;
//        }
//        if(left < right)
//        {
//            int tmp = arr[left];
//            arr[left] = arr[right];
//            arr[right] = tmp;
//        }
//    }
//    return left;
//}
//
//int MoreThanHalfNum(int arr[],int len)
//{
//    if(arr == NULL || len <= 0)
//    {
//        sta = invalid;
//        return 0;
//    }
//    if(len == 1)
//    {
//        return arr[0];
//    }
//    int mid = len >> 1;
//    int start = 0;
//    int end = len - 1;
//    int offset = Partion(arr,len,start,end);
//    while(offset != mid)
//    {
//        if(offset > mid)
//        {
//            end = offset - 1;
//            offset = Partion(arr,len,start,end);
//        }
//        else
//        {
//            start = offset + 1;
//            offset = Partion(arr,len,start,end);
//        }
//    }
//    int result = arr[mid];
//    if(!CheckMoreThanHelf(arr,len,result))
//    {
//        return 0;
//    }
//    return result;
//}
////////////////////////////////////////////////////

//方法2,利用一个计数来统计
//      最后使count>0的值就是超过一半的数字(存在的话)
int MoreThanHalfNum(int arr[],int len)
{
    if(arr == NULL || len <= 0)
    {
        sta = invalid;
        return 0;
    }
    int count = 0;
    int key = arr[0];
    int i = 0;
    for(; i < len; ++i)
    {
        if(arr[i] == key)
        {
            ++count;
        }
        else
        {
            --count;
        }
        if(count < 0)
        {
            key = arr[i];
        }
    }
    if(!CheckMoreThanHelf(arr,len,key))
    {
        sta = invalid;
        return 0;
    }
    return key;
}

int main()
{
    /* int arr[] = {1,2,3,2,2,2,5,4,2}; */
    /* int arr[] = {1,2,3,4,5,6,7,8,9,0}; */
    /* int arr[] = {1,1,1,1,1,1,1,1,1}; */
    int* arr = NULL;
    int len = sizeof(arr)/sizeof(arr[0]);
    int ret = MoreThanHalfNum(arr,len);
    if(sta == valid)
    {
        printf("ret is valid, ret = %d\n",ret);
    }
    else
    {
        printf("no exists\n");
    }
    return 0;
}
