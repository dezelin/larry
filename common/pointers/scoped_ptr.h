/* Copyright (c) 2015, Aleksandar Dezelin
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <common/misc/noncopyable.h>
#include <common/misc/swap.h>

#include <assert.h>

#ifndef __SCOPED_PTR_H__
#define __SCOPED_PTR_H__

namespace knt {

template<typename T>
class scoped_ptr : public noncopyable<scoped_ptr<T>> {
    T *_t;

public:
    explicit scoped_ptr(T *t = nullptr) noexcept : _t(t) {}
    ~scoped_ptr() noexcept { delete _t; }

    void reset(T *t = nullptr) noexcept {
        delete _t;
        _t = t;
    }

    T& operator *() const noexcept { assert(_t); return *_t; }
    T* operator->() const noexcept { assert(_t); return _t; }
    T* get() const noexcept { return _t; }

    void swap(scoped_ptr &p) noexcept { knt::swap(_t, p._t); }
};

} // knt

#endif // __SCOPED_PTR_H__
