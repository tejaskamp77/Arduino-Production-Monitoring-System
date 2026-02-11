# Setup & Installation Guide
## Arduino Real-Time Production Monitoring System

---

## 📋 Table of Contents

1. [Pre-Installation Checklist](#pre-installation-checklist)
2. [Hardware Assembly](#hardware-assembly)
3. [Software Installation](#software-installation)
4. [System Configuration](#system-configuration)
5. [Testing & Calibration](#testing--calibration)
6. [Deployment](#deployment)
7. [Troubleshooting](#troubleshooting)

---

## Pre-Installation Checklist

### Required Components
- ✅ Arduino MEGA 2560
- ✅ PIR Motion Sensor (HC-SR501)
- ✅ DS3231 Real-Time Clock Module
- ✅ 3x LEDs (Red, Green, Yellow - 5mm)
- ✅ Piezo Buzzer (5V)
- ✅ Push Button (Momentary)
- ✅ 4x 220Ω Resistors
- ✅ Breadboard or custom PCB
- ✅ Jumper wires (M-M)
- ✅ USB cable (Type-B)
- ✅ 5V DC power supply (2A minimum)

### Required Software
- ✅ Arduino IDE (1.8.19 or higher)
- ✅ USB drivers for Arduino MEGA
- ✅ RTClib library (by Adafruit)

### Tools Needed
- ✅ Computer with USB port
- ✅ Small Phillips screwdriver (for mounting)
- ✅ Wire strippers (optional, for custom wiring)
- ✅ Multimeter (optional, for testing)

---

## Hardware Assembly

### Step 1: Prepare the Breadboard

1. **Place Arduino MEGA** on breadboard or mounting surface
2. **Ensure clearance** for all pin connections
3. **Verify power connections** - do not connect power yet

### Step 2: Connect PIR Motion Sensor

```
PIR Sensor Connections:
┌─────────────────┐
│  PIR Sensor     │
│  [HC-SR501]     │
└─────────────────┘
   │    │    │
  VCC  OUT  GND
   │    │    │
   │    │    └──────→ Arduino GND
   │    └───────────→ Arduino Pin 2
   └────────────────→ Arduino 5V
```

**Instructions:**
1. Connect **VCC** (red wire) to Arduino **5V** pin
2. Connect **GND** (black wire) to Arduino **GND** pin
3. Connect **OUT** (yellow wire) to Arduino **Pin 2**

**Important:** Adjust PIR sensitivity potentiometers if needed
- Left pot: Sensitivity (distance)
- Right pot: Time delay (set to minimum)

### Step 3: Connect RTC Module (DS3231)

```
RTC Module Connections:
┌─────────────────┐
│  DS3231 RTC     │
└─────────────────┘
   │  │  │  │
  VCC SDA SCL GND
   │  │  │  │
   │  │  │  └────────→ Arduino GND
   │  │  └───────────→ Arduino Pin 21 (SCL)
   │  └──────────────→ Arduino Pin 20 (SDA)
   └─────────────────→ Arduino 5V
```

**Instructions:**
1. Connect **VCC** to Arduino **5V**
2. Connect **GND** to Arduino **GND**
3. Connect **SDA** to Arduino **Pin 20** (I2C Data)
4. Connect **SCL** to Arduino **Pin 21** (I2C Clock)

### Step 4: Connect LEDs with Current-Limiting Resistors

Each LED requires a 220Ω resistor in series:

```
LED Connection Pattern (repeat for each LED):

Arduino Pin ──→ 220Ω Resistor ──→ LED Anode (+) ──→ LED Cathode (-) ──→ GND

Pin 31 (Red LED):
Pin 31 ──→ 220Ω ──→ Red LED ──→ GND

Pin 22 (Green LED):
Pin 22 ──→ 220Ω ──→ Green LED ──→ GND

Pin 4 (Yellow LED):
Pin 4 ──→ 220Ω ──→ Yellow LED ──→ GND
```

**Instructions:**
1. **Red LED:** Pin 31 → 220Ω resistor → LED long leg (+) → LED short leg (-) → GND
2. **Green LED:** Pin 22 → 220Ω resistor → LED long leg (+) → LED short leg (-) → GND
3. **Yellow LED:** Pin 4 → 220Ω resistor → LED long leg (+) → LED short leg (-) → GND

**LED Polarity:**
- **Long leg** = Anode (+) = connects to resistor
- **Short leg** = Cathode (-) = connects to GND

### Step 5: Connect Buzzer

```
Buzzer Connection:
┌─────────────┐
│   Buzzer    │
│   [5V]      │
└─────────────┘
     │   │
    (+) (-)
     │   │
     │   └──────────→ Arduino GND
     └──────────────→ Arduino Pin 5
```

**Instructions:**
1. Connect buzzer **positive (+)** to Arduino **Pin 5**
2. Connect buzzer **negative (-)** to Arduino **GND**

**Note:** Use active 5V buzzer (no additional circuit needed)

### Step 6: Connect Reset Button

```
Reset Button Connection:
┌───────────┐
│  Button   │
└───────────┘
    │   │
    │   └──────────→ Arduino GND
    └──────────────→ Arduino Pin 10
```

**Instructions:**
1. Connect one button terminal to Arduino **Pin 10**
2. Connect other button terminal to Arduino **GND**

**Note:** Internal pull-up resistor handles logic (no external resistor needed)

### Step 7: Final Power Connections

```
Power Distribution:
┌────────────────┐
│ 5V Power Supply│
└────────────────┘
      │    │
     (+)  (-)
      │    │
      │    └──────→ Arduino GND (common ground)
      └───────────→ Arduino VIN or 5V pin
```

**Power Options:**
- **Option 1:** USB power during testing (500mA limit)
- **Option 2:** External 5V adapter via barrel jack (2A recommended)
- **Option 3:** 9-12V adapter via VIN pin (onboard regulator)

---

## Software Installation

### Step 1: Install Arduino IDE

1. **Download:** Visit [arduino.cc/software](https://www.arduino.cc/software)
2. **Install:** Run installer for your operating system
3. **Launch:** Open Arduino IDE

### Step 2: Install Required Libraries

**Method 1: Library Manager (Recommended)**
1. Open Arduino IDE
2. Go to **Sketch** → **Include Library** → **Manage Libraries**
3. Search for "**RTClib**"
4. Click **Install** on "RTClib by Adafruit"
5. Wait for installation to complete

**Method 2: Manual Installation**
1. Download RTClib from [GitHub](https://github.com/adafruit/RTClib)
2. Extract ZIP file
3. Copy to Arduino libraries folder:
   - Windows: `Documents\Arduino\libraries\`
   - Mac: `~/Documents/Arduino/libraries/`
   - Linux: `~/Arduino/libraries/`

### Step 3: Load the Code

1. **Clone or download** this repository
2. Open `production_monitor.ino` in Arduino IDE
3. **Verify code** compiles (click checkmark ✓)

### Step 4: Configure Arduino Board

1. **Connect Arduino** to computer via USB
2. In Arduino IDE:
   - **Tools** → **Board** → **Arduino AVR Boards** → **Arduino Mega or Mega 2560**
   - **Tools** → **Port** → Select your Arduino's COM port (e.g., COM3, /dev/ttyUSB0)
   - **Tools** → **Programmer** → **AVRISP mkII**

### Step 5: Upload Code

1. Click **Upload** button (→) in Arduino IDE
2. Wait for compilation and upload
3. Look for "**Done uploading**" message
4. Red LED should turn ON after upload completes

---

## System Configuration

### Adjust Timeout Period

Default timeout is **10 seconds**. To adjust:

```cpp
// In production_monitor.ino, line ~53:
unsigned long sensorTimeout = 10000;  // 10,000 ms = 10 seconds

// Examples:
unsigned long sensorTimeout = 5000;   // 5 seconds (faster pace)
unsigned long sensorTimeout = 15000;  // 15 seconds (slower pace)
unsigned long sensorTimeout = 20000;  // 20 seconds (complex tasks)
```

**Re-upload code** after making changes.

### Calibrate PIR Sensor

The PIR sensor has two adjustable potentiometers:

**Sensitivity Adjustment (Left Pot):**
- Clockwise: Increase detection range (up to 7m)
- Counter-clockwise: Decrease range (down to 3m)

**Time Delay (Right Pot):**
- Set to **minimum** (fully counter-clockwise)
- Arduino code handles timing logic

**Testing Calibration:**
1. Power on system
2. Wave hand at different distances
3. Adjust sensitivity until desired range achieved
4. Allow 60 seconds for PIR to stabilize after adjustments

---

## Testing & Calibration

### Step 1: Initial Power-On Test

1. **Connect power** to Arduino
2. **Verify:**
   - ✅ Red LED lights up immediately
   - ✅ No other LEDs are lit
   - ✅ No buzzer sound

**If red LED doesn't light:** Check power connections and LED polarity

### Step 2: Serial Monitor Test

1. **Open Serial Monitor:**
   - **Tools** → **Serial Monitor**
   - Set baud rate to **115200**

2. **Expected output:**
   ```
   ==============================================
   Arduino Production Monitoring System
   Lancer Worldwide - San Antonio, TX
   ==============================================
   System initializing...
   Waiting for PIR sensor to stabilize...
   System ready!
   Monitoring for operator activity...
   Timeout period: 10 seconds
   ==============================================
   
   New cycle started - monitoring for activity...
   ```

### Step 3: Motion Detection Test

1. **Trigger PIR sensor** by waving hand in front
2. **Expected behavior:**
   - Red LED turns OFF
   - Green LED turns ON
   - Serial Monitor shows: "✓ ACTIVITY DETECTED - ON SCHEDULE"

3. **Verify timing:**
   - Motion must occur within 10 seconds
   - Check reported cycle time in serial monitor

### Step 4: Timeout Alert Test

1. **Do NOT trigger sensor** for 10+ seconds
2. **Expected behavior:**
   - Yellow LED turns ON
   - Buzzer sounds
   - Serial Monitor shows: "⚠ TIMEOUT EXPIRED"

3. **Verify alert state:**
   - Yellow LED remains ON
   - Buzzer continues until reset

### Step 5: Reset Button Test

1. **While alert is active**, press reset button
2. **Expected behavior:**
   - Yellow LED turns OFF
   - Buzzer stops
   - Green LED turns ON
   - Serial Monitor shows: "✓ Reset button pressed"

### Step 6: Full Cycle Test

Run through complete production cycle simulation:

1. **Start:** System powers on (Red LED)
2. **Trigger within timeout:** Motion detected (Green LED)
3. **Reset system** (press reset or power cycle)
4. **Allow timeout:** No motion for 10+ seconds (Yellow + Buzzer)
5. **Acknowledge:** Press reset button (Green LED)

**All steps should work smoothly without errors**

---

## Deployment

### Site Preparation

**Location Selection:**
- Clear line-of-sight to operator work zone
- 3-7 meter distance from operator
- Avoid heat sources (HVAC vents, heaters)
- Minimize background movement (fans, conveyors)
- Ensure LED visibility for operators and supervisors

**Mounting Considerations:**
- Secure enclosure to wall or pole
- Angle PIR sensor toward work area
- Position LEDs at eye level for visibility
- Weatherproof if outdoors or high-moisture area

### Installation Steps

1. **Mount enclosure** at selected location
2. **Connect power supply** (industrial 5V, 2A adapter)
3. **Route cables** neatly and securely
4. **Test all functions** before going live
5. **Document installation:**
   - Location
   - PIR sensor settings
   - Timeout configuration
   - Date of installation

### Operator Training

**Training Duration:** 15 minutes per operator

**Key Points to Cover:**
1. **Red LED** = System waiting, no action needed
2. **Green LED** = Working on schedule, keep pace
3. **Yellow + Buzzer** = Behind schedule, speed up or call supervisor
4. **Reset Button** = For supervisor use only (acknowledge alerts)

**Training Materials:**
- Quick reference card (laminated)
- Visual diagram of LED meanings
- Contact information for technical support

### Integration with Dashboard

If connecting to Power BI or Excel dashboard:

1. **Serial Data Logging:**
   - Connect Arduino via USB to data collection PC
   - Use serial logging software (Python script, PLX-DAQ, etc.)
   - Parse serial output for metrics

2. **Data to Collect:**
   - Cycle times
   - On-time rate
   - Alert frequency
   - Daily/shift statistics

3. **Dashboard Metrics:**
   - Real-time on-time %
   - Hourly trend charts
   - Alert heat maps
   - Efficiency tracking

---

## Troubleshooting

### Issue: Red LED Doesn't Turn On

**Possible Causes:**
- No power to Arduino
- LED connected backward (wrong polarity)
- Damaged LED

**Solutions:**
1. Check power supply connection
2. Verify USB cable is connected
3. Test LED polarity (swap connections)
4. Replace LED if damaged

---

### Issue: Green LED Doesn't Activate

**Possible Causes:**
- PIR sensor not detecting motion
- Sensor not warmed up yet
- Wrong pin connection
- Sensor out of range

**Solutions:**
1. Wait 60 seconds for PIR stabilization
2. Check Pin 2 connection to sensor
3. Move closer to sensor (within 3-7m)
4. Adjust PIR sensitivity potentiometer
5. Verify sensor with Serial Monitor output

---

### Issue: Buzzer Continuously Sounds

**Possible Causes:**
- Sensor triggering immediately
- Code stuck in alert loop
- Faulty reset button

**Solutions:**
1. Press reset button to clear alert
2. Power cycle the system
3. Check for sensor obstructions
4. Verify reset button connection (Pin 10)
5. Re-upload code to Arduino

---

### Issue: No Serial Monitor Output

**Possible Causes:**
- Wrong baud rate selected
- Wrong COM port selected
- USB driver issues

**Solutions:**
1. Set baud rate to **115200**
2. Select correct COM port (Tools → Port)
3. Reinstall Arduino drivers
4. Try different USB cable
5. Test with different USB port

---

### Issue: Intermittent False Alerts

**Possible Causes:**
- Sensor picking up background movement
- Heat sources causing false triggers
- Sensor too sensitive

**Solutions:**
1. Reduce PIR sensitivity (adjust pot)
2. Reposition sensor away from heat sources
3. Add physical shielding to narrow detection cone
4. Increase timeout period in code

---

## Maintenance Schedule

### Daily
- Visual inspection of LED status
- Verify buzzer functionality

### Weekly
- Check all connections for looseness
- Clean PIR sensor lens
- Verify system accuracy vs. actual production

### Monthly
- Full system test (all modes)
- Review performance data
- Update documentation if needed

### Quarterly
- Replace CR2032 battery in RTC module
- Deep clean all components
- Recalibrate PIR sensor if needed

### Annually
- Full system audit
- Replace worn components (buzzer, button)
- Software updates if available

---

## Support Resources

**Technical Questions:**
- Email: txk77.uta@gmail.com
- LinkedIn: [linkedin.com/in/tejaskamp](https://www.linkedin.com/in/tejaskamp)

**Documentation:**
- README.md - Project overview and business impact
- Bill of Materials - Component specifications
- Production Monitor Code - Detailed code comments

**Community:**
- GitHub Issues - Report bugs or request features
- Arduino Forums - General Arduino support

---

*Last Updated: February 2026*
*Guide Version: 1.0*
