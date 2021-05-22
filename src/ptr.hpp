#pragma once

#include <memory>


#define PtrStr(StructType) \
public: \
  using Ptr = typename StructType*; \
  using UniPtr = typename std::unique_ptr<typename StructType>; \
  using ShaPtr = typename std::shared_ptr<typename StructType>; \
  using WekPtr = typename std::weak_ptr<typename StructType>;


#define PtrCls(ClassType) \
PtrStr(ClassType) \
private:
