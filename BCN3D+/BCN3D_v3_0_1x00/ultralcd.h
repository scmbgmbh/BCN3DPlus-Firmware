#ifndef ULTRALCD_H
#define ULTRALCD_H

#include "Marlin.h"

#ifdef ULTRA_LCD

  void lcd_update();
  void lcd_init();
  void lcd_setstatus(const char* message);
  void lcd_setstatuspgm(const char* message);
  void lcd_setalertstatuspgm(const char* message);
  void lcd_reset_alert_level();
  
  //Changes Rapduch
  #define PAUSE_Z_CORRECTION_MM=10;
  
  static unsigned char blink = 0;	// Variable for visualisation of fan rotation in GLCD

  #define LCD_MESSAGEPGM(x) lcd_setstatuspgm(PSTR(x))
  #define LCD_ALERTMESSAGEPGM(x) lcd_setalertstatuspgm(PSTR(x))

  #define LCD_UPDATE_INTERVAL 100
  #define LCD_TIMEOUT_TO_STATUS 30000

  #ifdef ULTIPANEL
  void lcd_buttons_update();
  #else
  FORCE_INLINE void lcd_buttons_update() {}
  #endif
   
  extern int plaPreheatHotendTemp;
  extern int plaPreheatHPBTemp;
  extern int plaPreheatFanSpeed;

  extern int absPreheatHotendTemp;
  extern int absPreheatHPBTemp;
  extern int absPreheatFanSpeed;
  
  extern int nylonPreheatHotendTemp;
  extern int nylonPreheatHPBTemp;
  extern int nylonPreheatFanSpeed;

  extern int pvaPreheatHotendTemp;
  extern int pvaPreheatHPBTemp;
  extern int pvaPreheatFanSpeed;
  
  extern int laywoodPreheatHotendTemp;
  extern int laywoodPreheatHPBTemp;
  extern int laywoodPreheatFanSpeed;
  
  extern int laybrickPreheatHotendTemp;
  extern int laybrickPreheatHPBTemp;
  extern int laybrickPreheatFanSpeed;
  
  void lcd_buzz(long duration,uint16_t freq);
  bool lcd_clicked();

#else //no lcd
  FORCE_INLINE void lcd_update() {}
  FORCE_INLINE void lcd_init() {}
  FORCE_INLINE void lcd_setstatus(const char* message) {}
  FORCE_INLINE void lcd_buttons_update() {}
  FORCE_INLINE void lcd_reset_alert_level() {}
  FORCE_INLINE void lcd_buzz(long duration,uint16_t freq) {}

  #define LCD_MESSAGEPGM(x) 
  #define LCD_ALERTMESSAGEPGM(x) 
#endif 

char *itostr2(const uint8_t &x);
char *itostr31(const int &xx);
char *itostr3(const int &xx);
char *itostr3left(const int &xx);
char *itostr4(const int &xx);

char *ftostr3(const float &x);
char *ftostr31ns(const float &x); // float to string without sign character
char *ftostr31(const float &x);
char *ftostr32(const float &x);
char *ftostr5(const float &x);
char *ftostr51(const float &x);
char *ftostr52(const float &x);


//Rapduch
extern void update_hysteresis_circles ();
extern void update_hysteresis_off();
//static void lcd_hysteresis_menu();


#endif //ULTRALCD
