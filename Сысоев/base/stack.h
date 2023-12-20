#ifndef __STACK_H__
#define __STACK_H__

const int MaxStackSize = 100;

template <class T>
class TStack
{
  T *pMem;
  int memSize;
  int top;
public:
	TStack() : top(-1), memSize(MaxStackSize), pMem(new T[memSize]) {}

  TStack(int _size)
  {
    memSize = _size;
    top = -1;
    if ((memSize < 1) || (memSize > MaxStackSize))
		throw ("incorrect_size");
    pMem = new T[memSize];
  }

  ~TStack()
  {
    delete [] pMem;
  }

  TStack(const TStack& a) : top(a.top), memSize(a.memSize)
  {
	  pMem = new T[memSize];
	  for (int i = 0; i < memSize; i++)
		  pMem[i] = a.pMem[i];
  }

  int size() {
	  return memSize;
  }

  //проверка на пустоту
  bool IsEmpty() const {
	  return top == -1;
  }

  //проверка на заполненость
  bool IsFull() const {
	  return top == memSize - 1;
  }

  //достать последний элемент
  T Top() {
	  if (top == -1)
		  throw("incorrect");
	  else return pMem[top--];
  }

  //взять элемент 
  void Pop() {
	  if (top == -1)
		  throw("incorrect");
	  else top--;
  }

  //поместить элемент
  void Push(const T& v) {
	  /*if (top == memSize - 1) {
		  T* tmpMem = new T[memSize * 2];
		  std::copy(pMem, pMem + memSize, tmpMem);
		  delete[] pMem;
		  pMem = tmpMem;
		  memSize *= 2;
	  }*/
	  pMem[++top] = v;
	  //memSize += 1;
  }

  //оператор сравнения
  bool operator == (TStack<T> a) {

	  if (memSize != a.memSize)
		  return 0;
	  else
	  {
		  int f = 0;
		  for (int i = 0; i < a.size(); i++)
			  if (pMem[i] != a.pMem[i]) f = 1; 
		  if (f==0) return 1;
		  else return 0;
	  }
  }

  //оператор приваивания
  TStack operator = (TStack a) {
	  if (this != s) {
		  top = s.top;
		  memSize = s.memSize;
		  for (int i=0; i<s.size(); i++)
			  pMem[i] = s.pMem[i];
	  }
	  return (*this);
  }

  bool operator !=(TStack a) {
	  return !(this == a);
  }
};

#endif
