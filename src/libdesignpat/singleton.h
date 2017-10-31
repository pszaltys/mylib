#ifndef __SINGLETON_H__
#define __SINGLETON_H__

template<class T>
class Singleton
{
public:
	static T* GetInstance()
	{
		if (!minstance)
		{
			minstance = new T;
		}
		return minstance;
	}

private:
	Singleton();
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	~Singleton();

	static T* minstance;
};

template<class T>
T* Singleton<T>::minstance = NULL;

#endif //__SINGLETON_H__