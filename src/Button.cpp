#include "vex.h"
#include "Button.h"

using namespace vex;

#define AUTON_BUTTONS_X_START 20
#define AUTON_BUTTONS_Y_START 20
#define AUTON_BUTTONS_WIDTH 60
#define AUTON_BUTTONS_HEIGHT 50

#define AUTON_SELECTOR_DEFAULT 4
#define AUTON_SELECTOR_COLOR_DEFAULT AUTON_SELECTOR_RED_SIDE

button buttonsAuton[] = {
  {AUTON_BUTTONS_X_START + 0 * (AUTON_BUTTONS_WIDTH + 10), AUTON_BUTTONS_Y_START + 0 * (AUTON_BUTTONS_HEIGHT + 10), 
    AUTON_BUTTONS_WIDTH, AUTON_BUTTONS_HEIGHT, "A0", "A0", false, vex::color::blue, vex::color::cyan},
  {AUTON_BUTTONS_X_START + 1 * (AUTON_BUTTONS_WIDTH + 10), AUTON_BUTTONS_Y_START + 0 * (AUTON_BUTTONS_HEIGHT + 10), 
    AUTON_BUTTONS_WIDTH, AUTON_BUTTONS_HEIGHT, "A1", "A1", false, vex::color::blue, vex::color::cyan},
  {AUTON_BUTTONS_X_START + 2 * (AUTON_BUTTONS_WIDTH + 10), AUTON_BUTTONS_Y_START + 0 * (AUTON_BUTTONS_HEIGHT + 10), 
    AUTON_BUTTONS_WIDTH, AUTON_BUTTONS_HEIGHT, "A2", "A2", false, vex::color::blue, vex::color::cyan},
  {AUTON_BUTTONS_X_START + 3 * (AUTON_BUTTONS_WIDTH + 10), AUTON_BUTTONS_Y_START + 0 * (AUTON_BUTTONS_HEIGHT + 10), 
    AUTON_BUTTONS_WIDTH, AUTON_BUTTONS_HEIGHT, "A3", "A3", false, vex::color::blue, vex::color::cyan},
  {AUTON_BUTTONS_X_START + 4 * (AUTON_BUTTONS_WIDTH + 10), AUTON_BUTTONS_Y_START + 0 * (AUTON_BUTTONS_HEIGHT + 10), 
    AUTON_BUTTONS_WIDTH, AUTON_BUTTONS_HEIGHT, "A4", "A4", false, vex::color::blue, vex::color::cyan}
};

button buttonsColor[] = {
  {AUTON_BUTTONS_X_START + 0 * (AUTON_BUTTONS_WIDTH + 10), AUTON_BUTTONS_Y_START + 1 * (AUTON_BUTTONS_HEIGHT + 10), 
    AUTON_BUTTONS_WIDTH, AUTON_BUTTONS_HEIGHT, "RED", "BLUE", false, vex::color::red, vex::color::blue}
};

int g_autonSelection = AUTON_SELECTOR_DEFAULT;
int g_redOrBlue = AUTON_SELECTOR_COLOR_DEFAULT;

int findButton( button *buttons, int nButtons,  int16_t xpos, int16_t ypos ) {
  for( int index=0;index < nButtons;index++) {
    button *pButton = &buttons[ index ];
    if( xpos < pButton->xpos || xpos > (pButton->xpos + pButton->width) )
      continue;

    if( ypos < pButton->ypos || ypos > (pButton->ypos + pButton->height) )
      continue;
    
    return(index);
  }
  return (-1);
}

void setSelected( button *buttons, int nButtons,  int16_t selectedIndex ) {
  printf("%d\n", selectedIndex);
  for( int index=0;index < nButtons;index++) {
    button *pButton = &buttons[ index ];
    pButton->state = (index == selectedIndex ? true : false);
  }
}

void userTouchCallbackReleased() {
  int index;
  int xpos = Brain.Screen.xPosition();
  int ypos = Brain.Screen.yPosition();
  int nAutonButtons = sizeof(buttonsAuton) / sizeof(button);
  int nColorButtons = sizeof(buttonsColor) / sizeof(button);
  //printf("Touch Released\n");

  if( (index = findButton(buttonsAuton, nAutonButtons, xpos, ypos )) >= 0 ) {
    g_autonSelection = index;
    setSelected(buttonsAuton, nAutonButtons, index);
    drawButtons(buttonsAuton, nAutonButtons);
    printf("AUTON CHANGED to %d\n",g_autonSelection);
  } else if( (index = findButton(buttonsColor, nColorButtons, xpos, ypos )) >= 0 ) {
    buttonsColor[index].state = !buttonsColor[index].state;
    if(buttonsColor[index].state) {
      g_redOrBlue = AUTON_SELECTOR_BLUE_SIDE;
    } else {
      g_redOrBlue = AUTON_SELECTOR_RED_SIDE;
    }
    drawButtons(buttonsColor, nColorButtons);
    printf("COLOR CHANGED to %d\n",g_redOrBlue);
  }
}

void drawButtons(button *buttons, int nButtons) {
  for( int index=0;index < nButtons;index++) {
    button *b = &buttons[ index ];
    vex::color c = vex::color::blue;
    c = b->colorUnselected;
    const char *text = b->label;
    if (b->state) {
      c = b->colorSelected;
      text = b->labelSelected;
    }

    Brain.Screen.setFillColor(c);
    Brain.Screen.drawRectangle(b->xpos, b->ypos, b->width, b->height);
    int x = b->xpos + b->width / 2 - Brain.Screen.getStringWidth(text) / 2;
    int y = b->ypos + b->height / 2 + Brain.Screen.getStringHeight(text) / 2;
    Brain.Screen.printAt(x, y, false, text);
  }
}

void initButtons() {
  int nAutonButtons = sizeof(buttonsAuton) / sizeof(button);
  int nColorButtons = sizeof(buttonsColor) / sizeof(button);
  setSelected(buttonsAuton, nAutonButtons, g_autonSelection);
  drawButtons(buttonsAuton, nAutonButtons);
  drawButtons(buttonsColor, nColorButtons);
  Brain.Screen.released( userTouchCallbackReleased );
}
