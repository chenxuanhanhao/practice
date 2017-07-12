#pragma  once
// Copyright (C) 2017 http://ustcdane.github.io/
// Author: Daniel Wang <daneustc@gmail.com>

namespace op
{
	// ֵ����Ĭ��Ϊdouble, ����ͨ������OP_FLOATING_POINT_TYPE���ľ���
#ifdef OP_FLOATING_POINT_TYPE
	typedef OP_FLOATING_POINT_TYPE Real;
#else
	typedef double Real;
#endif

	// expression ������ֵ��������
	typedef Real OP_VALUE_RETURN_TYPE;

	// �������expression template,�����������̳�����
	// op��valueType�ȵĻ��࣬CRTP���̳��߼�Expression��ģ�����
	template<class A>
	struct Expression {

		// ����ģ�����(A)����expression ת��������������(const reference of A)
		const A& cast() const { return static_cast<const A&>(*this); }

		OP_VALUE_RETURN_TYPE value() const {
			return cast().value();
		}

	private:// ��ֹ�̳��߲���Expression��ģ�����
		Expression() {}
		friend A;
		Expression& operator=(const Expression&) {
			return *this;
		}
	};
}// End of namespace op
