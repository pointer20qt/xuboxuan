#pragma once

template<class T>
class X_uniquePtr{//Ψһ����ָ�� ����ʹ�ÿ�������͸�ֵ
	T* obj = nullptr;
public:
	X_uniquePtr() = default;//Ĭ�Ϲ��캯�� �޲�
	X_uniquePtr(T* ptr):obj(ptr){//���췽������ֵһ��ָ��
	}
	~X_uniquePtr(){//�����������ͷ�ָ��	
		delete obj;
	}
	X_uniquePtr(const X_uniquePtr<T>&) = delete;//���ƹ��죨ת���ڲ�ָ�����Ȩ��������
	X_uniquePtr(X_uniquePtr<T>&& other) :obj(other.release()){//�ƶ�����
		/*obj = other.obj;
		other.obj = nullptr;*/
	}
	X_uniquePtr& operator=(const X_uniquePtr<T>&) = delete;//������ֵ��ת���ڲ�ָ�����Ȩ��������
	X_uniquePtr& operator=(X_uniquePtr<T>&& other){//�ƶ���ֵ
		obj = other.release();
		return *this;
	}
	void reset(T* newptr = nullptr){//reset �ͷ�֮ǰ�ģ�����µ�ָ��
		delete obj;
		obj = newptr;
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