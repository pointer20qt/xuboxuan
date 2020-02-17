#pragma once

//��Դ������
template<class T>
class Ref{
	int r_count = 0;
	T* object = nullptr;
public:
	Ref(T* target) :object(target){
		++r_count;
	}
	inline void increase(){
		r_count++;
	}
	inline void reduce(){
		r_count--;
		if (r_count == 0){
			delete object;
			delete this;
		}
	}
	//��öԶ���
	T* get(){
		return object;
	}
	int getCount(){
		return r_count;
	}
};
template<class T>
class X_sharedPtr{
	Ref<T> *ref = nullptr;
public:
	X_sharedPtr() = default; //�޲ι���
	X_sharedPtr(T* newPtr){//����ָ�빹��
		ref = new Ref<T>(newPtr);
	}
	~X_sharedPtr(){//��������
		if (ref){
			ref->reduce();
		}
	}
	X_sharedPtr(const X_sharedPtr<T>& other){//��������
		ref = other.ref;
		if (ref){
			ref->increase();
		}
	}
	X_sharedPtr(X_sharedPtr<T>&& other){//�ƶ�����
		swap(ref, other.ref);
	}
	X_sharedPtr& operator=(const X_sharedPtr& other){//������ֵ
		if (ref){
			ref->reduce();
		}
		ref = other.ref;
		if (ref){
			ref->increase();
		}
		return *this;
	}
	X_sharedPtr& operator=(X_sharedPtr&& other){//�ƶ���ֵ
		if (ref){
			ref->reduce();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	void swap(X_sharedPtr& other){//��������
		swap(ref, other.ref);
	}
	void reset(T* target=nullptr){//reset(T*)�滻���� reset() ���ٶ���
		if (ref){
			ref->reduce();
		}
		if (target != nullptr){
			ref = new Ref<T>(target);
		}
		else{
			ref = nullptr;
		}
	}
	T& operator*(){//operator*() 
		if (ref){
			return *ref->get();
		}
		else{
			return *(T*)nullptr;
		}
	}
	T* operator->(){//operator->()
		if (ref){
			return ref->get();
		}
		else{
			return (T*)nullptr;
		}
	}
	T* get(){//get()�����ָ��
		return ref->get();
	}
	int use_count(){//use_count() ������ü���
		if (ref){
			return ref->getCount();
		}
		else{
			return 0;
		}
		
	}
	bool unqiue(){//unique() �жϵ�ǰ�Ƿ�Ψһ  use_count() == 1
		if (ref){
			return ref->getCount() == 1;
		}
		else{
			return false;
		}
	}
	operator bool(){//operator bool() �Ƿ�������� �жϵ�ǰֻ��ָ���Ƿ�Ͷ������
		return ref != nullptr;
	}
};


