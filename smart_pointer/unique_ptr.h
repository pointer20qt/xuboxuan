#pragma once

template<class T>
class X_uniquePtr{//唯一智能指针 不能使用拷贝构造和赋值
	T* obj = nullptr;
public:
	X_uniquePtr() = default;//默认构造函数 无参
	X_uniquePtr(T* ptr):obj(ptr){//构造方法，赋值一个指针
	}
	~X_uniquePtr(){//析构方法，释放指针	
		delete obj;
	}
	X_uniquePtr(const X_uniquePtr<T>&) = delete;//复制构造（转移内部指针控制权）不存在
	X_uniquePtr(X_uniquePtr<T>&& other) :obj(other.release()){//移动构造
		/*obj = other.obj;
		other.obj = nullptr;*/
	}
	X_uniquePtr& operator=(const X_uniquePtr<T>&) = delete;//复赋赋值（转移内部指针控制权）不存在
	X_uniquePtr& operator=(X_uniquePtr<T>&& other){//移动赋值
		obj = other.release();
		return *this;
	}
	void reset(T* newptr = nullptr){//reset 释放之前的，获得新的指针
		delete obj;
		obj = newptr;
	}
	T* release(){//release 释放控制权，返回指针
		auto temp = obj;
		obj = nullptr;
		return temp;
	}
	T& operator*(){//operator*() 模拟指针访问方法	
		return *obj;
	}
	T* operator->(){//operator->() 模拟指针箭头方式访问方法	
		return obj;
	}
	T* get(){//get() 获得指针指向的指针
		return obj;
	}
};