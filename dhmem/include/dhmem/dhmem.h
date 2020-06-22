#ifndef _DHMEM_H_
#define _DHMEM_H_

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/map.hpp>


namespace dhmem {

template <typename T>
using vector = typename boost::interprocess::vector<T, boost::interprocess::allocator<T, boost::interprocess::managed_shared_memory::segment_manager>>;

template <typename K, typename T>
using map = typename boost::interprocess::map<K, T, std::less<K>, boost::interprocess::allocator<std::pair<const K, T>, boost::interprocess::managed_shared_memory::segment_manager>>;

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

    boost::interprocess::allocator<void, boost::interprocess::managed_shared_memory::segment_manager> allocator_;
};

} // namespace dhmem {

#endif
