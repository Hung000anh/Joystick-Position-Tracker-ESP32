#include <Arduino.h>

#define VERT_PIN 34 // Chân đọc trục dọc (Y)
#define HORZ_PIN 35 // Chân đọc trục ngang (X)
#define SEL_PIN  32 // Chân đọc nút nhấn

void setup() {
  Serial.begin(115200);
  pinMode(SEL_PIN, INPUT_PULLUP); // Kích hoạt điện trở kéo lên
}

void loop() {
  int vert = analogRead(VERT_PIN);  // Đọc trục dọc (Y)
  int horz = analogRead(HORZ_PIN);  // Đọc trục ngang (X)
  bool selPressed = digitalRead(SEL_PIN) == LOW; // Kiểm tra nút nhấn

  // Chuyển đổi giá trị từ (0-1023) sang (-100 đến 100)
  int xPos = map(horz, 0, 1023, -100, 100);
  int yPos = map(vert, 0, 1023, -100, 100);

  // Hiển thị kết quả
  Serial.print("X: "); Serial.print(xPos);
  Serial.print("\tY: "); Serial.print(yPos);
  Serial.print("\tButton: "); Serial.println(selPressed ? "Pressed" : "Not Pressed");

  delay(100); // Giảm tần suất đọc để tránh spam Serial
}
