#ifndef _DHMEM_H_
#define _DHMEM_H_

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/map.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/interprocess_condition.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/interprocess/smart_ptr/shared_ptr.hpp>


namespace dhmem {

using segment_manager = boost::interprocess::managed_shared_memory::segment_manager;

using handle = boost::interprocess::managed_shared_memory::handle_t;

template <typename T>
using allocator = boost::interprocess::allocator<T, segment_manager>;

template <typename T>
using vector = typename boost::interprocess::vector<T, allocator<T>>;

template <typename K, typename T>
using map = typename boost::interprocess::map<K, T, std::less<K>, allocator<std::pair<const K, T>>>;

using mutex = boost::interprocess::interprocess_mutex;

using cond = boost::interprocess::interprocess_condition;

using scoped_lock = boost::interprocess::scoped_lock<mutex>;

template <typename T>
using shared_ptr = boost::interprocess::managed_shared_ptr<T, boost::interprocess::managed_shared_memory>;

struct force_create_only_t {};
static const force_create_only_t force_create_only = force_create_only_t();

using create_only_t = boost::interprocess::create_only_t;
auto &create_only = boost::interprocess::create_only;

using open_only_t = boost::interprocess::open_only_t;
auto &open_only = boost::interprocess::open_only;

using open_read_only_t = boost::interprocess::open_read_only_t;
auto &open_read_only = boost::interprocess::open_read_only;

using open_or_create_t = boost::interprocess::open_or_create_t;
auto &open_or_create = boost::interprocess::open_or_create;

using open_copy_on_write_t = boost::interprocess::open_copy_on_write_t;
auto &open_copy_on_write = boost::interprocess::open_copy_on_write;

struct Dhmem {
    template <typename... Args>
    Dhmem(force_create_only_t, const std::string &name, Args... args)
        : remover_(dhmem::force_create_only, name)
        , segment_(dhmem::create_only, name.c_str(), args...)
        , allocator_(segment_.get_segment_manager())
    {}

    template <typename OpenMethod, typename... Args>
    Dhmem(OpenMethod m, const std::string &name, Args... args)
        : remover_(m, name)
        , segment_(m, name.c_str(), args...)
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

    template <typename T>
    dhmem::handle save(const T &t) {
        return segment_.get_handle_from_address(&t);
    }

    template <typename T>
    T &load(const dhmem::handle handle) {
        return *((T *)segment_.get_address_from_handle(handle));
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

    template <typename T>
    dhmem::shared_ptr<T> &make_shared(T &&t) {
        return boost::interprocess::make_managed_shared_ptr(&t, segment_);
    }

private:
    struct shm_remove {
        shm_remove(force_create_only_t, const std::string &name)
            : name_(name)
        {
            boost::interprocess::shared_memory_object::remove(name_.c_str());
        }

        template <typename OpenMethod>
        shm_remove(OpenMethod m, const std::string &name)
            : name_(name)
        {}

        ~shm_remove() {
             boost::interprocess::shared_memory_object::remove(name_.c_str());
        }

    private:
        const std::string name_;
    } remover_;

    boost::interprocess::managed_shared_memory segment_;

    dhmem::allocator<void> allocator_;
};

} // namespace dhmem {

#endif
