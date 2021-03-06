#ifndef configFile
#define configFile

/* DEVICE */
#define AVAILABLE_CORES   ESP.getChipCores()
#define DISCONNECTED_PIN  32



/*  OLED SCREEN   */
#define Display_SCL_Pin       22            // IO22
#define Display_SDA_Pin       21            // IO21
#define SCREEN_WIDTH          128           // OLED display width, in pixels
#define SCREEN_HEIGHT         32            // OLED display height, in pixels
#define OLED_RESET            4             // Reset pin
#define SCREEN_ADDRESS        0x3C          //< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define WHITE                 SSD1306_WHITE
#define BLACK                 SSD1306_BLACK
#define FPS                   60
int displayCore             = 0;            // Overwritten later. It's the core, on which the I^2C communication will take place on (it's also the core, the Arduino IDE starts on).
#define SCREEN_QUEUE_LENGTH   3
QueueHandle_t                 screenControllerQueue;
#define SCREEN_COMMAND_COUNT  6


/*  ROTARY ENCODER  */
#define             ROTARY_ENCODER_PIN_A                          18
#define             ROTARY_ENCODER_PIN_B                          5
#define             ROTARY_ENCODER_BUTTON_PIN                     19
#define             ROTARY_ENCODER_BUTTON_POLLING_RATE            60
TaskHandle_t        rotaryEncoderInterruptTaskHandle            = NULL;
const int           rotaryEncoderDebounceTime                   = 33;
#define             ROTARY_ENCODER_INPUT_QUEUE_LENGTH             8
QueueHandle_t       rotaryEncoderInputQueue;


/* WIFI SERVER + STATION */
#define   SERVER_PORT               80  // default port for HTTP, so you don't have to specify port in the browser
IPAddress AccessPointIPAddress;
#define   RECONNECTION_MAX_COUNT    15
#define   RECONNECTION_TIMEOUT      2000
IPAddress StationIPAddress;


/* LED CONTROLLER */
#define                       RGB_STRIP_PIN               32
#define                       RGB_STRIP_PIXELS            30
uint8_t                       RGBDefaultBrightness      = 255;
uint8_t                       RGBCurrentBrightness      = 255;
#define                       WHITE_STRIP_PIN             16
#define                       WHITE_STRIP_CHANNEL         0
#define                       WHITE_STRIP_PWM_RESOLUTION  8
#define                       WHITE_STRIP_PWM_FREQUENCY   50000
#define                       LED_QUEUE_LENGTH            16
#define                       ANIMATION_LENGTH            20
int                           checkTime                 = 1000 / FPS;
TaskHandle_t                  LEDWorkerTaskHandle       = NULL;
SemaphoreHandle_t             LEDWorkerTaskSemaphore    = NULL;
struct LEDControllerCommand   globalLEDCommand;
QueueHandle_t                 LEDControllerQueue;


#endif
