/*
 *
 * Callback
 * ledger-core
 *
 * Created by Pierre Pollastri on 27/09/2016.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Ledger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */
#ifndef LEDGER_CORE_CALLBACK_H
#define LEDGER_CORE_CALLBACK_H

#include <future>
#include "ExecutionContext.hpp"

namespace ledger {
    namespace core {

        template<>
        class CallbackResult {

        };

        template <typename T>
        class Callback {

        public:
            Callback(ExecutionContext *context, std::function<void (std::promise<T>)> function) : _function(function), _context(context) {};
            Callback(const Callback<T>& callback) {
                *this = callback;
            };

            void operator()(T param) {
                _context->execute([=]() {
                   _function(param);
                });
            };

            void operator=(const Callback<T>& callback) {
                this->_context = callback._context;
                this->_function = callback._function;
            };

        private:
            ExecutionContext *_context;
            T _function;
        };
    }
}

#endif //LEDGER_CORE_CALLBACK_H