#include <Otto.h>
Otto Otto;


#define LeftLeg 2 // left leg pin
#define RightLeg 3 // right leg pin
#define LeftFoot 4 // left foot pin
#define RightFoot 5 // right foot pin
#define Buzzer 13 //buzzer pin



void setup() {
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
  Otto.home();

}

void loop() {
  Otto.walk(2, 1000, 1);
}
