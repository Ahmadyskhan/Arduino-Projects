# Traffic Lights (Two-Way Intersection Controller)

My first proper Arduino build — a two-way traffic light setup for a North-South / East-West intersection, built on an Arduino Uno. Started simple on purpose since this was meant to nail the fundamentals (digital outputs, timing, sequencing) before adding any sensor complexity.

## Overview

- **North-South**: the tall light housing
- **East-West**: the short light housing (it's short purely because I ran out of filament mid-print, not a design choice — still works exactly the same)

The two directions run opposite phases, so there's always at least one direction stopped while the other has right of way, plus a short all-red "clearance" gap between switches so both directions are never green (or transitioning) at the same time.

## 3D Printed Housing

- **Model**: [Traffic Lights (Ampel) for Arduino/ESP32](https://www.printables.com/model/864750-traffic-lights-ampel-for-arduino-esp32-co)
- **Printer**: RS PLUS 3D Printer (Ideawerk)
- **Filament**: PLA, Natural, 1.75mm

## Components

| Component | Quantity |
|---|---|
| Arduino Uno (or similar board) | 1 |
| Breadboard | 1 |
| Red LEDs | 2 |
| Yellow LEDs | 2 |
| Green LEDs | 2 |
| 220Ω resistors | 6 |
| Male-to-male jumper wires | 13 (only 7 actually needed, just used what I had) |
| Male-to-female jumper wires | 12 |
| Power supply | 1 |
| Arduino IDE | — |

## Wiring / Pin Mapping

Each LED runs through a 220Ω resistor to a digital output pin, cathode side tied to ground on the breadboard rail.

| Signal | Arduino Pin |
|---|---|
| NS Red | 10 |
| NS Yellow | 9 |
| NS Green | 8 |
| EW Red | 13 |
| EW Yellow | 12 |
| EW Green | 11 |

## How It Works

The sketch runs a fixed 6-phase loop using `delay()` to time each phase — no sensors, no inputs, just a straight sequential cycle:

1. **NS Green / EW Red** — 5s
2. **NS Yellow / EW Red** — 2s
3. **All Red** (clearance gap) — 1s
4. **NS Red / EW Green** — 5s
5. **NS Red / EW Yellow** — 2s
6. **All Red** (clearance gap) — 1s

...then it loops back to phase 1. The all-red phases exist so there's a buffer where nobody has a green light while the intersection "switches over," same as a real traffic light.

I actually started out writing this with a `millis()`-based non-blocking state machine, which is the more "correct" way to do it if you ever want to read a button or sensor at the same time (since `millis()` doesn't freeze the whole program the way `delay()` does). For this version I simplified it back down to plain `delay()` calls since there's nothing else the Arduino needs to be doing — it's just running the fixed sequence. If I add a pedestrian button or a sensor later, I'll need to bring the `millis()` version back, otherwise the sketch would be too busy sitting in a `delay()` to notice a button press.

## Future Improvements

- [ ] Rework as a `millis()`-based state machine so it's non-blocking
- [ ] Add a pedestrian crossing button
- [ ] Add a vehicle sensor (IR or ultrasonic) for demand-based switching instead of a fixed timer

## Build Photos

Are under [assets](./assets)


## License

See the root [LICENSE](../LICENSE) file.
