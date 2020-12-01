#ifndef _DHMEM_SUPPORT_DECAF_H_
#define _DHMEM_SUPPORT_DECAF_H_

#include "../dhmem.h"
#include <bredala/data_model/simpleconstructdata.hpp>
#include <bredala/data_model/simplefield.hpp>

#include <boost/serialization/export.hpp>

// dhmem::handle maps to a long, but a long isn't registered with Boost
// serialization. Register it to get rid of "error: unregistered class"
BOOST_CLASS_EXPORT_GUID(decaf::SimpleConstructData<long>, "SimpleConstructData<long>")

namespace dhmem {
namespace support {
namespace decaf {

template <typename T>
class SharedField : public ::decaf::SimpleField<dhmem::handle> {
public:
	// simple delegation
	SharedField()
		: SimpleField()
	{}

	// simple delegation
	SharedField(std::shared_ptr<::decaf::BaseConstructData> &field)
		: SimpleField(field)
	{}

	// first save the handle from the Dhmem pointer
	SharedField(T &t, ::dhmem::Dhmem &dhmem)
		: SimpleField(dhmem.save(t))
	{}

	// load the Dhmem handle afterwards
	T &getData(::dhmem::Dhmem &dhmem) {
		return dhmem.load<T>(SimpleField::getData());
	}
};

} /* namespace decaf */
} /* namespace support */
} /* namespace dhmem */

namespace decaf {

template <typename T>
using SharedField = ::dhmem::support::decaf::SharedField<T>;

using SharedFieldi = SharedField<int>;
using SharedFieldu = SharedField<unsigned int>;
using SharedFieldf = SharedField<float>;
using SharedFieldd = SharedField<double>;

} /* namespace decaf */

#endif /* _DHMEM_SUPPORT_DECAF_H_ */
