# 🌞 Dual-Axis Arduino Solar Tracker

A more accurate dual-axis solar tracker using **4 LDRs** and **2 servo motors** to follow the sun throughout the day (left–right and up–down).

---

## 🧰 Components

- Arduino Uno
- 4x LDRs
- 4x 10kΩ resistors
- 2x Servo motors (SG90 or MG996R)
- Breadboard & jumper wires
- Mount structure (cardboard, 3D printed, or wood)

---

## ⚙️ Pin Connections

| Component       | Arduino Pin |
|----------------|-------------|
| LDR Top Left   | A0          |
| LDR Top Right  | A1          |
| LDR Bottom Left| A2          |
| LDR Bottom Right| A3         |
| Servo (Azimuth)| D9          |
| Servo (Elevation)| D10       |

- Each LDR is connected in a voltage divider with a 10kΩ resistor.
- Servo motors are powered from 5V (external supply recommended for MG996R).
- Ground all components to Arduino GND.

---

## 📐 How It Works

The tracker compares light values:
- Left vs Right → Horizontal movement (East–West)
- Top vs Bottom → Vertical movement (Elevation)

Servos adjust panel orientation based on which side receives more light.

---

## 🖼️ Circuit Diagram

![Diagram](https://github.com/abdellahaarab/-Dual-Axis-Solar-Tracker-using-Arduino/blob/main/assets/solar_sun_tracker.png?raw=true)

📌 Recommended layout:

```
TL  ---- TR
  \    /
   [ Solar Panel ]
  /    \
BL  ---- BR
```

---

## 📜 Arduino Code

See [`solar_tracker_dual_axis.ino`](./solar_tracker_dual_axis.ino)

---

## 🚀 Future Improvements

- Add GPS or RTC for time-based solar angles
- Data logging (SD card or cloud)
- Solar-powered version
- Automatic reset at night

---

## 🧪 Test Tips

- Use a flashlight to simulate sun movement
- Test servos separately before full assembly
- Make sure LDRs are equally spaced and aligned

---

## 📄 License

MIT License – Free to use, modify, and share
