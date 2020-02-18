#pragma once

template<class T>
class Ref{
	int r_count = 0;
	T* object = nullptr;
	int w_count = 0;//��ǰ������ָ�����
public:
	Ref(T* target) :object(target){
		++r_count;
	}
	inline void increase(){
		r_count++;
	}
	inline void increase_w(){
		w_count++;
	}
	inline void reduce(){
		r_count--;
		if (r_count == 0){
			delete object;
			object = nullptr;
			if (w_count == 0){
				delete this;
			}
		}
	}
	inline void reduce_w(){
		w_count--;
		if (w_count == 0 && r_count == 0){
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
template<class T> class X_weakPtr;//����һ�� �����Ҳ���
template<class T>
class X_sharedPtr{
	friend class X_weakPtr<T>;
	Ref<T>* ref = nullptr;
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
	X_sharedPtr(Ref<T>* newR){//Ϊ�˸��õ�ʵ��������� Ӧ����weak_ptr��
		ref = newR;
		if (ref){
			ref->increase();
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
	void reset(T* target = nullptr){//reset(T*)�滻���� reset() ���ٶ���
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
//����ָ��һ�����ü�����������Ҫʱ���shared_ptr
template<class T>
class X_weakPtr{
	Ref<T>* ref = nullptr;
public:
	X_weakPtr() = default;//�޲ι���
	X_weakPtr(X_sharedPtr<T>& other):ref(other.ref){//����һ��shared_ptr����
		cout << "ʹ��shared_ptr����һ��weak�Ŀ�����ֵ�����" << endl;
		if (ref){
			ref->increase_w();
		}
	}
	X_weakPtr(const X_weakPtr<T>& other){//��������
		if (ref){
			ref->increase_w();
		}
	}
	X_weakPtr(X_weakPtr<T>&& other){//�ƶ�����
		swap(ref, other.ref);
	}
	X_weakPtr& operator=(const X_weakPtr<T>& other){//������ֵ
		cout << "������weak�Ŀ�����ֵ" << endl;
		if (ref){
			ref->reduce_w();
		}
		ref = other.ref;
		if (ref){
			ref->increase_w();
		}
		return *this;
	}
	X_weakPtr& operator=(X_weakPtr<T>&& other){//�ƶ���ֵ
		cout << "������weak���ƶ���ֵ" << endl;
		if (ref){
			ref->reduce_w();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	int use_count(){//use_count()���ָ����������ü�����shared_ptr�ļ�����
		if (ref){
			return ref->getCount();
		}
		else{
			return 0;
		}
	}
	bool expired(){//expired()�ж��Ƿ��Ѿ�ɾ��
		if (ref){
			return ref->getCount() > 0;
		}
		else{
			return false;
		}
	}
	X_sharedPtr<T> lock(){//lock() ���һ��shared_ptr
		X_sharedPtr<T> tem(ref);
		/*tem.ref = ref;
		tem.ref->increase();*/
		return tem;
	}
	void swap(X_weakPtr<T>& other){//swap()
		std::swap(ref, other.ref);
	}
	void reset(){//reset()���ٵ�ǰ����
		ref->reduce_w();
		ref = nullptr;
	}
};


