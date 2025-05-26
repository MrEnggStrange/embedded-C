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

---
