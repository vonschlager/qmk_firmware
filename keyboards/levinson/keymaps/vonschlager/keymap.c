#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ARROW 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ARROW,
};

// Fillers to make layering more clear
#define KC_____ KC_TRNS
#define KC_XXXX KC_NO
#define KC_X1   LOWER
#define KC_X2   RAISE
#define KC_X3   S(KC_NUHS)
#define KC_X4   S(KC_NUBS)
#define KC_RST  RESET
#define KC_ARR  ARROW
#define KC_TALT ALT_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     TALT, Q  , W  , E  , R  , T  ,      Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     ESC , A  , S  , D  , F  , G  ,      H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,      N  , M  ,COMM,DOT ,SLSH,RSFT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LCTL,LALT,XXXX,LGUI, X1 ,SPC ,     ENT , X2 ,RALT,RGUI,RCTL,ARR
  //`----+----+----+----+----+----'    `----+----+----+----+----+----' 
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     TILD,XXXX,EXLM, AT ,HASH,XXXX,     LPRN,RPRN,LABK,RABK,XXXX,DEL ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     XXXX,XXXX,DLR ,PERC,CIRC,XXXX,     LCBR,RCBR,MINS,PLUS,XXXX,XXXX,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     XXXX,XXXX,AMPR,ASTR,XXXX,XXXX,     LBRC,RBRC,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     ____,____,____,____,____,____,     ____,____,____,____,____,____
  //`----+----+----+----+----+----'    `----+----+----+----+----+----' 
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     GRV ,XXXX, 1  , 2  , 3  , 0  ,     COLN,DQT ,UNDS,EQL ,XXXX,DEL ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     XXXX,XXXX, 4  , 5  , 6  ,XXXX,     SCLN,QUOT,BSLS,PIPE,XXXX,XXXX,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     XXXX,XXXX, 7  , 8  , 9  ,XXXX,     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     ____,____,____,____,____,____,     ____,____,____,____,____,____
  //`----+----+----+----+----+----'    `----+----+----+----+----+----' 
  ),

  [_ARROW] = LAYOUT_kc(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     XXXX,PGDN, UP ,PGUP, F1 , F2 ,      F7 , F8 ,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     XXXX,LEFT,DOWN,RGHT, F3 , F4 ,      F9 ,F10 ,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX, F5 , F6 ,     F11 ,F12 ,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     ____,____,____,____,RST ,____,     ____,____,____,____,____,____
  //`----+----+----+----+----+----'    `----+----+----+----+----+----' 
  ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case ARROW:
      if (record->event.pressed) {
        layer_on(_ARROW);
      } else {
        layer_off(_ARROW);
      }
      return false;
      break;
  }
  return true;
}
