<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# ATMEGA16 Zero Cross Detector

![Circuit](images/circuit.png)

This is an example of how make a zero cross detector with a ATmega16 which is based on the appnote [AN_2508](#Related-Documentation).

## Related Documentation

- [AN_2508 - Zero Cross Detector](https://www.microchip.com/wwwAppNotes/AppNotes.aspx?appnote=en591171)
- [ATmega16 Product Page](https://www.microchip.com/wwwproducts/en/ATmega16)
- [ATmega16 datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/doc2466.pdf)

## Software Used

- [MPLAB X IDE v5.40 or later](https://www.microchip.com/mplab/mplab-x-ide)
- ATmega_DFP 1.4.351 or later

## Hardware Used

-  [ATmega16 TQFN](https://www.microchip.com/wwwproducts/en/ATmega16)
-  [STK600](https://www.microchip.com/developmenttools/ProductDetails/ATSTK600) (Not required but we use it to hold our TQFN version of the chip)
-  [STK600 Routing card](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/ATSTK600-RC31)
-  [STK600 TQFP44](https://www.microchip.com/developmenttools/ProductDetails/ATSTK600-SC06)
-  [ATATMEL-ICE](https://www.microchip.com/DevelopmentTools/ProductDetails/ATATMEL-ICE) to program since programming over STK600 is not supported in MPLABX
- Logic analyser & wave generator to simulate mains and verify signal

## Setup

1. Connect the wavesource/wave generator to `PD2`
2. Connect the logic analyser/output to `PB0`

## Operation

1. Open `AVR182zerocrossdetector.X` in MPLAB
2. Connect the ATmega16 with your programmer of choice, we used a Atmel ICE.
3. Make sure the kit is selected as the tool to be programmed under project settings
4. Press the make and program button to program the device.
5. Generate a sinus waveform with **max** `VCC+0.5V` on `PD2` with a frequency of for example 50 Hz.
6. The logic analyser will then show a pulse train equivalent to that frequency on `PB0`

## Conclusion

We have shown how you can make a simple zero cross detector with a ATmega16. For more detailed workings about this example please refere to the appnote [AN_2508](#Related-Documentation)