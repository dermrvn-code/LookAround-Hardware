#include <Arduino.h>

void setup()
{
  Serial.begin(115200);
}

double rotation = 0;
bool interaction1Pressed = false;
bool interaction2Pressed = false;
double zoomPercent = 0;
int messages = 0;

int timer = 0;

bool down = false;
bool zoomIn = false;
void loop()
{
  interaction1Pressed = false;
  interaction2Pressed = false;

  if (timer > 800 && timer < 900)
  {
    interaction1Pressed = true;
  }
  if (timer > 600 && timer < 700)
  {
    interaction2Pressed = true;
  }

  if (timer > 1000 && timer < 8000)
  {
    if (rotation > 350)
      down = true;
    if (rotation <= 0)
      down = false;

    if (!down)
      rotation = rotation + 0.01;
    else
    {
      rotation = rotation - 0.01;
    }
  }

  if (timer > 1200 && timer < 4500)
  {
    if (zoomPercent > 99)
      zoomIn = false;
    if (zoomPercent < 1)
      zoomIn = true;

    if (zoomIn)
      zoomPercent = zoomPercent + 0.05;
    else
    {
      zoomPercent = zoomPercent - 0.2;
    }
  }

  Serial.println("$" + String((int)rotation) + ";" + String(interaction1Pressed) + ";" + String(interaction2Pressed) + ";" + String((int)zoomPercent) + ";" + String(messages) + "#\n");

  timer++;
  if (timer >= 10000)
    timer = 0;
  delay(5);
}