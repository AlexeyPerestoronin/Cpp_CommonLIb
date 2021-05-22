#include "base_error.hpp"

namespace Common
{
  namespace Errors
  {
    BaseError::BaseError()
      : _format(DefaultErrorFormat)
    {
    }

    BaseError::~BaseError()
    {
      if (_suberror)
        _suberror.release();
    }

    BaseError::BaseError(Str format)
      : _format(std::move(format))
    {
    }

    const char* BaseError::what() const
    {
      static Str lastError;
      lastError = WhatHappened();
      return lastError.data();
    }

    BaseError& BaseError::AddSuberror(BaseError&& suberror)
    {
      _suberror = std::make_unique<BaseError>(std::move(suberror));
      return *this;
    }

    BaseError& BaseError::SetDelimiter(Str delimiter)
    {
      _delimiter = std::move(delimiter);
      return *this;
    }

    BaseError& BaseError::SetFormat(Str format)
    {
      _format = std::move(format);
      return *this;
    }

    BaseError& BaseError::SetModule(Str module)
    {
      _module = std::move(module);
      return *this;
    }

    BaseError& BaseError::SetFile(Str file)
    {
      _file = std::move(file);
      return *this;
    }

    BaseError& BaseError::SetFunc(Str func)
    {
      _func = std::move(func);
      return *this;
    }

    BaseError& BaseError::SetLine(Str line)
    {
      _line = std::move(line);
      return *this;
    }

    BaseError& BaseError::SetWhat(Str what)
    {
      _what = std::move(what);
      return *this;
    }

    Str BaseError::WhatHappened() const
    {
      Str result = _format.value_or(DefaultErrorFormat);
      Str defaultValue = "unknown";
      
      result
        .Replace("{module}", _module.value_or(defaultValue))
        .Replace("{file}", _file.value_or(defaultValue))
        .Replace("{func}", _func.value_or(defaultValue))
        .Replace("{line}", _line.value_or(defaultValue))
        .Replace("{what}", _what.value_or(defaultValue));
      
      if (_suberror)
        result
        .append(_delimiter.value_or(DefaultErrorsDelimiter))
        .append(_suberror->WhatHappened());
      
      return result;
    };

  } // namespace Errors

} // namespace Common