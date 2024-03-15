#include "java\lang\string.hpp"
#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace java {
namespace lang {

jclass String::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("java/lang/String");
  return cached_class;
}

void String::destroy(const String* object)
{
  delete object;
}

}  // namespace lang
}  // namespace java

