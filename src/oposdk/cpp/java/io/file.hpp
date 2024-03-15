#ifndef CPP_JAVA_IO_FILE
#define CPP_JAVA_IO_FILE

#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace java {
namespace io {

class File : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const File* object);
    explicit File(jobject object) : ::gni::Object(object) {}
    ~File() override = default;
};

}  // namespace io
}  // namespace java

#endif  // CPP_JAVA_IO_FILE

