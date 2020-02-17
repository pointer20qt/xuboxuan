#pragma once

//资源计数类
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
	//获得对对象
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
	X_sharedPtr() = default; //无参构造
	X_sharedPtr(T* newPtr){//传递指针构造
		ref = new Ref<T>(newPtr);
	}
	~X_sharedPtr(){//析构函数
		if (ref){
			ref->reduce();
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
	void reset(T* target=nullptr){//reset(T*)替换对象 reset() 销毁对象
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


