#pragma once

#define GET_LOCK std::lock_guard<std::mutex> _lock(d_access);
