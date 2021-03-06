#ifndef _GUISLICE_CONFIG_ARD_H_
#define _GUISLICE_CONFIG_ARD_H_

// =============================================================================
// GUIslice library (example user configuration #013) for:
//   - CPU:     Arduino UNO (ATmega328P)
//              Arduino Mega2560 (ATmega2560)
//   - Display: Adafruit 2.8" TFT LCD Shield w/ Touchscreen (resistive)
//
// DIRECTIONS:
// - To use this example configuration, rename the file as "GUIslice_config_ard.h"
//   and copy into the GUIslice/src directory.
//
// WIRING:
// - As this config file is designed for a shield, no additional
//   wiring is required to support the GUI operation
//
// - Calvin Hass
// - https://www.impulseadventure.com/elec/guislice-gui.html
// - https://github.com/ImpulseAdventure/GUIslice
// =============================================================================
//
// The MIT License
//
// Copyright 2018 Calvin Hass
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================
// \file GUIslice_config_ard.h

// =============================================================================
// User Configuration
// - This file can be modified by the user to match the
//   intended target configuration
// =============================================================================

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// =============================================================================
// USER DEFINED CONFIGURATION
// =============================================================================

// -----------------------------------------------------------------------------
// Orientation
// -----------------------------------------------------------------------------

// Set Default rotation of the display
// - Values 0,1,2,3. Rotation is clockwise
// - Note that changing this value may require a change
//   to GSLC_TOUCH_ROTATE as well to ensure the touch screen
//   orientation matches the display.
#define GSLC_ROTATE     1

// Set Default rotation of the touch overlay
// - Values 0,1,2,3. ROtation is clockwise
#define GSLC_TOUCH_ROTATE 1

// -----------------------------------------------------------------------------
// Touch Handling
// -----------------------------------------------------------------------------

// Calibration values for resistive touch display
// - These values may need to be updated to match your display
// - Typically used in resistive displays
// - These values can be determined from the Adafruit touchtest example sketch
//   (check for min and max values reported from program as you touch display
//   corners)
// - Note that X & Y directions reference the display's natural orientation
#define ADATOUCH_X_MIN 230
#define ADATOUCH_Y_MIN 260
#define ADATOUCH_X_MAX 3800
#define ADATOUCH_Y_MAX 3700

// -----------------------------------------------------------------------------
// Diagnostics
// -----------------------------------------------------------------------------

// Error reporting
// - Set DEBUG_ERR to 1 to enable error reporting via the Serial connection
// - Enabling DEBUG_ERR increases FLASH memory consumption which may be
//   limited on the baseline Arduino (ATmega328P) devices.
// - For baseline Arduino UNO, recommended to disable this after one has
//   confirmed basic operation of the library is successful.
#define DEBUG_ERR               1   // 1 to enable, 0 to disable

// -----------------------------------------------------------------------------
// Optional Features
// -----------------------------------------------------------------------------

// Enable of optional features
// - For memory constrained devices such as Arduino, it is best to
//   set the following features to 0 (to disable) unless they are
//   required.
#define GSLC_FEATURE_COMPOUND       0   // Compound elements (eg. XSelNum)
#define GSLC_FEATURE_XGAUGE_RADIAL  0   // XGauge control with radial support
#define GSLC_FEATURE_XGAUGE_RAMP    0   // XGauge control with ramp support
#define GSLC_FEATURE_XTEXTBOX_EMBED 0   // XTextbox control with embedded color
#define GSLC_FEATURE_INPUT          0   // Keyboard / GPIO input control


// Enable support for SD card
// - Set to 1 to enable, 0 to disable
// - Note that the inclusion of the SD library consumes considerable
//   RAM and flash memory which could be problematic for Arduino models
//   with limited resources.
#define GSLC_SD_EN    0


// =============================================================================
// INTERNAL CONFIGURATION
// - The following settings should not require modification by users
// =============================================================================

// Define display and touch driver
#define DRV_DISP_ADAGFX           // Adafruit-GFX library
#define DRV_DISP_ADAGFX_ILI9341   // Adafruit ILI9341
#define DRV_TOUCH_ADA_STMPE610    // Adafruit STMPE610 touch driver


// -----------------------------------------------------------------------------
// Pinout
// -----------------------------------------------------------------------------

// On shields, the following pinouts are hardcoded
#define ADAGFX_PIN_CS    10   // Display chip select
#define ADAGFX_PIN_DC     9   // Display SPI data/command
#define ADAGFX_PIN_RST    0   // Display Reset
#define ADAGFX_PIN_SDCS   4   // SD card chip select
#define ADAGFX_PIN_WR    A1   // Display write pin (for parallel displays)
#define ADAGFX_PIN_RD    A0   // Display read pin (for parallel displays)

#define ADAGFX_SPI_HW     1	  // Use the hardware SPI interface

#define ADAGFX_PIN_MOSI
#define ADAGFX_PIN_MISO
#define ADAGFX_PIN_CLK


// -----------------------------------------------------------------------------
// Touch Handling
// -----------------------------------------------------------------------------

// Select wiring method by setting one of the following to 1
#define ADATOUCH_I2C_HW 0
#define ADATOUCH_SPI_HW 1
#define ADATOUCH_SPI_SW 0  // [TODO]

// For ADATOUCH_I2C_HW=1
#define ADATOUCH_I2C_ADDR   0x41  // I2C address of touch device

// For ADATOUCH_SPI_HW=1
#define ADATOUCH_PIN_CS     8 // From Adafruit 2.8" TFT touch shield


#define TOUCH_ROTATION_DATA 0x6350
#define TOUCH_ROTATION_SWAPXY(rotation) ((( TOUCH_ROTATION_DATA >> ((rotation&0x03)*4) ) >> 2 ) & 0x01 )
#define TOUCH_ROTATION_FLIPX(rotation)  ((( TOUCH_ROTATION_DATA >> ((rotation&0x03)*4) ) >> 1 ) & 0x01 )
#define TOUCH_ROTATION_FLIPY(rotation)  ((( TOUCH_ROTATION_DATA >> ((rotation&0x03)*4) ) >> 0 ) & 0x01 )

// - Set any of the following to 1 to perform touch display
//   remapping functions, 0 to disable. Use DBG_TOUCH to determine which
//   remapping modes should be enabled for your display
// - Please refer to "docs/GUIslice_config_guide.xlsx" for detailed examples
// - NOTE: Both settings, GLSC_TOUCH_ROTATE and SWAP / FLIP are applied, 
//         try to set _SWAP_XY and _FLIP_X/Y to 0 and only use GLSC_TOUCH_ROTATE
#define ADATOUCH_SWAP_XY  0
#define ADATOUCH_FLIP_X   0
#define ADATOUCH_FLIP_Y   0

// Define the maximum number of touch events that are handled
// per gslc_Update() call. Normally this can be set to 1 but certain
// displays may require a greater value (eg. 30) in order to increase
// responsiveness of the touch functionality.
#define GSLC_TOUCH_MAX_EVT    1


// Define buffer size for loading images from SD
// - A larger buffer will be faster but at the cost of RAM
#define GSLC_SD_BUFFPIXEL   50


// Enable support for graphics clipping (DrvSetClipRect)
// - Note that this will impact performance of drawing graphics primitives
#define GSLC_CLIP_EN 1

// Enable for bitmap transparency and definition of color to use
#define GSLC_BMP_TRANS_EN     1               // 1 = enabled, 0 = disabled
#define GSLC_BMP_TRANS_RGB    0xFF,0x00,0xFF  // RGB color (default:pink)


#define GSLC_USE_FLOAT      0   // 1=Use floating pt library, 0=Fixed-point lookup tables


// Debug diagnostic modes
// - Uncomment any of the following to enable specific debug modes
//#define DBG_LOG           // Enable debugging log output
//#define DBG_TOUCH         // Enable debugging of touch-presses
//#define DBG_FRAME_RATE    // Enable diagnostic frame rate reporting
//#define DBG_DRAW_IMM      // Enable immediate rendering of drawing primitives
//#define DBG_DRIVER        // Enable graphics driver debug reporting



#define GSLC_DEV_TOUCH ""
#define GSLC_USE_PROGMEM 1

#define GSLC_LOCAL_STR      0   // 1=Use local strings (in element array), 0=External
#define GSLC_LOCAL_STR_LEN  30  // Max string length of text elements

// =============================================================================

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // _GUISLICE_CONFIG_ARD_H_
