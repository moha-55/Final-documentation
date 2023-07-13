#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>

#define DHTPIN 2     // Change this to the pin you connected the DHT sensor
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

const char* ssid     = "Atwa 2.4 G@unifi";         // Your WiFi ssid
const char* password = "atwa2020";     // Your WiFi password

const char* host = "192.168.1.10:8086"; // Your InfluxDB host (without "http://")
const uint16_t port = 8086; // Your InfluxDB port

WiFiClient wifiClient;

void setup() {
    Serial.begin(115200);
    delay(10);

    dht.begin();

    // Connect to WiFi
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
    delay(2000); // Reading frequency

    // Reading temperature or humidity takes about 250 milliseconds!
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    // If you're here, you successfully read temperature and humidity.
    // Now, we'll create an HTTP POST request to the InfluxDB API.

    // Prepare an HTTPClient instance
    HTTPClient http;

    // Format the data as InfluxDB line protocol
    String data = "dht,location=office temperature=";
    data += String(t);
    data += ",humidity=";
    data += String(h);

    String url = "http://";
    url += host;
    url += ":";
    url += port;
    url += "/write?db=mydb"; // Change "mydb" to your InfluxDB database name

    http.begin(wifiClient, url);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int httpResponseCode = http.POST(data);

    if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
    }
    else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }

    // Free the resources
    http.end();
}
