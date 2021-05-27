///**
//* Brief: Advanced implementation of std::find algorithm
//* Author: Alexey Perestoronin (Alexey.Perestoronin@yandex.ru)
//* Year: 2021
//*/
//
//#pragma once
//
//template<int64_t from, int64_t to, bool isOptionalResult, class Collection, class Action>
//decltype(auto) Common::AA::Find(Collection& collection, Action&& value)
//{
//  static_assert((from > 0 && to > 0 ? from <= to : true) && (from < 0 && to < 0 ? from <= to : true), "from-position must be less then to-position");
//
//  size_t size{ collection.size() };
//  if (!(from > 0 ? from < size : -from <= size))
//    AA_RAISE_ERROR("from-position cannot be greater than collection size");
//  if (!(to > 0 ? to < size : -to <= size))
//    AA_RAISE_ERROR("to-position cannot be greater than collection size");
//
//  IIS<from, Collection> iisFrom(collection);
//  IIS<to, Collection> iisTo(collection);
//  Collection::iterator resultIt(std::find(iisFrom.Get(), iisTo.Get(), value));
//  if constexpr (isOptionalResult)
//  {
//    std::optional<Collection::value_type> resultOp;
//    if (resultIt != iisTo.Get())
//      resultOp = *resultIt;
//    return resultOp;
//  }
//  else
//  {
//    return resultIt;
//  }
//}
