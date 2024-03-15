#include "java\io\file.hpp"
#include <memory>
#include "gni/common/scoped_local_ref.h"
#include "gni/gni.hpp"
#include "gni/object.hpp"

namespace java {
namespace io {

jclass File::GetClass()
{
  static const jclass cached_class = gni::GniCore::GetInstance()->GetClassGlobalRef("java/io/File");
  return cached_class;
}

void File::destroy(const File* object)
{
  delete object;
}

}  // namespace io
}  // namespace java

