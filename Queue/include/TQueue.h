 //  Copyright by Robert Oganyan

#ifndef QUEUE_TQUEUE_H
#define QUEUE_TQUEUE_H

 const int MaxQueueSize = 100;

 template <class T>
 class TQueue {
 private:
     T *pmem;
     int memsize; //размер выделенной памяти
     int datacount; //к-во заполненных в очереди элементов
     int last; //индекс последнего элемента очереди
     int first; //индекс первого элемента

 public:
     TQueue() = delete;
    explicit  TQueue(int _size = 20);
     ~TQueue();
     TQueue(const TQueue<T>& t);

     void Push(const T val);
     bool IsFull();
     T Get_notion_by_index(int ind);
     bool IsEmpty();
     int GetNextIndex(int index);
     T GetFirst();
     T Get();
     void Sort(Tasks a[]);
 };

 template <class T>
 TQueue<T>::TQueue(int _size) {
         memsize = _size;
         datacount = 0;
         lastt = -1;
         first = 0;
         if ((memsize < 1) || (memsize > MaxQueueSize)) {
             throw MemSize;
         }
         pMem = new T[MemSize];
 }

 template <class T>
 TQueue<T>::~TQueue() {
     if (pmem != nullptr) {
     delete[] pmem;
     }
 }

 template <class T>
 TQueue<T>::TQueue(const TQueue<T>& t) {
     memsize = t.memsize;
     datacount = t.datacount;
     lastt = t.last;
     first = t.first;
     pmem = nullptr;
     if (t.pmem != nullptr) {
         pmem = new T[memsize];
     }
 }

 template <class T>

 bool TQueue<T>::IsEmpty() {
    return !datacount;
 }

 template <class T>
 bool TQueue<T>::IsFull()
 {
     return datacount == memsize;
 }

 template <class T>
 void TQueue<T>::Push(const T val) {

     if (IsFull()) {
        throw val;
     }
     if (last == memsize - 1) {
         last = 0;
     }
     else {
         last++;
     }
     pMem[last] = val;
     datacount++;
 }

 template <class T>

 int TQueue<T>::GetNextIndex(int index) {
     return (index+1) % MemSize;
 }
 template <class T>
 T TQueue<T>::Get()
 {
     if (IsEmpty()) {
         throw "negative";
     }
    --datacount;
     T tmp = pmem[first];
     first = GetNextIndex(first);
     return tmp;

 }
/*
 template<class T>

 void TQueue<T>::Sort(Tasks a[])

 {

     T temp;

     for (int i = 0; i < datacount; i++)

     {

         for (int j = 0; j < datacount - i - 1; j++)

         {

             if ((a[Get_notion_by_index(j)].Getpriority() != 0) && (a[Get_notion_by_index(j + 1)].Getpriority() != 0) && (a[Get_notion_by_index(j)].Getpriority() > a[Get_notion_by_index(j + 1)].Getpriority()))

             {

                 temp = pMem[j];

                 pMem[j] = pMem[j + 1];

                 pMem[j + 1] = temp;

             }

         }

     }

 }
 */

 template<class T>

 T TQueue<T>::GetFirst() {

     if (IsEmpty()) throw "negative";

     return pmem[first];

 }

 template<class T>

 inline T TQueue<T>::Get_notion_by_index(int ind)

 {

     if (IsEmpty() == 1) throw "negative";

     return pMem[ind];

 }

#endif //QUEUE_TQUEUE_H
