# ErgoDox firmware

## Quickstart

```bash
# Install needed tools
brew install osx-cross/avr/avr-libc # this might take forever
brew install teensy_loader_cli
brew cask install teensy

# Build the hex-file
cd keyboard/ergodox_ez/
make clean
make KEYMAP=alcesleo
# make teensy
```

## References

Quick links to the relevant doc files in this repository:

- [Basic keycodes](tmk_core/doc/keycode.txt)
- [Layers and more advanced keys](tmk_core/doc/keymap.md)
- [Building the firmware](tmk_core/doc/build.md)
- [Misc](QMK_README.md)
