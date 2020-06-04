#include <cstdio>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/offset_ptr.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>

using namespace boost::interprocess;

struct shared_memory_data {
    shared_memory_data()
        : n(0)
    {}

    interprocess_mutex mutex;
    std::size_t n;
};

int main(int argc, char **argv) {
    struct shm_remove
    {
        ~shm_remove() {  shared_memory_object::remove("foobar"); }
    } remover;

    shared_memory_object shm(open_or_create, "foobar", read_write);
    shm.truncate(1024);
    mapped_region region(shm, read_write);

    shared_memory_data* data = new (region.get_address()) shared_memory_data;

    for (int i=0; i<10; ++i) {
        std::getchar();

        scoped_lock<interprocess_mutex> lock(data->mutex);
        std::fprintf(stderr, "n = %lu\n", data->n);
        data->n++;
    }
}
