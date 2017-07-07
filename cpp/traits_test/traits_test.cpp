#include <iostream>

/*
Bjarne Stroustrup:
Think of a trait as a small object whose main purpose is to carry information used
by another object or algorithm to determine "policy" or "implementation details".
*/

/*
�������������һЩ��װ��ͨ���㷨�е�ĳЩ���ֻ���Ϊ�������Ͳ�ͬ�����´�����߼���ͬ
���������ֲ�ϣ����Ϊ�������͵Ĳ�����޸��㷨����ķ�װʱ����traits����һ�ֺܺõĽ��������
*/

/*

��Ҫ�ڵ�TΪfloatʱ��Compute�����Ĳ���Ϊfloat����������Ϊint��
����TΪ�������ͣ�Compute�����Ĳ���ΪT����������ҲΪT
*/

template <typename T>
struct TraitsHelper {
	typedef T ret_type;
	typedef T par_type;
};

template <>
struct TraitsHelper<float> {
	typedef int ret_type;
	typedef float par_type;
};

template <typename T>
struct Test {
	static typename TraitsHelper<T>::ret_type compute(typename TraitsHelper<T>::par_type d)
	{
		return d;
	}
};

int main() {
	
	using namespace std;
	
	cout << "Test<int>::compute(1):\t" << Test<int>::compute(1) << "\n";
	cout << "Test<float>::compute(1.1):\t" << Test<float>::compute(1.1) << "\n";
	cout << "Test<double>::compute(1.1):\t" << Test<double>::compute(1.1) << "\n";
	
	return 0;
}
