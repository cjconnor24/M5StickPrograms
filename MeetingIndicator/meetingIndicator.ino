#include <WiFi.h>
#include <WiFiClient.h>
#include <M5StickCPlus.h>
#include <ESPAsyncWebSrv.h>

const char *ssid = "YourWiFiSSID";
const char *password = "YourWiFiPassword";

AsyncWebServer server(80);

void displayStatus(String status) {
    if (status == "busy") {
        Serial.println("Received busy status");
        M5.Lcd.fillScreen(RED);
        M5.Lcd.setTextSize(5);
        M5.Lcd.setCursor(30, 50);
        M5.Lcd.setTextColor(WHITE);
        M5.Lcd.print("BUSY");
    }
    if (status == "clear") {
        Serial.println("Received clear status");
        M5.Lcd.fillScreen(GREEN);
        M5.Lcd.setTextColor(BLACK);
        M5.Lcd.setTextSize(5);
        M5.Lcd.setCursor(30, 50);
        M5.Lcd.print("FREE");
    }
}

void setup() {
    M5.begin();

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        M5.Lcd.print("Connecting to WiFi...");
    }
    M5.Lcd.print("Connected to WiFi\nIP address:\n");
    M5.Lcd.print(WiFi.localIP());
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        String status = request->getParam("status")->value().c_str();
        Serial.println(status);
        M5.Lcd.setRotation(3);
        displayStatus(status);
        request->send(200, "text/plain", "POST received");
    });
    server.begin();
}

void loop() {
}
