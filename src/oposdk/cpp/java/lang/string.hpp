#ifndef CPP_JAVA_LANG_STRING
#define CPP_JAVA_LANG_STRING

#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace java {
namespace lang {

class String : virtual public ::gni::Object
{
public:
    static jclass GetClass();
    static void destroy(const String* object);
    explicit String(jobject object) : ::gni::Object(object) {}
    ~String() override = default;
};

}  // namespace lang
}  // namespace java

#endif  // CPP_JAVA_LANG_STRING

