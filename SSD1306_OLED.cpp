#include "pxt.h"
#include "Adafruit_SSD1306.h"

using namespace pxt;

namespace OLED {
	#define SSD1306_ADDRESS 0x78
	#undef printf


	MicroBitI2C i2c(I2C_SDA0, I2C_SCL0);
	Adafruit_SSD1306_I2c *oled;

	void init(int height, int width){
		if (oled != NULL) delete oled;
		oled = new Adafruit_SSD1306_I2c(i2c, SSD1306_ADDRESS, height, width);
		oled->splash();
		oled->display();
	}
	
	//%
	void init_terminal(int height, int width){
		if (oled != NULL) delete oled;
		oled = new Adafruit_SSD1306_I2c(i2c, SSD1306_ADDRESS, height, width);
		oled->clearDisplay();
		oled->display();
		oled->setTextCursor(0, 0);
	}
	

	//%
    void showStringNoNewLine(StringData *text) {
		oled->printf("%s", text->data);
		oled->display();
    }

	//%
    void showStringWithNewLine(StringData *text) {
		oled->printf("%s\n", text->data);
		oled->display();
    }
	
    //%
    void showNumberWithoutNewLine (int number) {
		oled->printf("%d", number);
		oled->display();
	}
	
	//%
    void showNumberWithNewLine (int number) {
		oled->printf("%d\n", number);
		oled->display();
	}
	
    //%
    void NextLine () {
		oled->printf("\n");
		oled->display();
	}

	//%
	void clearDisplay(){
		oled->setTextCursor(0, 0);
		oled->clearDisplay();
		oled->display();
	}

    //%
//%	void fillTriangle(int x, int y, int x1, int y1, int x2, int y2, int c){
//%		oled->fillTriangle(x, y, x1, y1, x2, y2, c);
//%		oled->display();
//%	}

	//%
	void drawCircle(int x, int y, int r){
		oled->drawCircle(x, y, r, 1);
		oled->display();
	}

    //%
	void fillCircle(int x, int y, int r, int c){
		oled->fillCircle(x, y, r, c);
		oled->display();
	}

	//%
	void drawLine(int x0, int y0, int x1, int y1){
		oled->drawLine(x0, y0, x1, y1, 1);
		oled->display();
	}

	//%
	void fillRect(int x, int y, int w, int h, int c){
		oled->fillRect(x, y, w, h, c);
		oled->display();
	}



    

	//%
    void drawRect(int x, int y, int w, int h){
    	oled->drawRect(x, y, w, h, 1);
		oled->display();
    }

    //%
	void fillRoundRect(int x, int y, int w, int h, int r){
		oled->fillRoundRect(x, y, w, h, r, 1);
		oled->display();
	}

    //%
	void removeRoundRect(int x, int y, int w, int h, int r){
		oled->fillRoundRect(x, y, w, h, r, 0);
		oled->display();
	}

	//%
    void drawRoundRect(int x, int y, int w, int h, int r){
    	oled->drawRoundRect(x, y, w, h, r, 1);
		oled->display();
    }

    //%
    void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2){
    	oled->drawTriangle(x0, y0, x1, y1, x2, y2, 1);
		oled->display();
    }

    //%
    void fillTriangle(int x0, int y0, int x1, int y1, int x2, int y2){
    	oled->fillTriangle(x0, y0, x1, y1, x2, y2, 1);
		oled->display();
    }
		
	//%
	void LoadingScreen() {
		int x,y = 0;
		int w = 21;
		int h = 64;
		for (int i = 0; i < 6;i++){
			fillRect(x, y, w, h,1);
			x = x + 21;
			oled->display();
		}

	}

	//%
	void showProgress(int progress) {
		oled->clearDisplay();
		drawRect(0,21,128,21);
		fillRect(0,21,progress*128/100,21,1);
	}
    #define printf(...) uBit.serial.printf(__VA_ARGS__)

}
