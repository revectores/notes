# ARM System Control

Components of system control:

- Reset control. 
- Clock control.
- Power control.
- Interrupt control.
- DMA control.



##### # Reset Control

The system detects the voltage periodically during

|                  |      |      |      |      |
| ---------------- | ---- | ---- | ---- | ---- |
| External reset   |      |      |      |      |
| Watchdog reset   |      |      |      |      |
| Software reset   |      |      |      |      |
| Power-on reset   |      |      |      |      |
| Power-down reset |      |      |      |      |



##### # Watchdog Reset

We are able to set the next PC when the watchdog counter overflows. When the watchdog counter overflows, it only clears the PC but keeps other registers.



##### # Software Reset

The software executes 



##### # Clock Types

Clocks can be classified to two types based on clock frequency: **high-speed clock** and **low-speed clock**, or based on locality: **internal clock** and **external clock**. The Cartesian product gives four types:

- High speed external clock (HSE). HFXTCLK.
- High speed internal clock (HSI). SYSOSC, MODCLK, DCOCLK.
- Low speed external clock (LSE). LFXTCLK.
- Low speed internal clock (LSI). VLOCLK, REFOCLK.

The internal clock generates by RC oscillator, it oscillates fast, but the external clock gets higher precision and stablability. Hence the internal clock is used when the system bootstraps, after the system is on, we can change the clock to external clock.



### 3. Power Control

##### # Sleep Mode



##### # Stop Mode

Exit: Any external interrupt or EXIT signal.



##### # Standby Mode

The kernel and external device, and the internal stop work

Exit: reset signal or RTC alarm event.









