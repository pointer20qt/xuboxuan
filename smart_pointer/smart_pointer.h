#pragma once
//模板化，可以接受任意类型
template<class T>
class X_autoPtr{
	T* obj = nullptr;//空指针为C++11中的关键字 可以释放
public:
	X_autoPtr() = default;//默认构造函数 无参
	X_autoPtr(T* ptr):obj(ptr){//构造方法，赋值一个指针
	}
	~X_autoPtr(){//析构方法，释放指针
		delete obj;
	}
	X_autoPtr(X_autoPtr<T> &ptr):obj(ptr.release()){//不标准的复制构造（转移内部指针控制权）
		/*obj = ptr.obj;
		ptr.obj = nullptr;*/
	}
	X_autoPtr& operator=(X_autoPtr<T> &ptr){//不标准的复赋赋值（转移内部指针控制权）
		/*delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;*/
		obj = ptr.release();
		return *this;
	}
	void reset(T* newPtr){//reset 释放之前的，获得新的指针
		delete obj;
		obj = newPtr;
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

