LTO_ENABLE = yes
CONVERT_TO = elite_pi

SRC += features/tap_dance.c

OLED_ENABLE = no
# OLED_DRIVER = SSD1306

MOUSEKEY_ENABLE = yes
AUTO_SHIFT_ENABLE = no
AUTO_SHIFT_MODIFIERS = no
COMBO_ENABLE = no
LEADER_ENABLE = no
TAP_DANCE_ENABLE = yes

# Require hex input which prevents OPT left/right shortcuts.
UNICODE_ENABLE = no

SEND_STRING_ENABLE = yes
