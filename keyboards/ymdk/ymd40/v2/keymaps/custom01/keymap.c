/* 
 * Customización teclado YMD40 por Santiago Intxausti <intxausti@gmail.com>
 */

#include QMK_KEYBOARD_H

const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{11, 0}, {10, 0}, {9, 0}, {8, 0}, {7, 0}, {6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
  {{11, 1}, {10, 1}, {9, 1}, {8, 1}, {7, 1}, {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
  {{11, 2}, {10, 2}, {9, 2}, {8, 2}, {7, 2}, {6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
  {{11, 3}, {10, 3}, {9, 3}, {8, 3}, {7, 3}, {6, 3}, {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
};

enum custom_keycodes {
  ALTTAB = SAFE_RANGE,
  WINTAB,
  eñe,
  EÑE
};

bool alttab_token;
bool altwin_token;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALTTAB: 
      if (record->event.pressed){
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_TAB));
        alttab_token = true;
      } else {
        // Cuando la tecla es liberada
        // clear_keyboard();
      }
      break;

      case WINTAB:
      if (record->event.pressed){
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_TAB));
        altwin_token = true;
      } else {
        // Cuando la tecla es liberada
        // clear_keyboard();
      }
      break;

    case eñe: 
      if (record->event.pressed){
        SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_GRV) SS_UP(X_LSFT) SS_TAP(X_N));
        alttab_token = true;
      } else {
        // Cuando la tecla es liberada
        // clear_keyboard();
      }
      break;
	 
    case EÑE: 
      if (record->event.pressed){
        SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_GRV) SS_TAP(X_N) SS_UP(X_LSFT));
        alttab_token = true;
      } else {
        // Cuando la tecla es liberada
        // clear_keyboard();
      }
      break;
	
  }
  return true;
};



// FUNCION TECLA LEADER
LEADER_EXTERNS();







// FUNCIONES TAP DANCE

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_TRIPLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void numpad_finished(qk_tap_dance_state_t *state, void *user_data);
void numpad_reset(qk_tap_dance_state_t *state, void *user_data);
void scape_finished(qk_tap_dance_state_t *state, void *user_data);
void scape_reset(qk_tap_dance_state_t *state, void *user_data);
void play_finished(qk_tap_dance_state_t *state, void *user_data);
void capslock_finished(qk_tap_dance_state_t *state, void *user_data);
void capslock_reset(qk_tap_dance_state_t *state, void *user_data);
void dance_exclam_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_exclam_reset(qk_tap_dance_state_t *state, void *user_data);
void vold_finished(qk_tap_dance_state_t *state, void *user_data);
void vold_reset(qk_tap_dance_state_t *state, void *user_data);
void volu_finished(qk_tap_dance_state_t *state, void *user_data);
void volu_reset(qk_tap_dance_state_t *state, void *user_data);
void lctl_finished(qk_tap_dance_state_t *state, void *user_data);
void lctl_reset(qk_tap_dance_state_t *state, void *user_data);
//NOMBRES TAP DANCE
enum {
    TD_ORDINAL,
    TD_EURO,
    TD_INTERROG,
    TD_SIFT_CAPSLOCK,
    TD_RHAND_LAYER,
    TD_WIN_MENU,
    TD_EXCLAM,
    TD_MNXT,
    TD_PLAY,
    TD_VOLD,
    TD_VOLU,
    TD_LCTL,
    TD_ESC
};

// Tap Dance DEFINICIONES
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ORDINAL]  = ACTION_TAP_DANCE_DOUBLE(RALT(KC_F),LSFT(RALT(KC_F))),
    [TD_EURO]  = ACTION_TAP_DANCE_DOUBLE(KC_HASH, RALT(KC_5)),
    [TD_INTERROG]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, RALT(KC_SLSH)),
    [TD_SIFT_CAPSLOCK]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, capslock_finished, capslock_reset),
    [TD_RHAND_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, numpad_finished, numpad_reset),
    [TD_WIN_MENU]  = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_APP),
    [TD_EXCLAM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_exclam_finished, dance_exclam_reset),
    [TD_MNXT]  = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT),
    [TD_PLAY]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, play_finished, NULL),
    [TD_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, scape_finished, scape_reset),
    [TD_VOLD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, vold_finished, vold_reset),
    [TD_VOLU] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, volu_finished, volu_reset),
    [TD_LCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lctl_finished, lctl_reset),
};



enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _OTHERS,
  _MOV,
  _NUM_PAD,
  _RNUM_PAD,
  _MOUSE,
  _QWERTY2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY]=LAYOUT_ortho_4x12(
			TD(TD_RHAND_LAYER),		KC_Q,			KC_W,			KC_E,			KC_R,				KC_T,			KC_Y,			KC_U,				KC_I,				KC_O,			KC_P,				KC_BSPC,
			TD(TD_ESC),				KC_A,			LALT_T(KC_S),	LCTL_T(KC_D),	LSFT_T(KC_F),		KC_G,			KC_H,			RSFT_T(KC_J),		RCTL_T(KC_K),		LALT_T(KC_L),	RGUI_T(KC_SCLN),	KC_QUOT,
			TD(TD_LCTL),			LGUI_T(KC_Z),	KC_X,			KC_C,			KC_V,				KC_B,			KC_N,			KC_M,				KC_COMM,			KC_DOT,			TD(TD_INTERROG),	KC_LEAD,
			TD(TD_SIFT_CAPSLOCK),	OSM(MOD_LALT),	OSM(MOD_RALT),	OSM(MOD_LGUI),	LT(_LOWER,KC_ENT),	SH_T(KC_SPACE),	SH_T(KC_SPACE),	LT(_RAISE,KC_ENT),	KC_NO,				TD(TD_PLAY),	TD(TD_VOLU),		TD(TD_VOLD)
	),
    
	[_RAISE]=LAYOUT_ortho_4x12(
			KC_NO,		KC_F9,		KC_F10,		KC_F11,		KC_F12,		    KC_NO,	KC_NO,  KC_F21,		KC_F22,	    KC_F23,	    KC_F24,	KC_NO,
			KC_NO,		KC_F5,		KC_F6,		KC_F7,		KC_F8,		    KC_NO,	KC_NO,	KC_F17,		KC_F18,	    KC_F19,	    KC_F20, KC_NO,
			KC_NO,	    KC_F1,		KC_F2,		KC_F3,		KC_F4,		    KC_NO,	KC_NO,	KC_F13,		KC_F14,	    KC_F15, 	KC_F16, KC_NO,
			KC_NO,      KC_PSCR,	KC_SCRL,    KC_PAUS,    MO(_OTHERS),    KC_NO,	KC_NO,	KC_NO,      KC_NO,	    KC_NO,      KC_NO,  KC_NO
	),
    
    [_LOWER]=LAYOUT_ortho_4x12(
			KC_DEL,         KC_NO,		KC_NO,		DM_PLY2,		DM_PLY1,            KC_NO,	KC_GRV,		 	TD(TD_EXCLAM),	KC_AT,		    TD(TD_EURO),	    KC_DLR,			KC_PERC,
			LSFT(G(KC_S)),	WINTAB,		ALTTAB,	    C(G(KC_LEFT)),	C(G(KC_RIGHT)),		KC_NO,	KC_TILD,	 	KC_CIRC,		KC_AMPR,	    KC_ASTR,	        KC_LPRN,	    KC_RPRN,
			A(KC_F4),		KC_NO,		KC_NO,		G(S(KC_S)),		G(KC_V),		    KC_NO,	eñe,			KC_MINS,		KC_EQL,		    KC_BSLS,		    KC_LBRC,		KC_RBRC,
			KC_TRNS,		KC_TRNS,	KC_TRNS,	KC_TRNS,		KC_TRNS,	        KC_NO,	KC_NO,		 	MO(_OTHERS),	RALT(KC_LBRC),	RALT(KC_RBRC),		KC_LCBR,		KC_RCBR
	),
    
	[_OTHERS]=LAYOUT_ortho_4x12(
			QK_BOOT,	KC_NO,		KC_WAKE,	KC_NO,		KC_NO,		KC_NO,			KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_PWR,		KC_NO,
			KC_NO,		KC_NO,		KC_SLEP,	KC_NO,		KC_PWR,		KC_NO,			KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
			KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,			KC_NO,		DM_REC1,	DM_REC2,	DM_RSTP,	DM_RSTP,	DM_RSTP,
			KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_NO,			KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
	),

	[_MOV]=LAYOUT_ortho_4x12(
			KC_NO,			KC_NO,			DM_PLY2,		DM_PLY1,		KC_NO,		KC_NO,		KC_PAUS,	KC_HOME,	KC_INS,	KC_PGUP,	KC_NO,		KC_BSPC,
			KC_TRNS,		KC_LGUI,		KC_LALT,		KC_LCTL,		KC_LSFT,	KC_HOME,	KC_LEFT,	KC_DOWN,	KC_UP,	KC_RGHT,	KC_NO,		KC_NO,
			KC_NO,			KC_NO,			KC_NO,			C(KC_C),		C(KC_V),	KC_NO,		KC_NO,		KC_END,		KC_NO,	KC_PGDN,	KC_NO,		KC_NO,
			KC_NO,			KC_NO,			KC_NO,			KC_NO,			KC_TAB,		KC_SPACE,	KC_SPACE,	KC_ENT,		KC_DEL,	KC_DEL,		KC_NO,		KC_NO
	),

	[_RNUM_PAD]=LAYOUT_ortho_4x12(
			KC_TRNS,						KC_NO,	KC_NO,	KC_NO,	KC_R,		KC_ESC,			KC_ESC,		KC_P7,	KC_P8,	KC_P9,		KC_PPLS,	KC_BSPC,
			LM(_QWERTY2,MOD_LCTL),			KC_NO,	KC_NO,	KC_NO,	KC_AT,		KC_TAB,			KC_TAB,		KC_P4,	KC_P5,	KC_P6,		KC_PPLS,	KC_PMNS,
			LM(_QWERTY2,MOD_LALT),			KC_NO,	KC_NO,	KC_NO,	KC_PERC,	KC_COMM,		KC_COMM,	KC_P1,	KC_P2,	KC_P3,		KC_PENT,	KC_PAST,
			LM(_QWERTY2,MOD_LCTL|MOD_LALT),	KC_NO,	KC_NO,	KC_NO,	KC_ENT,		KC_SPACE,		KC_SPACE,	KC_P0,	KC_P0,	KC_PDOT,	KC_PENT,	KC_PSLS
	),

	[_NUM_PAD]=LAYOUT_ortho_4x12(
			KC_TRNS,				KC_DEL,	KC_7,		KC_8,	KC_9,		KC_ESC,		KC_ESC,		KC_7,	KC_8,	KC_9,	KC_DEL,	KC_BSPC,
			LM(_QWERTY2,MOD_LCTL),	KC_NO,	KC_4,		KC_5,	KC_6,		KC_TAB,		KC_TAB,		KC_4,	KC_5,	KC_6,	KC_ENT,	KC_NO,
			LM(_QWERTY2,MOD_LALT),	KC_ENT,	KC_1,		KC_2,	KC_3,		KC_COMM,	KC_COMM,	KC_1,	KC_2,	KC_3,	KC_ENT,	KC_NO,
			KC_NUM,					KC_ENT,	KC_DOT,		KC_0,	KC_0,		KC_SPACE,	KC_SPACE,	KC_0,	KC_0,	KC_DOT,	KC_ENT,	KC_NO
	),

	[_MOUSE]=LAYOUT_ortho_4x12(
			KC_TRNS,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_MS_BTN1,		KC_MS_UP,	KC_MS_BTN2,		KC_MS_WH_UP,	KC_MS_ACCEL0,
			KC_TRNS,	KC_TRNS,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_MS_LEFT,		KC_MS_DOWN,	KC_MS_RIGHT,	KC_MS_WH_DOWN,	KC_MS_ACCEL1,
			KC_TRNS,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_MS_WH_LEFT,	KC_MS_BTN3,	KC_MS_WH_RIGHT,	KC_NO,			KC_MS_ACCEL2,
			KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,		KC_TRNS,	KC_TRNS,		KC_TRNS,		KC_TRNS
	),
	
	[_QWERTY2]=LAYOUT_ortho_4x12(
		KC_TRNS,	KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,			KC_BSPC,
		KC_TRNS,	KC_A,		KC_S,		KC_D,		KC_F,		KC_G,		KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,		KC_QUOT,
		KC_TRNS,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_N,		KC_M,		KC_COMM,	KC_DOT,		TD_INTERROG,	KC_LEAD,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TAB,		KC_SPACE,	KC_SPACE,	KC_ENT,		KC_TRNS,	KC_TRNS,	KC_TRNS,		KC_TRNS
	)
};

// FUNCION PARA ACTIVAR EL NUMLOCK SIEMPRE QUE SE ESTÉ EN CAPA _QWERTY 
void led_set_user(uint8_t usb_led) {
  if (!(usb_led & (1<<USB_LED_NUM_LOCK)) & (layer_state_is(_QWERTY))) {
    tap_code(KC_NUM);
  }
}

// Determine the current tap dance state
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;	
    } 
    
    else if (state->count == 2) {
    	if (!state->pressed) return TD_DOUBLE_TAP;
    	else return TD_DOUBLE_HOLD;	
    } 
    
    else if (state->count == 3) return TD_TRIPLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t numpad_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void numpad_finished(qk_tap_dance_state_t *state, void *user_data) {
    numpad_tap_state.state = cur_dance(state);
    switch (numpad_tap_state.state) {
        case TD_SINGLE_TAP:
        	if (layer_state_is(_QWERTY)) {
                layer_on(_NUM_PAD);
            }   else if (layer_state_is(_RNUM_PAD) || (layer_state_is(_NUM_PAD))){
            		layer_off(_RNUM_PAD);
            		layer_off(_NUM_PAD);
            		}   		
            break;
        case TD_SINGLE_HOLD:
            layer_on(_NUM_PAD);
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_RNUM_PAD)) {
                // If already set, then switch it off
                layer_off(_RNUM_PAD);
            } else {
                // If not already set, then switch the layer on
                layer_on(_RNUM_PAD);;
            }
            break;
		case TD_DOUBLE_HOLD:
           layer_on(_RNUM_PAD);
            break;
        default:
            break;
    }
}

void numpad_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (numpad_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_NUM_PAD);
    }    
    if (numpad_tap_state.state == TD_DOUBLE_HOLD) {
        layer_off(_RNUM_PAD);
    }
    numpad_tap_state.state = TD_NONE;
}

void scape_finished(qk_tap_dance_state_t *state, void *user_data) {
    numpad_tap_state.state = cur_dance(state);
    switch (numpad_tap_state.state) {
        case TD_SINGLE_TAP:
        	if (layer_state_is(_QWERTY)) {
				tap_code(KC_ESC);
        	}
  	    	
  	    	if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
   				tap_code(KC_CAPS);
 	    	}
	    	
	    	reset_oneshot_layer();
            clear_oneshot_locked_mods();
            layer_clear();
            clear_keyboard();    
            break;
            
        case TD_SINGLE_HOLD:
            if (layer_state_is(_MOV)) {
                layer_off(_MOV);
            } else {
                layer_on(_MOV);
            }
            break;
            
        case TD_DOUBLE_TAP:
            if (layer_state_is(_MOV)) {
                layer_off(_MOV);
            } else {
                layer_on(_MOV);
            }
            break;
                      
        case TD_DOUBLE_HOLD:
            if (layer_state_is(_MOUSE)) {
                layer_off(_MOUSE);
            } else {
                layer_on(_MOUSE);
            }
            break;
            
        default:
            break;
    }
}

void scape_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (numpad_tap_state.state == TD_SINGLE_HOLD) {
		layer_off(_MOV);
    }
    if (numpad_tap_state.state == TD_DOUBLE_HOLD) {
		layer_off(_MOUSE);
    }
    numpad_tap_state.state = TD_NONE;
}

void capslock_finished(qk_tap_dance_state_t *state, void *user_data) {
    numpad_tap_state.state = cur_dance(state);
    switch (numpad_tap_state.state) {
        case TD_SINGLE_TAP:
        	if (layer_state_is(_QWERTY)) {
				tap_code(KC_CAPS);
				}
            break;
        case TD_SINGLE_HOLD:
			SEND_STRING(SS_DOWN(X_LSFT));
            break;
        default:
            break;
    }
}

void capslock_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
	SEND_STRING(SS_UP(X_LSFT));
    numpad_tap_state.state = TD_NONE;
}

void dance_exclam_finished(qk_tap_dance_state_t *state, void *user_data) {
    numpad_tap_state.state = cur_dance(state);
    switch (numpad_tap_state.state) {
        case TD_SINGLE_TAP:
			register_code16(KC_EXLM);
            break;
        case TD_DOUBLE_TAP:
        	SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_1) SS_DELAY(10) SS_UP(X_RALT));
        	clear_keyboard();
            break;
        default:
            break;
    }
}

void dance_exclam_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_EXLM);
    }
}

void vold_finished(qk_tap_dance_state_t *state, void *user_data) {
    numpad_tap_state.state = cur_dance(state);
    switch (numpad_tap_state.state) {
        case TD_SINGLE_TAP:
			register_code16(KC_VOLD);
            break;
        case TD_SINGLE_HOLD:
        	tap_code(KC_MNXT);
            break;
        case TD_DOUBLE_HOLD:
        	register_code16(KC_VOLD);
            break;
        case TD_DOUBLE_TAP:
    		SEND_STRING(SS_TAP(X_VOLD) SS_TAP(X_VOLD));
        break;            
        case TD_TRIPLE_TAP:
    		SEND_STRING(SS_TAP(X_VOLD) SS_TAP(X_VOLD) SS_TAP(X_VOLD));
        break;
        default:
            break;
    }
}

void vold_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_VOLD);
    }
}

void volu_finished(qk_tap_dance_state_t *state, void *user_data) {
    numpad_tap_state.state = cur_dance(state);
    switch (numpad_tap_state.state) {
        case TD_SINGLE_TAP:
			register_code16(KC_VOLU);
            break;
        case TD_SINGLE_HOLD:
        	tap_code(KC_MPRV);
            break;
        case TD_DOUBLE_TAP:
    		SEND_STRING(SS_TAP(X_VOLU) SS_TAP(X_VOLU));
        break; 
         case TD_DOUBLE_HOLD:
        	register_code16(KC_VOLU);
            break;           
        case TD_TRIPLE_TAP:
    		SEND_STRING(SS_TAP(X_VOLU) SS_TAP(X_VOLU) SS_TAP(X_VOLU));
        break;
        default:
            break;
    }
}

void volu_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_VOLU);
    }
}

void play_finished(qk_tap_dance_state_t *state, void *user_data) {
    numpad_tap_state.state = cur_dance(state);
    switch (numpad_tap_state.state) {
        case TD_SINGLE_TAP:
			tap_code(KC_MPLY);
            break;
        case TD_DOUBLE_TAP:
        	tap_code(KC_MUTE);
            break;
        default:
            break;
    }
}

void lctl_finished(qk_tap_dance_state_t *state, void *user_data) {
    numpad_tap_state.state = cur_dance(state);
    switch (numpad_tap_state.state) {
        case TD_SINGLE_TAP:
			tap_code(KC_TAB);
            break;
        case TD_SINGLE_HOLD:
        	register_code16(KC_LCTL);
            break;
        default:
            break;
    }
}

void lctl_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_LCTL);
    }
}

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();


// ScreenShoot
    SEQ_ONE_KEY(KC_S) {
    	SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_S))));
    }
// Terminal
    SEQ_ONE_KEY(KC_T) {
    	SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_T))));
    }
// Explorador Archivos
    SEQ_ONE_KEY(KC_E) {
    	SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_E))));
    }    
// Chrome home page
    SEQ_ONE_KEY(KC_H) {
	SEND_STRING(SS_LALT(SS_TAP(X_HOME)));
	SEND_STRING(SS_LALT(SS_TAP(X_0)));
	}

//windows calculator
     SEQ_ONE_KEY(KC_K) {
    	SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_C))));
    }
// ctr + alt + spr 
    SEQ_THREE_KEYS(KC_C, KC_A, KC_D) {
    	SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_DELETE))));
    }

// ctr + alt + backspace 
    SEQ_THREE_KEYS(KC_C, KC_A, KC_B) {
    	SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_BSPC))));
    }
    
// Capslock
    SEQ_THREE_KEYS(KC_C, KC_A, KC_P) {
  	tap_code(KC_CAPS);
    }

// Close active windows
    SEQ_THREE_KEYS(KC_C, KC_L, KC_S) {
    	SEND_STRING(SS_LALT(SS_TAP(X_F4)));
    }
  }
  
	if (layer_state_is(_QWERTY) && alttab_token) {
		SEND_STRING(SS_UP(X_LALT));
		alttab_token = false;
		} 

	if (layer_state_is(_QWERTY) && altwin_token) {
		SEND_STRING(SS_UP(X_LGUI));
		altwin_token = false;
		} 
}

