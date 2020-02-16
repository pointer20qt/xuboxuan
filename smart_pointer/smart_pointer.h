#pragma once
//ģ�廯�����Խ�����������
template<class T>
class X_autoPtr{
	T* obj = nullptr;//��ָ��ΪC++11�еĹؼ��� �����ͷ�
public:
	X_autoPtr() = default;//Ĭ�Ϲ��캯�� �޲�
	X_autoPtr(T* ptr):obj(ptr){//���췽������ֵһ��ָ��
	}
	~X_autoPtr(){//�����������ͷ�ָ��
		delete obj;
	}
	X_autoPtr(X_autoPtr<T> &ptr):obj(ptr.release()){//����׼�ĸ��ƹ��죨ת���ڲ�ָ�����Ȩ��
		/*obj = ptr.obj;
		ptr.obj = nullptr;*/
	}
	X_autoPtr& operator=(X_autoPtr<T> &ptr){//����׼�ĸ�����ֵ��ת���ڲ�ָ�����Ȩ��
		/*delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;*/
		obj = ptr.release();
		return *this;
	}
	void reset(T* newPtr){//reset �ͷ�֮ǰ�ģ�����µ�ָ��
		delete obj;
		obj = newPtr;
	}
	T* release(){//release �ͷſ���Ȩ������ָ��
		auto temp = obj;
		obj = nullptr;
		return temp;
	}
	T& operator*(){//operator*() ģ��ָ����ʷ���
		return *obj;
	}
	T* operator->(){//operator->() ģ��ָ���ͷ��ʽ���ʷ���
		return obj;
	}
	T* get(){//get() ���ָ��ָ���ָ��
		return obj;
	}
};

