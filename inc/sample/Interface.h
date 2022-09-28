#pragma once

#include <string>
#include <json/value.h>
#include <json/writer.h>

class Interface
{
public:
    /**
     * Define how the class implementing this interface should serialise itself to a JSON value.
     * @return
     */
    virtual Json::Value jsonSerialize() const = 0;

    /**
     * Define how the class implementing this interface should deserialise itself from a JSON object which contains
     * data for all of its properties.
     */
    virtual void jsonDeserialize(const Json::Value &v) = 0;

    /**
     * Use the JSON serialisation capabilities of the class to convert the object into a valid JSON string.
     * @return
     */
    std::string toJsonString() const
    {
        static Json::FastWriter writer;
        return writer.write(jsonSerialize());
    }
};
