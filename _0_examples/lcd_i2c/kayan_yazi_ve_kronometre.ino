#include <LCD-I2C.h>


LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

void setup() {
    // If you are using more I2C devices using the Wire library use lcd.begin(false)
    // this stop the library(LCD-I2C) from calling Wire.begin()
    lcd.begin();
    lcd.display();
    lcd.backlight();
}

int col = 0; // kayan yazı için sütun değeri

void loop()
{   
    lcd.clear();
    // üst satırda kayan yazı
    
    lcd.setCursor(col, 0);
    lcd.print("iyi gunler...");
    col = (col+1)%16;

    // alt satır zaman gösterimi

    int t = millis()/1000;
    int saat = (int)floor(t/3600) % 24;
    
    int dakika = (int)floor(t/60) % 60;
    
    int saniye = t%60;
    
    lcd.setCursor(0, 1);
    
    if(saat<10){lcd.print("0");}
    lcd.print(saat);
    
    lcd.print(":");
    
    if(dakika<10){lcd.print("0");}
    lcd.print(dakika);
    
    lcd.print(":");
    
    if(saniye<10){lcd.print("0");}
    lcd.print(saniye);
    
    
    //delay(500);

    // Flashing the backlight
    /*
    for (int i = 0; i < 5; ++i)
    {
        lcd.backlight();
        delay(50);
        lcd.backlightOff();
        delay(50);
    }
    */
    lcd.backlight();
    //lcd.backlightOff();
    delay(300);
}
