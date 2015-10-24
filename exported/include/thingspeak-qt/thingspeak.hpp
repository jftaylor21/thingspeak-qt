#ifndef THINGSPEAK_HPP
#define THINGSPEAK_HPP

#include "thingspeak-qt_global.hpp"

#include <QString>

class ThingSpeakPacket;

class THINGSPEAKQTSHARED_EXPORT ThingSpeak
{
public:
  ThingSpeak(const QString& apiKey);

  void post(const ThingSpeakPacket& update);

private:
  const QString fAPIKey;
};

#endif // THINGSPEAK_HPP
