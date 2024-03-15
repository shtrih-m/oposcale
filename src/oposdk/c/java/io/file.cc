#include "java\io\file.h"

#include "java\io\file.hpp"

File* File_wrapJniReference(jobject jobj) {
  return reinterpret_cast<File*>(new ::java::io::File(jobj));
}

jobject File_getJniReference(const File* file) {
  return reinterpret_cast<const ::java::io::File*>(file)->GetImpl();
}

void File_destroy(const File* file) {
  ::java::io::File::destroy(reinterpret_cast<const ::java::io::File*>(file));
}
