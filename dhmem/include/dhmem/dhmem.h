#ifndef _DHMEM_H_
#define _DHMEM_H_

#include <cstdio>
#include <cstdlib>
#include <string>
#include <new>
#include <limits>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdexcept>
#include <memory>

namespace dhmem {

struct DhmemImpl {
    std::string name_;
    int fd_;
    bool closed_;

    DhmemImpl (const std::string &name)
        : name_(name),
          fd_(open(name)),
          closed_(false) {}

    ~DhmemImpl () noexcept {
        if (!closed_) {
            std::fprintf(stderr, "Error: DhmemImpl not closed before destructor\n");
            close();
        }
    }

    DhmemImpl(const DhmemImpl&) = delete;

    DhmemImpl& operator=(const DhmemImpl&) = delete;

    DhmemImpl(DhmemImpl &&other) = default;

    DhmemImpl& operator=(DhmemImpl &&other) = default;

    template <class T>
    [[nodiscard]] T* allocate(std::size_t n) {
        if (n > std::numeric_limits<std::size_t>::max() / sizeof(T))
            throw std::bad_alloc();

        //std::printf("requesting %lu bytes\n", n * sizeof(T));
        if (auto p = static_cast<T*>(std::malloc(n*sizeof(T))))
            return p;

        throw std::bad_alloc();
    }

    template <class T>
    void deallocate(T* p, std::size_t) noexcept { 
        std::free(p);
    }

    void close() {
        std::fprintf(stderr, "DhmemImpl->close()\n");
        if (closed_)
            throw std::runtime_error("DhmemImpl already closed");

        ::close(fd_);
        shm_unlink(name_.c_str());
        closed_ = true;
    }
        
private:
    int open(const std::string &name) {
        std::printf("called with name=%s\n", name.c_str());
        int fd = shm_open(name.c_str(), O_RDWR | O_CREAT, 0600);
        if (fd < 0)
            throw std::runtime_error("Could not open dhmem file");
        return fd;
    }
};

struct DhmemImplDeleter {
    void operator()(DhmemImpl *d) const {
        d->close();
        delete d;
    }
};

template <class T>
struct DhmemAllocator
{
    typedef T value_type;

    std::shared_ptr<DhmemImpl> impl_;

    DhmemAllocator (const std::string &name)
        : impl_(new DhmemImpl(name), DhmemImplDeleter())
    {
        std::fprintf(stderr, "DhmemAllocator(\"%s\")\n", name.c_str());
    }

    template <class U>
    DhmemAllocator (const DhmemAllocator<U>& other) : impl_(other.impl_)
    {
        std::fprintf(stderr, "DhmemAllocator(other)\n");
    }

    [[nodiscard]] T* allocate(std::size_t n) {
        std::fprintf(stderr, "DhmemAllocator->allocate(%lu * %lu)", n, sizeof(T));
        T* p = impl_->allocate<T>(n);
        std::fprintf(stderr, " = %p\n", (void*)p);
        return p;
    }

    void deallocate(T* p, std::size_t n) noexcept { 
        std::fprintf(stderr, "DhmemAllocator->deallocate(%p, %lu * %lu)\n", p, n, sizeof(T));
        impl_->deallocate<T>(p, n);
    }

    template <class U>
    DhmemAllocator<U> as() {
        return DhmemAllocator<U>(*this);
    }

    template <class... Args>
    std::shared_ptr<T> make_shared(Args&&... args) {
        DhmemSharedPtrDeleter deleter {this};
        T *t = allocate(1);
        new (t) T(args...);
        return std::shared_ptr<T>(t, deleter);
    }

private:
    struct DhmemSharedPtrDeleter {
        DhmemAllocator<T>* allocator_;

        void operator()(T *t) const {
            allocator_->deallocate(t, 1);
        }
    };
};

template <class T, class U>
bool operator==(const DhmemAllocator <T>&, const DhmemAllocator <U>&) { return true; }

template <class T, class U>
bool operator!=(const DhmemAllocator <T>&, const DhmemAllocator <U>&) { return false; }

}

#endif
