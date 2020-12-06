#ifndef _DHMEM_SUPPORT_HENSON_H_
#define _DHMEM_SUPPORT_HENSON_H_

#include "../dhmem.h"

namespace dhmem {
namespace support {
namespace henson {

template <typename T>
void henson_save_handle(const char *name, T &t, ::dhmem::Dhmem &dhmem) {
    ::dhmem::handle h = dhmem.save(t);
    size_t x = static_cast<size_t>(h);
    henson_save_size_t(name, x);
}

template <typename T>
T &henson_load_handle(const char *name, ::dhmem::Dhmem &dhmem) {
    size_t x;
    henson_load_size_t(name, &x);
    dhmem::handle h = static_cast<::dhmem::handle>(x);
    return dhmem.load<T>(h);
}

} /* namespace henson */
} /* namespace support */
} /* namespace dhmem */

namespace henson {

using dhmem::support::henson::henson_save_handle;
using dhmem::support::henson::henson_load_handle;

} /* namespace henson */

using henson::henson_save_handle;
using henson::henson_load_handle;

#endif /* _DHMEM_SUPPORT_HENSON_H_ */
