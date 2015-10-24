#include "thingspeak-qt/thingspeak.hpp"
#include "thingspeak-qt/thingspeak-packet.hpp"

#include <QNetworkAccessManager>
#include <QNetworkRequest>

ThingSpeak::ThingSpeak(const QString& apiKey)
  : fAPIKey(apiKey)
{
}

namespace
{
  const QUrl THINGSPEAK_URL("http://api.thingspeak.com/update");
}

void ThingSpeak::post(const ThingSpeakPacket &update)
{
  QUrlQuery params(update.getQUrlQuery(fAPIKey));

  QNetworkRequest request;
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

  QNetworkAccessManager networkManager;
  networkManager.post(request, params.toString(QUrl::FullyEncoded).toUtf8());
}
