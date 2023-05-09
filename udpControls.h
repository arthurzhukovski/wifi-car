AsyncUDP udp;
const int UDP_PORT = 6969;

void initUdpControls(){
  if(udp.listen(UDP_PORT)) {
    Serial.print("UDP Listening on IP: ");
    Serial.print(WiFi.localIP());
    Serial.print(", port: ");
    Serial.println(UDP_PORT);
    udp.onPacket([](AsyncUDPPacket packet) {
      int command = (int)(packet.data()[0] - '0');
      controls(command);
      
      Serial.println(command);
      packet.printf("OK");
    });
  }
}