#pragma once

template<class T>
class Ref{
	int r_count = 0;
	T* object = nullptr;
	int w_count = 0;//当前弱引用指针计数
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
	//获得对对象
	T* get(){
		return object;
	}
	int getCount(){
		return r_count;
	}
};
template<class T> class X_weakPtr;//声明一下 避免找不到
template<class T>
class X_sharedPtr{
	friend class X_weakPtr<T>;
	Ref<T>* ref = nullptr;
public:
	X_sharedPtr() = default; //无参构造
	X_sharedPtr(T* newPtr){//传递指针构造
		ref = new Ref<T>(newPtr);
	}
	~X_sharedPtr(){//析构函数
		if (ref){
			ref->reduce();
		}
	}
	X_sharedPtr(Ref<T>* newR){//为了更好的实现面向对象 应用于weak_ptr中
		ref = newR;
		if (ref){
			ref->increase();
		}
	}
	X_sharedPtr(const X_sharedPtr<T>& other){//拷贝构造
		ref = other.ref;
		if (ref){
			ref->increase();
		}
	}
	X_sharedPtr(X_sharedPtr<T>&& other){//移动构造
		swap(ref, other.ref);
	}
	X_sharedPtr& operator=(const X_sharedPtr& other){//拷贝赋值
		if (ref){
			ref->reduce();
		}
		ref = other.ref;
		if (ref){
			ref->increase();
		}
		return *this;
	}
	X_sharedPtr& operator=(X_sharedPtr&& other){//移动赋值
		if (ref){
			ref->reduce();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	void swap(X_sharedPtr& other){//交换函数
		swap(ref, other.ref);
	}
	void reset(T* target = nullptr){//reset(T*)替换对象 reset() 销毁对象
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
	T* get(){//get()获得裸指针
		return ref->get();
	}
	int use_count(){//use_count() 获得引用计数
		if (ref){
			return ref->getCount();
		}
		else{
			return 0;
		}

	}
	bool unqiue(){//unique() 判断当前是否唯一  use_count() == 1
		if (ref){
			return ref->getCount() == 1;
		}
		else{
			return false;
		}
	}
	operator bool(){//operator bool() 是否关联对象 判断当前只能指针是否和对象关联
		return ref != nullptr;
	}
};
//可以指定一个引用计数对象，在需要时获得shared_ptr
template<class T>
class X_weakPtr{
	Ref<T>* ref = nullptr;
public:
	X_weakPtr() = default;//无参构造
	X_weakPtr(X_sharedPtr<T>& other):ref(other.ref){//传递一个shared_ptr构造
		cout << "使用shared_ptr构造一个weak的拷贝赋值运算符" << endl;
		if (ref){
			ref->increase_w();
		}
	}
	X_weakPtr(const X_weakPtr<T>& other){//拷贝构造
		if (ref){
			ref->increase_w();
		}
	}
	X_weakPtr(X_weakPtr<T>&& other){//移动构造
		swap(ref, other.ref);
	}
	X_weakPtr& operator=(const X_weakPtr<T>& other){//拷贝赋值
		cout << "调用了weak的拷贝赋值" << endl;
		if (ref){
			ref->reduce_w();
		}
		ref = other.ref;
		if (ref){
			ref->increase_w();
		}
		return *this;
	}
	X_weakPtr& operator=(X_weakPtr<T>&& other){//移动赋值
		cout << "调用了weak的移动赋值" << endl;
		if (ref){
			ref->reduce_w();
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	int use_count(){//use_count()获得指定对象的引用计数（shared_ptr的计数）
		if (ref){
			return ref->getCount();
		}
		else{
			return 0;
		}
	}
	bool expired(){//expired()判断是否已经删除
		if (ref){
			return ref->getCount() > 0;
		}
		else{
			return false;
		}
	}
	X_sharedPtr<T> lock(){//lock() 获得一个shared_ptr
		X_sharedPtr<T> tem(ref);
		/*tem.ref = ref;
		tem.ref->increase();*/
		return tem;
	}
	void swap(X_weakPtr<T>& other){//swap()
		std::swap(ref, other.ref);
	}
	void reset(){//reset()销毁当前对象
		ref->reduce_w();
		ref = nullptr;
	}
};


