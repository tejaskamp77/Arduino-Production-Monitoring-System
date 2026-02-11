# Bill of Materials (BOM)
## Arduino Real-Time Production Monitoring System

### Core Components

| Item | Part Description | Part Number / Spec | Quantity | Unit Price (USD) | Total Price (USD) | Supplier | Notes |
|------|------------------|-------------------|----------|------------------|-------------------|----------|-------|
| 1 | Arduino MEGA 2560 | ATmega2560-16AU | 1 | $45.00 | $45.00 | Arduino / Amazon | Main microcontroller board |
| 2 | PIR Motion Sensor | HC-SR501 | 1 | $3.00 | $3.00 | Amazon / AliExpress | 3-7m detection range, 120° angle |
| 3 | Real-Time Clock Module | DS3231 RTC | 1 | $5.00 | $5.00 | Adafruit / Amazon | High-precision timekeeping |
| 4 | Red LED | 5mm, 2V, 20mA | 1 | $0.10 | $0.10 | Digi-Key / Mouser | Standby indicator |
| 5 | Green LED | 5mm, 2V, 20mA | 1 | $0.10 | $0.10 | Digi-Key / Mouser | Success indicator |
| 6 | Yellow LED | 5mm, 2V, 20mA | 1 | $0.10 | $0.10 | Digi-Key / Mouser | Warning indicator |
| 7 | Piezo Buzzer | 5V Active Buzzer | 1 | $2.00 | $2.00 | Amazon / Digi-Key | Audible alert system |
| 8 | Push Button | Momentary Switch, SPST | 1 | $0.50 | $0.50 | Digi-Key / Mouser | Reset/acknowledge button |
| 9 | Resistors | 220Ω, 1/4W, 5% | 4 | $0.05 | $0.20 | Digi-Key / Mouser | LED current limiting |
| 10 | Breadboard | 830 tie-points | 1 | $6.00 | $6.00 | Amazon / Adafruit | Prototyping (or custom PCB) |
| 11 | Jumper Wires | Male-to-Male, 22 AWG | 20 | $0.10 | $2.00 | Amazon / Adafruit | Circuit connections |
| 12 | USB Cable | USB Type-B, 6ft | 1 | $5.00 | $5.00 | Amazon / Monoprice | Programming and power |
| 13 | Power Supply | 5V DC, 2A Wall Adapter | 1 | $8.00 | $8.00 | Amazon / Adafruit | Industrial power source |
| 14 | Enclosure | Plastic Project Box | 1 | $12.00 | $12.00 | Amazon / Hammond | Weatherproof housing (optional) |

### **Total Component Cost: ~$89.00**

---

## Alternative Components (Cost Optimization)

For budget-conscious implementations or bulk ordering:

| Item | Alternative Part | Part Number | Unit Price (USD) | Savings | Notes |
|------|------------------|-------------|------------------|---------|-------|
| 1 | Arduino Compatible MEGA | CH340G Version | $15.00 | -$30.00 | Fully compatible, non-official |
| 2 | PIR Sensor (Bulk) | HC-SR501 (10-pack) | $1.50 each | -$1.50 | Bulk purchase discount |
| 10 | Custom PCB | Fabricated PCB | $25.00 | -$6.00 | Professional installation |

### **Optimized Total Cost: ~$60-70 per unit** (with bulk ordering)

---

## Tools Required (Not Included in BOM)

| Tool | Purpose | Notes |
|------|---------|-------|
| Soldering Iron | Component soldering (if using PCB) | 25W-60W recommended |
| Wire Strippers | Wire preparation | 22-18 AWG |
| Multimeter | Testing and troubleshooting | Basic voltage/continuity |
| Screwdrivers | Enclosure assembly | Phillips and flathead |
| Hot Glue Gun | Component mounting (optional) | Strain relief |

---

## Specifications

### Electrical Requirements
- **Operating Voltage:** 5V DC
- **Current Consumption:** 150mA average, 300mA peak
- **Power Supply:** Minimum 1A recommended for reliability

### Environmental Ratings
- **Operating Temperature:** 0°C to 50°C (32°F to 122°F)
- **Storage Temperature:** -20°C to 70°C (-4°F to 158°F)
- **Humidity:** 20% to 80% RH, non-condensing

### Physical Dimensions (with enclosure)
- **Width:** 120mm (4.7")
- **Height:** 80mm (3.1")
- **Depth:** 60mm (2.4")
- **Weight:** ~250g (8.8 oz) with components

---

## Procurement Notes

### Recommended Suppliers

**For Prototyping (Fast Shipping):**
- Amazon - Quick delivery, higher prices
- Adafruit - Quality components, maker-friendly
- SparkFun - Educational resources included

**For Production (Bulk Orders):**
- Digi-Key - Extensive inventory, same-day shipping
- Mouser - Technical support, reliable stock
- AliExpress - Low cost, longer shipping times

### Lead Times
- **Amazon/Local:** 1-2 days
- **Digi-Key/Mouser:** 2-5 days
- **AliExpress:** 2-4 weeks
- **Custom PCB Fabrication:** 1-2 weeks

---

## Assembly Estimates

### Time Requirements
- **Breadboard Prototype:** 2-3 hours
- **PCB Version (hand soldering):** 4-6 hours
- **PCB Version (reflow oven):** 1-2 hours
- **Testing and Calibration:** 1 hour
- **Enclosure Assembly:** 1 hour

### Skill Level
- **Beginner:** Breadboard version recommended
- **Intermediate:** Hand-soldered PCB version
- **Advanced:** Custom PCB with SMD components

---

## Scaling for Production

### Cost Analysis (Bulk Production)

| Quantity | Unit Cost | Total Cost | Cost Reduction |
|----------|-----------|------------|----------------|
| 1 unit | $89.00 | $89.00 | Baseline |
| 10 units | $65.00 | $650.00 | -27% |
| 50 units | $55.00 | $2,750.00 | -38% |
| 100 units | $48.00 | $4,800.00 | -46% |

*Assumes bulk component purchasing and custom PCB fabrication*

---

## Maintenance & Replacement Parts

| Part | Expected Lifespan | Replacement Cost | Notes |
|------|-------------------|------------------|-------|
| Arduino MEGA | 10+ years | $45.00 | Rarely fails |
| PIR Sensor | 5-7 years | $3.00 | Most common replacement |
| LEDs | 50,000+ hours | $0.30 | Rarely fails |
| Buzzer | 3-5 years | $2.00 | Mechanical wear |
| Push Button | 100,000+ cycles | $0.50 | Heavy use component |
| RTC Battery | 5-10 years | $2.00 | CR2032 coin cell |

### Recommended Spare Parts Kit
- PIR Sensors (x3)
- LEDs (x10 assorted)
- Push Buttons (x5)
- Buzzers (x2)
- 220Ω Resistors (x20)

**Spare Kit Cost: ~$25**

---

## Certifications & Compliance

For industrial deployment, consider:
- **CE Marking:** Required for European markets
- **FCC Compliance:** Required for US markets
- **RoHS Compliance:** Environmental regulations
- **UL Listing:** Optional safety certification

*Note: Basic prototype does not include certifications. Consult regulatory expert for commercial deployment.*

---

## Version History

| Version | Date | Changes | Cost Impact |
|---------|------|---------|-------------|
| 1.0 | Feb 2024 | Initial breadboard prototype | $89.00 |
| 1.1 | Mar 2024 | Added RTC module for logging | +$5.00 |
| 2.0 | Apr 2024 | Custom PCB version | -$6.00 |

---

## Contact for Bulk Orders

For institutional or bulk purchases:
- **Email:** txk77.uta@gmail.com
- **LinkedIn:** [linkedin.com/in/tejaskamp](https://www.linkedin.com/in/tejaskamp)

---

*Last Updated: February 2026*
*BOM Version: 2.0*
