#ifndef _DHMEM_H_
#define _DHMEM_H_

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/map.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/interprocess_condition.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>


namespace dhmem {

using segment_manager = boost::interprocess::managed_shared_memory::segment_manager;

template <typename T>
using allocator = boost::interprocess::allocator<T, segment_manager>;

template <typename T>
using vector = typename boost::interprocess::vector<T, allocator<T>>;

template <typename K, typename T>
using map = typename boost::interprocess::map<K, T, std::less<K>, allocator<std::pair<const K, T>>>;

using mutex = boost::interprocess::interprocess_mutex;

using cond = boost::interprocess::interprocess_condition;

using scoped_lock = boost::interprocess::scoped_lock<mutex>;

struct Dhmem {
    Dhmem(const std::string &name)
        : remover_(name)
        , segment_(boost::interprocess::open_or_create, name.c_str(), 65536)
        , allocator_(segment_.get_segment_manager())
    {}

//    template <typename T, typename... Args>
//    dhmem::vector<T> &vector(const std::string &name, Args... args) {
//        return *segment_.find_or_construct<dhmem::vector<T>>(name.c_str())(&args..., allocator_);
//    }

//    template <typename K, typename T>
//    dhmem::map<K, T> &map(const std::string &name) {
//        return *segment_.find_or_construct<dhmem::map<K, T>>(name.c_str())(std::less<K>(), allocator_);
//    }

    template <typename T, typename... Args>
    T &container(const std::string &name, Args... args) {
        return *segment_.find_or_construct<T>(name.c_str())(&args..., allocator_);
    }

    template <typename T, typename... Args>
    T &simple(const std::string &name, Args... args) {
        return *segment_.find_or_construct<T>(name.c_str())(&args...);
    }

    // ----

    template <typename T, typename... Args>
    dhmem::vector<T> &vector(const std::string &name, Args... args) {
        return container<dhmem::vector<T>>(name, &args...);
    }

    template <typename K, typename T, typename... Args>
    dhmem::map<K, T> &map(const std::string &name, Args... args) {
        return container<dhmem::map<K, T>>(name, &args...);
    }

private:
    struct shm_remove {
        shm_remove(const std::string &name) : name_(name) {}
        ~shm_remove() { boost::interprocess::shared_memory_object::remove(name_.c_str()); }
        const std::string name_;
    } remover_;

    boost::interprocess::managed_shared_memory segment_;

    dhmem::allocator<void> allocator_;
};

} // namespace dhmem {

#endif
