/***************************************************
*
*	CStackջ��ģ��Ķ����ļ�
*
***************************************************/


#ifndef _STACK_H_
#define _STACK_H_

#include <assert.h>

template <typename T, int MaxSize>
class CStack
{
public:
	explicit CStack(int maxSize);
	explicit CStack();
	~CStack();

	const T& Pop(int* result);		//��ջ
	int Push(const T& elem);		//��ջ
	int IsEmpty();					//�Ƿ�Ϊ��
	int IsFull();					//�Ƿ�Ϊ��
	int GetMaxSize();				//����ջ�ܴ�С
	int GetCurSize();				//����ջ��ǰԪ������
	int Clear();					//�������ջ

	typedef T value_type;			//��Ԫ����������������

protected:
	const int MAX_SIZE;				//��¼ջ�ܴ�С
	T* m_top;						//��¼ջ����ָ��
	T* m_stack;						//�洢����ջ
};


template <typename T, int MaxSize>
CStack<T, MaxSize>::CStack(int maxSize)
	: MAX_SIZE(maxSize)
{
	assert(maxSize == MaxSize && MaxSize > 0);
	
	//��һ��ջԪ��m_stack[0]�����洢Ԫ�ص�ջ��
	this->m_stack = new T[MAX_SIZE + 1]();
	this->m_top = this->m_stack;
}

template <typename T, int MaxSize>
CStack<T, MaxSize>::CStack()
	: MAX_SIZE(MaxSize)
{
	assert(MaxSize > 0);

	//��һ��ջԪ��m_stack[0]�����洢Ԫ�ص�ջ��
	this->m_stack = new T[MAX_SIZE + 1]();
	this->m_top = this->m_stack;

}

template <typename T, int MaxSize>
CStack<T, MaxSize>::~CStack()
{
	if (this->m_stack)
	{
		delete this->m_stack;
		this->m_stack = nullptr;
	}
}


/*
* ����: ��ջ
* ����: elem���ڽ��ճ�ջ��Ԫ��
* ����ֵ: �ɹ�Ϊtrue, ʧ��Ϊfalse
*/
template <typename T, int MaxSize>
const T& CStack<T, MaxSize>::Pop(int* result)
{
	static T elem;
	int res = true;
	do 
	{
		if (this->IsEmpty())
		{	
			//���ջ��
			res = false;
			break;
		}
		else
		{
			//ջ����
			elem = *this->m_top;
			this->m_top--;
		}
	} while (0);

	if (result) *result = res;
	return elem;
}


/*
* ����: ��ջ
* ����: elem���ڽ�����ջ��Ԫ��
* ����ֵ: �ɹ�Ϊtrue, ʧ��Ϊfalse
*/
template <typename T, int MaxSize>
int CStack<T, MaxSize>::Push(const T& elem)
{
	if (this->IsFull())
		return false;	//���ջ��
	else
	{
		//ջ����
		this->m_top++;
		*this->m_top = elem;
	}
	return true;
}


/*
* ����: ����Ƿ�ջΪ��
* ����: ��
* ����ֵ: ջΪ�շ���true, ջ����Ϊfalse
*/
template <typename T, int MaxSize>
int CStack<T, MaxSize>::IsEmpty()
{
	return (m_top == m_stack);
}


/*
* ����: ����Ƿ�ջΪ��
* ����: ��
* ����ֵ: ջΪ������true, ջ����Ϊfalse
*/
template <typename T, int MaxSize>
int CStack<T, MaxSize>::IsFull()
{
	return (this->GetCurSize() == this->MAX_SIZE);
}


/*
* ����: ����ջ��ǰԪ������
* ����: ��
* ����ֵ: ����ջ��ǰԪ������
*/
template <typename T, int MaxSize>
int CStack<T, MaxSize>::GetCurSize()
{
	int a = (this->m_top - this->m_stack);
	return (this->m_top - this->m_stack);
}


/*
* ����: ����ջ�ܴ�С
* ����: ��
* ����ֵ: ����ջ�ܴ�С
*/
template <typename T, int MaxSize>
int CStack<T, MaxSize>::GetMaxSize()
{
	return this->MAX_SIZE;
}


/*
* ����: ���ջ������Ԫ��
* ����: ��
* ����ֵ: �ɹ�����true, ����false
*/
template <typename T, int MaxSize>
int CStack<T, MaxSize>::Clear()
{
	this->m_top = this->m_stack;
	
	return true;
}










#endif /*_STACK_H_*/