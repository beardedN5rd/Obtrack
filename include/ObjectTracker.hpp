//============================================================================
// Object tracker using the "curiously recurring template pattern"
//
//	2014 by Hagen Pache
//	https://github.com/beardedN5rd
//============================================================================
#pragma once
#include <atomic>
#include <cstdint>


template <typename T>
class ObjectTracker
{
private:
    static std::atomic_uint32_t _created;
    static std::atomic_uint32_t _destroyed;
public:
	ObjectTracker()
	{
		++_created;
	}
	ObjectTracker(const ObjectTracker&)
	{
		++_created;
	}

	static std::uint32_t getAlive()
	{
		return 	_created.load(std::memory_order_relaxed) -
			_destroyed.load(std::memory_order_relaxed);
	}
	static std::uint32_t getCreated()
	{
		return _created.load(std::memory_order_relaxed);
	}
 	static std::uint32_t getDestroyed()
	{
		return _destroyed.load(std::memory_order_relaxed);
	}
protected:
    ~ObjectTracker()
    {
        ++_destroyed;
    }
};

template <typename T> std::atomic_uint32_t ObjectTracker<T>::_created(0);
template <typename T> std::atomic_uint32_t ObjectTracker<T>::_destroyed(0);
