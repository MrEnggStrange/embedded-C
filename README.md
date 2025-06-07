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

### ✅ Day 4: Traffic Light Control System Simulation (FSM-Based) 

– HAL Programming
**Objective:**: Simulate a basic Traffic Light Control System using a Finite State Machine (FSM) and STM32 HAL APIs on the STM32F407 microcontroller.

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

#### 🛠️ Step-by-Step Implementation (Using HAL):
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

---
  
### ✅ Day 5: Traffic Light Control System Simulation (FSM-Based) modfication with Pedestrian Button Interrupt – HAL Programming
Objective: Simulate a basic Traffic Light Control System using a Finite State Machine (FSM) and STM32 HAL APIs on the STM32F407 microcontroller.
  
🚦 Pedestrian Button Interrupt (EXTI) — Extension Feature
- This enhancement adds pedestrian crossing functionality to the basic traffic light finite state machine (FSM) implemented on the STM32F407 Discovery Board.

🧠**Objective:**
- When a pedestrian presses the button (simulated using the built-in USER button on PA0):
- If the traffic light is GREEN:
- Transition to ORANGE → RED to stop traffic.
- Allow 4 seconds of pedestrian crossing time before resuming the cycle.
- This is done using external interrupt (EXTI) functionality on the GPIO pin.

🧰 Hardware Used
- Component	Pin Used	Purpose
- User Button	PA0	EXTI input for pedestrian interrupt

#### ✅ How to Implement
🔧 1. Configure EXTI on PA0 in STM32CubeMX
- Open your .ioc file in STM32CubeIDE.
- Click on PA0 (usually labeled USER_BUTTON).
- Set Mode to GPIO_EXTI0.
- Go to NVIC Settings and enable the EXTI line0 interrupt.

⚙️ 2. Regenerate Code
- Click Project -> Generate Code to update your code with the EXTI configuration.

🧑‍💻 3. Modify FSM Logic in main.c
- Declare the pedestrian flag globally:
- In your FSM switch statement (while(1) loop) write the logic code:

📲 4. Add the EXTI Interrupt Callback
- At the bottom of your main.c , add pedestrian Interrupt Callback function.

✅ Result:
- On button press during GREEN: triggers a controlled transition to RED.
- During RED: activates pedestrian crossing wait time (4 seconds).
- The FSM then continues as usual.

---

### ✅ Day 6: Bitwise Operators & Even-Odd Detection – Embedded Bit Manipulation
- **Objective:**  Master bitwise operators and bit manipulation techniques in C by implementing a simple even-odd number checker using raw binary operations on the STM32F407 Discovery board.

🧠 **Core Concepts Covered:**
- Bitwise Operators: &, |, ^, ~, <<, >>  
- Bit masking & clearing
- Efficient embedded logic using direct binary manipulation
- Determining even vs. odd using the LSB (Least Significant Bit)

#### What to be done:
- Create an input variable (int32_t num1)
- Use bitwise AND (&) to check if LSB is 1 (odd) or 0 (even)
- Print result to the SWV ITM Console

---

### ✅ Day 7: LED Toggle – Bare-Metal Embedded (No HAL/LL)
- 🔧 **Objective:** Blink the Green LED (LD4 - Pin PD12) continuously using bare-metal register-level programming without any HAL or LL libraries.

#### 🧠 Key Concepts
- Direct register access using memory-mapped I/O
- Clock enable through RCC
- GPIO mode configuration
- Toggling output pin using bitwise operations
- Software delay loops

#### 💻 Program Summary
- This program toggles the Green LED (PD12) on and off at a fixed interval using direct register access. No HAL, CMSIS, or LL libraries are used — only raw C and STM32F407 register addresses.

#### 📍 Memory-Mapped Register Addresses
- Register	Address	Purpose
- RCC_AHB1ENR	0x40023830	Enables peripheral clock to GPIO ports
- GPIOD_MODER	0x40020C00	Configures GPIO mode (Input/Output)
- GPIOD_ODR	0x40020C14	Controls GPIO output level

**⚙️ Step-by-Step Execution**
1. Enable GPIOD Clock
- *pClkCtrlReg |= (1 << 3); // Enable clock to GPIOD
2. Configure PD12 as Output
- *pPortDModeReg &= ~(3 << 24); // Clear bits 25:24
- *pPortDModeReg |=  (1 << 24); // Set bit 24: Output mode
3. Toggle PD12 (LED)
- *pPortDOutReg |=  (1 << 12); // Turn ON LED
// Delay Loop
- *pPortDOutReg &= ~(1 << 12); // Turn OFF LED
// Delay Loop
**🧪 Result**
- ✅ The Green LED (LD4) toggles ON and OFF every ~300ms using direct register manipulation.
- ✅ No external libraries were used — only bare-metal access.

**📚 Concepts Reinforced**
- Bitwise operations: |, &, ~
- Memory-mapped I/O
- Embedded delay loops
- GPIO peripheral control via RCC

**📎 Notes**
- Delay timing depends on compiler optimization and system clock.
- This is a fundamental exercise in low-level embedded control without abstraction layers.

---

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
