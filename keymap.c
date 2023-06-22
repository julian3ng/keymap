#include QMK_KEYBOARD_H
#include "version.h"

#ifdef AUDIO_ENABLE
#include "audio.h"
#include "song_list.h"
float foo[][2] = SONG(MUSIC_ON_SOUND);
#endif

enum layers {
    QW, // base layer
    CL,
    SYMB,
    NAV,
    MOUSE,
    MEDIA,
};

/* enum custom_keycodes { */
/*     MY_LED_LEVEL = ML_SAFE_RANGE */
/* }; */


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QW] = LAYOUT_moonlander(
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_BRIU,    KC_VOLU,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_BRID,    KC_VOLD,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,

        MT(MOD_LCTL, KC_ESC), MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D), MT(MOD_LCTL, KC_F), KC_G, TO(CL),
        KC_MUTE, KC_H, MT(MOD_RCTL, KC_J), MT(MOD_RSFT, KC_K), MT(MOD_RALT, KC_L), MT(MOD_RGUI, KC_SCLN), KC_QUOT,

        SC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SC_RSPC,
        CW_TOGG, QK_LEAD, _______, KC_LGUI, KC_LALT,          RGB_RMOD,    RGB_MOD,   DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, DM_RSTP,
        LT(SYMB, KC_SPC), LT(NAV, KC_BSPC), LT(MOUSE, KC_DEL),    MO(MEDIA), LT(NAV, KC_ENT), LT(SYMB, KC_SPC)
        ),
    [CL] = LAYOUT_moonlander(
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,    _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
        _______,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B, _______,    _______,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, _______,

        _______, MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_R), MT(MOD_LSFT, KC_S), MT(MOD_LCTL, KC_T), KC_G, TO(QW),
        _______, KC_M, MT(MOD_RCTL, KC_N), MT(MOD_RSFT, KC_E), MT(MOD_RALT, KC_I), MT(MOD_RGUI, KC_O), KC_QUOT,

        _______,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, _______,
        _______, _______, _______, _______, _______,          _______,    _______,   _______, _______, _______, _______, _______,
        _______, _______, _______,    _______, _______, _______
        ),
    [SYMB] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,    _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
        KC_ESC, KC_LABK, KC_LCBR, KC_LBRC, KC_LPRN, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_RPRN, KC_RBRC, KC_RCBR, KC_RABK, KC_QUOT,


        XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_MINS, XXXXXXX,                      XXXXXXX,  KC_EQL, KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______,          _______,    _______,          _______, _______, _______, _______, _______,
        _______, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, _______
        ),
    [NAV] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_PGUP,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX, XXXXXXX,    XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______,          _______,    _______, _______, _______, _______, _______, _______,
        XXXXXXX, _______, XXXXXXX,          XXXXXXX, _______, XXXXXXX
        ),
    [MOUSE] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_WH_U, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX, XXXXXXX,    XXXXXXX, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_ACL2, KC_ACL1, KC_ACL0, XXXXXXX,                      XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______,          _______,    _______, _______, _______, _______, _______, _______,
        XXXXXXX, XXXXXXX, _______,          KC_BTN3, KC_BTN1, KC_BTN2
        ),
    [MEDIA] = LAYOUT_moonlander(
        XXXXXXX, RGB_M_P, RGB_M_B,  RGB_M_R,RGB_M_SW,RGB_M_SN, XXXXXXX,           XXXXXXX, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, XXXXXXX, QK_BOOT,
        XXXXXXX, KC_BRIU, RGB_TOG, RGB_RMOD, RGB_MOD, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_BRID, RGB_HUI,  RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, DT_DOWN, DT_UP, DT_PRNT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, RGB_HUD,  RGB_SAD, RGB_VAD, XXXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,LED_LEVEL, XXXXXXX,          XXXXXXX,           XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,          _______, XXXXXXX, XXXXXXX
        )
/*
  [BLANK] = LAYOUT_moonlander(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
  )
*/
};

typedef union {
    uint32_t raw;
    struct {
        bool         disable_layer_led   :1;
        bool         rgb_matrix_enable   :1;
        bool         led_level           :1;
        uint8_t      led_level_res       :2; // DO NOT REMOVE
    };
} user_config_t;

user_config_t user_config;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LED_LEVEL:
        if (record->event.pressed) {
            user_config.led_level ^= 1;
            eeconfig_update_user(user_config.raw);
            if (user_config.led_level) {
                layer_state_set_user(layer_state);
            } else {
                ML_LED_1(false);
                ML_LED_2(false);
                ML_LED_3(false);
                ML_LED_4(false);
                ML_LED_5(false);
                ML_LED_6(false);
            }
        }
        break;
    }
    return true;
}



layer_state_t layer_state_set_user(layer_state_t state) {
    if (!user_config.led_level) return state;
    bool LED_1 = false;
    bool LED_2 = false;
    bool LED_3 = false;
    bool LED_4 = false;
    bool LED_5 = false;
    bool LED_6 = false;

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
    case 1:
        LED_1 = true;
        break;
    case 2:
        LED_2 = true;
        break;
    case 3:
        LED_1 = true;
        LED_2 = true;
        break;
    case 4:
        LED_3 = true;
        break;
    case 5:
        LED_1 = true;
        LED_3 = true;
        break;
    case 6:
        LED_2 = true;
        LED_3 = true;
        break;
    case 7:
        LED_1 = true;
        LED_2 = true;
        LED_3 = true;
        break;
    case 8:
        LED_4 = true;
        break;
    default:
        break;
    }

    ML_LED_1(LED_1);
    ML_LED_2(LED_2);
    ML_LED_3(LED_3);
    ML_LED_4(LED_4);
    ML_LED_5(LED_5);
    ML_LED_6(LED_6);
    return state;
}

void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.rgb_matrix_enable = true;
    user_config.led_level = true;
    user_config.led_level_res = 0b11;
    eeconfig_update_user(user_config.raw);
}

void leader_start_user(void) {}
void leader_end_user(void) {
#ifdef AUDIO_ENABLE
    if (leader_sequence_one_key(KC_M)) {
        PLAY_SONG(foo);
    }
#endif
}
