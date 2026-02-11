/*
  Arduino Real-Time Production Monitoring System
  
  Author: Tejas Kamp
  Organization: Lancer Worldwide
  Location: San Antonio, TX
  Date: 2024
  
  Description:
  This system monitors production line cadence using a PIR motion sensor to detect
  operator activity. It provides real-time visual and audible alerts when production
  falls behind schedule, enabling immediate intervention to maintain efficiency.
  
  Business Impact:
  - Improved on-time part release from 68% to 94% (+26%)
  - Increased production efficiency by 22%
  - Raised monthly production value from $2.1M to $3.8M
  - Achieved results within 30 days of deployment
  
  Hardware Requirements:
  - Arduino MEGA 2560
  - PIR Motion Sensor
  - DS3231 Real-Time Clock Module
  - Red, Green, Yellow LEDs (5mm)
  - Piezo Buzzer
  - Push Button (Reset)
  - 220Ω Resistors (x4)
  
  Pin Configuration:
  - Pin 2:  PIR Motion Sensor (INPUT)
  - Pin 4:  Yellow LED (OUTPUT - Behind Schedule Warning)
  - Pin 5:  Buzzer (OUTPUT - Audible Alert)
  - Pin 10: Reset Button (INPUT)
  - Pin 22: Green LED (OUTPUT - On Schedule)
  - Pin 31: Red LED (OUTPUT - Waiting for Activity)
  
  System Logic:
  1. Red LED ON: System waiting for operator activity (standby mode)
  2. Motion detected within timeout → Green LED ON (on schedule)
  3. No motion within timeout → Yellow LED + Buzzer (alert - behind schedule)
  4. Reset button acknowledges alert and returns to monitoring
  
  License: MIT License
*/

// ============================================================================
// PIN DEFINITIONS
// ============================================================================

#define RED_LED 31          // Red LED - Waiting for activity
#define GREEN_LED 22        // Green LED - On schedule, activity detected
#define YELLOW_LED 4        // Yellow LED - Behind schedule warning
#define BUZZER 5            // Piezo buzzer - Audible alert
#define SENSOR 2            // PIR motion sensor - Detects operator activity
#define RESET_BUTTON 10     // Push button - Reset/acknowledge alerts

// ============================================================================
// CONFIGURATION PARAMETERS
// ============================================================================

// Timeout period for operator activity detection (milliseconds)
// Default: 10 seconds - Adjust based on your production cycle time
unsigned long sensorTimeout = 10000;  // 10,000 ms = 10 seconds

// System state tracking
bool sensorActivated = false;         // Tracks if current cycle is complete
unsigned long cycleStartTime = 0;     // Timestamp for cycle tracking
unsigned long totalCycles = 0;        // Production cycle counter
unsigned long onTimeCycles = 0;       // Successful (on-time) cycle counter

// Serial communication baud rate
#define SERIAL_BAUD 115200

// ============================================================================
// SETUP FUNCTION - Runs once at startup
// ============================================================================

void setup() {
  // Initialize serial communication for debugging and data logging
  Serial.begin(SERIAL_BAUD);
  Serial.println("==============================================");
  Serial.println("Arduino Production Monitoring System");
  Serial.println("Lancer Worldwide - San Antonio, TX");
  Serial.println("==============================================");
  Serial.println("System initializing...");
  
  // Configure pin modes
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(SENSOR, INPUT);
  pinMode(RESET_BUTTON, INPUT);
  
  // Set initial state - Red LED ON (waiting for activity)
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(BUZZER, LOW);
  
  // Allow PIR sensor to stabilize (typical warm-up: 30-60 seconds)
  Serial.println("Waiting for PIR sensor to stabilize...");
  delay(2000);  // 2-second delay for initial stabilization
  
  Serial.println("System ready!");
  Serial.println("Monitoring for operator activity...");
  Serial.print("Timeout period: ");
  Serial.print(sensorTimeout / 1000);
  Serial.println(" seconds");
  Serial.println("==============================================\n");
  
  // Record cycle start time
  cycleStartTime = millis();
}

// ============================================================================
// MAIN LOOP - Continuous monitoring and control
// ============================================================================

void loop() {
  // If current cycle is already complete, skip monitoring
  if (sensorActivated) {
    return;
  }
  
  // ===== MONITORING PHASE =====
  // Monitor for motion within the timeout window
  unsigned long startTime = millis();
  
  Serial.println("New cycle started - monitoring for activity...");
  
  while (millis() - startTime < sensorTimeout) {
    // Check if motion is detected
    if (digitalRead(SENSOR) == HIGH) {
      // Motion detected - Operator is working on schedule!
      
      // Calculate cycle time
      unsigned long cycleTime = millis() - cycleStartTime;
      
      // Update status LEDs
      digitalWrite(RED_LED, LOW);      // Turn off red (waiting) LED
      digitalWrite(GREEN_LED, HIGH);   // Turn on green (success) LED
      
      // Update counters and statistics
      sensorActivated = true;
      totalCycles++;
      onTimeCycles++;
      
      // Log success to serial monitor
      Serial.println("✓ ACTIVITY DETECTED - ON SCHEDULE");
      Serial.print("  Cycle time: ");
      Serial.print(cycleTime / 1000.0, 2);
      Serial.println(" seconds");
      Serial.print("  On-time rate: ");
      Serial.print((float)onTimeCycles / totalCycles * 100, 1);
      Serial.println("%");
      Serial.println("  Status: GREEN - Production flowing smoothly\n");
      
      // Exit monitoring loop
      return;
    }
    
    // Small delay to prevent excessive CPU usage
    delay(50);
  }
  
  // ===== ALERT PHASE =====
  // Timeout expired - No motion detected within window
  // Operator may be delayed or issue with production flow
  
  Serial.println("⚠ TIMEOUT EXPIRED - NO ACTIVITY DETECTED");
  Serial.println("  Status: YELLOW + BUZZER - Behind schedule alert");
  Serial.println("  Action required: Check operator status");
  
  // Activate alert indicators
  digitalWrite(YELLOW_LED, HIGH);   // Turn on yellow warning LED
  digitalWrite(BUZZER, HIGH);       // Activate audible buzzer
  
  // Update statistics
  totalCycles++;
  
  Serial.print("  On-time rate: ");
  Serial.print((float)onTimeCycles / totalCycles * 100, 1);
  Serial.println("%\n");
  
  // ===== WAITING FOR RESOLUTION =====
  // Wait for either:
  // 1. Operator activity (motion detected), OR
  // 2. Supervisor acknowledgment (reset button pressed)
  
  Serial.println("Waiting for resolution:");
  Serial.println("  - Motion detection (operator resumed work), OR");
  Serial.println("  - Reset button press (supervisor acknowledgment)");
  
  while (digitalRead(SENSOR) == LOW && digitalRead(RESET_BUTTON) == LOW) {
    // Continuous monitoring loop
    // System stays in alert state until one condition is met
    delay(50);  // Small delay to prevent CPU overuse
  }
  
  // ===== RESOLUTION DETECTED =====
  // Either motion detected or reset button pressed
  
  if (digitalRead(SENSOR) == HIGH) {
    Serial.println("✓ Motion detected - Operator activity resumed");
  } else {
    Serial.println("✓ Reset button pressed - Alert acknowledged by supervisor");
  }
  
  // Clear alert state
  digitalWrite(YELLOW_LED, LOW);    // Turn off yellow warning LED
  digitalWrite(BUZZER, LOW);        // Turn off buzzer
  digitalWrite(RED_LED, LOW);       // Turn off red waiting LED
  digitalWrite(GREEN_LED, HIGH);    // Turn on green success LED
  
  // Mark cycle as complete
  sensorActivated = true;
  
  // Reset for next cycle
  cycleStartTime = millis();
  
  Serial.println("Alert cleared - Resuming normal monitoring");
  Serial.println("==============================================\n");
  
  // Optional: Add delay before starting next cycle
  // Uncomment if needed to prevent immediate re-triggering
  // delay(2000);  // 2-second pause before next cycle
}

// ============================================================================
// OPTIONAL ENHANCEMENT FUNCTIONS
// ============================================================================

/*
  Additional features that can be implemented:

  1. DATA LOGGING TO SD CARD:
     - Log cycle times, alerts, and efficiency metrics
     - Enable historical performance analysis
     
  2. WIRELESS CONNECTIVITY:
     - Send data to Power BI dashboard via WiFi/Bluetooth
     - Real-time remote monitoring capabilities
     
  3. ADJUSTABLE TIMEOUT:
     - Add potentiometer to adjust timeout on-the-fly
     - Adapt to different production line speeds
     
  4. ADVANCED ALERTS:
     - Progressive alert levels (warning → critical)
     - Different buzzer patterns for different issues
     - Integration with facility management system
     
  5. PERFORMANCE ANALYTICS:
     - Calculate real-time OEE (Overall Equipment Effectiveness)
     - Trend analysis and predictive alerts
     - Shift-based performance tracking
*/

// ============================================================================
// END OF CODE
// ============================================================================
