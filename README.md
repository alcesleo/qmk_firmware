# ErgoDox firmware

## Quickstart

```bash
# Install needed tools
brew install osx-cross/avr/avr-libc # this might take forever
brew cask install teensy            # for loading the hex-file manually
brew install teensy_loader_cli      # for the make teensy command

# Build the hex-file, then load it with the teensy app
cd keyboard/ergodox_ez/
make clean
make KEYMAP=alcesleo

# Or load it automatically with teensy_loader_cli after building with:
make teensy KEYMAP=alcesleo
```

## References

Quick links to the relevant doc files in this repository:

- [Basic keycodes](tmk_core/doc/keycode.txt)
- [Layers and more advanced keys](tmk_core/doc/keymap.md)
- [Building the firmware](tmk_core/doc/build.md)
- [Misc](QMK_README.md)

## Template

```
[LAYER] = KEYMAP(
        // Left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                     KC_TRNS, KC_TRNS,
                                                              KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,

        // Right hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
```
