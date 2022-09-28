#pragma once

#include <cstdint>
#include <memory>
#include <sample/Interface.h>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <emscripten/bind.h>
#endif

class Sample;

using SamplePtr = std::shared_ptr<Sample>;

class Sample : public Interface
{
public:
    /**
     * Create a new sample view model object.
     * @return
     */
    static SamplePtr newSample();

    /**
     * Default destructor.
     */
    virtual ~Sample() = default;

    /**
     * Sample value getter.
     * @return
     */
    virtual int32_t getValue() const = 0;

    /**
     * Sample value setter
     * @param v
     */
    virtual void setValue(int32_t v) = 0;
};

#ifdef __EMSCRIPTEN__
using namespace emscripten;

EMSCRIPTEN_KEEPALIVE
EMSCRIPTEN_BINDINGS(sample)
{
   class_<Sample>("Sample")
       .smart_ptr_constructor("Sample", &Sample::newSample)
       .function("toJsonString", &Sample::toJsonString)
       // Why doesn't function bind, but property does? No idea!
       .property("json", &Sample::toJsonString)
       .property("value", &Sample::getValue, &Sample::setValue);
}
#endif
