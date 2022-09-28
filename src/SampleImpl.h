#pragma once

#include <cstdint>
#include <memory>
#include <json/value.h>
#include <sample/Sample.h>

class SampleImpl : public Sample
{
public:
    /**
     * Default constructor.
     */
    SampleImpl() = default;

    /**
     * Default destructor.
     */
    ~SampleImpl() override = default;

    /**
     * Sample value setter.
     * @param v
     */
    void setValue(int32_t v) override;

    /**
     * Sample value getter.
     * @return
     */
    int32_t getValue() const override;

    /**
     * JSON serialisation implementation.
     * @return
     */
    Json::Value jsonSerialize() const override;

    /**
     * JSON deserialisation implementation.
     * @param v
     */
    void jsonDeserialize(const Json::Value &v) override;

protected:
    /**
     * A sample value to demonstrate getters/setters.
     */
    int32_t m_iSampleValue {};
};
