#include "SampleImpl.h"

void SampleImpl::setValue(int32_t v)
{
    m_iSampleValue = v;
}

int32_t SampleImpl::getValue() const
{
    return m_iSampleValue;
}

Json::Value SampleImpl::jsonSerialize() const
{
    Json::Value value;
    value["value"] = m_iSampleValue;

    return value;
}

void SampleImpl::jsonDeserialize(const Json::Value &v)
{
    m_iSampleValue = v["value"].as<int32_t>();
}

SamplePtr Sample::newSample()
{
    return std::make_shared<SampleImpl>();
}
