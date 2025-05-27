# 🔧 STM32 Bare-Metal Embedded Projects – STM32F407 Discovery

A hands-on series of bare-metal embedded projects using the **STM32F407 Discovery Board**, demonstrating low-level register manipulation, memory-mapped IO, and embedded C fundamentals.

> 🚀 *Built from scratch with no HAL/LL libraries – just raw memory access and deep hardware understanding.*

---

## 📅 Project Timeline

Each day represents a foundational step toward mastering embedded systems and microcontroller programming.

---

### ✅ Day 1: Hello World – SWV Console Output

**Objective:** Compile and run a "Hello World" program on STM32 and verify output via **Serial Wire Viewer (SWV)**.

- 💬 Printed "Hello World" to the **SWV ITM Console**
- 🔧 Verified setup with debugger
- 🧠 Learned to initialize `Core Debug` and enable SWO for output

📷 *SWV Output Sample (if available)*

---

### ✅ Day 2: sizeof() Operation – Data Type Sizes

**Objective:** Use the `sizeof()` operator to determine memory usage of C data types on STM32.

- 🧪 Explored platform-specific sizes of:
  - `char`, `short`, `int`, `long`, `float`, `double`
- 🧠 Understood memory alignment and word boundaries on ARM Cortex-M4
- 🛠️ Output visualized on **SWV Console**

---

### ✅ Day 3: LED On (LD4 - Green LED) – Register-Level Programming

**Objective:** Turn on **LD4 (Green LED - PD12)** using **direct register access**.

#### 🔬 Step-by-step Bitwise Operations:

1. **Enable Clock to GPIOD**
   - Set bit 3 in `RCC_AHB1ENR` register:
     ```c
     RCC->AHB1ENR |= (1 << 3); // Enable GPIOD
     ```

2. **Configure PD12 as Output**
   - Modify `MODER` register to set mode bits [25:24] = `01`:
     ```c
     GPIOD->MODER &= ~(0b11 << 24); // Clear bits
     GPIOD->MODER |=  (0b01 << 24); // Set to output mode
     ```

3. **Set PD12 High (Turn ON LED)**
   - Write to `ODR` register:
     ```c
     GPIOD->ODR |= (1 << 12); // Set pin high
     ```

✅ **Result:** LD4 turned ON!  
🧠 **Key Concepts:** Clock gating, GPIO mode config, memory-mapped IO

---

✅ Day 4: Traffic Light Control System Simulation (FSM-Based) – HAL Programming
Objective: Simulate a basic Traffic Light Control System using a Finite State Machine (FSM) and STM32 HAL APIs on the STM32F407 microcontroller.

🚦 System Overview:
This project simulates a simple 3-light traffic signal using LEDs:

- Green LED (PD12) – Go

- Orange LED (PD13) – Caution

- Red LED (PD14) – Stop

The system cycles through the standard traffic light phases using an FSM approach.

🧠 FSM States:
- State Name	Active LED	Duration
- STATE_GREEN	Green	5 sec
- STATE_YELLOW	Orange	2 sec
- STATE_RED	Red	5 sec

🛠️ Step-by-Step Implementation (Using HAL):
1. Initialize HAL and GPIOs
- Use STM32CubeMX to:
- Enable GPIOD (Clock)
- Configure PD12, PD13, PD14 as Output
- Generate initialization code

2. Define FSM States
3. ontrol LEDs Based on State
4. Main FSM Logic (in while(1))
5. Get Next State & Duration

✅ Result:
- The system automatically cycles through traffic light phases with correct delays using HAL APIs and a clean FSM structure.

📚 Key Concepts:
- Finite State Machine (FSM)
- HAL GPIO Control
- Modular Design for Expandability
  
🔜 Next Up (Day 5 Preview):
Add Pedestrian Button to request safe crossing

## 💻 Tools Used

- 🔧 **IDE:** STM32CubeIDE / Keil / VS Code with OpenOCD
- 🧠 **Language:** Embedded C (Bare Metal)
- 🧲 **Target MCU:** STM32F407VG (ARM Cortex-M4)
- 🐞 **Debugging:** SWD + SWV Console

---

## 📈 Skills Demonstrated

- Low-level embedded programming
- Register-level peripheral control
- GPIO configuration
- Debugging via SWV / ITM
- Efficient C programming for microcontrollers
- HAL

---
