# TohHongXiang's GMMK Pro Keymaps

- Rotary knob enabled
- LED lights on the side show volume level (The higher the volume, the brighter the side LEDs, and the more side LEDs are activated)
- LED lights on the side also indicate caps lock status (Green sides = caps lock ON)
- Toggling layer with FN key changes RGB mode
- `Fn` + `N` toggles NKRO

# Flashing

```
qmk compile -kb gmmk/pro -km tohhongxiang123
```

Then open the compiled `.bin` file in QMK Toolbox, and press `Fn` + `\` to toggle boot mode

# TODO

- Light up LED for a key only if key has a binding on that layer

# Resources to Read

- https://www.pcgamingrace.com/blogs/news/step-by-step-guide-to-configuring-your-gmmk-pro-using-qmk
- https://www.reddit.com/r/glorious/comments/okrbjg/peeps_qmk_and_via_rgb_guide_only_for_ansi/