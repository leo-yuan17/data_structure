#include <iostream>
#include "Seqlist.hpp"
template <class T>
class Seqlist
{
protected:
    int *data;
    int length;
    int maxSize;

public:
    Seqlist(int size)
    {
        data = new T[size];
        length = 0;
        maxSize = size;
    }               // 构造函数,默认初始长度从0开始
    virtual ~Seqlist(){
        delete[] data;
    }         // 析构函数，释放动态数组空间
    Seqlist(T a[], int n, int size)
    {
        data = new T[size];
        length = n;
        maxSize = size;
        for (int i = 0; i < n; i++)
            data[i] = a[i];
    }// 根据数组a的内容构造顺序表
    int GetLength() const;
    bool IsEmpty() const;
    bool Clear();
    void Traverse(void (*visit)(const T &)) const; // 使用函数指针目的是为了让用户自定义visit函数
    int LocateElem(const T &x) const;              // 查找元素的位置
    bool GetElem(int i, T &x) const;               // 取第i个位置的元素
    bool SetElem(int i, const T &x);               // 设置第i个位置的元素
    bool Insert(int i, const T &x);                // 插入元素
    bool Remove(int i, T &x);                      // 删除元素
    Seqlist(const Seqlist<T> &L);
    Seqlist<T> &operator=(const Seqlist<T> &L);
};