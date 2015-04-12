#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x0000C000)
#define KEYS_MASK1 (0x3C3E0033)
#define KEYS_MASK2 (0x00000000)

#define SD_READONLY_FLAG (0x20000)
#define SD_READONLY_IDX 2

#define USB_MASK (0x20)
#define USB_IDX  2

#define KBD_ZOOM_FOR_MF_USE_MF_KEY 1
#endif
